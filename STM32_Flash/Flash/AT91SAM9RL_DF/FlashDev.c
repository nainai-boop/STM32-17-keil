/******************************************************************************/
/*  This file is part of the ARM Toolchain package                            */
/*  Copyright KEIL ELEKTRONIK GmbH 2005 - 2008                                */
/******************************************************************************/
/*                                                                            */
/*  FlashDev.C:  Device Description for flash algorithm using Atmel           */
/*               AT91SAM9RL Device for Programming External DataFlash         */
/*               AT45DB642D                                                   */
/*                                                                            */
/******************************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures


                               // Page Size 1056 Bytes
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "AT91SAM9RL DataFlash Page1056",  // Device Name
   EXTSPI,                     // Device Type
   0x20000000,                 // Device Start Address
   0x00840000,                 // Device Size in Bytes (8.25MB)
   1056,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   1000,                       // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x2100, 0x000000,           // Sector Size 8448 bytes (block = 8*page)
   SECTOR_END
};