/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2012 Keil Software. All rights reserved.        */
/***********************************************************************/
/*                                                                     */
/*  FlashPrg.C:  Flash Programming Functions adapted for               */
/*               Freescale MK40X256VMD100 Flash                        */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures
#include "SSD_Types.h"
#include "SSD_FTFx.h"
#include "SSD_FTFx_Internal.h"
#include "ConfigureKeil.h"


#define M8(adr)  (*((volatile unsigned char  *)(adr)))
#define M16(adr) (*((volatile unsigned short *)(adr)))
#define M32(adr) (*((volatile unsigned long  *)(adr)))

#define STACK_SIZE   1024      // Stack Size
#define PAGE_SIZE    2048      // Page Size

    /* FTFL module base */
#define FTFL_REG_BASE           0x40020000
#define EERAM_BLOCK_BASE        0x14000000

#if defined (MKP1024) || defined (MKPIFR_120MHZ) || defined (MKDIFR_120MHZ)
  #define PBLOCK_SIZE             0x00100000      /* 1 MB       */
  #define EERAM_BLOCK_SIZE        0x00004000      /* 16 KB size */
  #define DEFLASH_BLOCK_BASE      0x10000000
#elif defined (MKP2048)
  #define PBLOCK_SIZE             0x00200000      /* 2 MB     */
  #define EERAM_BLOCK_SIZE        0x00004000      /* 16 KB size */
  #define DEFLASH_BLOCK_BASE      0x10000000
#elif defined (MKP512X) || defined (MKD512)
  #define PBLOCK_SIZE             0x00080000      /* 512 KB     */
  #define EERAM_BLOCK_SIZE        0x00004000      /* 16 KB size */
  #define DEFLASH_BLOCK_BASE      0x10000000
#elif defined (MKD128_4KB_SECTOR)
  #define PBLOCK_SIZE             0x00080000      /* 512 KB     */
  #define EERAM_BLOCK_SIZE        0x00001000      /* 4 KB size */
  #define DEFLASH_BLOCK_BASE      0x10000000
#elif defined (MKD256_4KB_SECTOR)
  #define PBLOCK_SIZE             0x00100000      /* 1 MB     */
  #define EERAM_BLOCK_SIZE        0x00001000      /* 4 KB size */
  #define DEFLASH_BLOCK_BASE      0x10000000
#elif defined (MKP512)
  #define PBLOCK_SIZE             0x00080000      /* 512 KB     */
  #define EERAM_BLOCK_SIZE        0x00001000      /* 4 KB size  */
  #define DEFLASH_BLOCK_BASE      0x10000000
#elif defined (MKP128_50MHZ) || defined (MKP64_50MHZ) || defined (MKPIFR_50MHZ) ||\
  defined (MKP32_50MHZ) || defined (MKD32_50MHZ) || defined (MKDIFR_50MHZ) || defined (MKD32_72MHZ)

  #define PBLOCK_SIZE             0x00020000      /* 128 KB     */
  #define EERAM_BLOCK_SIZE        0x00000800      /* 4 KB size  */
  #define DEFLASH_BLOCK_BASE      0x10000000
#elif defined (MKP256_50MHZ) || defined (MKD64_50MHZ)

  #define PBLOCK_SIZE             0x00040000      /* 256 KB     */
  #define EERAM_BLOCK_SIZE        0x00000800      /* 4 KB size  */
  #define DEFLASH_BLOCK_BASE      0x10000000
#elif defined (MKP512_50MHZ)

  #define PBLOCK_SIZE             0x00080000      /* 512 KB     */
  #define EERAM_BLOCK_SIZE        0x00000800      /* 4 KB size  */
  #define DEFLASH_BLOCK_BASE      0x10000000
#else
  #define PBLOCK_SIZE             0x00040000      /* 256 KB     */
  #define EERAM_BLOCK_SIZE        0x00001000      /* 4 KB size  */
  #define DEFLASH_BLOCK_BASE      0x10000000
#endif

#define DATAFLASH_IFR_READRESOURCE_ADDRESS   0x100000FC 

FLASH_SSD_CONFIG flashSSDConfig; 
unsigned long base_adr;
const unsigned long unsecureword = 0xFFFFFFFE;
const unsigned long long unsecurewordLL = 0xFFFFFFFEFFFFFFFF;
#if defined (MKDIFR_120MHZ)
unsigned char tbuf[8]; 
#endif
/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */
#if defined (MKP128_48MHZ) || defined (MKP64_48MHZ) || defined (MKP32_48MHZ) \
    || defined (MKPIFR_48MHZ) || defined (MKP16_48MHZ) || defined (MKP8_48MHZ) || defined (MKP256_48MHZ)
 #define SIM_COPC                      *((volatile unsigned long *)0x40048100) 
