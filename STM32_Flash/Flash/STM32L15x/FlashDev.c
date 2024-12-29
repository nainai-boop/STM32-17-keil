/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2006-2010 Keil - An ARM Company.                     */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for                                */
/*               for ST Microelectronics STM32L15x Flash               */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef FLASH_MEMORY

#ifdef STM32L15x_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32L15x Low Power Flash", // Device Name (128kB/64kB/32kB)
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
#endif // STM32L15x_128

#endif // FLASH_MEMORY


#ifdef FLASH_EEPROM
#ifdef STM32L15x_EEPROM
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32L15x Data EEPROM",    // Device Name (4kB)
   ONCHIP,                     // Device Type
   0x08080000,                 // Device Start Address
   0x00001000,                 // Device Size in Bytes (4B)
   256,                        // Programming Page Size (256B)
   0,                          // Reserved, must be 0
   0x00,                       // Initial Content of Erased Memory
   500,                        // Program Page Timeout 500 mSec
   500,                        // Erase Sector Timeout 500 mSec

// Specify Size and Address of Sectors
   0x100, 0x000000,            // Sector Size 256B (16 Sectors)
   SECTOR_END
};
#endif // STM32L15x_EEPROM
#endif // FLASH_EEPROM

#ifdef FLASH_OPTION
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "STM32L15x Flash Options",  // Device Name
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
#endif // FLASH_OPTION 
