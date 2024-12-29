/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2012 Keil Software. All rights reserved.        */
/***********************************************************************/
/*                                                                     */
/* FlashDev.c    Freescale MKExx  Flash                                */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef MKExx_P256KB
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKExx 256kB P-Flash",      // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00040000,                 // Device Size in Bytes (256kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000400, 0x000000,         // Sector Size  1kB (256 Sectors)
   SECTOR_END
};
#endif
#ifdef MKExx_P128KB
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKExx 128kB P-Flash",      // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00020000,                 // Device Size in Bytes (256kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000400, 0x000000,         // Sector Size  1kB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef MKExx_D8KB
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKExx  8kB D-Flash",       // Device Name 
   ONCHIP,                     // Device Type
   0x10000000,                 // Device Start Address
   0x00002000,                 // Device Size in Bytes (8kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000100, 0x000000,         // Sector Size 256B (32 Sectors)
   SECTOR_END
};
#endif
