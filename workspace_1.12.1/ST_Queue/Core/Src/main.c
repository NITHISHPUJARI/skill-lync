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
#include <stdio.h>
#include <string.h>
#include<stdint.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"



/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
QueueHandle_t St_Queue;

TaskHandle_t Sender1, Sender2, Receiver;
//SemaphoreHandle_t sem;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */
void Sender1_Task (void *p);
void Sender2_Task (void *p);
void Receiver_Task (void *p);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
typedef struct{
	char *str;
	int counter;
	uint16_t large_value;
} my_struct;

int indx1 = 0;
int indx2 = 0;

void Sender1_Task (void *p)
{
	my_struct *ptrtostruct;
	uint32_t TickDelay = pdMS_TO_TICKS (2000);

while (1)
{
	char *str = "\r\nEntered SENDERI1_Task\r\nSEND to the queue\r\n";
	HAL_UART_Transmit (&huart2, (uint8_t *)str, strlen (str), HAL_MAX_DELAY);

/****** ALOOCATE MEMORY TO THE pER ********/
	ptrtostruct = pvPortMalloc(sizeof (my_struct) );
/********** LOAD THE DATA ******/
ptrtostruct -> counter = 1+indx1;
ptrtostruct -> large_value = 1000 + indx1*100;
ptrtostruct -> str = "HELLO FROM SENDER \r\n";


/***** send to the queue ****/
if (xQueueSend (St_Queue, &ptrtostruct, portMAX_DELAY) == pdPASS)
{
	char *str2 = " Successfully sent to the queue\r\nLeaving SENDER1\r\n\n";
	HAL_UART_Transmit (&huart2, (uint8_t *)str2, strlen (str2), HAL_MAX_DELAY);
}
indx1 = indx1+1;

vTaskDelay (TickDelay);
}
}


void Sender2_Task (void *p)
{
	my_struct *ptrtostruct;
	uint32_t TickDelay = pdMS_TO_TICKS (2000);

while (1)
{
	char *str = "\r\nEntered SENDER2_Task\r\nSEND to the queue\r\n";
	HAL_UART_Transmit (&huart2, (uint8_t *)str, strlen (str), HAL_MAX_DELAY);

/****** ALOOCATE MEMORY TO THE pER ********/
	ptrtostruct = pvPortMalloc(sizeof (my_struct) );
/********** LOAD THE DATA ******/
ptrtostruct -> counter = 1+indx2;
ptrtostruct -> large_value = 2000 + indx2*200;
ptrtostruct -> str = "SENDER2 says hello!!! \r\n";


/***** send to the queue ****/
if (xQueueSend (St_Queue, &ptrtostruct, portMAX_DELAY) == pdPASS)
{
	char *str2 = " Successfully sent to the queue\r\nLeaving SENDER2\r\n\n";
	HAL_UART_Transmit (&huart2, (uint8_t *)str2, strlen (str2), HAL_MAX_DELAY);
}
indx2 = indx2+1;

vTaskDelay (TickDelay);
}
}


void Receiver_Task (void *p)
{

	my_struct *Rptrtostruct;
	uint32_t TickDelay = pdMS_TO_TICKS(1000);
	char *ptr;

	while (1)
	{
		char *str = "Entered RECEIVER Task\r\nRECEIVING from the queue\r\n\n";
		HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen (str), HAL_MAX_DELAY);

		/** RECEIVE FROM QUEUE ***/
		if (xQueueReceive(St_Queue, &Rptrtostruct, portMAX_DELAY) == pdPASS)
		{
			ptr = pvPortMalloc(1000 * sizeof (char)); // allocate memory for the string

			sprintf (ptr, "Received from QUEUE:\r\n COUNTER = %d\r\n LARGE VALUE = %u\r\n STRING = %s\r\n\n",Rptrtostruct->counter,Rptrtostruct->large_value, Rptrtostruct->str);
			HAL_UART_Transmit(&huart2, (uint8_t *)ptr, strlen(ptr), HAL_MAX_DELAY);

			vPortFree(ptr);  // free the string memory
		}

		vPortFree(Rptrtostruct);  // free the structure memory

		vTaskDelay(TickDelay);


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
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  //sem = xSemaphoreCreateBinary();
  St_Queue = xQueueCreate(2, sizeof(my_struct));

  if (St_Queue == 0)
  {
	  char *str = "Unable to create STRUCTURE Queue \r\n\n";
	  HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen (str), HAL_MAX_DELAY);

  }
  else
  {
	  char *str = "STRUCTURE QUEUE Create Successfully\r\n\n";
	  HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen (str), HAL_MAX_DELAY);
  }


  xTaskCreate(Sender1_Task, "SENDER1", 128, NULL, 2, &Sender1);
  xTaskCreate(Sender2_Task, "SENDER1", 128, NULL, 3, &Sender2);
  xTaskCreate(Receiver_Task, "RECEIVER", 128, NULL, 1, &Receiver);


  vTaskStartScheduler();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
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
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart2, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart2, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM3 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM3) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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
