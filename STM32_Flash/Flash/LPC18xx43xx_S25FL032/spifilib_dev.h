/*
 * @brief LPCSPIFILIB FLASH library device specific functions
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2014
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licenser disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#ifndef __SPIFILIB_DEV_H_
#define __SPIFILIB_DEV_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Define for inline functions */
#ifndef INLINE
#ifdef __CC_ARM
#define INLINE  __inline
#else
#define INLINE inline
#endif /* __CC_ARM */
#endif /* !INLINE */

/** @defgroup LPCSPIFILIB_DEV LPCSPIFILIB device driver API functions
 * @ingroup LPCSPIFILIB
 * @{
 */
/**
 * @brief Possible error codes that can be returned from functions
 */
typedef enum {
	SPIFI_ERR_NONE = 0,							/**< No error */
	SPIFI_ERR_BUSY,									/**< Device is busy */
	SPIFI_ERR_GEN,									/**< General error */
	SPIFI_ERR_NOTSUPPORTED,					/**< Capability not supported */
	SPIFI_ERR_ALIGNERR,							/**< Attempted to do an operation on an unaligned section of the device */
	SPIFI_ERR_LOCKED,								/**< Device was locked and a program/erase operation was attempted */
	SPIFI_ERR_PROGERR,							/**< Error programming device (blocking mode only) */
	SPIFI_ERR_ERASEERR,							/**< Erase error (blocking mode only) */
	SPIFI_ERR_NOTBLANK,							/**< Program operation on block that is not blank */
	SPIFI_ERR_PAGESIZE,							/**< PageProgram write size exceeds page size */
	SPIFI_ERR_VAL,									/**< Program operation failed validation or readback compare */
	SPIFI_ERR_RANGE,								/**< Range error, bad block number, address out of range, etc. */
	SPIFI_ERR_MEMMODE,							/**< Library calls not allowed while in memory mode. */
	SPIFI_ERR_LASTINDEX
    
} SPIFI_ERR_T;

/**
 * @brief Possible device capabilities returned from getInfo()
 */
#define SPIFI_CAP_QUAD_READ         (1 << 0)		/**< Supports QUAD read mode */
#define SPIFI_CAP_QUAD_WRITE        (1 << 1)        /**< Supports QUAD write mode */
#define SPIFI_CAP_QUAD_READWRITE    (SPIFI_CAP_QUAD_READ | SPIFI_CAP_QUAD_WRITE) /**< Supports QUAD read and write */
#define SPIFI_CAP_FULLLOCK          (1 << 2)		/**< Full device lock supported */
#define SPIFI_CAP_BLOCKLOCK         (1 << 3)		/**< Individual block device lock supported */
#define SPIFI_CAP_SUBBLKERASE       (1 << 4)		/**< Sub-block erase supported */
#define SPIFI_CAP_NOBLOCK           (1 << 16)		/**< Non-blocking mode supported */

/**
 * @brief Possible driver options, may not be supported by all drivers
 */
#define SPIFI_OPT_USE_QUAD      SPIFI_CAP_QUAD_READWRITE	/**< Enables QUAD read / write if option is enabled */
#define SPIFI_OPT_NOBLOCK       SPIFI_CAP_NOBLOCK	        /**< Will not block on program and erase operations, poll device status manually */

/**
 * @brief Possible device statuses returned from getInfo()
 */
#define SPIFI_STAT_BUSY     (1 << 0)			/**< Device is busy erasing or programming */
#define SPIFI_STAT_ISWP     (1 << 1)			/**< Device is write protected (software or hardware) */
#define SPIFI_STAT_FULLLOCK (1 << 2)			/**< Device is fully locked */
#define SPIFI_STAT_PARTLOCK (1 << 3)			/**< Device is partially locked (device specific) */
#define SPIFI_STAT_PROGERR  (1 << 4)			/**< Device status shows a program error (non-blocking mode only) */
#define SPIFI_STAT_ERASEERR (1 << 5)			/**< Device status shows a erase error (non-blocking mode only) */

/**
 * @brief Possible info lookup requests
 */
