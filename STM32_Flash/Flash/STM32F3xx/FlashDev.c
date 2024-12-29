/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright (c) 2012 Keil - An ARM Company. All rights reserved.     */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.c:  Device Description for ST STM32F3xx Flash             */
/*                                                                     */
/***********************************************************************/

#include "FlashOS.H"        // FlashOS Structures

#ifdef FLASH_MEM

#ifdef STM32F3xx_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32F3xx Flash",          // Device Name (256kB/128kB)
   ONCHIP,                     // Device Type
   0x08000000,                 // Device Start Address
   0x00040000,                 // Device Size in Bytes (256kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   6000,                       // Erase Sector Timeout 6000 mSec

// Specify Size and Address of Sectors
   0x00800, 0x000000,          // Sector Size   2kB (128 Pages)
   SECTOR_END
};
#endif // STM32F3xx_256

#endif // FLASH_MEM


#ifdef FLASH_OPT
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32F3xx Flash Options",  // Device Name
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
