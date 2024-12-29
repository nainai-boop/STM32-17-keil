/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2013 Keil - An ARM Company.                     */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashPrg.c:  Flash Programming Functions adapted for               */
/*               Toshiba TMPM462 Flashes                               */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#define M8(adr)  (*((volatile unsigned char  *)(adr)))
#define M16(adr) (*((volatile unsigned short *)(adr)))
#define M32(adr) (*((volatile unsigned long  *)(adr)))

#define STACK_SIZE     64      // Stack Size
#define PAGE_SIZE    4096      // Page Size for TMPM462 but data is written in junks of 4 Words


// Watchdog Timer Registers
#define WDMOD            (*((volatile unsigned long  *)0x402F2000ul))
#define WDCR             (*((volatile unsigned long  *)0x402F2004ul))

// Protect Status Register 0
#define FCPSR0           (*((volatile unsigned long  *)0x41FFF020ul))
#define FCPSR0_RDY       (1ul << 0)

// Area Select Register
#define FCAREASEL        (*((volatile unsigned long  *)0x41FFF140ul))
#define FCAREASEL_AREA0  (7ul << 0)
#define FCAREASEL_AREA1  (7ul << 4)
#define FCAREASEL_AREA2  (7ul << 8)


unsigned long base_adr;
unsigned long area_adr;
unsigned long area_sel;

/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int Init (unsigned long adr, unsigned long clk, unsigned long fnc) {

  // Disable Watchdog
  WDMOD = 0x00;
  WDCR  = 0xB1;

  base_adr = adr;

  return (0);
}


/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int UnInit (unsigned long fnc) {

  return (0);
}


/*  Blank Check Block in Flash Memory
 *    Parameter:      adr:  Block Start Address
 *                    sz:   Block Size (in bytes)
 *                    pat:  Block Pattern
 *    Return Value:   0 - OK,  1 - Failed
 */

int BlankCheck (unsigned long adr, unsigned long sz, unsigned char pat) {
  return (1);                                    // Always Force Erase
}


/*
 *  Erase complete Flash Memory
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseChip (void) {
  
  area_adr = 0x5E000000ul;
  area_sel = (FCAREASEL_AREA2 | FCAREASEL_AREA1 | FCAREASEL_AREA0);
  
  FCAREASEL = area_sel;                          // Specify the target area of Flash memory
  while (FCAREASEL != area_sel);  

  // Start Chip Erase Command
  M8(area_adr | 0x5400) = 0xAA;
  M8(area_adr | 0xAA00) = 0x55;
  M8(area_adr | 0x5400) = 0x80;
  M8(area_adr | 0x5400) = 0xAA;
  M8(area_adr | 0xAA00) = 0x55;
  M8(area_adr | 0x5400) = 0x10;

  while ((FCPSR0 & FCPSR0_RDY) != FCPSR0_RDY);   // Wait until completed

  FCAREASEL = 0;                                 // Reset the target area of Flash memory
  while (FCAREASEL != 0);  

  return (0);                                    // Finished without Errors
}


/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseSector (unsigned long adr) {

//  area_adr = 0x5E000000ul + (adr & 0x00080000ul);
//  area_sel = (adr & 0x00080000ul) ? FCAREASEL_AREA1 : FCAREASEL_AREA0;
	if      (adr < 0x00080000) {
		area_adr = 0x5E000000ul;
		area_sel = FCAREASEL_AREA0;
	}
	else if (adr < 0x00100000) {
		area_adr = 0x5E080000ul;
		area_sel = FCAREASEL_AREA1;
	}
	else {
		area_adr = 0x5E100000ul;
		area_sel = FCAREASEL_AREA2;
	}

  FCAREASEL = area_sel;                          // Specify the target area of Flash memory
  while (FCAREASEL != area_sel);  

  // Start Block Erase Command
  M8(area_adr | 0x5400) = 0xAA;
  M8(area_adr | 0xAA00) = 0x55;
  M8(area_adr | 0x5400) = 0x80;
  M8(area_adr | 0x5400) = 0xAA;
  M8(area_adr | 0xAA00) = 0x55;
  M8(area_adr | adr   ) = 0x30;

  while ((FCPSR0 & FCPSR0_RDY) != FCPSR0_RDY);   // Wait until completed

  FCAREASEL = 0;                                 // Reset the target area of Flash memory
  while (FCAREASEL != 0);  

  return (0);                                    // Finished without Errors
}


/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */

int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {
  int len = sz;
  
//  area_adr = 0x5E000000 + (adr & 0x00080000);
//  area_sel = (adr & 0x00080000) ? FCAREASEL_AREA1 : FCAREASEL_AREA0;
	if      (adr < 0x00080000ul) {
		area_adr = 0x5E000000ul;
		area_sel = FCAREASEL_AREA0;
	}
	else if (adr < 0x00100000ul) {
		area_adr = 0x5E080000ul;
		area_sel = FCAREASEL_AREA1;
	}
	else {
		area_adr = 0x5E100000ul;
		area_sel = FCAREASEL_AREA2;
	}

  FCAREASEL = area_sel;                          // Specify the target area of Flash memory
  while (FCAREASEL != area_sel);  

  while (len > 0) {
    // Start Page Programming Command
    M8(area_adr | 0x5400) = 0xAA;
    M8(area_adr | 0xAA00) = 0x55;
    M8(area_adr | 0x5400) = 0xA0;

    // Write Data in junks of 4 * 4 words
    M32(area_adr | adr) = *((unsigned long *)(buf +  0));
    M32(area_adr | adr) = *((unsigned long *)(buf +  4));
    M32(area_adr | adr) = *((unsigned long *)(buf +  8));
    M32(area_adr | adr) = *((unsigned long *)(buf + 12));
    adr += 16;
    buf += 16;
    len -= 16;

    while ((FCPSR0 & FCPSR0_RDY) != FCPSR0_RDY); // Wait until completed
  }

  FCAREASEL = 0;                                 // Reset the target area of Flash memory
  while (FCAREASEL != 0);  

  return (0);                                    // Finished without Errors
}
