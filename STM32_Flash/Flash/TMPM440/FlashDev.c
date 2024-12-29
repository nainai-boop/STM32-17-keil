/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2012 Keil Software. All rights reserved.        */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for Toshiba TMPM365Fx Flash        */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures


#ifdef TMPM440_1024
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "TMPM440 1024kB Flash",     // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00100000,                 // Device Size (1024kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x002000, 0x000000,         // Sector Size   8kB (4 Sectors)
   0x004000, 0x008000,         // Sector Size  16kB (2 Sector) 
   0x008000, 0x010000,         // Sector Size  32kB (2 Sectors) 
   0x010000, 0x020000,         // Sector Size  64kB (6 Sectors) 
   0x002000, 0x080000,         // Sector Size   8kB (4 Sectors) 
   0x004000, 0x088000,         // Sector Size  16kB (2 Sectors) 
   0x008000, 0x090000,         // Sector Size  32kB (2 Sectors) 
   0x010000, 0x0A0000,         // Sector Size  64kB (6 Sectors) 
   SECTOR_END
};
#endif

#ifdef TMPM440_BE_1024
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "TMPM440 BE 1024kB Flash",  // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00100000,                 // Device Size (1024kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x002000, 0x000000,         // Sector Size   8kB (4 Sectors)
   0x004000, 0x008000,         // Sector Size  16kB (2 Sector) 
   0x008000, 0x010000,         // Sector Size  32kB (2 Sectors) 
   0x010000, 0x020000,         // Sector Size  64kB (6 Sectors) 
   0x002000, 0x080000,         // Sector Size   8kB (4 Sectors) 
   0x004000, 0x088000,         // Sector Size  16kB (2 Sectors) 
   0x008000, 0x090000,         // Sector Size  32kB (2 Sectors) 
   0x010000, 0x0A0000,         // Sector Size  64kB (6 Sectors) 
   SECTOR_END
};
#endif

#ifdef TMPM440_768
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "TMPM440 768kB Flash",      // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x000C0000,                 // Device Size (768kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x002000, 0x000000,         // Sector Size   8kB (4 Sectors)
   0x004000, 0x008000,         // Sector Size  16kB (2 Sector) 
   0x008000, 0x010000,         // Sector Size  32kB (2 Sectors) 
   0x010000, 0x020000,         // Sector Size  64kB (6 Sectors) 
   0x002000, 0x080000,         // Sector Size   8kB (4 Sectors) 
   0x004000, 0x088000,         // Sector Size  16kB (2 Sectors) 
   0x008000, 0x090000,         // Sector Size  32kB (2 Sectors) 
   0x010000, 0x0A0000,         // Sector Size  64kB (2 Sectors) 
   SECTOR_END
};
#endif

#ifdef TMPM440_BE_768
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "TMPM440 BE 768kB Flash",   // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x000C0000,                 // Device Size (768kB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x002000, 0x000000,         // Sector Size   8kB (4 Sectors)
   0x004000, 0x008000,         // Sector Size  16kB (2 Sector) 
   0x008000, 0x010000,         // Sector Size  32kB (2 Sectors) 
   0x010000, 0x020000,         // Sector Size  64kB (6 Sectors) 
   0x002000, 0x080000,         // Sector Size   8kB (4 Sectors) 
   0x004000, 0x088000,         // Sector Size  16kB (2 Sectors) 
   0x008000, 0x090000,         // Sector Size  32kB (2 Sectors) 
   0x010000, 0x0A0000,         // Sector Size  64kB (2 Sectors) 
   SECTOR_END
};
#endif
