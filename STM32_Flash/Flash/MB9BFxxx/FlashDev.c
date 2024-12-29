/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2006-2012 Keil - An ARM Company.                     */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for                                */
/*               Fujitsu MB9BFxxx Flash                                */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef FLASH_MEM

#ifdef MB9BF500_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9BF500 256kB Flash",     // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address                                     SA11 (64KB)
   0x00040000,                 // Device Size in Bytes (256kB)                             SA10 (64KB)
   1024,                       // Programming Page Size                                    SA9  (64KB)
   0,                          // Reserved, must be 0                                      SA8  (48KB)
   0xFF,                       // Initial Content of Erased Memory                         SA7  ( 4KB)
   100,                        // Program Page Timeout 100 mSec                            SA6  ( 4KB)
   3000,                       // Erase Sector Timeout 3000 mSec                           SA5  ( 4KB)
//                                                                                         SA4  ( 4KB)    
// Specify Size and Address of Sectors                                                  <-------------->
   0x001000, 0x000000,         // Sector Size  4KB (4 Sectors)                    bit 31                0
   0x00C000, 0x004000,         // Sector Size 48KB (1 Sector )                           +3  +2  +1  +0
   0x010000, 0x010000,         // Sector Size 64KB (3 Sectors)
   SECTOR_END
};
#endif

#ifdef MB9BFx01_64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9xFxx1 64kB Flash",      // Device Name 
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

#ifdef MB9BFx02_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9xFxx2 128kB Flash",     // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address                              
   0x00020000,                 // Device Size in Bytes (128kB)                       
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

#ifdef MB9BFx04_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9xFxx4 256kB Flash",     // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00040000,                 // Device Size in Bytes (256kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory                    SA11 (64KB)  | SA10 (64KB)
   100,                        // Program Page Timeout 100 mSec                       SA9  (48KB)  | SA8  (48KB)
   3000,                       // Erase Sector Timeout 3000 mSec                      SA7  ( 8KB)  | SA6  ( 8KB)
//                                                                                    SA5  ( 8KB)  | SA4  ( 8KB)   
// Specify Size and Address of Sectors                                             <---------------|-------------->
   0x004000, 0x000000,         // Sector Size  16KB (2 Sectors)              bit 63              32 31             0
   0x018000, 0x008000,         // Sector Size  96KB (1 Sectors)                     +7  +6  +5  +4  +3  +2  +1  +0  
   0x020000, 0x020000,         // Sector Size 128KB (1 Sectors)
   SECTOR_END
};
#endif

#ifdef MB9BFx05_384
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9xFxx5 384kB Flash",     // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00060000,                 // Device Size in Bytes (384kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0                                 SA13 (64KB)  | SA12 (64KB)
   0xFF,                       // Initial Content of Erased Memory                    SA11 (64KB)  | SA10 (64KB)
   100,                        // Program Page Timeout 100 mSec                       SA9  (48KB)  | SA8  (48KB)
   3000,                       // Erase Sector Timeout 3000 mSec                      SA7  ( 8KB)  | SA6  ( 8KB)
//                                                                                    SA5  ( 8KB)  | SA4  ( 8KB)   
// Specify Size and Address of Sectors                                             <---------------|-------------->
   0x004000, 0x000000,         // Sector Size  16KB (2 Sectors)              bit 63              32 31             0
   0x018000, 0x008000,         // Sector Size  96KB (1 Sectors)                     +7  +6  +5  +4  +3  +2  +1  +0  
   0x020000, 0x020000,         // Sector Size 128KB (2 Sectors)
   SECTOR_END
};
#endif

#ifdef MB9BFx06_512
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9xFxx6 512kB Flash",     // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00080000,                 // Device Size in Bytes (512kB)
   1024,                       // Programming Page Size                               SA15 (64KB)  | SA14 (64KB)
   0,                          // Reserved, must be 0                                 SA13 (64KB)  | SA12 (64KB)
   0xFF,                       // Initial Content of Erased Memory                    SA11 (64KB)  | SA10 (64KB)
   100,                        // Program Page Timeout 100 mSec                       SA9  (48KB)  | SA8  (48KB)
   3000,                       // Erase Sector Timeout 3000 mSec                      SA7  ( 8KB)  | SA6  ( 8KB)