#else
 #define WDOG_UNLOCK                   *((volatile unsigned short *)0x4005200E) 
 #define WDOG_STCTRLH                  *((volatile unsigned short *)0x40052000) 
 #define WDOG_STCTRLH_WDOGEN_MASK_X    0x00000001
#endif
#define FLASH_CONFIG_FSEC             0x0000040C



int Init (unsigned long adr, unsigned long clk, unsigned long fnc) {
  base_adr = adr;
#if defined (MKP128_48MHZ) || defined (MKP64_48MHZ) || defined (MKP32_48MHZ) \
	|| defined (MKPIFR_48MHZ) || defined (MKP16_48MHZ) || defined (MKP8_48MHZ) || defined (MKP256_48MHZ)
  SIM_COPC = 0x00u;
#else	
  /* Write 0xC520 to the unlock register */
  WDOG_UNLOCK = 0xC520;
  /* Followed by 0xD928 to complete the unlock */
  WDOG_UNLOCK = 0xD928;
  /* Clear the WDOGEN bit to disable the watchdog */
  WDOG_STCTRLH &= ~WDOG_STCTRLH_WDOGEN_MASK_X;
#endif
  flashSSDConfig.ftfxRegBase        = FTFL_REG_BASE;           /* FTFL control register base */
  flashSSDConfig.PFlashBlockBase    = 0;                       /* base address of PFlash block */
  flashSSDConfig.PFlashBlockSize    = PBLOCK_SIZE;             /* size of PFlash block */
#if(DEBLOCK_SIZE != 0)	
  flashSSDConfig.DFlashBlockBase    = DEFLASH_BLOCK_BASE;      /* base address of DFlash block */
#endif
  flashSSDConfig.EERAMBlockBase     = EERAM_BLOCK_BASE;        /* base address of EERAM block */
  flashSSDConfig.EERAMBlockSize     = EERAM_BLOCK_SIZE;        /* size of EERAM block */
  flashSSDConfig.DebugEnable        = 0;                       /* background debug mode enable bit */
  flashSSDConfig.CallBack           = NULL_CALLBACK;           /* pointer to callback function */
  if (FTFx_OK != pFlashInit(&flashSSDConfig)) return (1);
  return (0);
}


/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int UnInit (unsigned long fnc) {
  return (0);
}


/*  Blank Check Block in Flash Memory
 *    Parameter:      adr:  Block Start Address
 *                    sz:   Block Size (in bytes)
 *                    pat:  Block Pattern
 *    Return Value:   0 - OK,  1 - Failed
 */

#if defined (MKPIFR) || defined (MKDIFR) || defined (MKDIFR_50MHZ)  || defined (MKPIFR_50MHZ) || defined (MKPIFR_120MHZ)  ||\
    defined (MKPIFR_48MHZ) || defined (MKDIFR_120MHZ)
int BlankCheck (unsigned long adr, unsigned long sz, unsigned char pat) {
  return (0);                                  // Finished without Errors
}
#elif defined (MKP8_48MHZ) //Device with 1KB SRAM
#else
int BlankCheck (unsigned long adr, unsigned long sz, unsigned char pat) {
  if (FTFx_OK != pFlashVerifySection(&flashSSDConfig, adr, (sz/8), READ_NORMAL_MARGIN, pFlashCommandSequence)) return (1);
  return (0);                                  // Finished without Errors
}
#endif

/*  
 *  Verify Flash Contents
 *    Parameter:      adr:  Start Address
 *                    sz:   Size (in bytes)
 *                    buf:  Data
 *    Return Value:   (adr+sz) - OK, Failed Address
 */
#if defined (MKPIFR) || defined (MKPIFR_50MHZ) || defined (MKPIFR_120MHZ)|| defined (MKPIFR_48MHZ)
unsigned long Verify (unsigned long adr, unsigned long sz, unsigned char *buf) {
  if (FTFx_OK != pFlashReadOnce(&flashSSDConfig, buf, pFlashCommandSequence)) return(1);
  return (adr+sz);                                  // Finished without Errors
}
#elif defined (MKDIFR) || defined (MKDIFR_50MHZ)
unsigned long Verify (unsigned long adr, unsigned long sz, unsigned char *buf) {
  if (FTFx_OK != pFlashReadResource(&flashSSDConfig, DATAFLASH_IFR_READRESOURCE_ADDRESS, buf, pFlashCommandSequence)) return(1);
  return (adr+sz);                                  // Finished without Errors
}
#elif defined (MKDIFR_120MHZ)
unsigned long Verify (unsigned long adr, unsigned long sz, unsigned char *buf) {
  if (FTFx_OK != pFlashReadResource(&flashSSDConfig, 0x100003F8, buf, pFlashCommandSequence)) return(1);
  return (adr+sz);                                  // Finished without Errors
}
#endif 
/*
 *  Erase complete Flash Memory
 *    Return Value:   0 - OK,  1 - Failed
 */
