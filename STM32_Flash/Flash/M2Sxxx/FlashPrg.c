/***********************************************************************/
/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2006-2013 Keil - An ARM Company.                     */
/*  All rights reserved.                                               */
/***********************************************************************/
/*                                                                     */
/*  FlashPrg.c:  Flash Programming Functions adapted for               */
/*               SmartFusion2 M2Sxxxx Devices                          */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures
#include "m2Sxxx.h"

#define FLASH_PAGE_SIZE_BYTE    0x00000080UL
#define FLASH_NVM0_SIZE_BYTE    0x00040000UL


/* eNVM Status Register Bit Definitions */
#define NVM_READY               (0x01UL <<  0)     /* NVM Ready/busy (0: Busy, 1: Ready) */
#define NVM_VERIFY_FAIL         (0x01UL <<  1)     /* NVM verify failure */
#define NVM_E_VERIFY_FAIL       (0x01UL <<  2)     /* NVM erase verify failure */
#define NVM_W_VERIFY_FAIL       (0x01UL <<  3)     /* NVM write verify failure */
#define NVM_PE_FAIL             (0x01UL <<  4)     /* NVM program or erase failure due to page lock */
#define NVM_WRCNT_OVER          (0x01UL <<  5)     /* NVM write count is over threshold */
#define NVM_ACC_DENIED          (0x01UL << 18)     /* NVM Access denied */

#define NVM_ERROR               (NVM_VERIFY_FAIL   | \
                                 NVM_E_VERIFY_FAIL | \
                                 NVM_W_VERIFY_FAIL | \
                                 NVM_PE_FAIL       | \
                                 NVM_WRCNT_OVER    | \
                                 NVM_ACC_DENIED     )

/* eNVM Commands */
#define NVM_PROG_ADS            (0x08UL << 24)     /* NVM program page procedure */
#define NVM_USER_UNLOCK         (0x13UL << 24)     /* NVM s_unlock NVM command */





unsigned long base_adr;    

/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */
    
int Init (unsigned long adr, unsigned long clk, unsigned long fnc) {

  base_adr = adr;
    
  SYSREG->WDOG_CR = 0x00000000;                    /* Disable Watchdog */
	
  SYSREG->ENVM_REMAP_BASE_CR = 0x00000001;         /* Remap eNVM to 0x00000000 */

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


/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseSector (unsigned long adr) {

  return (0);                                      /* Automatic Erase during Program Cycle */
}


/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */

int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {
  int                retVal = 0;                   /* Success */
  int                cnt;
  unsigned long      page;
  volatile uint32_t  nvmStatus;       
  NVM_TypeDef       *NVM;

  /* select NVM according Flash address */
  NVM = (adr < FLASH_NVM0_SIZE_BYTE) ? ENVM_1 : ENVM_2;

  /* calculate page address */
  page  = ((adr - base_adr) & (FLASH_NVM0_SIZE_BYTE - 1)) & ~(FLASH_PAGE_SIZE_BYTE - 1);
  
  NVM->REQ_ACCESS = 0x01UL;                        /* Request register access */
  while (NVM->REQ_ACCESS != 0x05UL) __nop();       /* Wait until M3 got access */

  NVM->CMD = NVM_USER_UNLOCK;                      /* unlock eNVM */
//  nvmStatus = NVM->STATUS;                         /* Dummy read */
//  while (!(NVM->STATUS & NVM_READY)) __nop();      /* Wait until NVM ready */

  for (cnt = 0; cnt < sz; cnt++) {                 /* copy to the Write data buffer */
    NVM->WD[cnt] = *(uint8_t *)buf++;
  }

  NVM->PAGE_LOCK = 0x00;                           /* Unlock page */

  NVM->CMD = NVM_PROG_ADS | page;                  /* Program Page Command */
  nvmStatus = NVM->STATUS;                         /* Dummy read */
  while (!(NVM->STATUS & NVM_READY)) __nop();      /* Wait until NVM ready */

  if (NVM->STATUS & NVM_ERROR) {                   /* Check for Errors */
    retVal = 1;                                    /* Fail */
  }

  NVM->REQ_ACCESS = 0x00UL;                        /* Release register access */
  
  return (retVal);
}

