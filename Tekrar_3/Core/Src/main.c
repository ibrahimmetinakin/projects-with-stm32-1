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
#define LED_COUNT 4
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
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

     int led_state=0;  // karasimsek if uygulaması icin lazım, lazım olunca ac, birkac uygulamayı beraber yaptıgım icin uyarı veriyor değiskeni kullanmayınca

//	 uint16_t ledPins[LED_COUNT] = {GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15};

//     int currentLed = 0;

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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  //LEDLERİN HEPSİNİ SÜREKLİ YAKMAK//
	//  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15 , GPIO_PIN_SET);


	  //LEDLERİ YAKIP SÖNDÜRMEK
	  /*
	  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15 , GPIO_PIN_SET);
	  HAL_Delay(2000);  //delay fonksiyonu hal kütüphanesinde zaten var, main dısında tanımlamaya gerek yok
	  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15 , GPIO_PIN_RESET);
	  HAL_Delay(2000);
	  */


	  //LEDLERİ YAKIP SÖNDÜRMEK toggle ile //toggle ilk durumu tersler, yani led sönükse yakar
	  //pinleri ilk configuration kısmında low (sönük) olarak seçmiştik
	  /*
	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15); //led yanacak
	  HAL_Delay(3000); //3000ms=3s bekle
	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15); //led sönecek
	  HAL_Delay(5000); //5000ms=5s bekle
	  */


	  //led karaşimşek uygulaması 12 13 14 15.ledler sırayla yanacak 15.ledden sonra tekrar 14 13 12
/*
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	  HAL_Delay(100);

*/

	  //if ile 12-13-14-15-12-13-14-15  //12 yi yakınca digerlerinin hepsini reset yapmaya gerek yok. zaten configurationda low yaptık

	  if(led_state == 0)
	  {
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);

	  }
	  if(led_state == 1)
	  {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
	  }
	  if(led_state == 2)
	  {

		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);

	  }
	  if(led_state == 3)
	  {
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
	  }

	  HAL_Delay(1000);
	  led_state++;
	  if(led_state>3)
	  {
		  led_state=0;
	  }





/*
	 //switch case ile 12 13 14 15 - 12 13 14 15 led yakma uygulaması
	     // Mevcut LED'i yak
	     switch (currentLed)  //yukarıda tanımlamasını yaptım
	     {
	       case 0:
	         HAL_GPIO_WritePin(GPIOD, ledPins[0], GPIO_PIN_SET);
	      //   HAL_GPIO_WritePin(GPIOD, ledPins[1], GPIO_PIN_RESET);  //config kısmında low olarak ayarladıgım icin burada tekrar yazmasam da olur
	      //   HAL_GPIO_WritePin(GPIOD, ledPins[2], GPIO_PIN_RESET);
	         HAL_GPIO_WritePin(GPIOD, ledPins[3], GPIO_PIN_RESET);    //case3 ten sonra case1 e gelince 15.ledi söndürmen lazım
	         break; //break , case 0 dan sonra cıkmaya yarıyordu
	       case 1:
	         HAL_GPIO_WritePin(GPIOD, ledPins[0], GPIO_PIN_RESET);
	         HAL_GPIO_WritePin(GPIOD, ledPins[1], GPIO_PIN_SET);
	    //    HAL_GPIO_WritePin(GPIOD, ledPins[2], GPIO_PIN_RESET);
	   //      HAL_GPIO_WritePin(GPIOD, ledPins[3], GPIO_PIN_RESET);
	         break;
	       case 2:
	     //    HAL_GPIO_WritePin(GPIOD, ledPins[0], GPIO_PIN_RESET);
	         HAL_GPIO_WritePin(GPIOD, ledPins[1], GPIO_PIN_RESET);
	         HAL_GPIO_WritePin(GPIOD, ledPins[2], GPIO_PIN_SET);
	      //   HAL_GPIO_WritePin(GPIOD, ledPins[3], GPIO_PIN_RESET);
	         break;
	       case 3:
	       //  HAL_GPIO_WritePin(GPIOD, ledPins[0], GPIO_PIN_RESET);
	      //   HAL_GPIO_WritePin(GPIOD, ledPins[1], GPIO_PIN_RESET);
	         HAL_GPIO_WritePin(GPIOD, ledPins[2], GPIO_PIN_RESET);
	         HAL_GPIO_WritePin(GPIOD, ledPins[3], GPIO_PIN_SET);
	         break;
	     }
	     HAL_Delay(1000);
	     // Bir sonraki LED'e geçmek için
	     currentLed = (currentLed + 1) % LED_COUNT ;    // (0+1)%4=1  (1+1)%4=2 ... (3+1)%4=0  //led_count 4 olarak define etmistim

*/

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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
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
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pins : PD12 PD13 PD14 PD15 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
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
