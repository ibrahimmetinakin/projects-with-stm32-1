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
#include "string.h"

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
char rx_buffer[50];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

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

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  HAL_UART_Receive(&huart2, (uint8_t*)rx_buffer , 50 , 100);
/*
	  if(rx_buffer[0]=='l' && rx_buffer[1]=='e' && rx_buffer[2]=='d' && rx_buffer[3]=='1' && rx_buffer[4]=='=' && rx_buffer[5]=='o')   //o means open(turn on)
	  {
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
	  }

	  else if(rx_buffer[0]=='l' && rx_buffer[1]=='e' && rx_buffer[2]=='d' && rx_buffer[3]=='1' && rx_buffer[4]=='=' && rx_buffer[5]=='c')    //c it means close(turn off)
	  {
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
	  }

	  else if(rx_buffer[0]=='l' && rx_buffer[1]=='e' && rx_buffer[2]=='d' && rx_buffer[3]=='2' && rx_buffer[4]=='=' && rx_buffer[5]=='o')
	  	  {
	  		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
	  	  }

	  else if(rx_buffer[0]=='l' && rx_buffer[1]=='e' && rx_buffer[2]=='d' && rx_buffer[3]=='2' && rx_buffer[4]=='=' && rx_buffer[5]=='c')
		  	  {
		  		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
		  	  }

	  else if(rx_buffer[0]=='l' && rx_buffer[1]=='e' && rx_buffer[2]=='d' && rx_buffer[3]=='3' && rx_buffer[4]=='=' && rx_buffer[5]=='o')
		  	  {
		  		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
		  	  }

	  else if(rx_buffer[0]=='l' && rx_buffer[1]=='e' && rx_buffer[2]=='d' && rx_buffer[3]=='3' && rx_buffer[4]=='=' && rx_buffer[5]=='c')
			  	  {
			  		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
			  	  }

	  else if(rx_buffer[0]=='l' && rx_buffer[1]=='e' && rx_buffer[2]=='d' && rx_buffer[3]=='4' && rx_buffer[4]=='=' && rx_buffer[5]=='o')
			  	  {
			  		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
			  	  }

	  else if(rx_buffer[0]=='l' && rx_buffer[1]=='e' && rx_buffer[2]=='d' && rx_buffer[3]=='3' && rx_buffer[4]=='=' && rx_buffer[5]=='c')
			  	  {
			  		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
			  	  }

	  else if(rx_buffer[0]=='o' && rx_buffer[1]=='p' && rx_buffer[2]=='e' && rx_buffer[3]=='n')
	  			  	  {
	  			  		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_SET);
	  			  	  }

	  else if(rx_buffer[0]=='c' && rx_buffer[1]=='l' && rx_buffer[2]=='o' && rx_buffer[3]=='s' && rx_buffer[4]=='e')
			  	  {
			  		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_RESET);
			  	  }

	  //PE4 output olarak seçtim ve led bagladım
	  else if(rx_buffer[0]=='p' && rx_buffer[1]=='e' && rx_buffer[2]=='4' && rx_buffer[3]=='=' && rx_buffer[4]=='o')
				  	  {
		  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4 , GPIO_PIN_SET);
				  	  }

	  else if(rx_buffer[0]=='p' && rx_buffer[1]=='e' && rx_buffer[2]=='4' && rx_buffer[3]=='=' && rx_buffer[4]=='c')
					  	  {
		  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4 , GPIO_PIN_RESET);
					  	  }
*/



	  //karakterlere tek tek bakmadan bu şekilde yapabiliriz
	  //strncmp str1 parametresi ile gösterilen karakter dizisinin, n parametre değeri kadar ilk karakterini, str2 parametresi ile gösterilen karakter dizisi ile karşılaştırır.
     //Eğer her iki karakter dizisindeki tüm karakterler aynı ise sıfır değeri, aksi takdirde sıfırdan farklı bir değer geri döndürür.

	  if (strncmp(rx_buffer, "led1=o", 6) == 0)
	  {    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);}

	  else if (strncmp(rx_buffer, "led1=c", 6) == 0)
	    {  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET); }

	  else if (strncmp(rx_buffer, "led2=o", 6) == 0)
	         { HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);  }

	  else if (strncmp(rx_buffer, "led2=c", 6) == 0)
	  {         HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);  }

	  else if (strncmp(rx_buffer, "led3=o", 6) == 0)
	  {   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET); }

	  else if (strncmp(rx_buffer, "led3=c", 6) == 0)
	  { HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);

	  } else if (strncmp(rx_buffer, "led4=o", 6) == 0)
	  {HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET); }

	  else if (strncmp(rx_buffer, "led4=c", 6) == 0)
	  { HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET); }

	  else if (strncmp(rx_buffer, "open", 4) == 0)
	  {HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_SET);}

	  else if (strncmp(rx_buffer, "close", 5) == 0)
	  { HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_RESET);}

	  // else if (strcmp(rx_buffer, "pe4=o")== 0)
	//strcmp ile yine tamamını karsılastırabilirim ama bu sefer led sürekli yanıyor???
	  else if (strncmp(rx_buffer, "pe4=o", 5) == 0)
	          { HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET); }

      else if (strncmp(rx_buffer, "pe4=c", 5) == 0)
      { HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET);}
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
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
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
  if (HAL_UART_Init(&huart2) != HAL_OK)
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
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin : PE4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PD12 PD13 PD14 PD15 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

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
