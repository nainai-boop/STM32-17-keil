/*----------------------------------------------------------------------------
 * Name:    FlashDev.C
 * Purpose: Device Description for flash algorithm using Samsung S3FM02G device
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2011 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef S3FM02G_PFLASH 
struct FlashDevice const FlashDevice  =  {
  FLASH_DRV_VERS,                       // Driver Version, do not modify!
  "S3FM02G 384kB Prog Flash",           // Device Name
  ONCHIP,                               // Device Type
  0x0,                                  // Device Start Address
  0x60000,                              // Device Size in Bytes (384 kB)
  1024,                                 // Programming Page Size
  0,                                    // Reserved, must be 0
  0xFF,                                 // Initial Content of Erased Memory
  1000,                                 // Program Page Timeout max. 30 uSec
  3000,                                 // Erase Sector Timeout max. 28 mSec

  // Specify Size and Address of Sectors
  0x8000, 0x0000,                       // Sector Size  32kB (12 sectors)
  SECTOR_END
};
#endif

#ifdef S3FM02G_DFLASH 
struct FlashDevice const FlashDevice  =  {
  FLASH_DRV_VERS,                       // Driver Version, do not modify!
  "S3FM02G 16kB Data Flash",            // Device Name
  ONCHIP,                               // Device Type
  0x80000000,                           // Device Start Address
  0x4000,                               // Device Size in Bytes (384 kB)
  1024,                                 // Programming Page Size
  0,                                    // Reserved, must be 0
  0xFF,                                 // Initial Content of Erased Memory
  1000,                                 // Program Page Timeout max. 30 uSec
  3000,                                 // Erase Sector Timeout max. 28 mSec
  // Specify Size and Address of Sectors
  0x400, 0x0000,                        // Sector Size  32kB (12 sectors)
  SECTOR_END
};
#endif

#ifdef S3FM02G_SOPT 
struct FlashDevice const FlashDevice  =  {
  FLASH_DRV_VERS,                       // Driver Version, do not modify!
  "S3FM02G Smart Option",               // Device Name
  ONCHIP,                               // Device Type
  0x1FFFF400,                           // Device Start Address
  0x8,                                  // Device Size in Bytes (8 Bytes)
  8,                                    // Programming Page Size
  0,                                    // Reserved, must be 0
  0xFF,                                 // Initial Content of Erased Memory
  1000,                                 // Program Page Timeout max. 30 uSec
  3000,                                 // Erase Sector Timeout max. 28 mSec
  // Specify Size and Address of Sectors
  0x8,  0x0000,                         // Sector Size  8 Bytes (1 Sector)
  SECTOR_END
};
#endif
