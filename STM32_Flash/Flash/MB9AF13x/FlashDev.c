/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2012 Keil - An ARM Company.                          */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for                                */
/*               Fujitsu MB9A130L/ 130LA/ 130N/                        */
/*                           A30N                      Series          */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef FLASH_MEM

#ifdef MB9AF13x_64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9AF13x 64kB Flash",      // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00010000,                 // Device Size in Bytes (64kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec                           SA2  (60KB)
//                                                                                         SA1  ( 4KB)    
// Specify Size and Address of Sectors                                                  <-------------->
   0x001000, 0x000000,         // Sector Size  4KB (1 Sector)                    bit 31                0
   0x00F000, 0x001000,         // Sector Size 60KB (1 Sector)
   SECTOR_END
};
#endif

#ifdef MB9AF13x_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9AF13x 128kB Flash",     // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00020000,                 // Device Size in Bytes (64kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec                            SA3  (64KB)
   3000,                       // Erase Sector Timeout 3000 mSec                           SA2  (60KB)
//                                                                                         SA1  ( 4KB)    
// Specify Size and Address of Sectors                                                  <-------------->
   0x001000, 0x000000,         // Sector Size  4KB (1 Sector)                    bit 31                0
   0x00F000, 0x001000,         // Sector Size 60KB (1 Sector)
   0x010000, 0x010000,         // Sector Size 64KB (1 Sector)
   SECTOR_END
};
#endif


#endif                         // end FLASH_MEM
