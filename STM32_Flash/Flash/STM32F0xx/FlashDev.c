/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2013 Keil - An ARM Company.                     */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for                                */
/*               ST Microelectronics STM32F0xx Flash                   */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef FLASH_MEM

#ifdef STM32F0xx_16
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32F0xx 16kB Flash",     // Device Name (16kB)
   ONCHIP,                     // Device Type
   0x08000000,                 // Device Start Address
   0x00004000,                 // Device Size in Bytes (64kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   6000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x0400, 0x000000,           // Sector Size  1kB (16 Sectors)
   SECTOR_END
};
#endif // STM32F0xx_16

#ifdef STM32F0xx_32
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32F0xx 32kB Flash",     // Device Name (32kB)
   ONCHIP,                     // Device Type
   0x08000000,                 // Device Start Address
   0x00008000,                 // Device Size in Bytes (64kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   6000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x0400, 0x000000,           // Sector Size  1kB (32 Sectors)
   SECTOR_END
};
#endif // STM32F0xx_32

#ifdef STM32F0xx_64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32F0xx 64kB Flash",     // Device Name (64kB)
   ONCHIP,                     // Device Type
   0x08000000,                 // Device Start Address
   0x00010000,                 // Device Size in Bytes (64kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   6000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x0400, 0x000000,           // Sector Size  1kB (64 Sectors)
   SECTOR_END
};
#endif // STM32F0xx_64

#ifdef STM32F0xx_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32F0xx 128kB Flash",    // Device Name (128kB)
   ONCHIP,                     // Device Type
   0x08000000,                 // Device Start Address
   0x00020000,                 // Device Size in Bytes (128kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   6000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x0400, 0x000000,           // Sector Size  1kB (128 Sectors)
   SECTOR_END
};
#endif // STM32F0xx_128

#endif // FLASH_MEM


#ifdef FLASH_OPT
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32F0xx Flash Options",  // Device Name
   ONCHIP,                     // Device Type
   0x1FFFF800,                 // Device Start Address
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
