/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2012 Keil Software. All rights reserved.             */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.c:  Device Description adapted for                        */
/*               NXP LPC8xx Flash using IAP                            */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures


#ifdef LPC8XX

#ifdef FLASH_16
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC8xx IAP 16kB Flash",    // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00004000,                 // Device Size (16kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000400, 0x000000,         // Sector Size  1kB (16 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_8
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC8xx IAP 8kB Flash",     // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00002000,                 // Device Size (8kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000400, 0x000000,         // Sector Size  1kB (8 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_4
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC8xx IAP 4kB Flash",     // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00001000,                 // Device Size (4kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000400, 0x000000,         // Sector Size  1kB (4 Sectors)
   SECTOR_END
};
#endif

#endif // LPC8XX

