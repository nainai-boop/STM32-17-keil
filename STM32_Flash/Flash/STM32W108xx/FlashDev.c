/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright KEIL ELEKTRONIK GmbH 2012                                */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for                                */
/*               ST Microelectronics STM32W108 Flash                   */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures


#ifdef STM32W108_64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32W108 64kB Flash",     // Device Name (64kB)
   ONCHIP,                     // Device Type
   0x08000000,                 // Device Start Address
   0x00010000,                 // Device Size in Bytes (128kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   500,                        // Erase Sector Timeout 500 mSec

// Specify Size and Address of Sectors
   0x0400, 0x000000,           // Sector Size 1kB (64 Sectors)
   SECTOR_END
};
#endif

#ifdef STM32W108_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32W108 128kB Flash",    // Device Name (128kB/64kB)
   ONCHIP,                     // Device Type
   0x08000000,                 // Device Start Address
   0x00020000,                 // Device Size in Bytes (128kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   500,                        // Erase Sector Timeout 500 mSec

// Specify Size and Address of Sectors
   0x0400, 0x000000,           // Sector Size 1kB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef STM32W108_192
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32W108 192kB Flash",    // Device Name (192kB)
   ONCHIP,                     // Device Type
   0x08000000,                 // Device Start Address
   0x00030000,                 // Device Size in Bytes (256kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   500,                        // Erase Sector Timeout 500 mSec

// Specify Size and Address of Sectors
   0x0800, 0x000000,           // Sector Size 2kB (96 Sectors)
   SECTOR_END
};
#endif

#ifdef STM32W108_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32W108 256kB Flash",    // Device Name (256kB/192kB)
   ONCHIP,                     // Device Type
   0x08000000,                 // Device Start Address
   0x00040000,                 // Device Size in Bytes (256kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   500,                        // Erase Sector Timeout 500 mSec

// Specify Size and Address of Sectors
   0x0800, 0x000000,           // Sector Size 2kB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_OPT
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32F108 Flash Options",  // Device Name
   ONCHIP,                     // Device Type
   0x08040800,                 // Device Start Address
   0x00000010,                 // Device Size in Bytes (16)
   16,                         // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   3000,                       // Program Page Timeout 3 Sec
   3000,                       // Erase Sector Timeout 3 Sec

// Specify Size and Address of Sectors
   0x0010, 0x000000,           // Sector Size 16B
   SECTOR_END
};
#endif