//                                                                                    SA5  ( 8KB)  | SA4  ( 8KB)   
// Specify Size and Address of Sectors                                             <---------------|-------------->
   0x004000, 0x000000,         // Sector Size  16KB (2 Sectors)              bit 63              32 31             0
   0x018000, 0x008000,         // Sector Size  96KB (1 Sectors)                     +7  +6  +5  +4  +3  +2  +1  +0  
   0x020000, 0x020000,         // Sector Size 128KB (3 Sectors)
   SECTOR_END
};
#endif

#ifdef MB9BFx07_768
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9xFxx7 768kB Flash",     // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address                                SA19 (64KB)  | SA18 (64KB)
   0x000C0000,                 // Device Size in Bytes (768kB)                        SA17 (64KB)  | SA16 (64KB)
   1024,                       // Programming Page Size                               SA15 (64KB)  | SA14 (64KB)
   0,                          // Reserved, must be 0                                 SA13 (64KB)  | SA12 (64KB)
   0xFF,                       // Initial Content of Erased Memory                    SA11 (64KB)  | SA10 (64KB)
   100,                        // Program Page Timeout 100 mSec                       SA9  (48KB)  | SA8  (48KB)
   3000,                       // Erase Sector Timeout 3000 mSec                      SA7  ( 8KB)  | SA6  ( 8KB)
//                                                                                    SA5  ( 8KB)  | SA4  ( 8KB)   
// Specify Size and Address of Sectors                                             <---------------|-------------->
   0x004000, 0x000000,         // Sector Size  16KB (2 Sectors)              bit 63              32 31             0
   0x018000, 0x008000,         // Sector Size  96KB (1 Sectors)                     +7  +6  +5  +4  +3  +2  +1  +0  
   0x020000, 0x020000,         // Sector Size 128KB (5 Sectors)
   SECTOR_END
};
#endif

#ifdef MB9BFx08_1024
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9xFxx8 1024kB Flash",    // Device Name                                         SA23 (64KB)  | SA22 (64KB) 
   ONCHIP,                     // Device Type                                         SA21 (64KB)  | SA20 (64KB)
   0x00000000,                 // Device Start Address                                SA19 (64KB)  | SA18 (64KB)
   0x00100000,                 // Device Size in Bytes (1024kB)                       SA17 (64KB)  | SA16 (64KB)
   1024,                       // Programming Page Size                               SA15 (64KB)  | SA14 (64KB)
   0,                          // Reserved, must be 0                                 SA13 (64KB)  | SA12 (64KB)
   0xFF,                       // Initial Content of Erased Memory                    SA11 (64KB)  | SA10 (64KB)
   100,                        // Program Page Timeout 100 mSec                       SA9  (48KB)  | SA8  (48KB)
   3000,                       // Erase Sector Timeout 3000 mSec                      SA7  ( 8KB)  | SA6  ( 8KB)
//                                                                                    SA5  ( 8KB)  | SA4  ( 8KB)   
// Specify Size and Address of Sectors                                             <---------------|-------------->
   0x004000, 0x000000,         // Sector Size  16KB (2 Sectors)              bit 63              32 31             0
   0x018000, 0x008000,         // Sector Size  96KB (1 Sectors)                     +7  +6  +5  +4  +3  +2  +1  +0  
   0x020000, 0x020000,         // Sector Size 128KB (7 Sectors)
   SECTOR_END
};
#endif

#ifdef MB9xFxxx_32WF
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MB9xFxxx 32kB WorkFlash",  // Device Name
   ONCHIP,                     // Device Type
   0x200C0000,                 // Device Start Address
   0x00008000,                 // Device Size in Bytes (32kB)
   1024,                       // Programming Page Size                               SA3  ( 8KB)
   0,                          // Reserved, must be 0                                 SA2  ( 8KB)
   0xFF,                       // Initial Content of Erased Memory                    SA1  ( 8KB)
   100,                        // Program Page Timeout 100 mSec                       SA0  ( 8KB)
   3000,                       // Erase Sector Timeout 3000 mSec                    <----------->
//                                                                           bit 31             0
// Specify Size and Address of Sectors                                              +3  +2  +1  +0
   0x002000, 0x000000,         // Sector Size   8KB (4 Sectors)
   SECTOR_END
};
#endif

#endif                         // end FLASH_MEM
