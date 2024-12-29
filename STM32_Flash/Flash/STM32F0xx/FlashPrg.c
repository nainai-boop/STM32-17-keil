/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2013 Keil - An ARM Company.                     */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashPrg.c:  Flash Programming Functions adapted for               */
/*               ST Microelectronics STM32F0xx Flash                   */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

typedef volatile unsigned char    vu8;
typedef          unsigned char     u8;
typedef volatile unsigned short   vu16;
typedef          unsigned short    u16;
typedef volatile unsigned long    vu32;
typedef          unsigned long     u32;

#define M8(adr)  (*((vu8  *) (adr)))
#define M16(adr) (*((vu16 *) (adr)))
#define M32(adr) (*((vu32 *) (adr)))

// Peripheral Memory Map
#define IWDG_BASE       0x40003000
#define FLASH_BASE      0x40022000

#define IWDG            ((IWDG_TypeDef *) IWDG_BASE)
#define FLASH           ((FLASH_TypeDef*) FLASH_BASE)

// Independent WATCHDOG
typedef struct {
  vu32 KR;                                              // offset  0x000
  vu32 PR;                                              // offset  0x004
  vu32 RLR;                                             // offset  0x008
  vu32 SR;                                              // offset  0x00C
} IWDG_TypeDef;

// Flash Registers
typedef struct {
  vu32 ACR;                                             // offset  0x000
  vu32 KEYR;                                            // offset  0x004
  vu32 OPTKEYR;                                         // offset  0x008
  vu32 SR;                                              // offset  0x00C
  vu32 CR;                                              // offset  0x010
  vu32 AR;                                              // offset  0x014
  vu32 RESERVED0[1];
  vu32 OBR;                                             // offset  0x01C
  vu32 WRPR;                                            // offset  0x020
} FLASH_TypeDef;


// Flash Keys
#define RDPRT_KEY               ((unsigned int)    0x55AA)
#define FLASH_KEY1              ((unsigned int)0x45670123)
#define FLASH_KEY2              ((unsigned int)0xCDEF89AB)
#define FLASH_OPTKEY1           ((unsigned int)0x45670123)
#define FLASH_OPTKEY2           ((unsigned int)0xCDEF89AB)

// Flash Control Register definitions
#define FLASH_PG                ((unsigned int)0x00000001)
#define FLASH_PER               ((unsigned int)0x00000002)
#define FLASH_MER               ((unsigned int)0x00000004)
#define FLASH_OPTPG             ((unsigned int)0x00000010)
#define FLASH_OPTER             ((unsigned int)0x00000020)
#define FLASH_STRT              ((unsigned int)0x00000040)
#define FLASH_LOCK              ((unsigned int)0x00000080)
#define FLASH_OPTWRE            ((unsigned int)0x00000100)

// Flash Status Register definitions
#define FLASH_BSY               ((unsigned int)0x00000001)
#define FLASH_PGERR             ((unsigned int)0x00000004)
#define FLASH_WRPRTERR          ((unsigned int)0x00000010)
#define FLASH_EOP               ((unsigned int)0x00000020)

#define FLASH_ERR               (FLASH_PGERR | FLASH_WRPRTERR)


/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

#ifdef FLASH_MEM
int Init (unsigned long adr, unsigned long clk, unsigned long fnc) {

  FLASH->KEYR = FLASH_KEY1;                             // Unlock Flash
  FLASH->KEYR = FLASH_KEY2;

  FLASH->ACR  = 0x00000000;                             // Zero Wait State, no Prefetch
  FLASH->SR  |= FLASH_ERR;                              // Reset Error Flags

  if ((FLASH->OBR & 0x04) == 0x00) {                    // Test if IWDG is running (IWDG in HW mode)
    // Set IWDG time out to ~32.768 second
    IWDG->KR  = 0x5555;                                 // Enable write access to IWDG_PR and IWDG_RLR     
    IWDG->PR  = 0x06;                                   // Set prescaler to 256  
    IWDG->RLR = 4095;                                   // Set reload value to 4095
  }

  return (0);
}
#endif

#ifdef FLASH_OPT
int Init (unsigned long adr, unsigned long clk, unsigned long fnc) {

  FLASH->KEYR = FLASH_KEY1;                             // Unlock Flash
  FLASH->KEYR = FLASH_KEY2;

  FLASH->OPTKEYR = FLASH_OPTKEY1;                       // Unlock Option Bytes
  FLASH->OPTKEYR = FLASH_OPTKEY2;

  FLASH->ACR  = 0x00000000;                             // Zero Wait State, no Prefetch
  FLASH->SR  |= FLASH_ERR;                              // Reset Error Flags


  if ((FLASH->OBR & 0x04) == 0x00) {                    // Test if IWDG is running (IWDG in HW mode)
    // Set IWDG time out to ~32.768 second
    IWDG->KR  = 0x5555;                                 // Enable write access to IWDG_PR and IWDG_RLR     
    IWDG->PR  = 0x06;                                   // Set prescaler to 256  
    IWDG->RLR = 4095;                                   // Set reload value to 4095
  }

  return (0);
}
#endif


/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

#ifdef FLASH_MEM
int UnInit (unsigned long fnc) {

  FLASH->CR    |=  FLASH_LOCK;                          // Lock Flash

  return (0);
}
#endif

#ifdef FLASH_OPT
int UnInit (unsigned long fnc) {

  FLASH->CR    |=  FLASH_LOCK;                          // Lock Flash
  FLASH->CR    &= ~FLASH_OPTWRE;                        // Lock Option Bytes

  return (0);
}
#endif


/*
 *  Erase complete Flash Memory
 *    Return Value:   0 - OK,  1 - Failed
 */

