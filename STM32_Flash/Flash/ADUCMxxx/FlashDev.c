/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright KEIL ELEKTRONIK GmbH 2003 - 2013                         */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for ADUCMxxx Flash                 */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
#ifdef ADuCMxxx_128	
   "ADuCM360 128kB Flash",           // Device Name
#else
   "ADuCRF101 128kB Flash",           // Device Name
#endif
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x0020000,                  // Device Size in Bytes (128kB)
  
   0x200,                      // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   500,                        // Program Page Timeout
   5000,                       // Erase Sector Timeout

// Specify Size and Address of Sectors
   0x200, 0x000000,             // Sector Size 512B (128 Sectors)
   SECTOR_END
};

