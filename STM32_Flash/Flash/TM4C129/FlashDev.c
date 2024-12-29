/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2013 Keil - An ARM Company.                     */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.c:  Flash Programming Device Description for              */
/*               Texas Instruments TM4C129 Flashes                     */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures


#ifdef TM4C129_1024
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "TM4C129 1024kB Flash",     // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00100000,                 // Device Size in Bytes (1024kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   500,                        // Program Page Timeout 500 mSec
   500,                        // Erase Sector Timeout 500 mSec

// Specify Size and Address of Sectors
   0x4000, 0x000000,           // Sector Size 16kB (64 Sectors)
   SECTOR_END
};
#endif
