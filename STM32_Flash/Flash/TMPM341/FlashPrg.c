/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2011 Keil Software. All rights reserved.        */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Flash Programming Functions adapted for               */
/*               Toshiba TMPM341Fx Flash                               */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#define M8(adr)  (*((volatile unsigned char  *)(adr)))
#define M16(adr) (*((volatile unsigned short *)(adr)))
#define M32(adr) (*((volatile unsigned long  *)(adr)))

#define STACK_SIZE     64      // Stack Size
#ifdef TMPM341_256
#define PAGE_SIZE     256      // Page Size for TMPM341FYXBG
#else
#define PAGE_SIZE     512      // Page Size for TMPM341FDXBG
#endif


// Watchdog Timer Registers
#define WDMOD    (*((volatile unsigned long  *)0x400F2000))
#define WDCR     (*((volatile unsigned long  *)0x400F2004))

// Flash Control/Status Register
#define FLCSF    (*((volatile unsigned long  *)0x41FFF020))

#define FLCS_RDY  0x00000001


unsigned long base_adr;


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
  return (1);                                  // Always Force Erase
}


/*
 *  Erase complete Flash Memory
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseChip (void) {

  // Start Chip Erase Command
  M8(base_adr + 0x5400) = 0xAA;
  M8(base_adr + 0xAA00) = 0x55;
  M8(base_adr + 0x5400) = 0x80;
  M8(base_adr + 0x5400) = 0xAA;
  M8(base_adr + 0xAA00) = 0x55;
  M8(base_adr + 0x5400) = 0x10;

  while ((FLCSF & FLCS_RDY) != FLCS_RDY);      // Wait until completed

  return (0);                                  // Finished without Errors
}


/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseSector (unsigned long adr) {

  // Start Block Erase Command
  M8(base_adr + 0x5400) = 0xAA;
  M8(base_adr + 0xAA00) = 0x55;
  M8(base_adr + 0x5400) = 0x80;
  M8(base_adr + 0x5400) = 0xAA;
  M8(base_adr + 0xAA00) = 0x55;
  M8(adr) = 0x30;

  while ((FLCSF & FLCS_RDY) != FLCS_RDY);      // Wait until completed

  return (0);                                  // Finished without Errors
}


/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */

int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {
  int i;

  // Start Page Programming Command
  M8(base_adr + 0x5400) = 0xAA;
  M8(base_adr + 0xAA00) = 0x55;
  M8(base_adr + 0x5400) = 0xA0;

  // Write Page Data
  for (i = 0; i < (PAGE_SIZE/4); i++) {
    M32(adr) = *((unsigned long *)buf);
    buf += 4;
  }

  while ((FLCSF & FLCS_RDY) != FLCS_RDY);      // Wait until completed

  return (0);                                  // Finished without Errors
}