typedef enum {
	SPIFI_INFO_DEVSIZE = 0,						/**< Device size in Bytes */
	SPIFI_INFO_ERASE_BLOCKS,					/**< Number of erase blocks */
	SPIFI_INFO_ERASE_BLOCKSIZE,					/**< Size of erase blocks */
	SPIFI_INFO_ERASE_SUBBLOCKS,					/**< Number of erase sub-blocks */
	SPIFI_INFO_ERASE_SUBBLOCKSIZE,				/**< Size of erase sub-blocks */
	SPIFI_INFO_PAGESIZE,						/**< Size of a page, page write size limit */
	SPIFI_INFO_MAXREADSIZE,						/**< Maximum read size, read size limit in bytes */
	SPIFI_INFO_MAXCLOCK,						/**< Maximum device speed in Hz */
    SPIFI_INFO_MAX_READ_CLOCK,                  /**< Maximum device speed for read cmd in Hz */
    SPIFI_INFO_MAX_QUADREAD_CLOCK,              /**< Maximum device speed for quad read cmd in Hz */
    SPIFI_INFO_MAX_PROG_CLOCK,                  /**< Maximum device speed for program cmd in Hz */
    SPIFI_INFO_MAX_QUADPROG_CLOCK,              /**< Maximum device spped for quad program cmd in Hz */
	SPIFI_INFO_CAPS,							/**< Device capabilities, OR'ed SPIFI_CAP_* values */
	SPIFI_INFO_STATUS,							/**< Or'ed SPIFI_STAT_xxx values. Any persistint hardware bits will be cleared  */
    SPIFI_INFO_STATUS_RETAIN,                   /**< Or'ed SPIFI_STAT_xxx values. Any persistint hardware bits will be retained */
	SPIFI_INFO_OPTIONS,							/**< Device capabilities, Or'ed SPIFI_OPT_* values */
    SPIFI_INFO_LASTINDEX
} SPIFI_INFO_ID_T;

/**
 * @brief Possible device specific lock / un-lock commands
 */
typedef enum {
	SPIFI_PCMD_UNLOCK_DEVICE = 0,			/**< unlock device */
	SPIFI_PCMD_LOCK_DEVICE,					/**< lock device */
	SPIFI_PCMD_UNLOCK_BLOCK,				/**< unlock specified block */
	SPIFI_PCMD_LOCK_BLOCK					/**< lock specified block */

} SPIFI_PCMD_LOCK_UNLOCK_T;

/**
 * @brief Possible device specific sub-block commands
 */
typedef enum {
	SPIFI_PCMD_ADDR_TO_SUB_BLOCK = 0,			/**< Convert address to a sub-block */
	SPIFI_PCMD_SUB_BLOCK_TO_ADDR,				/**< Convert sub-block to address */
	SPIFI_PCMD_BLOCK_TO_SUB_BLOCK				/**< Convert block to sub-block */

} SPIFI_PCMD_SUBBLK_T;


/* Forward type declaration */
struct SPIFI_HANDLE;
struct SPIFI_DEVICE_DATA;
struct SPIFI_FAM_DESC;
struct SPIFI_DEVICE_ID;

/**
 * @brief LPCSPIFILIB family data.
 */
typedef struct SPIFI_FAM_NODE {
	const struct SPIFI_FAM_DESC *pDesc;					/**< Pointer to device descriptor */
	struct SPIFI_FAM_NODE *pNext;						/**< Reserved list pointer */

} SPIFI_FAM_NODE_T;

/**
 * @brief LPCSPIFILIB family descriptor, used to describe devices to non-device specific functions
 */
typedef struct SPIFI_FAM_DESC {
	const char              *pFamName;						/**< (required) Pointer to generic family name */
	struct SPIFI_DEV_NODE   *pDevList;						/**< (required) Pointer to device list */
	uint32_t                prvContextSize;				/**< Number of bytes needed for driver context allocation */
    uint32_t                *pDevCount;                      /**< (required) Pointer to device count */
	void (*pPrvDevGetID)(uint32_t baseAddr, struct SPIFI_DEVICE_ID *pID);                              /**< (NULL allowed) Pointer to method that querries deviceID */
	SPIFI_ERR_T (*pPrvDevSetup)(struct SPIFI_HANDLE *pHandle, uint32_t spifiCtrlAddr, uint32_t baseAddr);	/**< (required) Pointer to device specific device initialization */

} SPIFI_FAM_DESC_T;

/**
 * @brief Register device data node
 */
typedef struct SPIFI_DEV_NODE {
	const struct SPIFI_DEVICE_DATA *pDevData;	/**< (required) Pointer to device specific data */
	struct SPIFI_DEV_NODE *pNext;			    /**< Reserved */

} SPIFI_DEV_NODE_T;


/**
 * @brief Device specific function pointers
 */
typedef struct SPIFI_FAM_FX {
	/* Device init and de-initialization */

	SPIFI_ERR_T (*lockCmd)(const struct SPIFI_HANDLE *, SPIFI_PCMD_LOCK_UNLOCK_T, uint32_t);	/**< (required) Lock / unlock handler */

	SPIFI_ERR_T (*eraseAll)(const struct SPIFI_HANDLE *);										/**< (required) Full device erase */

	SPIFI_ERR_T (*eraseBlock)(const struct SPIFI_HANDLE *, uint32_t);							/**< (required) Erase a block by block number */

	SPIFI_ERR_T (*eraseSubBlock)(const struct SPIFI_HANDLE *, uint32_t);						/**< (reauired) Erase a sub-block by block number */

	SPIFI_ERR_T (*pageProgram)(const struct SPIFI_HANDLE *, uint32_t, const uint32_t *, uint32_t);	/**< (required) Program up to a page of data at an address */

	SPIFI_ERR_T (*read)(const struct SPIFI_HANDLE *, uint32_t, uint32_t *, uint32_t);			/**< (required) Read an address range */

	SPIFI_ERR_T (*setOpts)(const struct SPIFI_HANDLE *, uint32_t, uint8_t);					/**< (NULL allowed) Set or Unset driver options */

	SPIFI_ERR_T (*reset)(const struct SPIFI_HANDLE *);										/**< (required) Reset SPIFI device */

	/* Info query functions */
	uint32_t (*getStatus)(const struct SPIFI_HANDLE *, uint8_t);								/**< (required) Returns device status */

	uint32_t (*subBlockCmd)(const struct SPIFI_HANDLE *, SPIFI_PCMD_SUBBLK_T, uint32_t);		/**< (NULL allowed) Performs specified cmd */
} SPIFI_FAM_FX_T;

/**
 * @brief Device identification data
 */
typedef struct SPIFI_DEVICE_ID {
	uint8_t mfgId[3];							/**< JEDEC ID data */
	uint8_t extCount;							/**< Number of extended bytes to check */
	uint8_t extId[8];							/**< extended data */
} SPIFI_DEVICE_ID_T;

/**
 * @brief Register device data.
 */
typedef struct SPIFI_DEVICE_DATA {
	const char *pDevName;						/**< (required) Device friendly name */
	SPIFI_DEVICE_ID_T id;						/**< Device id structure */
    uint32_t caps;								/**< capabilities supported */
	uint16_t blks;								/**< # of blocks */
	uint32_t blkSize;							/**< size of block */
	uint16_t subBlks;							/**< # of sub-blocks */
	uint16_t subBlkSize;						/**< size of sub-block */
	uint16_t pageSize;							/**< page size */
	uint32_t maxReadSize;						/**< max read allowed in one operation */
	uint32_t maxClkRate;						/**< maximum clock rate (max common speed) */
    uint32_t maxReadRate;                       /**< max clock rate for read (driver may utilize fast read) */
    uint32_t maxQuadReadRate;                   /**< max clock rate for quad read */
    uint32_t maxProgramRate;                    /**< max clock rate for program */
    uint32_t maxQuadProgramRate;                /**< max clock rate for quad program */
    SPIFI_ERR_T (*prvInitDeInit)(const struct SPIFI_HANDLE *, uint32_t);  /**< (NULL allowed) Fx* to Init / DeInit */
    void (*prvClearStatus)(const struct SPIFI_HANDLE *);                  /**< (NULL allowed) Fx* to clear status */
	uint32_t (*prvGetStatus)(const struct SPIFI_HANDLE *);	            /**< (required) Fx* to get status */
    void (*prvSetStatus)(const struct SPIFI_HANDLE *, uint32_t);          /**< (required) Fx* to set status */
    void (*prvSetQuadMode)(const struct SPIFI_HANDLE *, uint32_t);        /**< (required) Fx* to set quad mode */
    void (*prvGetMemModeCmd)(const struct SPIFI_HANDLE *, uint8_t, uint32_t *, uint32_t *);	  /**< (NULL allowed) Returns memoryMode cmd */
    
} SPIFI_DEVICE_DATA_T;

