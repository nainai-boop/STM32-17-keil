/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright (c) 2013 Keil - An ARM Company. All rights reserved.     */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.c:  Device Description for ST STM32F2xx Flash             */
/*                                                                     */
/***********************************************************************/

#include "FlashOS.H"        // FlashOS Structures

#ifdef FLASH_MEM

#ifdef STM32F2xx_1024
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32F2xx Flash",          // Device Name (1024kB/768kB/512kB/256kB/128kB)
   ONCHIP,                     // Device Type
   0x08000000,                 // Device Start Address
   0x00100000,                 // Device Size in Bytes (1024kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   6000,                       // Erase Sector Timeout 6000 mSec

// Specify Size and Address of Sectors
   0x04000, 0x000000,          // Sector Size  16kB (4 Sectors)
   0x10000, 0x010000,          // Sector Size  64kB (1 Sectors)
   0x20000, 0x020000,          // Sector Size 128kB (7/5/3 Sectors)
   SECTOR_END
};
#endif // STM32F2xx_1024

#endif // FLASH_MEM


#ifdef FLASH_OPT
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32F2xx Flash Options",  // Device Name
   ONCHIP,                     // Device Type
   0x1FFFC000,                 // Device Start Address
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

#ifdef FLASH_OTP
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32F2xx Flash OTP",      // Device Name
   ONCHIP,                     // Device Type
   0x1FFF7800,                 // Device Start Address
   0x00000210,                 // Device Size in Bytes (528)
   528,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   3000,                       // Program Page Timeout 3 Sec
   3000,                       // Erase Sector Timeout 3 Sec

// Specify Size and Address of Sectors
   0x0210, 0x000000,           // Sector Size 528B
   SECTOR_END
};
#endif
