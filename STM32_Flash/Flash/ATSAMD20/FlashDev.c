/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2013 Keil - An ARM Company.                     */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for                                */
/*               Atmel ATSAMD20 Flashes                                */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"         // FlashOS Structures


/* ---- SAMD20 --------------------------------------------------------*/
#ifdef FLASH_MEM

#ifdef ATSAMD20_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAMD20 256kB Flash",      // Device Name
   ONCHIP,                      // Device Type
   0x00000000,                  // Device Start Address
   0x00040000,                  // Device Size in Bytes (256kB)
   64,                          // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x4000, 0x000000,            // Sector Size 16kB (16 regions a 256 pages)
   SECTOR_END
};
#endif

#ifdef ATSAMD20_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAMD20 128kB Flash",      // Device Name
   ONCHIP,                      // Device Type
   0x00000000,                  // Device Start Address
   0x00020000,                  // Device Size in Bytes (128kB)
   64,                          // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x2000, 0x000000,            // Sector Size 8kB (16 regions a 128 pages)
   SECTOR_END
};
#endif

#ifdef ATSAMD20_64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAMD20 64kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00000000,                  // Device Start Address
   0x00010000,                  // Device Size in Bytes (64kB)
   64,                          // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x1000, 0x000000,            // Sector Size 4kB (16 regions a 64 pages)
   SECTOR_END
};
#endif

#ifdef ATSAMD20_32
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAMD20 32kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00000000,                  // Device Start Address
   0x00008000,                  // Device Size in Bytes (64kB)
   64,                          // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x0800, 0x000000,            // Sector Size 2kB (16 regions a 32 pages)
   SECTOR_END
};
#endif

#ifdef ATSAMD20_16
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAMD20 16kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00000000,                  // Device Start Address
   0x00004000,                  // Device Size in Bytes (64kB)
   64,                          // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x0400, 0x000000,            // Sector Size 1kB (16 regions a 16 pages)
   SECTOR_END
};
#endif

#endif /* FLASH_MEM */
