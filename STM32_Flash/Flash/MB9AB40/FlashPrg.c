/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2012 Keil - An ARM Company.                          */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Flash Programming Functions adapted for               */
/*               Fujitsu MB9AB40N/A40N/340N/140N/150R/                 */
/*                       MB9B520M/320M/120M            Series          */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

typedef volatile unsigned long    vu32;
typedef          unsigned long     u32;
typedef volatile unsigned short   vu16;
typedef          unsigned short    u16;

#define M16(adr) (*((vu16 *) (adr)))

// Peripheral Memory Map
#define FIF_BASE          (0x40000000)
#define HWWDT_BASE        (0x40011000)

#define FIF               ((FIF_TypeDef *) FIF_BASE)
#define HWWDT             ((WDT_TypeDef *) HWWDT_BASE)


typedef struct {             // Flash Interface
  vu32 RESERVED0;
  vu32 FRWTR;                // Offset: 0x004 (R/W) Flash Read Wait Register
  vu32 FSTR;                 // Offset: 0x008 (R/ ) Flash Status Register
} FIF_TypeDef;

// FSTR (Flash Status Register) defines
#define FSTR_PGMS   (1UL << 5)          // Flash Program Status
#define FSTR_SERS   (1UL << 4)          // Flash Sector Erase Status
#define FSTR_ESPS   (1UL << 3)          // Flash Erase Suspend Status
#define FSTR_CERS   (1UL << 2)          // Flash Chip Erase Status
#define FSTR_HNG    (1UL << 1)          // Flash Hang
#define FSTR_RDY    (1UL << 0)          // Flash Ready Status


typedef struct {             // Watchdog Timer
  vu32 LDR;                  // offset: 0x000 (R/W) Watchdog Timer Load Register
  vu32 VLR;                  // Offset: 0x004 (R/W) Watchdog Timer Value Register
  vu32 CTL;                  // Offset: 0x008 (R/W) Watchdog Timer Control Register
  vu32 ICL;                  // Offset: 0x00C (R/W) Watchdog Timer Clear Register
  vu32 RIS;                  // Offset: 0x010 (R/W) Watchdog Timer Interrupt Status Register
  vu32 RESERVED0[763];
  vu32 LCK;                  // Offset: 0xC00 (R/W) Watchdog Timer Lock Register
} WDT_TypeDef;


/* MB9AB40N device
  -------------+-----------+-------------+-------------+-------------+-------------+-------------+--------------
               |           |  1st write  |  2nd write  |  3rd write  |  4th write  |  5th write  |  6th write
     Command   | Number of |-------------+-------------+-------------+-------------+-------------+--------------
               | writes    | Addr.| Data | Addr.| Data | Addr.| Data | Addr.| Data | Addr.| Data | Addr.| Data
  -------------+-----------+------+------+------+------+------+------+------+------+------+------+------+-------
  Read/Reset         1      0xXXX  0xF0   RA     RD     --     --     --     --     --     --     --     --
  Write              4      0xAA8  0xAA   0x554  0x55   0xAA8  0xA0   PA     PD     --     --     --     --
  Chip erase         6      0xAA8  0xAA   0x554  0x55   0xAA8  0x80   0xAA8  0xAA   0x554  0x55   0xAA8  0x10
  Sector erase       6      0xAA8  0xAA   0x554  0x55   0xAA8  0x80   0xAA8  0xAA   0x554  0x55   SA     0x30
 */


/* define Address for command write cycle */
#if 1
  #define ADDR_1st    0x0AA8
  #define ADDR_2nd    0x0554
  #define ADDR_3rd    0x0AA8
  #define ADDR_4th    0x0AA8
  #define ADDR_5th    0x0554
  #define ADDR_6th    0x0AA8
#endif


unsigned long base_adr;


/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int Init (unsigned long adr, unsigned long clk, unsigned long fnc) {

  HWWDT->LCK = 0x1ACCE551;
  HWWDT->LCK = 0xE5331AAE;
  HWWDT->CTL = 0;                                       // Disable Watchdog

  base_adr = adr;

  return (0);                                           // Done
}


/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int UnInit (unsigned long fnc) {

  return (0);                                           // Done
}


/*
 *  Erase complete Flash Memory
 *    Return Value:   0 - OK,  1 - Failed
 */
#if 0   // JIRA case SDMDK-2052: Flash Erase does erase RC clock calibration settings
int EraseChip (void) {
  vu32 dummy;

  // Start Chip Erase Command
  M16(base_adr + ADDR_1st) = 0xAA;
  M16(base_adr + ADDR_2nd) = 0x55;
  M16(base_adr + ADDR_3rd) = 0x80;
  M16(base_adr + ADDR_4th) = 0xAA;
  M16(base_adr + ADDR_5th) = 0x55;
  M16(base_adr + ADDR_6th) = 0x10;

  dummy = FIF->FSTR;                                    // dummy read
  while ((FIF->FSTR & FSTR_RDY) == 0) {
    ;
  }

  if ((FIF->FSTR & (FSTR_CERS | FSTR_HNG)) != 0) {      // Check for Error
    return (1);                                         // Failed
  }

  return (0);
}
#endif

/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseSector (unsigned long adr) {
  vu32 dummy;

  // Start Erase Sector Command
  M16(base_adr + ADDR_1st) = 0xAA;
  M16(base_adr + ADDR_2nd) = 0x55;
  M16(base_adr + ADDR_3rd) = 0x80;
  M16(base_adr + ADDR_4th) = 0xAA;
  M16(base_adr + ADDR_5th) = 0x55;
  M16(adr)     = 0x30;                                  // erase fist   internal sector

  dummy = FIF->FSTR;                                    // dummy read
  while ((FIF->FSTR & FSTR_RDY) == 0) {
    ;
  }

  if ((FIF->FSTR & (FSTR_SERS | FSTR_HNG)) != 0) {      // Check for Error
    return (1);                                         // Failed
  }

  return (0);
}



/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */

int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {
  int  i;
  vu32 dummy;

  for (i = 0; i < ((sz+1)/2); i++)  {
    // Start Program Command
    M16(base_adr + ADDR_1st) = 0xAA;
    M16(base_adr + ADDR_2nd) = 0x55;
    M16(base_adr + ADDR_3rd) = 0xA0;
    M16(adr) = *((u16 *) buf);

    dummy = FIF->FSTR;                                  // dummy read
    while ((FIF->FSTR & FSTR_RDY) == 0) {
      ;
    }

  if ((FIF->FSTR & (FSTR_PGMS | FSTR_HNG)) != 0) {      // Check for Error
      return (1);                                       // Failed
    }

    buf += 2;
    adr += 2;
  }

  return (0);
}
