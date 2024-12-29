/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2013 Keil Software. All rights reserved.        */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.c:  Device Description adapted for                        */
/*               Atmel ATSAM4L Flash                                   */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"         // FlashOS Structures


/* ---- SAM4L ----------------------------------------------------------*/
#ifdef FLASH_MEM

#ifdef ATSAM4L_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4L 128kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00000000,                  // Device Start Address
   0x00020000,                  // Device Size in Bytes (128kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   300,                         // Program Page Timeout 300 mSec
   3000,                        // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x4000, 0x000000,            // Sector Size 16KB (8 Sectors(Regions); 1 Sector  = PAGE_SIZE * 32)
   SECTOR_END
};
#endif

#ifdef ATSAM4L_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4L 256kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00000000,                  // Device Start Address
   0x00040000,                  // Device Size in Bytes (256kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   300,                         // Program Page Timeout 300 mSec
   3000,                        // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x4000, 0x000000,            // Sector Size 16KB (16 Sectors(Regions); 1 Sector  = PAGE_SIZE * 32)
   SECTOR_END
};
#endif


#ifdef ATSAM4L_512
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4L 512kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00000000,                  // Device Start Address
   0x00080000,                  // Device Size in Bytes (256kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   300,                         // Program Page Timeout 300 mSec
   3000,                        // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x4000, 0x000000,            // Sector Size 16KB (16 Sectors(Regions); 1 Sector  = PAGE_SIZE * 32)
   SECTOR_END
};
#endif
#endif /* FLASH_MEM */

#ifdef FLASH_GPNVM

#endif /* FLASH_GPNVM */
