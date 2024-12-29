/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2006-2013 Keil - An ARM Company.                     */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for                                */
/*               SmartFusion2 M2Sxxxx Devices                          */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures


#ifdef M2Sxxx_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "M2Sxxx 128kB Flash",       // Device Name (128kB)
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00020000,                 // Device Size in Bytes (128kB)
   128,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec 
   500,                        // Erase Sector Timeout 500 mSec 

// Specify Size and Address of Sectors
   0x1000, 0x000000,           // Sector Size 4kB (32 Sectors)
   SECTOR_END        
};
#endif

#ifdef M2Sxxx_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "M2Sxxx 256kB Flash",       // Device Name (128kB)
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00040000,                 // Device Size in Bytes (256kB)
   128,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec 
   500,                        // Erase Sector Timeout 500 mSec 

// Specify Size and Address of Sectors
   0x1000, 0x000000,           // Sector Size 4kB (64 Sectors)
   SECTOR_END        
};
#endif

#ifdef M2Sxxx_512
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "M2Sxxx 512kB Flash",       // Device Name (512kB)
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00080000,                 // Device Size in Bytes (256kB)
   128,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec 
   500,                        // Erase Sector Timeout 500 mSec 

// Specify Size and Address of Sectors
   0x1000, 0x000000,           // Sector Size 4kB (64 Sectors)
   0x1000, 0x040000,           // Sector Size 4kB (64 Sectors)
   SECTOR_END        
};
#endif
