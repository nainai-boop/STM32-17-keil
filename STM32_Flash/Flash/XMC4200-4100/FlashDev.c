/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright (c) 2012 Keil - An ARM Company. All rights reserved.     */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.c:  Device Description for                                */
/*               Infineon XMC4200-4100 Flash                           */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef FLASH_MEM

#ifdef XMC4200_4100_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,                // Driver Version, do not modify!
   "XMC4200/4100 256kB Flash",         // Device name
   ONCHIP,                        // Device Type
   0x0C000000,                    // Device Start Address
   0x00040000,                    // Device Size in Bytes (256kB)
   256,                           // Programming Page Size (Bytes)
   0,                             // Reserved, must be 0
   0x00,                          // Initial Content of Erased Memory
   100,                           // Program Page Timeout 100 mSec
   20000,                         // Erase Sector Timeout 20000 mSec

// Specify Size and Address of Sectors
   0x04000, 0x000000,             // Sector Size  16kB (8 Sectors)
   0x20000, 0x020000,             // Sector Size 128kB (1 Sector )
   SECTOR_END                 
};
#endif

#ifdef XMC4200_4100c_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,                // Driver Version, do not modify!
   "XMC4200/4100 256kB cached Flash",  // Device name
   ONCHIP,                        // Device Type
   0x08000000,                    // Device Start Address
   0x00040000,                    // Device Size in Bytes (256kB)
   256,                           // Programming Page Size (Bytes)
   0,                             // Reserved, must be 0
   0x00,                          // Initial Content of Erased Memory
   100,                           // Program Page Timeout 100 mSec
   20000,                         // Erase Sector Timeout 20000 mSec

// Specify Size and Address of Sectors
   0x04000, 0x000000,             // Sector Size  16kB (8 Sectors)
   0x20000, 0x020000,             // Sector Size 128kB (1 Sector )
   SECTOR_END                 
};
#endif

#ifdef XMC4200_4100_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,                // Driver Version, do not modify!
   "XMC4200/4100 128kB Flash",         // Device name
   ONCHIP,                        // Device Type
   0x0C000000,                    // Device Start Address
   0x00020000,                    // Device Size in Bytes (128kB)
   256,                           // Programming Page Size (Bytes)
   0,                             // Reserved, must be 0
   0x00,                          // Initial Content of Erased Memory
   100,                           // Program Page Timeout 100 mSec
   20000,                         // Erase Sector Timeout 20000 mSec

// Specify Size and Address of Sectors
   0x04000, 0x000000,             // Sector Size  16kB (8 Sectors)
   SECTOR_END                 
};
#endif

#ifdef XMC4200_4100c_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,                // Driver Version, do not modify!
   "XMC4200/4100 128kB cached Flash",  // Device name
   ONCHIP,                        // Device Type
   0x08000000,                    // Device Start Address
   0x00020000,                    // Device Size in Bytes (128kB)
   256,                           // Programming Page Size (Bytes)
   0,                             // Reserved, must be 0
   0x00,                          // Initial Content of Erased Memory
   100,                           // Program Page Timeout 100 mSec
   20000,                         // Erase Sector Timeout 20000 mSec

// Specify Size and Address of Sectors
   0x04000, 0x000000,             // Sector Size  16kB (8 Sectors)
   SECTOR_END                 
};
#endif

#ifdef XMC4200_4100_64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,                // Driver Version, do not modify!
   "XMC4200/4100 64kB Flash",         // Device name
   ONCHIP,                        // Device Type
   0x0C000000,                    // Device Start Address
   0x00010000,                    // Device Size in Bytes (64kB)
   256,                           // Programming Page Size (Bytes)
   0,                             // Reserved, must be 0
   0x00,                          // Initial Content of Erased Memory
   100,                           // Program Page Timeout 100 mSec
   20000,                         // Erase Sector Timeout 20000 mSec

// Specify Size and Address of Sectors
   0x04000, 0x000000,             // Sector Size  16kB (4 Sectors)
   SECTOR_END                 
};
#endif

#ifdef XMC4200_4100c_64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,                // Driver Version, do not modify!
   "XMC4200/4100 64kB cached Flash",  // Device name
   ONCHIP,                        // Device Type
   0x08000000,                    // Device Start Address
   0x00010000,                    // Device Size in Bytes (64kB)
   256,                           // Programming Page Size (Bytes)
   0,                             // Reserved, must be 0
   0x00,                          // Initial Content of Erased Memory
   100,                           // Program Page Timeout 100 mSec
   20000,                         // Erase Sector Timeout 20000 mSec

// Specify Size and Address of Sectors
   0x04000, 0x000000,             // Sector Size  16kB (4 Sectors)
   SECTOR_END                 
};
#endif

#endif
