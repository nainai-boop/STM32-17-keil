/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2011 Keil Software. All rights reserved.        */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for Luminary Micro                 */
/*               LM3Sxxx Flash                                         */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures


#ifdef FLASH_384
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LM3Sxxx 384kB Flash",      // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00060000,                 // Device Size in Bytes (384kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   500,                        // Program Page Timeout 500 mSec
   500,                        // Erase Sector Timeout 500 mSec

// Specify Size and Address of Sectors
   0x0400, 0x000000,           // Sector Size 1kB (384 Sectors)
   SECTOR_END
};
#endif


#ifdef FLASH_512
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LM3Sxxx 512kB Flash",      // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00080000,                 // Device Size in Bytes (512kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   500,                        // Program Page Timeout 500 mSec
   500,                        // Erase Sector Timeout 500 mSec

// Specify Size and Address of Sectors
   0x0400, 0x000000,           // Sector Size 1kB (512 Sectors)
   SECTOR_END
};
#endif
