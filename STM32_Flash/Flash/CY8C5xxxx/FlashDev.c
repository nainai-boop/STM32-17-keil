/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2013 Keil Software. All rights reserved.        */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for Cypress CY8C5xxxx Flash        */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures


#ifdef CY8C5XXXX_FLASH
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "CY8C5xxx Flash",           // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00040000,                 // Device Size (max 256kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0x00,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   500,                        // Erase Sector Timeout 500 mSec

// Specify Size and Address of Sectors
   0x004000, 0x000000,         // Sector Size 16kB
   SECTOR_END
};
#endif

#ifdef CY8C5XXXX_CFG
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "CY8C5xxx Configuration",   // Device Name 
   ONCHIP,                     // Device Type
   0x80000000,                 // Device Start Address
   0x00008000,                 // Device Size (max 32kB)
   32,                         // Programming Page Size
   0,                          // Reserved, must be 0
   0x00,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   500,                        // Erase Sector Timeout 500 mSec

// Specify Size and Address of Sectors
   0x000800, 0x000000,         // Sector Size 2kB
   SECTOR_END
};
#endif

#ifdef CY8C5XXXX_CFG_NVL
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "CY8C5xxx CFG NVL",         // Device Name 
   ONCHIP,                     // Device Type
   0x90000000,                 // Device Start Address
   0x00000004,                 // Device Size (4B)
   4,                          // Programming Page Size
   0,                          // Reserved, must be 0
   0x00,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   1000,                       // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x000004, 0x000000,         // Sector Size 4
   SECTOR_END
};
#endif

#ifdef CY8C5XXXX_WO_NVL
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "CY8C5xxx WO NVL",          // Device Name 
   ONCHIP,                     // Device Type
   0x90100000,                 // Device Start Address
   0x00000004,                 // Device Size (4B)
   4,                          // Programming Page Size
   0,                          // Reserved, must be 0
   0x00,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   1000,                       // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x000004, 0x000000,         // Sector Size 4
   SECTOR_END
};
#endif

#ifdef CY8C5XXXX_EEPROM
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "CY8C5xxx EEPROM",          // Device Name 
   ONCHIP,                     // Device Type
   0x90200000,                 // Device Start Address
   0x00000800,                 // Device Size (max 2kB)
   16,                         // Programming Page Size
   0,                          // Reserved, must be 0
   0x00,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   300,                        // Erase Sector Timeout 300 mSec

// Specify Size and Address of Sectors
   0x000400, 0x000000,         // Sector Size 1kB
   SECTOR_END
};
#endif

#ifdef CY8C5XXXX_PROTECT
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "CY8C5xxx Flash Protection",// Device Name 
   ONCHIP,                     // Device Type
   0x90400000,                 // Device Start Address
   0x00000100,                 // Device Size (max 256B)
   64,                         // Programming Page Size
   0,                          // Reserved, must be 0
   0x00,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   1000,                       // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x000040, 0x000000,         // Sector Size 64B
   SECTOR_END
};
#endif