#ifdef FLASH_MEM
int EraseChip (void) {

  FLASH->SR  |= FLASH_ERR;                              // Reset Error Flags

  FLASH->CR |=  FLASH_MER;                              // Mass Erase Enabled
  FLASH->CR |=  FLASH_STRT;                             // Start Erase

  while (FLASH->SR & FLASH_BSY) {
    IWDG->KR = 0xAAAA;                                  // Reload IWDG
  }

  FLASH->CR &= ~FLASH_MER;                              // Mass Erase Disabled

  if (FLASH->SR & FLASH_ERR) {                          // Check for Errors
    FLASH->SR |= FLASH_ERR;
    return (1);                                         // Failed
  }

  return (0);                                           // Done
}
#endif

#ifdef FLASH_OPT
int EraseChip (void) {

  FLASH->SR  |= FLASH_ERR;                              // Reset Error Flags

  FLASH->CR |=  FLASH_OPTER;                            // Option Byte Erase Enabled 
  FLASH->CR |=  FLASH_STRT;                             // Start Erase

  while (FLASH->SR & FLASH_BSY) {
    IWDG->KR = 0xAAAA;                                  // Reload IWDG
  }

  FLASH->CR &= ~FLASH_OPTER;                            // Option Byte Erase Disabled 

  // Unprotect Flash
  FLASH->CR |=  FLASH_OPTPG;                            // Option Byte Programming Enabled

  M16(0x1FFFF800) = RDPRT_KEY;                          // Program Half Word: RDPRT Key
  while (FLASH->SR & FLASH_BSY) {
    IWDG->KR = 0xAAAA;                                  // Reload IWDG
  }

  FLASH->CR &= ~FLASH_OPTPG;                            // Option Byte Programming Disabled
  
  if (FLASH->SR & FLASH_ERR) {                          // Check for Errors
    FLASH->SR |= FLASH_ERR;
    return (1);                                         // Failed
  }

  return (0);                                           // Done
}
#endif


/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */

#ifdef FLASH_MEM
int EraseSector (unsigned long adr) {

  FLASH->SR  |= FLASH_ERR;                              // Reset Error Flags

  FLASH->CR  |=  FLASH_PER;                             // Page Erase Enabled 
  FLASH->AR   =  adr;                                   // Page Address
  FLASH->CR  |=  FLASH_STRT;                            // Start Erase

  while (FLASH->SR  & FLASH_BSY) {
    IWDG->KR = 0xAAAA;                                  // Reload IWDG
  }

  FLASH->CR  &= ~FLASH_PER;                             // Page Erase Disabled 

  if (FLASH->SR & FLASH_ERR) {                          // Check for Errors
    FLASH->SR |= FLASH_ERR;
    return (1);                                         // Failed
  }

  return (0);                                           // Done
}
#endif

#ifdef FLASH_OPT
int EraseSector (unsigned long adr) {

  FLASH->SR  |= FLASH_ERR;                              // Reset Error Flags

  FLASH->CR |=  FLASH_OPTER;                            // Option Byte Erase Enabled 
  FLASH->CR |=  FLASH_STRT;                             // Start Erase

  while (FLASH->SR & FLASH_BSY) {
    IWDG->KR = 0xAAAA;                                  // Reload IWDG
  }

  FLASH->CR &= ~FLASH_OPTER;                            // Option Byte Erase Disabled 

  if (FLASH->SR & FLASH_ERR) {                          // Check for Errors
    FLASH->SR |= FLASH_ERR;
    return (1);                                         // Failed
  }

  return (0);                                           // Done
}
#endif


/*  
 *  Blank Check Checks if Memory is Blank
 *    Parameter:      adr:  Block Start Address
 *                    sz:   Block Size (in bytes)
 *                    pat:  Block Pattern
 *    Return Value:   0 - OK,  1 - Failed
 */

#ifdef FLASH_OPT
int BlankCheck (unsigned long adr, unsigned long sz, unsigned char pat) {
  return (1);                                            // Always Force Erase
}
#endif


/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */

#ifdef FLASH_MEM
int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {

  sz = (sz + 1) & ~1;                                   // Adjust size for Half Words
  
  FLASH->SR |= FLASH_PGERR;                             // Reset Error Flags

  while (sz) {
    FLASH->CR  |=  FLASH_PG;                            // Programming Enabled

    M16(adr) = *((u16 *)buf);                           // Program Half Word
    while (FLASH->SR & FLASH_BSY) {
      IWDG->KR = 0xAAAA;                                // Reload IWDG
    }

    FLASH->CR  &= ~FLASH_PG;                            // Programming Disabled

    if (FLASH->SR & FLASH_ERR) {                        // Check for Errors
      FLASH->SR |= FLASH_ERR;
      return (1);                                       // Failed
    }

    adr += 2;                                           // Go to next Half Word
    buf += 2;
    sz  -= 2;
  }

  return (0);                                           // Done
}
#endif

#ifdef FLASH_OPT
int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {

  sz = (sz + 1) & ~1;                                   // Adjust size for Half Words
  
  FLASH->SR |= FLASH_PGERR;                             // Reset Error Flags

  while (sz) {
    FLASH->CR |=  FLASH_OPTPG;                          // Option Byte Programming Enabled

    M16(adr) = *((u16 *)buf);                           // Program Half Word
    while (FLASH->SR & FLASH_BSY) {
      IWDG->KR = 0xAAAA;                                // Reload IWDG
    }

    FLASH->CR &= ~FLASH_OPTPG;                          // Option Byte Programming Disabled

    if (FLASH->SR & FLASH_ERR) {                        // Check for Errors
      FLASH->SR |= FLASH_ERR;
      return (1);                                       // Failed
    }

    adr += 2;                                           // Go to next Half Word
    buf += 2;
    sz  -= 2;
  }

  return (0);                                           // Done
}
#endif
