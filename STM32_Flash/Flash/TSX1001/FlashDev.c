/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2006-2012 Keil - An ARM Company.                     */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for                                */
/*               for Triad TSX1001 EEPROM Flash                        */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef FLASH_MEMORY

#ifdef TSX1001_32
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "TSX1001 Code EEPROM",      // Device Name (32kB)
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00008000,                 // Device Size in Bytes (32kB)
   128,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   5000,                       // Program Page Timeout 5000 mSec
   5000,                       // Erase Sector Timeout 5000 mSec

// Specify Size and Address of Sectors
   0x0080, 0x000000,           // Sector Size 128B (512 Sectors)
   SECTOR_END
};
#endif // TSX1001_32

#endif // FLASH_MEMORY
