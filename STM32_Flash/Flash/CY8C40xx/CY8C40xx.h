//Registers
#define CPUSS_SYSREQ			0x40100004
#define CPUSS_SYSARG			0x40100008
#define CPUSS_PROTECTION	0x4010000C
#define TEST_MODE					0x40030014

//SFLASH Constants
#define SFLASH_CPUSS_WOUNDING   0x0FFFF140 //RAM/Flash wounding information

//Register masks
#define NO_RST_OVR			0x08000000

//SROM Constants (offset, masks, etc)
#define SRAM_PARAMS_BASE	0x20000100
#define SROM_KEY1           0xB6
#define SROM_KEY2           0xD3
#define SROM_SYSREQ_BIT     0x80000000
#define SROM_PRIVILEGED_BIT 	0x10000000
#define SROM_STATUS_SUCCEEDED 	0xA0000000 //Succeeded
#define SROM_STATUS_FAILED		0xF0000000 //Failed
#define SROM_SYSREQ_TIMEOUT 	200 //in ms units

//SROM Commands
#define SROM_CMD_GET_SILICON_ID				0x00
#define SROM_CMD_WRITE_NVL						0x01
#define SROM_CMD_REFRESH_NVL					0x02
#define SROM_CMD_READ_NVL							0x03
#define SROM_CMD_LOAD_LATCH						0x04
#define SROM_CMD_WRITE_ROW						0x05
#define SROM_CMD_PROGRAM_ROW					0x06
#define SROM_CMD_NB_WRITEROW					0x07
#define SROM_CMD_NB_PROGRAMROW				0x08
#define SROM_CMD_NB_RESUMECMD					0x09
#define SROM_CMD_ERASE_ALL						0x0A
#define SROM_CMD_CHECKSUM							0x0B
#define SROM_CMD_MARGIN_READFLASH			0x0C
#define SROM_CMD_WRITE_PROTECTION			0x0D
#define SROM_CMD_CONFIGURE_REGIONBULK	0x0E
#define SROM_CMD_SRAM_BIST 						0x0F
#define SROM_CMD_SET_IMO_48MHZ				0x15
