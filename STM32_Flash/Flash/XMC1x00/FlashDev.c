/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2006-2013 Keil - An ARM Company.                     */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for                                */
/*               Infineon XMC1x00 Flash                                */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef XMC1100_64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "XMC1100 64kB Flash",       // Device Name
   ONCHIP,                     // Device Type
   0x10001000,                 // Device Start Address
   0x00010000,                 // Device Size in Bytes (64kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x01000, 0x000000,           // Sector Size  4kB (16 Sectors)
   SECTOR_END
};
#endif

#ifdef XMC1200_200
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "XMC1200 200kB Flash",      // Device Name
   ONCHIP,                     // Device Type
   0x10001000,                 // Device Start Address
   0x00032000,                 // Device Size in Bytes (200kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x01000, 0x000000,           // Sector Size  4kB (50 Sectors)
   SECTOR_END
};
#endif


#ifdef XMC1300_200
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "XMC1300 200kB Flash",      // Device Name
   ONCHIP,                     // Device Type
   0x10001000,                 // Device Start Address
   0x00032000,                 // Device Size in Bytes (200kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x01000, 0x000000,           // Sector Size  4kB (50 Sectors)
   SECTOR_END
};
#endif
