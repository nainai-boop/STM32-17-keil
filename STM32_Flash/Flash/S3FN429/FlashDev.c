/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright KEIL ELEKTRONIK GmbH 2003 - 2012                         */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for flash algorithm using Samsung  */
/*               S3FN429 Device Flash                                  */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef S3FN429_PFLASH 
struct FlashDevice const FlashDevice  =  {
  FLASH_DRV_VERS,                       // Driver Version, do not modify!
  "S3FN429 32K Flash",                  // Device Name
  ONCHIP,                               // Device Type
  0x0,                                  // Device Start Address
  0x8000,                               // Device Size in Bytes (32 kB)
  1024,                                 // Programming Page Size
  0,                                    // Reserved, must be 0
  0xFF,                                 // Initial Content of Erased Memory
  500,                                  // Program Page Timeout 500  mSec
  5000,                                 // Erase Sector Timeout 5000 mSec
  // Specify Size and Address of Sectors
  0x2000, 0x0000,                       // Sector Size  8KB (4 sectors)
  SECTOR_END
};
#endif

#ifdef S3FN429_SOPT 
struct FlashDevice const FlashDevice  =  {
  FLASH_DRV_VERS,                       // Driver Version, do not modify!
  "S3FN429 Smart Option",               // Device Name
  ONCHIP,                               // Device Type
  0x1FFFFFC0,                           // Device Start Address
  0x8,                                  // Device Size in Bytes (8 Bytes)
  8,                                    // Programming Page Size
  0,                                    // Reserved, must be 0
  0xFF,                                 // Initial Content of Erased Memory
  1000,                                 // Program Page Timeout max. 30 uSec
  3000,                                 // Erase Sector Timeout max. 28 mSec
  // Specify Size and Address of Sectors
  0x8,  0x0000,                         // Sector Size  8 Bytes (1 Sector)
  SECTOR_END
};
#endif
