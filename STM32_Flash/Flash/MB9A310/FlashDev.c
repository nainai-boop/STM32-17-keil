/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2012 Keil - An ARM Company.                          */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for                                */
/*               Fujitsu MB9A310K/110K Series                          */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef FLASH_MEM

#ifdef MB9A310_64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9A310 64kB Flash",       // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00010000,                 // Device Size in Bytes (64kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec                       SA9  (16KB)  | SA8  (16KB)
   3000,                       // Erase Sector Timeout 3000 mSec                      SA7  ( 8KB)  | SA6  ( 8KB)
//                                                                                    SA5  ( 8KB)  | SA4  ( 8KB)
// Specify Size and Address of Sectors                                             <---------------|-------------->
   0x004000, 0x000000,         // Sector Size  16KB (2 Sectors)              bit 63              32 31             0
   0x008000, 0x008000,         // Sector Size  32KB (1 Sectors)                     +7  +6  +5  +4  +3  +2  +1  +0
   SECTOR_END
};
#endif

#ifdef MB9A310_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9A310 128kB Flash",      // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00020000,                 // Device Size in Bytes (64kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec                       SA9  (48KB)  | SA8  (48KB)
   3000,                       // Erase Sector Timeout 3000 mSec                      SA7  ( 8KB)  | SA6  ( 8KB)
//                                                                                    SA5  ( 8KB)  | SA4  ( 8KB)
// Specify Size and Address of Sectors                                             <---------------|-------------->
   0x004000, 0x000000,         // Sector Size  16KB (2 Sectors)              bit 63              32 31             0
   0x018000, 0x008000,         // Sector Size  96KB (1 Sectors)                     +7  +6  +5  +4  +3  +2  +1  +0
   SECTOR_END
};
#endif


#endif                         // end FLASH_MEM
