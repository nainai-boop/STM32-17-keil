/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2013 Keil Software. All rights reserved.        */
/***********************************************************************/
/*                                                                     */
/* FlashDev.c    Freescale MKE04 Device Flash                          */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef MKE04Zxxx_P8KB
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKE04Zxxx 8kB P-Flash",    // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00002000,                 // Device Size in Bytes (8kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000200, 0x000000,         // Sector Size  512Byte (16 Sectors)
   SECTOR_END
};
#endif

#ifdef MKE04Zxxx_P64KB
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKE04Zxxx 64kB P-Flash",   // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00010000,                 // Device Size in Bytes (64kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000200, 0x000000,         // Sector Size  512Byte (128 Sectors)
   SECTOR_END
};
#endif

#ifdef MKE04Zxxx_P128KB
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKE04Zxxx 128kB P-Flash",  // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00020000,                 // Device Size in Bytes (128kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000200, 0x000000,         // Sector Size  512Byte (256 Sectors)
   SECTOR_END
};
#endif
