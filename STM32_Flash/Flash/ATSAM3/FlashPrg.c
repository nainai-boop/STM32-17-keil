/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright (c) 2003-2013 Keil Software. All rights reserved.        */
/***********************************************************************/
/*                                                                     */
/*  FlashPrg.c:  Flash Programming Functions adapted for               */
/*               Atmel ATSAM3  Flash                                   */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"                          /* FlashOS Structures */

typedef volatile unsigned long    vu32;
typedef          unsigned long     u32;
typedef          unsigned char     u8;

/* Power Management Controller register */
typedef struct {
  vu32 PMC_SCER;
  vu32 PMC_SCDR;
  vu32 PMC_SCSR;
  vu32 Reserved1[1];
  vu32 PMC_PCER;
  vu32 PMC_PCDR;
  vu32 PMC_PCSR;
  vu32 Reserved2[1];
  vu32 CKGR_MOR;
  vu32 CKGR_MCFR;
  vu32 CKGR_PLLAR;
  vu32 CKGR_PLLBR;
  vu32 PMC_MCKR;
  vu32 Reserved3[1];
  vu32 PMC_USB;
  vu32 Reserved4[1];
  vu32 PMC_PCK[3];
  vu32 Reserved5[5];
  vu32 PMC_IER;
  vu32 PMC_IDR;
  vu32 PMC_SR;
  vu32 PMC_IMR;
  vu32 PMC_FSMR;
  vu32 PMC_FSPR;
  vu32 PMC_FOCR;
  vu32 Reserved6[26];
  vu32 PMC_WPMR;
  vu32 PMC_WPSR;
} PMC_TypeDef;

/* PMC clock generator main oscillatoer register definitions */
#define PMC_CKGR_MOSCXTEN     (0x01   <<  0)     /* MOSCXTEN: Main Crystal Oscillator Enable             */
#define PMC_CKGR_MOSCXTST     (0x0F   <<  8)     /* MOSCXTST: Main Crystal Oscillator Start-up Time (15) */
#define PMC_CKGR_CKGR_KEY     (0x37   << 16)     /* KEY: Password                                        */
#define PMC_CKGR_MOSCSEL      (0x01   << 24)     /* MOSCSEL: Main Oscillator Selection                   */

/* PMC master clock register definitions */
#define PMC_MCKR_CSS          (0x03   <<  0)     /* CSS: Master Clock Source Selection */
#define PMC_MCKR_CSS_MAIN_CLK (0x01   <<  0)     /* Main Clock is selected             */
#define PMC_MCKR_PRES_1       (0x01   <<  4)     /* PRES: Processor Clock Prescaler    */

/* PMC status register definitions */
#define PMC_SR_MOSCXTS        (0x01   <<  0)     /* MOSCXTS: Main XTAL Oscillator Status */
#define PMC_SR_MCKRDY         (0x01   <<  3)     /* MCKRDY: Master Clock  Status         */

/* PMC write protection register definitions */
#define PMC_WPMR_WPEN         (0x01     <<  0)   /* WPEN: Write Protect Enable */
#define PMC_WPMR_WPKEY        (0x504D43 <<  8)   /* WPKEY: Write Protect KEY   */

/* Independent WATCHDOG register */
typedef struct {
  vu32 CR;
  vu32 MR;
  vu32 SR;
} WDT_TypeDef;

/* WDT mode register definitions */
#define WDT_MR_WDDIS          (0x01   << 15)     /* WDDIS: Watchdog Disable */

/* Flash Registers register */
typedef struct {
  vu32 FMR;
  vu32 FCR;
  vu32 FSR;
  vu32 FRR;
} EEFC_TypeDef;

/* EEFC command register definitions */
#define EEFC_FCR_FKEY         (0x5A   << 24)     /* Flash Writing Protection Key */
#define EEFC_FCR_FARG         (0xFFFF <<  8)     /* Flash Command Argument bits  */
#define EEFC_FCR_FCMD         (0xFF   <<  0)     /* Flash Command bits           */

