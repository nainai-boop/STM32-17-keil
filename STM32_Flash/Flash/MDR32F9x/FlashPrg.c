/***********************************************************************/
/* This file is part of the uVision/ARM development tools              */
/* Copyright (c) 2006-2011 Keil Software. All rights reserved.         */
/***********************************************************************/
/*                                                                     */
/* FlashPrg.c: Flash Programming Functions adapted for                 */
/*             Milandr MDR32F9x Flash using Flash Boot Loader with IAP */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"                      // FlashOS Structures

typedef volatile unsigned long    vu32;
typedef          unsigned long     u32;

#define M32(adr) (*((vu32 *) (adr)))

// Peripheral Memory Map
#define FMC_BASE            (0x40018000)     // EEPROM Control
#define CLK_BASE            (0x40020000)     // Reset and clock control
#define BKP_BASE            (0x400D8000)     // Backup control

#define FMC                 ((EEPROM_TypeDef  *) FMC_BASE)
#define CLK                 ((RST_CLK_TypeDef *) CLK_BASE)
#define BKP                 ((BKP_TypeDef     *) BKP_BASE)

#define ICER0               (*((vu32 *) 0xE000E180))

// MDR_EEPROM_TypeDef structure */
typedef struct
{
  vu32 CMD;
  vu32 ADR;
  vu32 DI;
  vu32 DO;
  vu32 KEY;
} EEPROM_TypeDef;


// MDR_RST_CLK_TypeDef structure
typedef struct
{
  vu32 CLOCK_STATUS;
  vu32 PLL_CONTROL;
  vu32 HS_CONTROL;
  vu32 CPU_CLOCK;
  vu32 USB_CLOCK;
  vu32 ADC_MCO_CLOCK;
  vu32 RTC_CLOCK;
  vu32 PER_CLOCK;
  vu32 CAN_CLOCK;
  vu32 TIM_CLOCK;
  vu32 UART_CLOCK;
  vu32 SSP_CLOCK;
} RST_CLK_TypeDef;


// MDR_BKP_TypeDef structure
typedef struct {
  vu32 REG[16];                              // REG[15] controls oscillators
  vu32 RTC_CNT;
  vu32 RTC_DIV;
  vu32 RTC_PRL;
  vu32 RTC_ALRM;
  vu32 RTC_CS;
} BKP_TypeDef;

// BKP REG_0F Register definitions
#define BKP_HSI_ON       (1UL << 22)        // HSI_CONTROL
#define BKP_HSI_RDY      (1UL << 23)        // HSI_STATUS

// Flash Key Register definitions
#define FL_KEY            0x8AAA5551

// Flash Control Register definitions
#define FL_CON            0x00000001
#define FL_WR             0x00000002
#define FL_RD             0x00000004
#define FL_DELAY0         0x00000008
#define FL_DELAY1         0x00000010
#define FL_DELAY2         0x00000020
#define FL_XE             0x00000040
#define FL_YE             0x00000080
#define FL_SE             0x00000100
#define FL_IFREN          0x00000200
#define FL_ERASE          0x00000400
#define FL_MAS1           0x00000800
#define FL_PROG           0x00001000
#define FL_NVSTR          0x00002000

#define STACK_SIZE         64                // Stack Size

/* 
 *  Program delay.
 *    Parameter:      num: Number of the loops.
 *    Return Value:   None.
 */
  
static void Delay(unsigned long num) {
  volatile unsigned long i = num*8;

  for (; i > 0; i--) __nop();
}


/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int Init (unsigned long adr, unsigned long clk, unsigned long fnc) {

  CLK->PER_CLOCK = 0xFFFFFFFF;                   /* Enable all              */ 
  ICER0          = 0xFFFFFFFF;                   /* Disable all interrupts  */

  BKP->REG[15]  = BKP_HSI_ON;
  while (!(BKP->REG[15] & BKP_HSI_RDY)) {}       /* Wait Ready from HSI     */

  CLK->CPU_CLOCK = 0x00000000;                   /* CPU_CLOCK from HSI      */
  Delay(10);

  return (0);                                    /* Finished without Errors */
}


/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int UnInit (unsigned long fnc) {

  CLK->PER_CLOCK = 0xFFFFFFFF;
  FMC->CMD       = 0x0;

  return (0);                                    /* Finished without Errors */
}


/*
 *  Erase complete Flash Memory
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseChip (void) {
  int i;

  FMC->CMD |=  (FL_CON);
  FMC->KEY  =  (FL_KEY);

  for (i = 0; i < 4; i++) {
    FMC->ADR = i*4;
    FMC->DI  = 0;

    FMC->CMD |=  (FL_WR);
    FMC->CMD &= ~(FL_WR);
    FMC->CMD |=  (FL_XE | FL_MAS1 | FL_ERASE);  
    Delay(5);                                    /* Wait for   5 us         */
    FMC->CMD |=  (FL_NVSTR);
    Delay(40000);                                /* Wait for  40 ms         */
    FMC->CMD &= ~(FL_ERASE);
    Delay(100);                                  /* Wait for 100 us         */
    FMC->CMD &= ~(FL_NVSTR | FL_XE | FL_MAS1); 
  }

  FMC->CMD &= ~(FL_CON);
  FMC->KEY  =   0;   
  Delay(1);                                      /* Wait for 1 us */  

  return (0);                                    /* Finished without Errors */
}


/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseSector (unsigned long adr) {
  int i;

  FMC->CMD |=  (FL_CON);
  FMC->KEY  =  (FL_KEY);
  FMC->DI   =   0;

  for (i = 0; i < 4; i++) {
    FMC->ADR = adr + i*4;

    FMC->CMD |=  (FL_XE | FL_ERASE);
    Delay(5);                                    /* Wait for   5 us         */
    FMC->CMD |=  (FL_NVSTR);
    Delay(200);                                  /* Wait for 200 us         */
    FMC->CMD &= ~(FL_ERASE); 
    Delay(100);                                  /* Wait for 100 us         */
    FMC->CMD &= ~(FL_NVSTR | FL_XE ); 
  }

  FMC->CMD &= ~(FL_CON);
  FMC->KEY  =   0;    
  Delay(1);                                      /* Wait for 1 us */  

  return (0);                                    /* Finished without Errors */
}


/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */

int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {

  sz = (sz + 3) & ~3;                            /* Adjust size for Words   */

  FMC->KEY  =  (FL_KEY);
  FMC->CMD |=  (FL_CON);

  while (sz) {
    FMC->ADR  = adr;
    Delay(10);                                   /* Wait for  10 us         */
    FMC->CMD |=  (FL_PROG | FL_XE);
    Delay(5);                                    /* Wait for   5 us         */
    FMC->CMD |=  (FL_NVSTR);
    FMC->DI   =  *((u32 *)buf);
    FMC->CMD |=  (FL_WR);
    FMC->CMD &= ~(FL_WR);
    Delay(15);                                   /* Wait for  15 us         */
    FMC->CMD |=  (FL_YE);
    Delay(50);                                   /* Wait for  50 us         */
    FMC->CMD &= ~(FL_YE);
    FMC->CMD &= ~(FL_PROG);
    Delay(5);                                    /* Wait for   5 us         */
    FMC->CMD &= ~(FL_NVSTR | FL_XE);
    Delay(5);                                    /* Wait for   5 us         */

    adr += 4;                                    /* Go to next Word         */
    buf += 4;
    sz  -= 4;
  }

  FMC->CMD &= ~(FL_CON);
  FMC->KEY  =   0;
  Delay(1);                                      /* Wait for 1 us */  

  return (0);                                    /* Finished without Errors */
}
