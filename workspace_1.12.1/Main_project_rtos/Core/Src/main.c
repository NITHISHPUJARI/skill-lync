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
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"
#include "timers.h"

#include "lcd_i2c.h"  // Library for I2C LCD display

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define TRIGGER_PIN        GPIO_PIN_0
#define ECHO_PIN           GPIO_PIN_1
#define LEFT_IR_PIN        GPIO_PIN_2
#define RIGHT_IR_PIN       GPIO_PIN_3
#define MOTOR_ENA          GPIO_PIN_4
#define MOTOR_IN1          GPIO_PIN_5
#define MOTOR_IN2          GPIO_PIN_6
#define MOTOR_ENB          GPIO_PIN_7
#define MOTOR_IN3          GPIO_PIN_8
#define MOTOR_IN4          GPIO_PIN_9
#define BLUETOOTH_RX_PIN   GPIO_PIN_10
#define BLUETOOTH_TX_PIN   GPIO_PIN_11
#define RFID_RX_PIN        GPIO_PIN_12
#define RFID_TX_PIN        GPIO_PIN_13
#define LDR_PIN            GPIO_PIN_14
#define SWITCH_PIN         GPIO_PIN_13
#define I2C_SCL_PIN        GPIO_PIN_9
#define I2C_SDA_PIN        GPIO_PIN_10

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;

TIM_HandleTypeDef htim1;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
QueueHandle_t distanceQueue;
QueueHandle_t bluetoothQueue;
QueueHandle_t rfidQueue;
SemaphoreHandle_t ldrSemaphore;
TaskHandle_t lcdTaskHandle;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_I2C1_Init(void);
static void MX_I2C2_Init(void);
static void MX_TIM1_Init(void);
/* USER CODE BEGIN PFP */

typedef enum {
  IR_MODE,
  BLUETOOTH_MODE
} Mode;

Mode currentMode = IR_MODE;
uint32_t rfidData = 0;
char receivedChar = '\0';





void UltrasonicSensor_Task(void *pvParameters);
void ObstacleAvoidance_Task(void *pvParameters);
void LineController_Task(void *pvParameters);
void Bluetooth_Task(void *pvParameters);
void RFID_Task(void *pvParameters);
void LDRLight_Task(void *pvParameters);
void LCD_Task(void *pvParameters);


void UltrasonicSensor_Task(void *pvParameters)
{
  float distance;

  while (1)
  {
    // Measure distance using ultrasonic sensor
    // Trigger the sensor and calculate the time for echo
    // Calculate the distance based on the time and the speed of sound
    // Store the distance in a variable or queue

    xQueueSend(distanceQueue, &distance, portMAX_DELAY);

    vTaskDelay(pdMS_TO_TICKS(500)); // Adjust the delay based on your requirements
  }
}

void ObstacleAvoidance_Task(void *pvParameters)
{
  float distance;

  while (1)
  {
    // Check the distance measured by the ultrasonic sensor
    // If an obstacle is detected within a threshold distance, take appropriate action
    // For example, stop the motors, reverse, and turn in a different direction
    // You can control the motor driver using HAL_GPIO_WritePin to set GPIO outputs

    if (currentMode == IR_MODE)
    {
      xQueueReceive(distanceQueue, &distance, portMAX_DELAY);

      // Implement obstacle avoidance logic

      vTaskDelay(pdMS_TO_TICKS(100)); // Adjust the delay based on your requirements
    }
    else
    {
      // No obstacle avoidance needed in Bluetooth mode
      vTaskDelay(pdMS_TO_TICKS(100)); // Adjust the delay based on your requirements
    }
  }
}

void LineController_Task(void *pvParameters)
{
  while (1)
  {
    // Read the values from the IR sensors to detect the line
    // Based on the sensor readings, adjust the motor speed and direction to follow the line
    // You can control the motor driver using HAL_GPIO_WritePin to set GPIO outputs

    if (currentMode == IR_MODE)
    {
      // Implement line following logic

      vTaskDelay(pdMS_TO_TICKS(50)); // Adjust the delay based on your requirements
    }
    else
    {
      // No line following needed in Bluetooth mode
      vTaskDelay(pdMS_TO_TICKS(50)); // Adjust the delay based on your requirements
    }
  }
}

void Bluetooth_Task(void *pvParameters)
{
  while (1)
  {
    // Read data from Bluetooth module and process it
    // You can use UART or USART HAL functions to communicate with the Bluetooth module
    // Process the received data and take necessary actions
    // You can send data to other tasks using a queue or semaphore

    if (currentMode == BLUETOOTH_MODE)
    {
      // Implement Bluetooth processing logic

      vTaskDelay(pdMS_TO_TICKS(10)); // Adjust the delay based on your requirements
    }
    else
    {
      // No Bluetooth processing needed in IR mode
      vTaskDelay(pdMS_TO_TICKS(10)); // Adjust the delay based on your requirements
    }
  }
}

void RFID_Task(void *pvParameters)
{
  while (1)
  {
    // Read data from RFID reader and process it
    // You can use UART or USART HAL functions to communicate with the RFID reader
    // Process the received data and take necessary actions
    // You can send data to other tasks using a queue or semaphore

    xQueueSend(rfidQueue, &rfidData, portMAX_DELAY);

    vTaskDelay(pdMS_TO_TICKS(10)); // Adjust the delay based on your requirements
  }
}

