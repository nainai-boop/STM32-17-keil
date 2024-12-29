/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "fatfs.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "SDdriver.h"




/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#include "flash.h"
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
uint8_t FlashWBuff [255];
uint8_t FlashRBuff [255];
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int fputc(int ch, FILE *f)    
{
    HAL_UART_Transmit(&huart1, (unsigned char *)&ch, 1, 0xFFFF);   
    return ch;
}
uint16_t uart_value[3];
uint8_t aRxBuffer1;	//uart rx buff 





void WritetoSD(BYTE write_buff[],uint8_t bufSize);
char SD_FileName[] = "hello.txt";
uint8_t WriteBuffer[] = "01 write buff to sd \r\n";

//uint8_t test_sd =0;	//���ڲ��Ը�ʽ��
uint8_t write_cnt =0;	//дSD������




void WritetoSD(BYTE write_buff[],uint8_t bufSize)
{
	FATFS fs;
	FIL file;
	uint8_t res=0;
	UINT Bw;	
	
	res = SD_init();		//SD����ʼ��
	
	if(res == 1)
	{
		printf("SD����ʼ��ʧ��! \r\n");		
	}
	else
	{
		printf("SD����ʼ���ɹ��� \r\n");		
	}
	
	res=f_mount(&fs,"0:",1);		//����
	
//	if(test_sd == 0)		//���ڲ��Ը�ʽ��
	if(res == FR_NO_FILESYSTEM)		//û���ļ�ϵͳ����ʽ��
	{
//		test_sd =1;				//���ڲ��Ը�ʽ��
		printf("û���ļ�ϵͳ! \r\n");		
		res = f_mkfs("", 0, 0);		//��ʽ��sd��
		if(res == FR_OK)
		{
			printf("��ʽ���ɹ�! \r\n");		
			res = f_mount(NULL,"0:",1); 		//��ʽ������ȡ������
			res = f_mount(&fs,"0:",1);			//���¹���	
			if(res == FR_OK)
			{
				printf("SD���Ѿ��ɹ����أ����Խ������ļ�д�����!\r\n");
			}	
		}
		else
		{
			printf("��ʽ��ʧ��! \r\n");		
		}
	}
	else if(res == FR_OK)
	{
		printf("���سɹ�! \r\n");		
	}
	else
	{
		printf("����ʧ��! \r\n");
	}	
	
	res = f_open(&file,SD_FileName,FA_OPEN_ALWAYS |FA_WRITE);
	if((res & FR_DENIED) == FR_DENIED)
	{
		printf("���洢������д��ʧ��!\r\n");		
	}
	
	f_lseek(&file, f_size(&file));//ȷ��д��д�벻�Ḳ��֮ǰ������
	if(res == FR_OK)
	{
		printf("�򿪳ɹ�/�����ļ��ɹ��� \r\n");		
		res = f_write(&file,write_buff,bufSize,&Bw);		//д���ݵ�SD��
		if(res == FR_OK)
		{
			printf("�ļ�д��ɹ��� \r\n");			
		}
		else
		{
			printf("�ļ�д��ʧ�ܣ� \r\n");
		}		
	}
	else
	{
		printf("���ļ�ʧ��!\r\n");
	}	
	
	f_close(&file);						//�ر��ļ�		
	f_mount(NULL,"0:",1);		 //ȡ������
	
}


void Get_SDCard_Capacity(void)
{
	FRESULT result;
	FATFS FS;
	FATFS *fs;
	DWORD fre_clust,AvailableSize,UsedSize;  
	uint16_t TotalSpace;
	uint8_t res;
	
	res = SD_init();		//SD����ʼ��
	if(res == 1)
	{
		printf("SD����ʼ��ʧ��! \r\n");		
	}
	else
	{
		printf("SD����ʼ���ɹ��� \r\n");		
	}
	
	/* ���� */
	res=f_mount(&FS,"0:",1);		//����
	if (res != FR_OK)
	{
		printf("FileSystem Mounted Failed (%d)\r\n", result);
	}

	res = f_getfree("0:", &fre_clust, &fs);  /* ��Ŀ¼ */
	if ( res == FR_OK ) 
	{
		TotalSpace=(uint16_t)(((fs->n_fatent - 2) * fs->csize ) / 2 /1024);
		AvailableSize=(uint16_t)((fre_clust * fs->csize) / 2 /1024);
		UsedSize=TotalSpace-AvailableSize;              
		/* Print free space in unit of MB (assuming 512 bytes/sector) */
		printf("\r\n%d MB total drive space.\r\n""%d MB available.\r\n""%d MB  used.\r\n",TotalSpace, AvailableSize,UsedSize);
	}
	else 
	{
		printf("Get SDCard Capacity Failed (%d)\r\n", result);
	}		
} 


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  uint8_t i;
	uint8_t FlashTest[] = "Hello This is TM Flash Test DEMO";
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_FATFS_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
	
	HAL_UART_Receive_IT(&huart1,&aRxBuffer1,1); 	//enable uart	

	printf(" main \r\n");

	Get_SDCard_Capacity();	//�õ�ʹ���ڴ沢ѡ���ʽ��



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		
		
		
		WritetoSD(WriteBuffer,sizeof(WriteBuffer));		

		
		
		HAL_Delay(500);
		WriteBuffer[0] = WriteBuffer[0] +10;
		WriteBuffer[1] = WriteBuffer[1] +10;
		write_cnt ++;
		
		while(write_cnt > 10)
		{	
			printf(" while \r\n");
			HAL_Delay(500);
		}		
		
		
		
		
		
		
		
		
		
		
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