/**
 * @brief LPCSPIFILIB device handle, used with all device and info functions
 */
typedef struct SPIFI_HANDLE {
	const struct SPIFI_FAM_FX *pFamFx;	        /**< (required) Pointer to device specific functions */
	struct SPIFI_INFODATA   *pInfoData;			/**< (required) Pointer to info data area */
	void                    *pDevContext;		/**< (NULL allowed) Pointer to device context (used by device functions) */
} SPIFI_HANDLE_T;

/**
 * @brief Common data applicable to all devices
 */
typedef struct SPIFI_INFODATA {
	uint32_t        spifiCtrlAddr;				/**< SPIFI controller base address */
	uint32_t        baseAddr;					/**< Physical base address for the device */
	uint32_t        numBlocks;					/**< Number of blocks on the device */
	uint32_t        blockSize;					/**< Size of blocks on the device */
	uint32_t        numSubBlocks;				/**< Number of sub-blocks on the device */
	uint32_t        subBlockSize;				/**< Size of sub-blocks on the device */
	uint32_t        pageSize;					/**< Size of a page, usually denotes maximum write size in bytes for a single write operation */
	uint32_t        maxReadSize;				/**< Maximum read size in bytes for a single read operation */
    const struct SPIFI_DEVICE_DATA *pDeviceData;  /**< (required) Pointer to device specific data */
	uint32_t        opts;						/**< Device options of values SPIFI_OPT_* */
	const char      *pDevName;					/**< (required) Pointer to device name */
	SPIFI_ERR_T     lastErr;					/**< Last error for the driver */
	const SPIFI_DEVICE_ID_T *pId;				/**< (required) Device id structure (JEDEC ID etc) */
} SPIFI_INFODATA_T;

/**
 * @}
 */

/** @defgroup LPCSPIFILIB_REGISTERHELPER LPCSPIFILIB family registration functions
 * @ingroup LPCSPIFILIB
 * @{
 */

/**
 * @brief	Family registration function
 * @return	A pointer to a persistent SPIFI_DEV_FAMILY_T initialized for family.
 * @note	This function constructs and returns a non-volitile SPIFI_DEV_FAMILY_T
 * structure that contains family specific information needed to register family.
 * This function MUST NOT be called directly and should only be passed to the
 * registration function spifiRegisterFamily()
 */
SPIFI_FAM_NODE_T *spifi_REG_FAMILY_CommonCommandSet(void);

/**
 * @brief SPIFI_REG_FAMILY_Spansion_2Byte_PStatus Depricated! Do NOT use for new development
 */
#define SPIFI_REG_FAMILY_Spansion_2Byte_PStatus spifi_REG_FAMILY_CommonCommandSet

/**
 * @brief SPIFI_REG_FAMILY_Spansion_3Byte_Status Depricated! Do NOT use for new development
 */
#define SPIFI_REG_FAMILY_Spansion_3Byte_Status spifi_REG_FAMILY_CommonCommandSet

/**
 * @brief SPIFI_REG_FAMILY_Macronix_2Byte_Status Depricated! Do NOT use for new development
 */
#define SPIFI_REG_FAMILY_Macronix_2Byte_Status spifi_REG_FAMILY_CommonCommandSet

/**
 * @brief SPIFI_REG_FAMILY_SpansionS25FLP Depricated! Do NOT use for new development
 */
#define SPIFI_REG_FAMILY_SpansionS25FLP spifi_REG_FAMILY_CommonCommandSet

/**
 * @brief SPIFI_REG_FAMILY_SpansionS25FL1 Depricated! Do NOT use for new development
 */
#define SPIFI_REG_FAMILY_SpansionS25FL1 spifi_REG_FAMILY_CommonCommandSet 

/**
 * @brief SPIFI_REG_FAMILY_MacronixMX25L Depricated! Do NOT use for new development
 */
#define SPIFI_REG_FAMILY_MacronixMX25L spifi_REG_FAMILY_CommonCommandSet


/**
 * @}
 */
#ifdef __cplusplus
}
#endif

#endif /* __SPIFILIB_DEV_H_ */
