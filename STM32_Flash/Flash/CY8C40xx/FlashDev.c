/************************************************************************/
/*  This file was adapted from the ARM Toolchain package				*/
/*  Copyright (c) 2013 Cypress Semiconductor. All rights reserved.		*/
/************************************************************************/
/*																		*/
/*  FlashDev.C:  Device Description for CY8C40xx Device Flash			*/
/*																		*/
/************************************************************************/

#include "..\FlashOS.H"					// FlashOS Structures

struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,								// Driver Version, do not modify!
   "CY8C40xx (16kB) Flash",				// Device Name 
   ONCHIP,												// Device Type
   0x00000000,										// Device Start Address
   0x00004000,										// Device Size in Bytes (16kB)
   64,														// Programming Page Size
   0,															// Reserved, must be 0
   0x00,													// Initial Content of Erased Memory
   100,														// Program Page Timeout 100 mSec
   3000,													// Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x004000, 0x000000,						// Sector Size  16kB (1 Sectors)
   /*0x010000, 0x010000,					// Sector Size 64kB (2 Sectors) 
   0x002000, 0x030000,						// Sector Size  8kB (8 Sectors)*/
   SECTOR_END
};