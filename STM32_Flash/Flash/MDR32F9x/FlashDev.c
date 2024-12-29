/***********************************************************************/
/* This file is part of the uVision/ARM development tools              */
/* Copyright (c) 2006-2011 Keil Software. All rights reserved.         */
/***********************************************************************/
/*                                                                     */
/* FlashDev.c: Device Description for                                  */
/*             Milandr MDR32F9x Flash using Flash Boot Loader with IAP */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures


#ifdef MDR32F9x_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MDR32F9x 128kB Flash",     // Device Name 
   ONCHIP,                     // Device Type
   0x08000000,                 // Device Start Address
   0x00020000,                 // Device Size without Boot Loader (128kB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xff,                       // Initial Content of Erased Memory
   10000,                      // Program Page Timeout 10 Sec
   30000,                      // Erase Sector Timeout 30 Sec

// Specify Size and Address of Sectors
   0x001000, 0x000000,        // Sector Size  4kB (4 Sectors)
   SECTOR_END
};
#endif
