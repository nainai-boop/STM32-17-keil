/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright KEIL ELEKTRONIK GmbH 2003 - 2008                         */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Flash Programming Functions adapted                   */
/*               for EFM32 Gecko/Tiny device series                    */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        /* FlashOS Structures */
#include "em_device.h"
#include "em_msc.h"

/* Gecko and Tiny have 512 bytes flash page size */
#define FLASH_PAGE_SIZE      512
#define FLASH_PAGE_MASK      (~(FLASH_PAGE_SIZE-1))

#define MIN(a, b) ((a) < (b) ? (a) : (b))

/* The size of the flash in the device */
uint32_t flashSize;

static msc_Return_TypeDef MscStatusWait( uint32_t mask, uint32_t value )
{
  uint32_t status;
  int timeOut = MSC_PROGRAM_TIMEOUT;

  while (1)
  {
    status = MSC->STATUS;

    if ( status &
         ( MSC_STATUS_LOCKED | MSC_STATUS_INVADDR | MSC_STATUS_WORDTIMEOUT ) )
    {
      MSC->WRITECTRL &= ~MSC_WRITECTRL_WREN;

      if ( status & MSC_STATUS_LOCKED )
        return mscReturnLocked;

      if ( status & MSC_STATUS_INVADDR )
        return mscReturnInvalidAddr;

      return mscReturnTimeOut;
    }

    if ( ( status & mask ) == value )
      return mscReturnOk;

    timeOut--;
    if ( timeOut == 0 )
      break;
  }
  return mscReturnTimeOut;
}

static msc_Return_TypeDef DoFlashCmd( uint32_t cmd )
{
  MSC->WRITECMD = cmd;
  return MscStatusWait( MSC_STATUS_BUSY, 0 );
}

static msc_Return_TypeDef PgmBurst( uint32_t addr, uint32_t *p, uint32_t cnt )
{
  msc_Return_TypeDef retVal;

  if ( (retVal = MscStatusWait( MSC_STATUS_BUSY, 0 )) != mscReturnOk )
    return retVal;

  MSC->ADDRB    = addr;
  MSC->WRITECMD = MSC_WRITECMD_LADDRIM;
  MSC->WDATA    = *p++;
  MSC->WRITECMD = MSC_WRITECMD_WRITEONCE;
  cnt          -= 4;

  while ( cnt )
  {
    if ( (retVal = MscStatusWait( MSC_STATUS_WDATAREADY, MSC_STATUS_WDATAREADY )) != mscReturnOk )
      return retVal;

    MSC->WDATA = *p++;
    cnt       -= 4;
  }
  return mscReturnOk;
}

/*****************************************************************************
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 ****************************************************************************/
int Init(unsigned long adr, unsigned long clk, unsigned long fnc)
{
  uint32_t sramSize;

  /* Unlock the MSC */
  MSC->LOCK = MSC_UNLOCK_CODE;

  /* Read memory sizes from the Device Information Page */
  flashSize = (DEVINFO->MSIZE & _DEVINFO_MSIZE_FLASH_MASK)
              >> _DEVINFO_MSIZE_FLASH_SHIFT;
  sramSize  = (DEVINFO->MSIZE & _DEVINFO_MSIZE_SRAM_MASK)
              >> _DEVINFO_MSIZE_SRAM_SHIFT;

  /* Some very early samples had SRAM/Flash fields interchanged */
  if ( sramSize > flashSize )
  {
    flashSize = sramSize;
  }
  /* Convert to Bytes */
  flashSize = flashSize << 10;

  return 0;
}


/*****************************************************************************
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 ****************************************************************************/
int UnInit(unsigned long fnc)
{
  /* Disable write in MSC */
  MSC->WRITECTRL &= ~MSC_WRITECTRL_WREN;
  return 0;
}


/*****************************************************************************
 *  Erase complete Flash Memory
 *    Return Value:   0 - OK,  1 - Failed
 ****************************************************************************/
int EraseChip(void)
{
  uint32_t addr;

  for (addr = 0; addr < flashSize; addr += FLASH_PAGE_SIZE)
  {
    if (EraseSector(addr) != 0)
      return 1;
  }
  return 0;
}

/*****************************************************************************
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 ****************************************************************************/
int EraseSector(unsigned long adr)
{
  uint32_t            blank;
  msc_Return_TypeDef  result    = mscReturnOk;
  uint32_t            *p        = (uint32_t*)adr;
  uint32_t            pageSize  = FLASH_PAGE_SIZE;

  do
  {
    blank     = *p++;
    pageSize -= 4;
  } while ( pageSize && ( blank == 0xFFFFFFFF ) );

  if ( blank != 0xFFFFFFFF )
  {
    MSC->WRITECTRL |= MSC_WRITECTRL_WREN;
    MSC->ADDRB      = adr;
    MSC->WRITECMD   = MSC_WRITECMD_LADDRIM;
    result          = DoFlashCmd( MSC_WRITECMD_ERASEPAGE );
    MSC->WRITECTRL &= ~MSC_WRITECTRL_WREN;
  }

  return result == mscReturnOk ? 0 : 1;
}

/*****************************************************************************
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 ****************************************************************************/
int ProgramPage(unsigned long adr, unsigned long sz, unsigned char *buf)
{
  uint32_t burst;

  sz = (sz + 3) & ~3;                     /* Make sure we are modulo 4. */

  MSC->WRITECTRL |= MSC_WRITECTRL_WREN;

  while ( sz )
  {
    /* Max burst len is up to next flash page boundary. */
    burst = MIN( sz, ( ( adr + FLASH_PAGE_SIZE ) & FLASH_PAGE_MASK ) - adr );

    if ( PgmBurst( adr, (uint32_t*)buf, burst ) != mscReturnOk )
      return 1;

    buf += burst;
    adr += burst;
    sz  -= burst;
  }
  if ( MscStatusWait( MSC_STATUS_BUSY, 0 ) != mscReturnOk )
    return 1;

  MSC->WRITECTRL &= ~MSC_WRITECTRL_WREN;

  return 0;
}