#if defined (MKPIFR) || defined (MKDIFR) || defined (MKDIFR_50MHZ) || defined (MKPIFR_50MHZ) \
|| defined (MKPIFR_120MHZ) || defined (MKPIFR_48MHZ) || defined (MKDIFR_120MHZ)
int EraseChip (void) {
  return(0);
}
#else
int EraseChip (void) {
  int ret;

  if (FTFx_OK != (ret = pFlashEraseAllBlock(&flashSSDConfig,pFlashCommandSequence))) return (ret);

#if defined (MKP512X) || defined (MKP1024) || defined (MKD512) || defined (MKD128_4KB_SECTOR) || defined (MKP2048) || defined (MKD256_4KB_SECTOR)
  // Program SECURITY bit
  if (FTFx_OK != pFlashProgramPhrase(&flashSSDConfig, 0x408, 8, (unsigned long long)&unsecurewordLL, pFlashCommandSequence)) return (1);
#else 
  // Program SECURITY bit
  if (FTFx_OK != pFlashProgramLongword(&flashSSDConfig, FLASH_CONFIG_FSEC, 4, (unsigned long)&unsecureword, pFlashCommandSequence)) return (1);
#endif
  return (0);                                  // Finished without Errors
}
#endif

/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */
#if defined (MKPIFR) || defined (MKDIFR) || defined (MKDIFR_50MHZ) || defined (MKPIFR_50MHZ) \
|| defined (MKPIFR_120MHZ) || defined (MKPIFR_48MHZ) || defined (MKDIFR_120MHZ)
int EraseSector (unsigned long adr) {
  return (0);                                  // Finished without Errors
}
#else
int EraseSector (unsigned long adr) {
  // Start Sector Erase Command
  return((int)pFlashEraseSector(&flashSSDConfig, adr, FTFx_PSECTOR_SIZE, pFlashCommandSequence));
}
#endif

/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */
#if defined (MKPIFR) || defined (MKPIFR_50MHZ) || defined (MKPIFR_120MHZ) || defined (MKPIFR_48MHZ)
int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {
  if (FTFx_OK != pFlashProgramOnce(&flashSSDConfig, buf, pFlashCommandSequence)) return (1);
  return (0);                                  // Finished without Errors
}
#elif defined (MKDIFR) || defined (MKDIFR_50MHZ)
int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {
  if (FTFx_OK != pFlashEraseAllBlock(&flashSSDConfig,pFlashCommandSequence)) return(1);

  // Program SECURITY bit
  if (FTFx_OK != pFlashProgramLongword(&flashSSDConfig, FLASH_CONFIG_FSEC, 4, (unsigned long)&unsecureword, pFlashCommandSequence)) return (1);

  if (FTFx_OK != pDEFlashPartition(&flashSSDConfig, buf[2], buf[3], pFlashCommandSequence)) return(1);

  return (0);                                  // Finished without Errors
}
#elif defined (MKDIFR_120MHZ)
int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {
  if (FTFx_OK != pFlashEraseAllBlock(&flashSSDConfig,pFlashCommandSequence)) return(1);

  if (FTFx_OK != pFlashProgramPhrase(&flashSSDConfig, 0x408, 8, (unsigned long long)&unsecurewordLL, pFlashCommandSequence)) return (1);

  if (FTFx_OK != pDEFlashPartition(&flashSSDConfig, buf[2], buf[3], pFlashCommandSequence)) return(1);

  return (0);                                  // Finished without Errors
}
#elif defined (MKP512X) || defined (MKP1024) || defined (MKD512) || defined (MKD128_4KB_SECTOR) || defined (MKP2048) || defined (MKD256_4KB_SECTOR)
int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {
  sz = (sz + 7) & ~0x00000007;                 // Align to FTFL_PHRASE_SIZE
  if (FTFx_OK != pFlashProgramPhrase(&flashSSDConfig, adr, sz, (unsigned long)buf, pFlashCommandSequence)) return (1);
  return (0);                                  // Finished without Errors
}
#else
int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {

  if (FTFx_OK != pFlashProgramLongword(&flashSSDConfig, adr, sz, (unsigned long)buf, pFlashCommandSequence)) return (1);
  return (0);                                  // Finished without Errors
}
#endif