/* EEFC command definitions */
#define EEFC_FCR_FCMD_GETD     0x00              /* Get Flash Descriptor                */
#define EEFC_FCR_FCMD_WP       0x01              /* Write Page                          */
#define EEFC_FCR_FCMD_WPL      0x02              /* Write Page and Lock                 */
#define EEFC_FCR_FCMD_EWP      0x03              /* Erase Page and Write Page           */
#define EEFC_FCR_FCMD_EWPL     0x04              /* Erase Page and Write Page then Lock */
#define EEFC_FCR_FCMD_EA       0x05              /* Erase All                           */
#define EEFC_FCR_FCMD_EPL      0x06              /* Erase Plane                         */
#define EEFC_FCR_FCMD_EPA      0x07              /* Erase Pages                         */
#define EEFC_FCR_FCMD_SLB      0x08              /* Set Lock Bit                        */
#define EEFC_FCR_FCMD_CLB      0x09              /* Clear Lock Bit                      */
#define EEFC_FCR_FCMD_GLB      0x0A              /* Get Lock Bit                        */
#define EEFC_FCR_FCMD_SGPB     0x0B              /* Set GPNVM Bit                       */
#define EEFC_FCR_FCMD_CGPB     0x0C              /* Clear GPNVM Bit                     */
#define EEFC_FCR_FCMD_GGPB     0x0D              /* Get GPNVM Bit                       */
#define EEFC_FCR_FCMD_STUI     0x0E              /* Start Read Unique Identifier        */
#define EEFC_FCR_FCMD_SPUI     0x0F              /* Stop Read Unique Identifier         */

/* EEFC status register definitions */
#define EEFC_FSR_FRDY          0x01              /* Flash Ready Status         */
#define EEFC_FSR_FCMDE         0x02              /* Flash Command Error Status */
#define EEFC_FSR_FLOCKE        0x04              /* Flash Lock Error Status    */

/* EEFC mode register */
#define EEFC_FMR_FAM          (0x01   << 24)     /* FAM: Flash Access mode */
#define EEFC_FMR_FWS          (0x0F   <<  8)     /* FWS: Flash Wait State  */

/* GPNVM bits */
#define GPNVM_BIT0             0x00              /* GPNVM bit0: Security bit */
#define GPNVM_BIT1             0x01              /* GPNVM bit1: Boot mode selection  0 = Boot from ROM,    1 = Boot from Flash  */
#define GPNVM_BIT2             0x02              /* GPNVM bit2: Flash selection      0 = Boot from Flash0, 1 = Boot from Flash1 */


/* Peripheral Memory Map */
/* ---- SAM3N --------------------------------------------------------------------*/
#if defined ATSAM3N_16 || ATSAM3N_32 || ATSAM3N_64 || defined ATSAM3N_128 || defined ATSAM3N_256
  #define PMC_BASE             0x400E0400        /* SAM3U, SAM3S, SAM3N        */
  #define WDT_BASE             0x400E1450        /*        SAM3S, SAM3N        */
  #define EEFC0_BASE           0x400E0A00        /*        SAM3S, SAM3N        */
#endif

/* ---- SAM3S --------------------------------------------------------------------*/
#if defined ATSAM3S_64 || defined ATSAM3S_128 || defined ATSAM3S_256 || defined ATSAM3S_512
  #define PMC_BASE             0x400E0400        /* SAM3U, SAM3S, SAM3N        */
  #define WDT_BASE             0x400E1450        /*        SAM3S               */
  #define EEFC0_BASE           0x400E0A00        /*        SAM3S               */
#endif

/* ---- SAM3U --------------------------------------------------------------------*/
#if defined ATSAM3U_64 || defined ATSAM3U_128 || defined ATSAM3U_128_B1
  #define PMC_BASE             0x400E0400        /* SAM3U, SAM3S, SAM3N        */
  #define WDT_BASE             0x400E1250        /* SAM3U                      */
  #define EEFC0_BASE           0x400E0800        /* SAM3U                      (internal Flash 0) */
  #define EEFC1_BASE           0x400E0A00        /* SAM3U                      (internal Flash 1) */
#endif

/* ---- SAM3X --------------------------------------------------------------------*/
#if defined ATSAM3X_128 || defined ATSAM3X_256 || defined ATSAM3X_512
  #define PMC_BASE             0x400E0600        /*                      SAM3X */
  #define WDT_BASE             0x400E1A50        /*                      SAM3X */
  #define EEFC0_BASE           0x400E0A00        /*                      SAM3X (internal Flash 0) */
  #define EEFC1_BASE           0x400E0C00        /*                      SAM3X (internal Flash 1) */

  #if defined ATSAM3X_512
    #define FLASH_SIZE         0x00080000        /* 512 kB  */
  #endif
  #if defined ATSAM3X_256
    #define FLASH_SIZE         0x00040000        /* 256 kB  */
  #endif
  #if defined ATSAM3X_128
    #define FLASH_SIZE         0x00020000        /* 128 kB  */
  #endif
#endif


#define PMC            (( PMC_TypeDef *)   PMC_BASE)
#define WDT            (( WDT_TypeDef *)   WDT_BASE)
#define EEFC0          ((EEFC_TypeDef *) EEFC0_BASE)
#define EEFC1          ((EEFC_TypeDef *) EEFC1_BASE)

#define FLASH_PAGE_SIZE        256               /* Page size is 256 Byte for all devices */



unsigned long base_adr;        /* Base Address  */


/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int Init (unsigned long adr, unsigned long clk, unsigned long fnc) {

  /* store Flash Start address */
  base_adr = adr;

  /* set Flash Waite State to maximum */
  EEFC0->FMR = EEFC_FMR_FWS;
#if defined EEFC1_BASE
  EEFC1->FMR = EEFC_FMR_FWS;
#endif

  /* disable Watchdog */
  WDT->MR   = WDT_MR_WDDIS;

  /* disable PMC write protection */
  PMC->PMC_WPMR = PMC_WPMR_WPKEY;

  /* Enable the Main Oscillator:
     SCK Period = 1/32768 = 30.51 us
     Start-up Time = 8 * 15 / SCK = 120 * 30.51us = 3.6612 ms */
  PMC->CKGR_MOR = (PMC_CKGR_MOSCSEL | PMC_CKGR_CKGR_KEY | PMC_CKGR_MOSCXTST | PMC_CKGR_MOSCXTEN);

  /* Wait the Start-up Time */
  while(!(PMC->PMC_SR & PMC_SR_MOSCXTS));

  /* Select Main Clock (CSS field) */
  PMC->PMC_MCKR = (PMC->PMC_MCKR & ~PMC_MCKR_CSS) | PMC_MCKR_CSS_MAIN_CLK;

  /* Wait for Clock ready */
  while (!(PMC->PMC_SR & PMC_SR_MCKRDY));

  /* Select Main Clock */
  PMC->PMC_MCKR = PMC_MCKR_CSS_MAIN_CLK;

  /* Wait for Clock ready */
  while (!(PMC->PMC_SR & PMC_SR_MCKRDY));

  /* enable PMC write protection */
  PMC->PMC_WPMR = PMC_WPMR_WPKEY | PMC_WPMR_WPEN;

  return (0);
}


/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int UnInit (unsigned long fnc) {
#ifdef FLASH_MEM
  u32           frr;

  /* after programming Flash  set GPNVMBit to boot from Flash */
  if (fnc == 2) {

    /* read current GPNVM bits */
    EEFC0->FCR = EEFC_FCR_FKEY | EEFC_FCR_FCMD_GGPB;
    while (!(EEFC0->FSR & EEFC_FSR_FRDY));
    frr = EEFC0->FRR;

    /* configure GPNVM bit #1 :  1 = Boot from Flash  */
    if ((frr & (1 << GPNVM_BIT1)) == 0) {
      EEFC0->FCR = EEFC_FCR_FKEY | (GPNVM_BIT1 << 8) | EEFC_FCR_FCMD_SGPB; 

      /* Wait until the end of Command */
      while (!(EEFC0->FSR & EEFC_FSR_FRDY));
    }

//#if defined FLASH_BANK_SELECTION
    /* configure GPNVM bit #2 : Flash selection      0 = Boot from Flash 0 */
    if ((frr & (1 << GPNVM_BIT1)) != 0) {
      EEFC0->FCR = EEFC_FCR_FKEY | (GPNVM_BIT2 << 8) | EEFC_FCR_FCMD_CGPB;

      /* Wait until the end of Command */
      while (!(EEFC0->FSR & EEFC_FSR_FRDY));
  }
//#endif

  }
#endif

  return (0);
}


