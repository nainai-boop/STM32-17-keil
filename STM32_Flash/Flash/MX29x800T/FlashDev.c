/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright KEIL ELEKTRONIK GmbH 2003 - 2006                         */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for MX29x800T (16-bit Bus)         */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures


struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MX29x800T Flash",          // Device Name
   EXT16BIT,                   // Device Type
   0x000000,                   // Device Start Address
   0x100000,                   // Device Size in Bytes (1MB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x10000, 0x00000,           // Sector Size 64kB (15 Sectors)
   0x08000, 0xF0000,           // Sector Size 32kB (1 Sector)
   0x02000, 0xF8000,           // Sector Size  8kB (2 Sectors)
   0x04000, 0xFC000,           // Sector Size 16kB (1 Sector)
   SECTOR_END
};
