/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "math.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
uint8_t deviceid, statusvalue;
uint8_t buff_rx[24], buff_rx1[24], strt_add;
unsigned short dig_T1, dig_P1;
signed short dig_T2, dig_T3, dig_P2, dig_P3, dig_P4, dig_P5, dig_P6, dig_P7, dig_P8, dig_P9 ;


signed long temperature_raw, pressure_raw;
float temperature, pressure, altitude, init_height;

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define dev_addr 0xEE

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

/* USER CODE BEGIN PV */
uint8_t buff_tx[2], devname;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void I2C_DEVICE_Check (void)
{

buff_tx[0] = 0xD0;


HAL_I2C_Master_Transmit(&hi2c1, dev_addr, &buff_tx[0], 1, 10000);
HAL_I2C_Master_Receive(&hi2c1, dev_addr+1, &devname, 1, 10000);
}

void I2C_DEVICE_Init(void)
{
	buff_tx[0] = 0xF5;
	buff_tx[1] = 0x10;
	HAL_I2C_Master_Transmit(&hi2c1, dev_addr, &buff_tx[0], 2, 10000);

	buff_tx[0] = 0xF4;
	buff_tx[1] = 0x57;
	HAL_I2C_Master_Transmit(&hi2c1, dev_addr, &buff_tx[0], 2, 10000);
}

void I2C_DEVICE_cali (void)
{
	strt_add = 0x88;
	HAL_I2C_Master_Transmit(&hi2c1, dev_addr, &strt_add, 1, 10000);
	HAL_I2C_Master_Receive(&hi2c1, dev_addr+1, &buff_rx[0], 24, 10000);

	dig_T1 = ((buff_rx[1]<<8) + buff_rx[0]);
	dig_T2 = ((buff_rx[3]<<8) + buff_rx[2]);
	dig_T3 = ((buff_rx[5]<<8) + buff_rx[4]);
	dig_P1 = ((buff_rx[7]<<8) + buff_rx[6]);
	dig_P2 = ((buff_rx[9]<<8) + buff_rx[8]);
	dig_P3 = ((buff_rx[11]<<8) + buff_rx[10]);
	dig_P4 = ((buff_rx[13]<<8) + buff_rx[12]);
	dig_P5 = ((buff_rx[15]<<8) + buff_rx[14]);
	dig_P6 = ((buff_rx[17]<<8) + buff_rx[16]);
	dig_P7 = ((buff_rx[19]<<8) + buff_rx[18]);
	dig_P8 = ((buff_rx[21]<<8) + buff_rx[20]);
	dig_P9 = ((buff_rx[23]<<8) + buff_rx[22]);

}

void BMP280_calc_values(void)
{
uint8_t status;
strt_add=0xF7;

do
{
buff_tx[0] = 0xF3;

HAL_I2C_Master_Transmit(&hi2c1, dev_addr, &buff_tx[0], 1, 10000);
HAL_I2C_Master_Receive(&hi2c1, dev_addr + 1, &statusvalue, 1, 10000);

status=statusvalue;


}
while(((statusvalue&0x08)==8)||((status&0x01)==1));

HAL_I2C_Master_Transmit(&hi2c1, dev_addr, &strt_add, 1, 10000);
HAL_I2C_Master_Receive(&hi2c1, dev_addr + 1, &buff_rx1[0], 6, 10000);

volatile uint32_t temp[3];
temp[2]=buff_rx1[3];
temp[1]=buff_rx1[4];
temp[0]=buff_rx1[5];
temperature_raw= (temp[2]<<12)+(temp[1]<<4)+(temp[0]>>4);

temp[2]=buff_rx1[0];
temp[1]=buff_rx1[1];
temp[0]=buff_rx1[2];
pressure_raw=(temp[2]<<12)+(temp[1]<<4)+(temp[0]>>4);

double var1, var2;
var1=(((double)temperature_raw)/16384.0-((double)dig_T1)/1024.0)*((double)dig_T2);
var2=((((double)temperature_raw)/131072.0 - ((double)dig_T1)/8192.0)*(((double)temperature_raw)/131072.0-((double)dig_T1)/8192.0))*((double)dig_T3);
double t_fine = (int32_t)(var1+var2);
volatile float T = (var1+var2)/5120.0;

var1=((double)t_fine/2.0)-64000.0;
var2=var1*var1*((double)dig_P6)/32768.0;
var2=var2+var1*((double)dig_P5)*2.0;
var2=(var2/4.0)+(((double)dig_P4)*65536.0);
var1=(((double)dig_P3)*var1*var1/524288.0+((double)dig_P2)*var1)/524288.0;
var1=(1.0+var1/32768.0)*((double)dig_P1);
volatile double p=1048576.0-(double)pressure_raw;
p=(p-(var2/4096.0))*6250.0/var1;
var1=((double)dig_P9)*p*p/2147483648.0;
var2=p*((double)dig_P8)/32768.0;
p=p+(var1+var2+((double)dig_P7))/16.0;

//altitude=44330.0f*(1-powf(pressure/101325.0f,1.0f/5.255f)); //altitude=((powf(101325.0/pressure, 1/5.257f)-1)*(temperature+273.15f))/0.0065f;

p= p/133.322; // pa to mmHg conversion
temperature=T;
pressure=p;
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

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
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  I2C_DEVICE_Check();
  I2C_DEVICE_Init();
  I2C_DEVICE_cali ();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  HAL_Delay(500);
	  BMP280_calc_values();

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

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x00303D5B;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */