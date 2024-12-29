/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright (c) 2012 Keil - An ARM Company. All rights reserved.     */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.c:  Device Description for                                */
/*               SiLabs SiM3x Flash                                    */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef FLASH_MEM

#ifdef SiM3x_32
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "SiM3x 32kB Flash",         // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00008000,                 // Device Size ( 32kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec (1s)
   2000,                       // Erase Sector Timeout 2000 mSec (2s)

// Specify Size and Address of Sectors
   0x00400, 0x000000,          // Sector Size  1kB ( 32 Sectors)
   SECTOR_END
};
#endif // SiM3x_32

#ifdef SiM3x_64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "SiM3x 64kB Flash",         // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00010000,                 // Device Size ( 64kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec (1s)
   2000,                       // Erase Sector Timeout 2000 mSec (2s)

// Specify Size and Address of Sectors
   0x00400, 0x000000,          // Sector Size  1kB ( 64 Sectors)
   SECTOR_END
};
#endif // SiM3x_64

#ifdef SiM3x_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "SiM3x 128kB Flash",        // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00020000,                 // Device Size (128kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec (1s)
   2000,                       // Erase Sector Timeout 2000 mSec (2s)

// Specify Size and Address of Sectors
   0x00400, 0x000000,          // Sector Size  1kB (128 Sectors)
   SECTOR_END
};
#endif // SiM3x_128

#ifdef SiM3x_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "SiM3x 256kB Flash",        // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
//   0x00040000,                 // Device Size (256kB)
   0x0003FFFC,                 // Device Size (256kB) - Lock Byte
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec (1s)
   2000,                       // Erase Sector Timeout 2000 mSec (2s)

// Specify Size and Address of Sectors
   0x00400, 0x000000,          // Sector Size  1kB (256 Sectors)
   SECTOR_END
};
#endif // SiM3x_256

#endif // FLASH_MEM
