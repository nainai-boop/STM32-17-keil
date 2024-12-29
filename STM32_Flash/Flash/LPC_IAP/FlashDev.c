/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2013 Keil - An ARM Company.                     */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for                                */
/*               NXP LPC11xx/LPC11U6x/13xx/LPC17xx Flash               */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures


#ifdef LPC1XXX

#ifdef FLASH_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC11xx/LPC122x IAP 128kB Flash",  // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00020000,                 // Device Size (128kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (32 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_96
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC11xx/LPC122x IAP 96kB Flash",   // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00018000,                 // Device Size (96kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (24 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_80
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC122x IAP 80kB Flash",   // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00014000,                 // Device Size (80kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (20 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC11xx/122x/13xx IAP 64kB Flash", // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00010000,                 // Device Size (64kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (16 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_56
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC11xx/122x/13xx IAP 56kB Flash", // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x0000E000,                 // Device Size (56kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (12 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_48
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC11xx/122x/13xx IAP 48kB Flash", // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x0000C000,                 // Device Size (48kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (12 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_40
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC11xx IAP 40kB Flash",   // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x0000A000,                 // Device Size (40kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (12 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_32
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC11xx/122x/13xx IAP 32kB Flash", // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00008000,                 // Device Size (32kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (8 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_24
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC11xx/13xx IAP 24kB Flash", // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00006000,                 // Device Size (24kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (6 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_16
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC11xx/13xx IAP 16kB Flash", // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00004000,                 // Device Size (16kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (4 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_8
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC11xx/13xx IAP 8kB Flash",  // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00002000,                 // Device Size (8kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (2 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_4
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC11xx/13xx IAP 4kB Flash",  // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00001000,                 // Device Size (1kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (1 Sectors)
   SECTOR_END
};
#endif

#endif // LPC1XXX


#ifdef LPC11U6X

#ifdef FLASH_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC11U6x IAP 256kB Flash", // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00040000,                 // Device Size (256kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (24 Sectors)
   0x008000, 0x018000,         // Sector Size 32kB (5 Sectorss) 
   SECTOR_END
};
#endif

#ifdef FLASH_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC11U6x IAP 128kB Flash", // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00020000,                 // Device Size (128kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (24 Sectors)
   0x008000, 0x018000,         // Sector Size 32kB (1 Sectorss) 
   SECTOR_END
};
#endif

#endif // LPC11U6X


#ifdef LPC17XX

#ifdef FLASH_512
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC17xx IAP 512kB Flash",  // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00080000,                 // Device Size (512kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (16 Sectors)
   0x008000, 0x010000,         // Sector Size 32kB (14 Sectors) 
   SECTOR_END
};
#endif

#ifdef FLASH_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC17xx IAP 256kB Flash",  // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00040000,                 // Device Size (256kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (16 Sectors)
   0x008000, 0x010000,         // Sector Size 32kB ( 6 Sectors) 
   SECTOR_END
};
#endif

#ifdef FLASH_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC17xx IAP 128kB Flash",  // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00020000,                 // Device Size (128kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (16 Sectors)
   0x008000, 0x010000,         // Sector Size 32kB ( 2 Sectors) 
   SECTOR_END
};
#endif

#ifdef FLASH_64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC17xx IAP 64kB Flash",   // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00010000,                 // Device Size (64kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (16 Sectors)
   SECTOR_END
};
#endif

#ifdef FLASH_32
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC17xx IAP 32kB Flash",   // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00008000,                 // Device Size (32kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   300,                        // Program Page Timeout 300 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (8 Sectors)
   SECTOR_END
};
#endif

#endif // LPC17XX
