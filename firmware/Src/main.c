/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "whiskey.h"
#include <stdbool.h>
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
bool flag_switch_mode = false;
uint8_t rx_data[3] = {0};
typedef enum{
	REGULAR = 1,
	OFF,
	BLINK_ALL,
	UP_DOWN_ON__ALL_OFF,
	DOWN_UP_ON__ALL_OFF,
	UP_DOWN_ON__UP_DOWN_OFF,
	DOWN_UP_ON__DOWN_UP_OFF,
	UP_DOWN_ON__DOWN_UP_OFF,
	DOWN_UP_ON__UP_DOWN_OFF,
	CHAOS,
	ROUND_UP,
	ROUND_DOWN
} mode;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
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
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
	HAL_UART_Receive_IT(&huart3, rx_data, 3);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		switch(rx_data[0])
		{
			case REGULAR: 								flag_switch_mode = false;	func_regular(); 																								break;
			case OFF:											flag_switch_mode = false;	func_off();																					 						break;
			case BLINK_ALL:								flag_switch_mode = false; func_blink_all(rx_data[1] | (rx_data[2] << 8) ); 								break;
			case UP_DOWN_ON__ALL_OFF: 		flag_switch_mode = false; func_up_down_on__all_off(rx_data[1] | (rx_data[2] << 8) ); 			break;
			case DOWN_UP_ON__ALL_OFF: 		flag_switch_mode = false; func_down_up_on__all_off(rx_data[1] | (rx_data[2] << 8) ); 			break;
			case UP_DOWN_ON__UP_DOWN_OFF:	flag_switch_mode = false; func_up_down_on__up_down_off(rx_data[1] | (rx_data[2] << 8) );	break;
			case DOWN_UP_ON__DOWN_UP_OFF: flag_switch_mode = false; func_down_up_on__down_up_off(rx_data[1] | (rx_data[2] << 8) ); 	break;
			case UP_DOWN_ON__DOWN_UP_OFF: flag_switch_mode = false; func_up_down_on__down_up_off(rx_data[1] | (rx_data[2] << 8) ); 	break;
			case DOWN_UP_ON__UP_DOWN_OFF: flag_switch_mode = false; func_down_up_on__up_down_off(rx_data[1] | (rx_data[2] << 8) ); 	break;
			case CHAOS: 									flag_switch_mode = false; func_chaos(rx_data[1] | (rx_data[2] << 8) ); 										break;
			case ROUND_UP: 								flag_switch_mode = false; func_round_up(rx_data[1] | (rx_data[2] << 8) ); 								break;
			case ROUND_DOWN: 							flag_switch_mode = false; func_round_down(rx_data[1] | (rx_data[2] << 8) ); 							break;
			default: func_off();
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL3;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_Delay(uint32_t Delay)
{
  uint32_t tickstart = HAL_GetTick();
  uint32_t wait = Delay;

  /* Add a freq to guarantee minimum wait */
  if (wait < HAL_MAX_DELAY)
  {
    wait += (uint32_t)(uwTickFreq);
  }

  while ( ((HAL_GetTick() - tickstart) < wait) && (!flag_switch_mode) )
  {
  }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart == &huart3)
	{
		flag_switch_mode = true;
		HAL_UART_Receive_IT(&huart3, rx_data, 3);
	}
}
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
