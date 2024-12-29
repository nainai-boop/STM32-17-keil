/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2006-2010 Keil - An ARM Company.                     */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for Nano100 Flash                   */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef FLASH_APROM

#ifdef FLASH_123
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "Nano100 123kB Flash AP",   // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x0001EC00,                 // Device Size in Bytes (123kB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000200, 0x000000,         // Sector Size  512B (128 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "Nano100 64kB Flash AP",     // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00010000,                 // Device Size in Bytes (64kB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000200, 0x000000,         // Sector Size  512B (128 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_32
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "Nano100 32kB Flash AP",     // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00008000,                 // Device Size in Bytes (32kB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000200, 0x000000,         // Sector Size  512B (64 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_16
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "Nano100 16kB Flash AP",     // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00004000,                 // Device Size in Bytes (16kB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000200, 0x000000,         // Sector Size  512B (64 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_8
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "Nano100 8kB Flash AP",     // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00002000,                 // Device Size in Bytes (8kB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000200, 0x000000,         // Sector Size  512B (64 Sectors)
   SECTOR_END
};
#endif

#endif                         // end FLASH_APROM


#ifdef FLASH_LDROM

struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "Nano100 4kB Flash LD",      // Device Name 
   ONCHIP,                     // Device Type
   0x00100000,                 // Device Start Address
   0x00001000,                 // Device Size in Bytes (4kB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000200, 0x000000,         // Sector Size  512B (8 Sectors)
   SECTOR_END
};

#endif                         // end FLASH_LDROM


#ifdef FLASH_DATA

struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "Nano100 4kB Flash Data",    // Device Name 
   ONCHIP,                     // Device Type
   0x00100000,                 // Device Start Address
   0x00001000,                 // Device Size in Bytes (4kB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000200, 0x000000,         // Sector Size  512B (8 Sectors)
   SECTOR_END
};

#endif                         // end FLASH_DATA


#ifdef FLASH_CFG

struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "Nano100 Flash User Config", // Device Name 
   ONCHIP,                     // Device Type
   0x00300000,                 // Device Start Address
   0x00000008,                 // Device Size in Bytes (8)
   8,                          // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000008, 0x000000,         // Sector Size  8B
   SECTOR_END
};

#endif                         // end FLASH_CFG