void LDRLight_Task(void *pvParameters)
{
  while (1)
  {
    // Read the value from the LDR sensor
    // Take appropriate actions based on the sensor reading
    // You can use HAL_GPIO_ReadPin to read the LDR pin status
    // Use a semaphore to synchronize with other tasks if required

    if (xSemaphoreTake(ldrSemaphore, pdMS_TO_TICKS(10)) == pdTRUE)
    {
      // Implement LDR light control logic

      xSemaphoreGive(ldrSemaphore);
    }

    vTaskDelay(pdMS_TO_TICKS(100)); // Adjust the delay based on your requirements
  }
}

void LCD_Task(void *pvParameters)
{
  LCD_Init();  // Initialize LCD display
  LCD_Clear();

  while (1)
  {
    // Update the LCD display with relevant information
    // You can use LCD library functions to write text and control the display
    // Use a mutex or semaphore to protect the LCD access when multiple tasks are writing to it

    xSemaphoreTake(ldrSemaphore, portMAX_DELAY);

    if (currentMode == IR_MODE)
    {
      LCD_SetCursor(0, 0);
      LCD_Print("IR Mode");

      // Display other relevant information for IR mode

      vTaskDelay(pdMS_TO_TICKS(1000)); // Adjust the delay based on your requirements
    }
    else
    {
      LCD_SetCursor(0, 0);
      LCD_Print("Bluetooth Mode");

      // Display other relevant information for Bluetooth mode

      vTaskDelay(pdMS_TO_TICKS(1000)); // Adjust the delay based on your requirements
    }

    xSemaphoreGive(ldrSemaphore);
  }
}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	LCD_Init();  // Initialize LCD display
		  LCD_Clear();
		  LCD_SetCursor(0, 1);
		  LCD_Print("IR Mode");

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
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
  distanceQueue = xQueueCreate(1, sizeof(float));
    bluetoothQueue = xQueueCreate(10, sizeof(char));
    rfidQueue = xQueueCreate(10, sizeof(uint32_t));
    ldrSemaphore = xSemaphoreCreateBinary();

  	xTaskCreate(UltrasonicSensor_Task, "UltrasonicTask", configMINIMAL_STACK_SIZE, NULL, 4, NULL);
    xTaskCreate(ObstacleAvoidance_Task, "ObstacleTask", configMINIMAL_STACK_SIZE, NULL, 5, NULL);
    xTaskCreate(LineController_Task, "LineTask", configMINIMAL_STACK_SIZE, NULL, 6, NULL);
    xTaskCreate(Bluetooth_Task, "BluetoothTask", configMINIMAL_STACK_SIZE, NULL, 7, NULL);
    xTaskCreate(RFID_Task, "RFIDTask", configMINIMAL_STACK_SIZE, NULL, 8, NULL);
    xTaskCreate(LDRLight_Task, "LDRTask", configMINIMAL_STACK_SIZE, NULL, 9, NULL);
    xTaskCreate(LCD_Task, "LCDTask", configMINIMAL_STACK_SIZE, NULL, 1, &lcdTaskHandle);

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
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.Timing = 0x00303D5B;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_IC_InitTypeDef sConfigIC = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 72-1;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_IC_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
  sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
  sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
  sConfigIC.ICFilter = 0;
  if (HAL_TIM_IC_ConfigChannel(&htim1, &sConfigIC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

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
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA4 PA5 PA6 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PD5 PD6 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PB4 PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */






  void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin)
    {
      if (GPIO_Pin == SWITCH_PIN)
      {
        if (HAL_GPIO_ReadPin(GPIOC, SWITCH_PIN) == GPIO_PIN_RESET)
        {
          // Switch is pressed, change the mode
          if (currentMode == IR_MODE)
          {
            currentMode = BLUETOOTH_MODE;
            LCD_SetCursor(0, 0);
            LCD_Print("Bluetooth Mode");


            // Suspend tasks related to IR mode
            //vTaskSuspend(ObstacleAvoidance_Task_Handle);
            //vTaskSuspend(LineController_Task_Handle);
          }
          else
          {
            currentMode = IR_MODE;
            LCD_SetCursor(0, 0);
            LCD_Print("IR Mode");

            // Resume tasks related to IR mode
            //vTaskResume(ObstacleAvoidance_Task_Handle);
            //vTaskResume(LineController_Task_Handle);
          }
        }
      }
    }

    void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
    {
      if (huart->Instance == USART1)
      {
        // Bluetooth UART receive interrupt callback
        // Process the received character and handle Bluetooth commands

        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        xQueueSendFromISR(bluetoothQueue, &receivedChar, &xHigherPriorityTaskWoken);

        if (xHigherPriorityTaskWoken == pdTRUE)
        {
          //portYIELD_FROM_ISR();
        }
      }
    }

    void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
    {
      if (huart->Instance == USART1)
      {
        // Bluetooth UART transmit complete callback
        // Handle any necessary actions after transmission completes
      }
    }

    void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
    {
      if (huart->Instance == USART1)
      {
        // Bluetooth UART error callback
        // Handle any necessary error handling or recovery
      }
    }

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