/*  
 *  Blank Check Checks if Memory is Blank
 *    Parameter:      adr:  Block Start Address
 *                    sz:   Block Size (in bytes)
 *                    pat:  Block Pattern
 *    Return Value:   0 - OK,  1 - Failed
 */

#ifdef FLASH_GPNVM
int BlankCheck (unsigned long adr, unsigned long sz, unsigned char pat) {

  /* for GPNVM bits blankCheck is always ok */
  return (0);
}
#endif


/*
 *  Erase complete Flash Memory
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseChip (void) {
#ifdef FLASH_MEM

  /* erase all command
     memory covered by the Flash Programming Algorithm is erased */
#if   defined ATSAM3X_128 || defined ATSAM3X_256 || defined ATSAM3X_512
  EEFC0->FCR  = EEFC_FCR_FKEY | EEFC_FCR_FCMD_EA;
  while (!(EEFC0->FSR  & EEFC_FSR_FRDY));

  EEFC1->FCR = EEFC_FCR_FKEY | EEFC_FCR_FCMD_EA;
  while (!(EEFC1->FSR & EEFC_FSR_FRDY));
#elif defined ATSAM3U_128_B1
  EEFC1->FCR = EEFC_FCR_FKEY | EEFC_FCR_FCMD_EA;
  while (!(EEFC1->FSR & EEFC_FSR_FRDY));
#else
  EEFC0->FCR  = EEFC_FCR_FKEY | EEFC_FCR_FCMD_EA;
  while (!(EEFC0->FSR  & EEFC_FSR_FRDY));
#endif

#endif

  return (0);
}


/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseSector (unsigned long adr) {
 
  /* automatic erase during program cycle */
  return (0);
}


/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */
#ifdef FLASH_MEM
int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {
  u32           page;
  u32          *Flash;
  EEFC_TypeDef *EEFC;

  /* select EEFC, calculate page */   
#if   defined ATSAM3X_128 || defined ATSAM3X_256 || defined ATSAM3X_512
  if (adr < (base_adr + (FLASH_SIZE / 2))) {
    EEFC  =  EEFC0;
    page  = (adr - (base_adr                   )) / FLASH_PAGE_SIZE;
  }
  else {
    EEFC  =  EEFC1;
    page  = (adr - (base_adr + (FLASH_SIZE / 2))) / FLASH_PAGE_SIZE;
  }
#elif defined ATSAM3U_128_B1
    EEFC  = EEFC1;
    page  = (adr - (base_adr                   )) / FLASH_PAGE_SIZE;
#else
    EEFC  = EEFC0;
    page  = (adr - (base_adr                   )) / FLASH_PAGE_SIZE;   
#endif

  /* unlock page command */
  EEFC->FCR = EEFC_FCR_FKEY | EEFC_FCR_FCMD_CLB | (EEFC_FCR_FARG & (page << 8));
  while (!(EEFC->FSR & EEFC_FSR_FRDY));

  /* set write pointer to Flash address */
  Flash = (unsigned long *)adr;

  /* copy data to write buffer */
  for (sz = (sz + 3) & ~3; sz; sz -= 4, buf += 4) {
    *Flash++ = *((unsigned long *)buf);
  }
  
  /* start programming command */
  EEFC->FCR = EEFC_FCR_FKEY | EEFC_FCR_FCMD_EWP | (EEFC_FCR_FARG & (page << 8));
  while (!(EEFC->FSR & EEFC_FSR_FRDY));

  /* check for errors */
  if (EEFC->FSR & (EEFC_FSR_FCMDE | EEFC_FSR_FLOCKE))
    return (1);

  return (0);
}
#endif

