/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright KEIL ELEKTRONIK GmbH 2003 - 2008                         */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for Energy Micro EFM32G            */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        /* FlashOS Structures */


/*
 * NOTE: Program Page Timeout is NOT time it takes to program a flash page !
 *       Timeout found by "try/fail" method plus ample margin,
 *       but never less than 100ms.
 */
struct FlashDevice const FlashDevice =
{
  FLASH_DRV_VERS,            /* Driver Version, do not modify!   */
  "EFM32 Gecko/Tiny Gecko",  /* Device Name                      */
  ONCHIP,                    /* Flash Type                       */
  0x00000000,                /* Flash Start Address              */
  0x00020000,                /* Flash Size                       */
  1024,                      /* Programming Page (buffer) Size   */
  0,                         /* Reserved, must be 0              */
  0xFF,                      /* Content of Erased Memory cell    */
  100,                       /* Program Page Timeout 100 mSec    */
  200,                       /* Erase Sector Timeout 200 mSec    */
  {
    {
      512,                   /* Sector Size                      */
      0x00000000             /* Address of first sector          */
    },
    {
      SECTOR_END
    }
  }
};
