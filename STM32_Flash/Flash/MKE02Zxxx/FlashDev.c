/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2012 Keil Software. All rights reserved.        */
/***********************************************************************/
/*                                                                     */
/* FlashDev.c    Freescale MKE02 Device Flash                          */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef MKE02Zxxx_P16KB
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKE02Zxxx 16kB P-Flash",   // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00004000,                 // Device Size in Bytes (16kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000200, 0x000000,         // Sector Size  512Byte (32 Sectors)
   SECTOR_END
};
#endif
#ifdef MKE02Zxxx_P32KB
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKE02Zxxx 32kB P-Flash",   // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00008000,                 // Device Size in Bytes (32kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000200, 0x000000,         // Sector Size  512Byte (64 Sectors)
   SECTOR_END
};
#endif
#ifdef MKE02Zxxx_P64KB
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKE02Zxxx 64kB P-Flash",   // Device Name 
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


#ifdef MKE02Zxxx_EE256B
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKE02Zxxx 256B EEPROM",    // Device Name 
   ONCHIP,                     // Device Type
   0x10000000,                 // Device Start Address
   0x00000100,                 // Device Size in Bytes (256B)
   2,                          // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erase mSec
   3000,                       // Erase Sector Timeout 300d Memory
   100,                        // Program Page Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x000002, 0x000000,         // Sector Size 2B (128 Sectors)
   SECTOR_END
};
#endif
