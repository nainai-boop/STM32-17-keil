/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2006-2012 Keil - An ARM Company.                     */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for                                */
/*               for ST Microelectronics STM32L15x Flash               */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef FLASH_MEMORY

#ifdef STM32L1xx_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32L1xx Med-density Flash", // Device Name (128kB/64kB/32kB)
   ONCHIP,                     // Device Type
   0x08000000,                 // Device Start Address
   0x00020000,                 // Device Size in Bytes (128kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0x00,                       // Initial Content of Erased Memory
   500,                        // Program Page Timeout 500 mSec
   500,                        // Erase Sector Timeout 500 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,           // Sector Size 256B (512 Sectors)
   SECTOR_END
};
#endif // STM32L1xx_128

#ifdef STM32L1xx_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32L1xx Med+-density Flash", // Device Name (256kB)
   ONCHIP,                     // Device Type
   0x08000000,                 // Device Start Address
   0x00040000,                 // Device Size in Bytes (256kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0x00,                       // Initial Content of Erased Memory
   500,                        // Program Page Timeout 500 mSec
   500,                        // Erase Sector Timeout 500 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,           // Sector Size 256B (1000 Sectors)
   SECTOR_END
};
#endif // STM32L1xx_256

#ifdef STM32L1xx_384
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32L1xx High-density Flash", // Device Name (384kB)
   ONCHIP,                     // Device Type
   0x08000000,                 // Device Start Address
   0x00060000,                 // Device Size in Bytes (384kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0x00,                       // Initial Content of Erased Memory
   500,                        // Program Page Timeout 500 mSec
   500,                        // Erase Sector Timeout 500 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,           // Sector Size 256B (1512 Sectors)
   SECTOR_END
};
#endif // STM32L1xx_384

#endif // FLASH_MEMORY


#ifdef FLASH_EEPROM

#ifdef STM32L1xx_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32L1xx Mid-density Data EEPROM",    // Device Name (4kB)
   ONCHIP,                     // Device Type
   0x08080000,                 // Device Start Address
   0x00001000,                 // Device Size in Bytes (4kB)
   256,                        // Programming Page Size (256B)
   0,                          // Reserved, must be 0
   0x00,                       // Initial Content of Erased Memory
   500,                        // Program Page Timeout 500 mSec
   500,                        // Erase Sector Timeout 500 mSec

// Specify Size and Address of Sectors
   0x100, 0x000000,            // Sector Size 256B (16 Sectors)
   SECTOR_END
};
#endif // STM32L1xx_128


#ifdef STM32L1xx_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32L1xx Mid+-density Data EEPROM",    // Device Name (4kB)
   ONCHIP,                     // Device Type
   0x08080000,                 // Device Start Address
   0x00002000,                 // Device Size in Bytes (8kB)
   256,                        // Programming Page Size (256B)
   0,                          // Reserved, must be 0
   0x00,                       // Initial Content of Erased Memory
   500,                        // Program Page Timeout 500 mSec
   500,                        // Erase Sector Timeout 500 mSec

// Specify Size and Address of Sectors
   0x100, 0x000000,            // Sector Size 256B (16 Sectors)
   SECTOR_END
};
#endif // STM32L1xx_256


#ifdef STM32L1xx_384
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32L1xx High-density Data EEPROM",    // Device Name (4kB)
   ONCHIP,                     // Device Type
   0x08080000,                 // Device Start Address
   0x00003000,                 // Device Size in Bytes (12kB)
   256,                        // Programming Page Size (256B)
   0,                          // Reserved, must be 0
   0x00,                       // Initial Content of Erased Memory
   500,                        // Program Page Timeout 500 mSec
   500,                        // Erase Sector Timeout 500 mSec

// Specify Size and Address of Sectors
   0x100, 0x000000,            // Sector Size 256B (16 Sectors)
   SECTOR_END
};
#endif // STM32L1xx_384

#endif // FLASH_EEPROM

#ifdef FLASH_OPTION

#ifdef STM32L1xx_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32L1xx Mid-density Options",  // Device Name
   ONCHIP,                     // Device Type
   0x1FF80000,                 // Device Start Address
   0x00000010,                 // Device Size in Bytes (16)
   16,                         // Programming Page Size
   0,                          // Reserved, must be 0
   0x00,                       // Initial Content of Erased Memory
   3000,                       // Program Page Timeout 3 Sec
   3000,                       // Erase Sector Timeout 3 Sec

// Specify Size and Address of Sectors
   0x0010, 0x000000,           // Sector Size 16B
   SECTOR_END
};
#endif // STM32L15x_128

#ifdef STM32L1xx_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32L1xx Mid+-density Options",  // Device Name
   ONCHIP,                     // Device Type
   0x1FF80000,                 // Device Start Address
   0x00000010,                 // Device Size in Bytes (24)
   24,                         // Programming Page Size
   0,                          // Reserved, must be 0
   0x00,                       // Initial Content of Erased Memory
   3000,                       // Program Page Timeout 3 Sec
   3000,                       // Erase Sector Timeout 3 Sec

// Specify Size and Address of Sectors
   0x0018, 0x000000,           // Sector Size 24B
   SECTOR_END
};
#endif // STM32L15x_256

#ifdef STM32L1xx_384
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32L1xx High-density Options",  // Device Name
   ONCHIP,                     // Device Type
   0x1FF80000,                 // Device Start Address
   0x00000020,                 // Device Size in Bytes (32)
   32,                         // Programming Page Size
   0,                          // Reserved, must be 0
   0x00,                       // Initial Content of Erased Memory
   3000,                       // Program Page Timeout 3 Sec
   3000,                       // Erase Sector Timeout 3 Sec

// Specify Size and Address of Sectors
   0x0020, 0x000000,           // Sector Size 32B
   SECTOR_END
};
#endif // STM32L15x_384

#endif // FLASH_OPTION 
