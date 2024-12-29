/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2006-2010 Keil - An ARM Company.                     */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Flash Programming Functions adapted                   */
/*               for Triad TSX1001 EEPROM Flash                        */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

typedef volatile unsigned long  vu32;

#define M32(adr) (*((vu32 *) (adr)))

// Peripheral Memory Map
#define MOCHA1_BASE      0xB0000000
#define GPIO1_BASE       0x50000800

#define MOCHA1          ((MOCHA1_TypeDef*) MOCHA1_BASE)
#define GPIO1           ((GPIO1_TypeDef*)  GPIO1_BASE)

// SYSCTRL Registers
typedef struct {
  vu32 CTRL0;                                            // offset  0x000 Control 0 register
  vu32 CTRL1;                                            // offset  0x004 Control 1 register
  vu32 WIC;                                              // offset  WIC register
} MOCHA1_TypeDef;

// GPIO1 Registers
typedef struct {
  vu32 DATA;                                             // offset  0x000 Data register
} GPIO1_TypeDef;

#define EE_WR_OFFSET   0xC0000000                        // EEPROM Write Offset
#define EE_PG_SZ       128                               // EEPROM Page Size

/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int Init (unsigned long adr, unsigned long clk, unsigned long fnc) {

  switch (fnc) {
    case 1:
    case 2:
      if ((GPIO1->DATA & (1UL << 5)) != (1UL << 5)) {
        GPIO1->DATA |= (1UL << 8);                       // set SWCHK_LOCK
      }
        
      MOCHA1->CTRL0  =  ((1UL << 23) |                   // EE_NOWRSTALL enable
                         (1UL << 21) |                   // EE_WREN enable
                         (3UL << 16)  );                 // EE_WAIT (3 Waitstates)

      MOCHA1->CTRL0 |=   (7UL <<  0);                    // CLK rate 1:1
    break;
  }

  return (0);
}


/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int UnInit (unsigned long fnc) {

  switch (fnc) {
    case 1:
    case 2:
      MOCHA1->CTRL0 &= ~((1UL << 23) |                   // EE_NOWRSTALL disable
                         (1UL << 21)  );                 // EE_WREN enable
    break;
  }

  return (0);
}


/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseSector (unsigned long adr) {
  unsigned long  cnt = EE_PG_SZ;
  unsigned long  to = 0;

  adr = (adr + (EE_PG_SZ-1)) & ~(EE_PG_SZ-1);            // adjust Address

//  MOCHA1->CTRL0  &=  ~(1UL << 31);                       // reset EEPROM ready bit
  while (cnt) {
    M32(adr + EE_WR_OFFSET) = 0xFFFFFFFF;                // write '1' to the first address to erase page

    adr += 4;
    cnt -= 4;
  }

  while (MOCHA1->CTRL0 & (1UL << 31) == 0) {             // wait until EEPROM ready
    to++;
    if (to > 0x1000)
      break;
    __nop();
  }

//for (to = 0; to < 0x200; to++) __nop();
  return (0);                                            // Done
}


/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */

int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {
  unsigned long  cnt = EE_PG_SZ;
  unsigned long  to = 0;
  
  adr = (adr + (EE_PG_SZ-1)) & ~(EE_PG_SZ-1);            // adjust Address

  //  MOCHA1->CTRL0  &=  ~(1UL << 31);                       // reset EEPROM ready bit
  while (cnt) {
    if (sz > 0) {
      M32(adr + EE_WR_OFFSET) = *((unsigned long *)buf); // Program Word
    } else {
      M32(adr + EE_WR_OFFSET) = 0xFFFFFFFF;              // Program erased value
    }

    adr += 4;
    buf += 4;
    sz  -= 4;
    cnt -= 4;
  }

  while (MOCHA1->CTRL0 & (1UL << 31) == 0) {             // wait until EEPROM ready
    to++;
    if (to > 0x1000)
      break;
    __nop();
  }

  return (0);                                            // Done
}


/*
 *  Verify Flash Contents
 *    Parameter:      adr:  Start Address
 *                    sz:   Size (in bytes)
 *                    buf:  Data
 *    Return Value:   (adr+sz) - OK, Failed Address
 */

unsigned long Verify (unsigned long adr, unsigned long sz, unsigned char *buf) {
  unsigned long i, adr_dest;

  adr_dest = adr + EE_WR_OFFSET;

  for (i = 0; i < ((sz+3)/4); i++)  {
    if (M32(adr_dest) != *((unsigned long *)buf)) return (adr);
    buf      += 4;
    adr      += 4;
    adr_dest += 4;
  }

  return (adr);
}
