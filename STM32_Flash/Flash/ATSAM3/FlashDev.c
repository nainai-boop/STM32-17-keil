/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2013 Keil Software. All rights reserved.        */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.c:  Device Description adapted for                        */
/*               Atmel ATSAM3  Flash                                   */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"         // FlashOS Structures


/* ---- SAM3N --------------------------------------------------------------------*/
#ifdef FLASH_MEM
#ifdef ATSAM3N_16
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3N 16kB Flash",        // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00004000,                  // Device Size in Bytes ( 16kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,            // Sector Size 256B (  64 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM3N_32
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3N 32kB Flash",        // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00008000,                  // Device Size in Bytes ( 32kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,            // Sector Size 256B ( 128 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM3N_64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3N 64kB Flash",        // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00010000,                  // Device Size in Bytes ( 64kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,            // Sector Size 256B ( 256 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM3N_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3N 128kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00020000,                  // Device Size in Bytes (128kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,            // Sector Size 256B ( 512 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM3N_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3N 256kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00040000,                  // Device Size in Bytes (256kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,            // Sector Size 256B (1024 Sectors)
   SECTOR_END
};
#endif
#endif /* FLASH_MEM */

#ifdef FLASH_GPNVM
#if defined ATSAM3N_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3N GPNVM bits",        // Device Name
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


/* ---- SAM3S --------------------------------------------------------------------*/
#ifdef FLASH_MEM
#ifdef ATSAM3S_64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3S 64kB Flash",        // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00010000,                  // Device Size in Bytes ( 64kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,            // Sector Size 256B ( 256 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM3S_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3S 128kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00020000,                  // Device Size in Bytes (128kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,            // Sector Size 256B ( 512 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM3S_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3S 256kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00040000,                  // Device Size in Bytes (256kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,            // Sector Size 256B (1024 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM3S_512
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3S 512kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00400000,                  // Device Start Address
   0x00080000,                  // Device Size in Bytes (512kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,            // Sector Size 256B (2048 Sectors)
   SECTOR_END
};
#endif
#endif /* FLASH_MEM */

#ifdef FLASH_GPNVM
#if defined ATSAM3S_512
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3S GPNVM bits",        // Device Name
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


/* ---- SAM3U --------------------------------------------------------------------*/
#ifdef FLASH_MEM
#ifdef ATSAM3U_64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3U 64kB Flash",        // Device Name
   ONCHIP,                      // Device Type
   0x00080000,                  // Device Start Address
   0x00010000,                  // Device Size in Bytes ( 64kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,            // Sector Size 256B (512 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM3U_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3U 128kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00080000,                  // Device Start Address
   0x00020000,                  // Device Size in Bytes (128kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,            // Sector Size 256B (512 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM3U_128_B1
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3U 128kB Flash Bank 1",// Device Name
   ONCHIP,                      // Device Type
   0x00100000,                  // Device Start Address
   0x00020000,                  // Device Size in Bytes (128kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,            // Sector Size 256B (512 Sectors)
   SECTOR_END
};
#endif
#endif /* FLASH_MEM */

#ifdef FLASH_GPNVM
#if defined ATSAM3U_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3U GPNVM bits",        // Device Name
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


/* ---- SAM3X --------------------------------------------------------------------*/
#ifdef FLASH_MEM
#ifdef ATSAM3X_128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3X 128kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00080000,                  // Device Start Address
   0x00020000,                  // Device Size in Bytes (128kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,            // Sector Size 256B (2 *   64 Sectors)
   SECTOR_END
};
#endif

#ifdef ATSAM3X_256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3X 256kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00080000,                  // Device Start Address
   0x00040000,                  // Device Size in Bytes (256kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,            // Sector Size 256B (2 *  512 Sectors)
   SECTOR_END
};
#endif

#if defined ATSAM3X_512
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3X 512kB Flash",       // Device Name
   ONCHIP,                      // Device Type
   0x00080000,                  // Device Start Address
   0x00080000,                  // Device Size in Bytes (512kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   100,                         // Program Page Timeout 100 mSec
   1000,                        // Erase Sector Timeout 1000 mSec

// Specify Size and Address of Sectors
   0x0100, 0x000000,            // Sector Size 256B (2 * 1024 Sectors)
   SECTOR_END
};
#endif
#endif /* FLASH_MEM */

#ifdef FLASH_GPNVM
#if defined ATSAM3X_512
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "ATSAM3X GPNVM bits",        // Device Name
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
