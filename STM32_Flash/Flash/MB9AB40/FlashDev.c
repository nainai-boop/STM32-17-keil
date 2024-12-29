/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2012 Keil - An ARM Company.                          */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for                                */
/*               Fujitsu MB9AB40N/A40N/340N/140N/150R/                 */
/*                       MB9B520M/320M/120M            Series          */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef FLASH_MEM

#ifdef MB9AB40_64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9AB40 64kB Flash",       // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00010000,                 // Device Size in Bytes (64kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec                            SA8  (48KB)
   3000,                       // Erase Sector Timeout 3000 mSec                           SA3  ( 8KB)
//                                                                                         SA2  ( 8KB)
// Specify Size and Address of Sectors                                                  <-------------->
   0x002000, 0x000000,         // Sector Size  8KB (2 Sector)                     bit 31                0
   0x00C000, 0x004000,         // Sector Size 48KB (1 Sector)
   SECTOR_END
};
#endif

#ifdef MB9AB40_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9AB40 128kB Flash",      // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00020000,                 // Device Size in Bytes (128kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory                         SA9  (64KB)
   100,                        // Program Page Timeout 100 mSec                            SA8  (48KB)
   3000,                       // Erase Sector Timeout 3000 mSec                           SA3  ( 8KB)
//                                                                                         SA2  ( 8KB)
// Specify Size and Address of Sectors                                                  <-------------->
   0x002000, 0x000000,         // Sector Size  8KB (2 Sector)                     bit 31                0
   0x00C000, 0x004000,         // Sector Size 48KB (1 Sector)
   0x010000, 0x010000,         // Sector Size 64KB (1 Sector)
   SECTOR_END
};
#endif

#ifdef MB9AB40_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9AB40 256kB Flash",      // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00040000,                 // Device Size in Bytes (256kB)
   1024,                       // Programming Page Size                                    SA11 (64KB)
   0,                          // Reserved, must be 0                                      SA10 (64KB)
   0xFF,                       // Initial Content of Erased Memory                         SA9  (64KB)
   100,                        // Program Page Timeout 100 mSec                            SA8  (48KB)
   3000,                       // Erase Sector Timeout 3000 mSec                           SA3  ( 8KB)
//                                                                                         SA2  ( 8KB)
// Specify Size and Address of Sectors                                                  <-------------->
   0x002000, 0x000000,         // Sector Size  8KB (2 Sector)                     bit 31                0
   0x00C000, 0x004000,         // Sector Size 48KB (1 Sector)
   0x010000, 0x010000,         // Sector Size 64KB (3 Sector)
   SECTOR_END
};
#endif

#ifdef MB9AB40_384
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9AB40 384kB Flash",      // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address                                     SA13 (64KB)
   0x00060000,                 // Device Size in Bytes (384kB)                             SA12 (64KB)
   1024,                       // Programming Page Size                                    SA11 (64KB)
   0,                          // Reserved, must be 0                                      SA10 (64KB)
   0xFF,                       // Initial Content of Erased Memory                         SA9  (64KB)
   100,                        // Program Page Timeout 100 mSec                            SA8  (48KB)
   3000,                       // Erase Sector Timeout 3000 mSec                           SA3  ( 8KB)
//                                                                                         SA2  ( 8KB)
// Specify Size and Address of Sectors                                                  <-------------->
   0x002000, 0x000000,         // Sector Size  8KB (2 Sector)                     bit 31                0
   0x00C000, 0x004000,         // Sector Size 48KB (1 Sector)
   0x010000, 0x010000,         // Sector Size 64KB (5 Sector)
   SECTOR_END
};
#endif

#ifdef MB9AB40_512
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9AB40 512kB Flash",      // Device Name                                              SA15 (64KB)
   ONCHIP,                     // Device Type                                              SA14 (64KB)
   0x00000000,                 // Device Start Address                                     SA13 (64KB)
   0x00080000,                 // Device Size in Bytes (512kB)                             SA12 (64KB)
   1024,                       // Programming Page Size                                    SA11 (64KB)
   0,                          // Reserved, must be 0                                      SA10 (64KB)
   0xFF,                       // Initial Content of Erased Memory                         SA9  (64KB)
   100,                        // Program Page Timeout 100 mSec                            SA8  (48KB)
   3000,                       // Erase Sector Timeout 3000 mSec                           SA3  ( 8KB)
//                                                                                         SA2  ( 8KB)
// Specify Size and Address of Sectors                                                  <-------------->
   0x002000, 0x000000,         // Sector Size  8KB (2 Sector)                     bit 31                0
   0x00C000, 0x004000,         // Sector Size 48KB (1 Sector)
   0x010000, 0x010000,         // Sector Size 64KB (7 Sector)
   SECTOR_END
};
#endif

#ifdef MB9xFxxx_32DWF
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9xFxxx 32kB Dual WorkFlash",  // Device Name
   ONCHIP,                     // Device Type
   0x00200000,                 // Device Start Address
   0x00008000,                 // Device Size in Bytes (32kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory                         SA7  ( 8KB)
   100,                        // Program Page Timeout 100 mSec                            SA6  ( 8KB)
   3000,                       // Erase Sector Timeout 3000 mSec                           SA5  ( 8KB)
//                                                                                         SA4  ( 8KB)
// Specify Size and Address of Sectors                                                  <-------------->
   0x002000, 0x000000,         // Sector Size  8KB (4 Sector)                     bit 31                0
   SECTOR_END
};
#endif


#endif                         // end FLASH_MEM
