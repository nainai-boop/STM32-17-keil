/******************************************************************************/
/*  This file is part of the ARM Toolchain package                            */
/*  Copyright KEIL ELEKTRONIK GmbH 2003 - 2009                                */
/******************************************************************************/
/*                                                                            */
/*  FlashDev.C:  Device Description for Actel A2FM3Fxxx                       */
/*                                                                            */
/******************************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures


#ifdef A2FxxxM3_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "A2FxxxM3 128kB Flash",     // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00020000,                 // Device Size in Bytes (128kB)
   128,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   1000,                       // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x40000, 0x000000,          // Sector Size 256kB (1 Block)
   SECTOR_END
};
#endif

#ifdef A2FxxxM3_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "A2FxxxM3 256kB Flash",     // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00040000,                 // Device Size in Bytes (256kB)
   128,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   1000,                       // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x40000, 0x000000,          // Sector Size 256kB (1 Block)
   SECTOR_END
};
#endif

#ifdef A2FxxxM3_512
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "A2FxxxM3 512kB Flash",     // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00080000,                 // Device Size in Bytes (512kB)
   128,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   1000,                       // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x40000, 0x000000,          // Sector Size 256kB (1 Block)
   SECTOR_END
};
#endif

