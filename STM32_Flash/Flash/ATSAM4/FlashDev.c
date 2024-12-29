/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2013 Keil - An ARM Company.                     */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for                                */
/*               Atmel ATSAM4 Flashes                                  */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"         // FlashOS Structures


#ifdef FLASH_MEM
#ifdef ATSAM4C_512
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4C 512kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x01000000,                  // Device Start Address
   0x00080000,                  // Device Size in Bytes (512kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x2000, 0x000000,            // Sector Size 8KB ( 64 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM4C_1024
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4C 1024kB Flash",      // Device Name
   ONCHIP,                      // Device Type
   0x01000000,                  // Device Start Address
   0x00100000,                  // Device Size in Bytes (1024kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x2000, 0x000000,            // Sector Size 8KB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM4E_512
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4E 512kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00080000,                  // Device Size in Bytes (512kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x2000, 0x000000,            // Sector Size 8KB ( 64 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM4E_1024
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4E 1024kB Flash",      // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00100000,                  // Device Size in Bytes (1024kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x2000, 0x000000,            // Sector Size 8KB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM4N_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4N 256kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00040000,                  // Device Size in Bytes (256kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x2000, 0x000000,            // Sector Size 8KB ( 32 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM4N_512
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4N 512kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00080000,                  // Device Size in Bytes (512kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x2000, 0x000000,            // Sector Size 8KB ( 64 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM4N_1024
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4N 1024kB Flash",      // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00100000,                  // Device Size in Bytes (1024kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x2000, 0x000000,            // Sector Size 8KB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM4S_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4S 128kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00020000,                  // Device Size in Bytes (128kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x2000, 0x000000,            // Sector Size 8KB ( 16 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM4S_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4S 256kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00040000,                  // Device Size in Bytes (256kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x2000, 0x000000,            // Sector Size 8KB ( 32 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM4S_512
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4S 512kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00080000,                  // Device Size in Bytes (512kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x2000, 0x000000,            // Sector Size 8KB ( 64 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM4S_1024
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4S 1024kB Flash",      // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00100000,                  // Device Size in Bytes (1024kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x2000, 0x000000,            // Sector Size 8KB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM4SD_1024
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4SD 1024kB Flash",     // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00100000,                  // Device Size in Bytes (1024kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x2000, 0x000000,            // Sector Size 8KB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM4SD_2048
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4SD 2048kB Flash",     // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00200000,                  // Device Size in Bytes (2048kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x2000, 0x000000,            // Sector Size 8KB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM4SP_2048
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4SP 2048kB Flash",     // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00200000,                  // Device Size in Bytes (2048kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x2000, 0x000000,            // Sector Size 8KB (128 Sectors)
   SECTOR_END
};
#endif
#endif /* FLASH_MEM */

#ifdef FLASH_GPNVM
#if defined ATSAM4S_1024
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM4S GPNVM bits",        // Device Name
   ONCHIP,                      // Device Type
   0x1FFFFFF0,                  // Device Start Address
   0x00000010,                  // Device Size in Bytes (16)
   16,                          // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x010, 0x000000,             // Sector Size 16B
   SECTOR_END
};
#endif
#endif /* FLASH_GPNVM */
