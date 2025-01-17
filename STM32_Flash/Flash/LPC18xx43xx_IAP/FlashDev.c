/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2013 Keil Software. All rights reserved.        */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.c:  Device Description adapted for                        */
/*               NXP LPC18xx/43xx Flash using IAP                      */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures


#ifdef LPC18xx43xx

#ifdef FLASH_512_BA
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC18xx/43xx IAP 512kB Flash Bank A",  // Device Name
   ONCHIP,                     // Device Type
   0x1A000000,                 // Device Start Address
   0x00080000,                 // Device Size (512kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   5000,                       // Program Page Timeout 5000 mSec
   5000,                       // Erase Sector Timeout 5000 mSec

// Specify Size and Address of Sectors
   0x002000, 0x000000,         // Sector Size  8kB (8 Sectors)
   0x010000, 0x010000,         // Sector Size 64kB (7 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_512_BB
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC18xx/43xx IAP 512kB Flash Bank B",  // Device Name
   ONCHIP,                     // Device Type
   0x1B000000,                 // Device Start Address
   0x00080000,                 // Device Size (512kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   5000,                       // Program Page Timeout 5000 mSec
   5000,                       // Erase Sector Timeout 5000 mSec

// Specify Size and Address of Sectors
   0x002000, 0x000000,         // Sector Size  8kB (8 Sectors)
   0x010000, 0x010000,         // Sector Size 64kB (7 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_384_BA
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC18xx/43xx IAP 384kB Flash Bank A",  // Device Name
   ONCHIP,                     // Device Type
   0x1A000000,                 // Device Start Address
   0x00060000,                 // Device Size (384kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   5000,                       // Program Page Timeout 5000 mSec
   5000,                       // Erase Sector Timeout 5000 mSec

// Specify Size and Address of Sectors
   0x002000, 0x000000,         // Sector Size  8kB (8 Sectors)
   0x010000, 0x010000,         // Sector Size 64kB (5 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_384_BB
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC18xx/43xx IAP 384kB Flash Bank B",  // Device Name
   ONCHIP,                     // Device Type
   0x1B000000,                 // Device Start Address
   0x00060000,                 // Device Size (384kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   5000,                       // Program Page Timeout 5000 mSec
   5000,                       // Erase Sector Timeout 5000 mSec

// Specify Size and Address of Sectors
   0x002000, 0x000000,         // Sector Size  8kB (8 Sectors)
   0x010000, 0x010000,         // Sector Size 64kB (5 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_256_BA
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC18xx/43xx IAP 256kB Flash Bank A",  // Device Name
   ONCHIP,                     // Device Type
   0x1A000000,                 // Device Start Address
   0x00040000,                 // Device Size (256kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   5000,                       // Program Page Timeout 5000 mSec
   5000,                       // Erase Sector Timeout 5000 mSec

// Specify Size and Address of Sectors
   0x002000, 0x000000,         // Sector Size  8kB (8 Sectors)
   0x010000, 0x010000,         // Sector Size 64kB (3 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_256_BB
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC18xx/43xx IAP 256kB Flash Bank B",  // Device Name
   ONCHIP,                     // Device Type
   0x1B000000,                 // Device Start Address
   0x00040000,                 // Device Size (256kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   5000,                       // Program Page Timeout 5000 mSec
   5000,                       // Erase Sector Timeout 5000 mSec

// Specify Size and Address of Sectors
   0x002000, 0x000000,         // Sector Size  8kB (8 Sectors)
   0x010000, 0x010000,         // Sector Size 64kB (3 Sectors)
   SECTOR_END
};
#endif

#endif // LPC18xx43xx