#ifdef FLASH_GPNVM
int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {
  u32           frr;
  u8            gpnvm;

  gpnvm = *buf;

  /* read current GPNVM bits */
  EEFC0->FCR = EEFC_FCR_FKEY | EEFC_FCR_FCMD_GGPB;
  while (!(EEFC0->FSR & EEFC_FSR_FRDY));
  frr = EEFC0->FRR;

  /* configure GPNVM bit #0 : Security bit */
  if ((gpnvm & (1 << GPNVM_BIT0)) != (frr & (1 << GPNVM_BIT0))) {
    if (gpnvm & (1 << GPNVM_BIT0))
      EEFC0->FCR = EEFC_FCR_FKEY | (GPNVM_BIT0 << 8) | EEFC_FCR_FCMD_SGPB; 
    else
      EEFC0->FCR = EEFC_FCR_FKEY | (GPNVM_BIT0 << 8) | EEFC_FCR_FCMD_CGPB;

    /* Wait until the end of Command */
    while (!(EEFC0->FSR & EEFC_FSR_FRDY));
  }

  /* configure GPNVM bit #1 : Boot mode selection  0 = Boot from ROM,    1 = Boot from Flash  */
  if ((gpnvm & (1 << GPNVM_BIT1)) != (frr & (1 << GPNVM_BIT1))) {
    if (gpnvm & (1 << GPNVM_BIT1))
      EEFC0->FCR = EEFC_FCR_FKEY | (GPNVM_BIT1 << 8) | EEFC_FCR_FCMD_SGPB; 
    else
      EEFC0->FCR = EEFC_FCR_FKEY | (GPNVM_BIT1 << 8) | EEFC_FCR_FCMD_CGPB;

    /* Wait until the end of Command */
    while (!(EEFC0->FSR & EEFC_FSR_FRDY));
  }

  /* configure GPNVM bit #2 : Flash selection      0 = Boot from Flash0, 1 = Boot from Flash1 */
  if ((gpnvm & (1 << GPNVM_BIT2)) != (frr & (1 << GPNVM_BIT2))) {
    if (gpnvm & (1 << GPNVM_BIT2))
      EEFC0->FCR = EEFC_FCR_FKEY | (GPNVM_BIT2 << 8) | EEFC_FCR_FCMD_SGPB; 
    else
      EEFC0->FCR = EEFC_FCR_FKEY | (GPNVM_BIT2 << 8) | EEFC_FCR_FCMD_CGPB;

    /* Wait until the end of Command */
    while (!(EEFC0->FSR & EEFC_FSR_FRDY));
}

  return (0);
}
#endif

/*  
 *  Verify Flash Contents
 *    Parameter:      adr:  Start Address
 *                    sz:   Size (in bytes)
 *                    buf:  Data
 *    Return Value:   (adr+sz) - OK, Failed Address
 */

#ifdef FLASH_GPNVM
unsigned long Verify (unsigned long adr, unsigned long sz, unsigned char *buf) {
  u32           frr;
  u8            gpnvm;

  gpnvm = *buf;

  /* read current GPNVM bits */
  EEFC0->FCR = EEFC_FCR_FKEY | EEFC_FCR_FCMD_GGPB;
  while (!(EEFC0->FSR & EEFC_FSR_FRDY));
  frr = EEFC0->FRR;

  /* check GPNVM bit #0 : Security bit */
  if ((gpnvm & (1 << GPNVM_BIT0)) != (frr & (1 << GPNVM_BIT0))) {
    return (adr + GPNVM_BIT0);
  }

  /* check GPNVM bit #1 : Boot mode selection */
  if ((gpnvm & (1 << GPNVM_BIT1)) != (frr & (1 << GPNVM_BIT1))) {
    return (adr + GPNVM_BIT1);
  }

  /* check GPNVM bit #2 : Flash selection */
  if ((gpnvm & (1 << GPNVM_BIT2)) != (frr & (1 << GPNVM_BIT2))) {
    return (adr + GPNVM_BIT2);
}

  return (adr + sz);
}
#endif


// --- Test --- Test --- Test --- Test ---
#ifdef FLASH_GPNVM
void rdGPNVM (u32 *gpnvm0, u32 *gpnvm1) {

  *gpnvm0 = 0;
  *gpnvm1 = 0;

  /* read current GPNVM bits */
  EEFC0->FCR = EEFC_FCR_FKEY | EEFC_FCR_FCMD_GGPB;
  while (!(EEFC0->FSR & EEFC_FSR_FRDY));
  *gpnvm0 = EEFC0->FRR;

#if defined EEFC1_BASE
  /* read current GPNVM bits */
  EEFC1->FCR = EEFC_FCR_FKEY | EEFC_FCR_FCMD_GGPB;
  while (!(EEFC1->FSR & EEFC_FSR_FRDY));
  *gpnvm1 = EEFC1->FRR;
#endif
}
#endif
