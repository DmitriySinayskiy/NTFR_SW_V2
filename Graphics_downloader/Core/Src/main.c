/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "allmyheaders.h"
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
SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
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
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */

  HAL_GPIO_WritePin(DSP_BL_GPIO_Port, DSP_BL_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(V3_PRH_EN_GPIO_Port, V3_PRH_EN_Pin, GPIO_PIN_SET);

  ST7735_Init();
  ST7735_InvertColors(0);
  W25qxx_Init();

  ST7735_FillScreen(ST7735_RED);

//	  FIRMWARE 0
//    W25qxx_EraseBlock(1);
//    W25qxx_WriteBlock(M1_data, 1, 0, 2592);
//    W25qxx_WriteBlock(M2_data, 1, 2592, 2592);
//    W25qxx_WriteBlock(M3_data, 1, 2592*2, 2592);
//    W25qxx_WriteBlock(M4_data, 1, 2592*3, 2592);
//    W25qxx_WriteBlock(M5_data, 1, 2592*4, 2592);
//    W25qxx_WriteBlock(M6_data, 1, 2592*5, 2592);
//    W25qxx_WriteBlock(M7_data, 1, 2592*6, 2592);
//    W25qxx_WriteBlock(M8_data, 1, 2592*7, 2592);
//    W25qxx_WriteBlock(M9_data, 1, 2592*8, 2592);
//    W25qxx_WriteBlock(M10_data, 1, 2592*9, 2592);
//    W25qxx_WriteBlock(M11_data, 1, 2592*10, 2592);
//    W25qxx_WriteBlock(M12_data, 1, 2592*11, 2592);
//    W25qxx_WriteBlock(M13_data, 1, 2592*12, 2592);
//    W25qxx_WriteBlock(M14_data, 1, 2592*13, 2592);
//    W25qxx_WriteBlock(M15_data, 1, 2592*14, 2592);
//    W25qxx_WriteBlock(M16_data, 1, 2592*15, 2592);
//    W25qxx_WriteBlock(M17_data, 1, 2592*16, 2592);
//    W25qxx_WriteBlock(M18_data, 1, 2592*17, 2592);
//    W25qxx_WriteBlock(M19_data, 1, 2592*18, 2592);
//    W25qxx_WriteBlock(M20_data, 1, 2592*19, 2592);
//    W25qxx_WriteBlock(M21_data, 1, 2592*20, 2592);
//    W25qxx_WriteBlock(M22_data, 1, 2592*21, 2592);
//    W25qxx_WriteBlock(M23_data, 1, 2592*22, 2592);
//    W25qxx_WriteBlock(M24_data, 1, 2592*23, 2592);
//
//
//    W25qxx_EraseBlock(2);
//    W25qxx_WriteBlock(M25_data, 2, 0, 2592);
//    W25qxx_WriteBlock(M26_data, 2, 2592, 2592);
//    W25qxx_WriteBlock(M27_data, 2, 2592*2, 2592);
//    W25qxx_WriteBlock(M28_data, 2, 2592*3, 2592);
//    W25qxx_WriteBlock(M29_data, 2, 2592*4, 2592);
//    W25qxx_WriteBlock(M30_data, 2, 2592*5, 2592);
//    W25qxx_WriteBlock(M31_data, 2, 2592*6, 2592);
//    W25qxx_WriteBlock(M32_data, 2, 2592*7, 2592);
//    W25qxx_WriteBlock(M33_data, 2, 2592*8, 2592);
//    W25qxx_WriteBlock(M34_data, 2, 2592*9, 2592);
//    W25qxx_WriteBlock(M35_data, 2, 2592*10, 2592);
//    W25qxx_WriteBlock(M36_data, 2, 2592*11, 2592);
//    W25qxx_WriteBlock(M37_data, 2, 2592*12, 2592);
//    W25qxx_WriteBlock(M38_data, 2, 2592*13, 2592);
//    W25qxx_WriteBlock(M39_data, 2, 2592*14, 2592);
//    W25qxx_WriteBlock(M40_data, 2, 2592*15, 2592);
//    W25qxx_WriteBlock(M41_data, 2, 2592*16, 2592);
//    W25qxx_WriteBlock(M42_data, 2, 2592*17, 2592);
//    W25qxx_WriteBlock(M43_data, 2, 2592*18, 2592);
//    W25qxx_WriteBlock(M44_data, 2, 2592*19, 2592);
//    W25qxx_WriteBlock(M45_data, 2, 2592*20, 2592);
//    W25qxx_WriteBlock(M46_data, 2, 2592*21, 2592);
//    W25qxx_WriteBlock(M47_data, 2, 2592*22, 2592);
//    W25qxx_WriteBlock(M48_data, 2, 2592*23, 2592);
//    HAL_Delay(10);
//
//    W25qxx_EraseBlock(3);
//    W25qxx_WriteBlock(M49_data, 3, 0, 2592);
//    W25qxx_WriteBlock(M50_data, 3, 2592, 2592);
//    W25qxx_WriteBlock(M51_data, 3, 2592*2, 2592);
//    W25qxx_WriteBlock(M52_data, 3, 2592*3, 2592);
//    W25qxx_WriteBlock(M53_data, 3, 2592*4, 2592);
//    W25qxx_WriteBlock(M54_data, 3, 2592*5, 2592);
//    W25qxx_WriteBlock(M55_data, 3, 2592*6, 2592);
//    W25qxx_WriteBlock(M56_data, 3, 2592*7, 2592);
//    W25qxx_WriteBlock(M57_data, 3, 2592*8, 2592);
//    W25qxx_WriteBlock(M58_data, 3, 2592*9, 2592);
//    W25qxx_WriteBlock(M59_data, 3, 2592*10, 2592);
//    W25qxx_WriteBlock(M60_data, 3, 2592*11, 2592);
//    W25qxx_WriteBlock(M61_data, 3, 2592*12, 2592);
//    W25qxx_WriteBlock(L1_data, 3, 2592*13, 4232);
//
//    W25qxx_EraseBlock(4);
//    W25qxx_WriteBlock(L2_data, 4, 0, 4232);
//    W25qxx_WriteBlock(L3_data, 4, 4232, 4232);
//    W25qxx_WriteBlock(L4_data, 4, 4232*2, 4232);
//    W25qxx_WriteBlock(L5_data, 4, 4232*3, 4232);
//    W25qxx_WriteBlock(L6_data, 4, 4232*4, 4232);
//    W25qxx_WriteBlock(L7_data, 4, 4232*5, 4232);
//    W25qxx_WriteBlock(L8_data, 4, 4232*6, 4232);
//    W25qxx_WriteBlock(L9_data, 4, 4232*7, 4232);
//    W25qxx_WriteBlock(L10_data, 4, 4232*8, 4232);
//    W25qxx_WriteBlock(L11_data, 4, 4232*9, 4232);
//    W25qxx_WriteBlock(L12_data, 4, 4232*10, 4232);
//    W25qxx_WriteBlock(L13_data, 4, 4232*11, 4232);
//    W25qxx_WriteBlock(L14_data, 4, 4232*12, 4232);
//    W25qxx_WriteBlock(L15_data, 4, 4232*13, 4232);
//    W25qxx_WriteBlock(L16_data, 4, 4232*14, 4232);

/////// FIRMWARE 1


//  W25qxx_EraseBlock(5);
//  W25qxx_WriteBlock(L17_data, 5, 0, 4232);
//  W25qxx_WriteBlock(L18_data, 5, 4232, 4232);
//  W25qxx_WriteBlock(L19_data, 5, 4232*2, 4232);
//  W25qxx_WriteBlock(L20_data, 5, 4232*3, 4232);
//  W25qxx_WriteBlock(L21_data, 5, 4232*4, 4232);
//  W25qxx_WriteBlock(L22_data, 5, 4232*5, 4232);
//  W25qxx_WriteBlock(L23_data, 5, 4232*6, 4232);
//  W25qxx_WriteBlock(L24_data, 5, 4232*7, 4232);
//  W25qxx_WriteBlock(L25_data, 5, 4232*8, 4232);
//  W25qxx_WriteBlock(L26_data, 5, 4232*9, 4232);
//  W25qxx_WriteBlock(L27_data, 5, 4232*10, 4232);
//  W25qxx_WriteBlock(L28_data, 5, 4232*11, 4232);
//  W25qxx_WriteBlock(L29_data, 5, 4232*12, 4232);
//  W25qxx_WriteBlock(L30_data, 5, 4232*13, 4232);
//  W25qxx_WriteBlock(L31_data, 5, 4232*14, 4232);
//
//  W25qxx_EraseBlock(6);
//  W25qxx_WriteBlock(L32_data, 6, 0, 4232);
//  W25qxx_WriteBlock(L33_data, 6, 4232, 4232);
//  W25qxx_WriteBlock(L34_data, 6, 4232*2, 4232);
//  W25qxx_WriteBlock(L35_data, 6, 4232*3, 4232);
//  W25qxx_WriteBlock(L36_data, 6, 4232*4, 4232);
//  W25qxx_WriteBlock(L37_data, 6, 4232*5, 4232);
//  W25qxx_WriteBlock(L38_data, 6, 4232*6, 4232);
//  W25qxx_WriteBlock(L39_data, 6, 4232*7, 4232);
//  W25qxx_WriteBlock(L40_data, 6, 4232*8, 4232);
//  W25qxx_WriteBlock(L41_data, 6, 4232*9, 4232);
//  W25qxx_WriteBlock(L42_data, 6, 4232*10, 4232);
//  W25qxx_WriteBlock(L43_data, 6, 4232*11, 4232);
//  W25qxx_WriteBlock(L44_data, 6, 4232*12, 4232);
//  W25qxx_WriteBlock(L45_data, 6, 4232*13, 4232);
//  W25qxx_WriteBlock(L46_data, 6, 4232*14, 4232);
//
//  W25qxx_EraseBlock(7);
//  W25qxx_WriteBlock(L47_data, 7, 0, 4232);
//  W25qxx_WriteBlock(L48_data, 7, 4232, 4232);
//  W25qxx_WriteBlock(L49_data, 7, 4232*2, 4232);
//  W25qxx_WriteBlock(L50_data, 7, 4232*3, 4232);
//  W25qxx_WriteBlock(L51_data, 7, 4232*4, 4232);
//  W25qxx_WriteBlock(L52_data, 7, 4232*5, 4232);
//  W25qxx_WriteBlock(L53_data, 7, 4232*6, 4232);
//  W25qxx_WriteBlock(L54_data, 7, 4232*7, 4232);
//  W25qxx_WriteBlock(L55_data, 7, 4232*8, 4232);
//  W25qxx_WriteBlock(L56_data, 7, 4232*9, 4232);
//  W25qxx_WriteBlock(L57_data, 7, 4232*10, 4232);
//  W25qxx_WriteBlock(L58_data, 7, 4232*11, 4232);
//  W25qxx_WriteBlock(L59_data, 7, 4232*12, 4232);
//  W25qxx_WriteBlock(L60_data, 7, 4232*13, 4232);
//  W25qxx_WriteBlock(L61_data, 7, 4232*14, 4232);
//
//  W25qxx_EraseBlock(8);
//  W25qxx_WriteBlock(LOADING_1_data, 8, 0, 5408 );
//  W25qxx_WriteBlock(LOADING_2_data, 8, 5408, 5408 );
//  W25qxx_WriteBlock(LOADING_3_data, 8, 10816, 5408 );
//  W25qxx_WriteBlock(LOAD_0_data, 8, 16224, 1800 );
//  W25qxx_WriteBlock(LOAD_10_data, 8, 16224 + 1800*1, 1800 );
//  W25qxx_WriteBlock(LOAD_20_data, 8, 16224 + 1800*2, 1800 );
//  W25qxx_WriteBlock(LOAD_30_data, 8, 16224 + 1800*3, 1800 );
//  W25qxx_WriteBlock(LOAD_40_data, 8, 16224 + 1800*4, 1800 );
//  W25qxx_WriteBlock(LOAD_50_data, 8, 16224 + 1800*5, 1800 );
//  W25qxx_WriteBlock(LOAD_60_data, 8, 16224 + 1800*6, 1800 );
//  W25qxx_WriteBlock(LOAD_70_data, 8, 16224 + 1800*7, 1800 );
//  W25qxx_WriteBlock(LOAD_80_data, 8, 16224 + 1800*8, 1800 );
//  W25qxx_WriteBlock(LOAD_90_data, 8, 16224 + 1800*9, 1800 );
//  W25qxx_WriteBlock(LOAD_100_data, 8, 16224 + 1800*10, 1800 );
//  W25qxx_WriteBlock(LOAD_150_data, 8, 16224 + 1800*11, 1800 );
//  W25qxx_WriteBlock(LOAD_200_data, 8, 16224 + 1800*12, 1800 );
//
//  W25qxx_WriteBlock(CHECK_MARK_M_data, 8,39774 , 1920 );
//  W25qxx_WriteBlock(EXCLAMATION_MARK_M_data, 8,41664 , 1920 );
//  W25qxx_WriteBlock(CROSS_MARK_M_data, 8,43584 , 1920 );
//  W25qxx_WriteBlock(CHECK_MARK_L_data, 8,47104 , 3520 );
//  W25qxx_WriteBlock(EXCLAMATION_MARK_L_data, 8,50624 , 3520 );
//  W25qxx_WriteBlock(CROSS_MARK_L_data, 8,54144 , 3520 );
//
//  W25qxx_WriteBlock(ARROW_SUB_DARK_DOWN_data, 8,57664 , 90);
//  W25qxx_WriteBlock(ARROW_SUB_DARK_LEFT_data, 8,57754 , 90);
//  W25qxx_WriteBlock(ARROW_SUB_DARK_RIGHT_data, 8,57844 , 90);
//  W25qxx_WriteBlock(ARROW_SUB_DARK_UP_data, 8,57934 , 90);
//
//  W25qxx_WriteBlock(ARROW_SUB_LIGHT_DOWN_data, 8,58024 , 90);
//  W25qxx_WriteBlock(ARROW_SUB_LIGHT_LEFT_data, 8,58114 , 90);
//  W25qxx_WriteBlock(ARROW_SUB_LIGHT_RIGHT_data, 8,58204 , 90);
//  W25qxx_WriteBlock(ARROW_SUB_LIGHT_UP_data, 8,58294 , 90);
//
//  W25qxx_WriteBlock(FAVORITE_STAR_data, 8,58384 , 162);
//  W25qxx_WriteBlock(ARROW_MAIN_DARK_RIGHT_data, 8,58546 , 224);
//  W25qxx_WriteBlock(ARROW_MAIN_LIGHT_RIGHT_data, 8,58770 , 224);

  //FIRMWARE 2
  W25qxx_EraseBlock(9);
  W25qxx_WriteBlock(NORM_RECTANGLE_data, 9, 0, 6384);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

	  HAL_GPIO_WritePin(ANOD_GPIO_Port, ANOD_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(LED_BLUE_1_GPIO_Port,LED_BLUE_1_Pin, GPIO_PIN_RESET);
	  HAL_Delay(1000);
	  HAL_GPIO_WritePin(ANOD_GPIO_Port, ANOD_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(LED_BLUE_1_GPIO_Port,LED_BLUE_1_Pin, GPIO_PIN_SET);
	  HAL_Delay(1000);

//  	  SPI_Flash_to_LCD(LOADING_1,28,14);
//  	  SPI_Flash_to_LCD(LOADING_2,80,14);
//  	  HAL_Delay(70);
//  	  SPI_Flash_to_LCD(LOADING_3,28,14);
//  	  SPI_Flash_to_LCD(LOADING_3,80,14);
//  	  HAL_Delay(70);
//  	  SPI_Flash_to_LCD(LOADING_2,28,14);
//  	  SPI_Flash_to_LCD(LOADING_1,80,14);
//  	  HAL_Delay(70);

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
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

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
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

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
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, FLASH_CS_Pin|DSP_BL_Pin|V3_PRH_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED_RED_2_Pin|LED_GREEN_2_Pin|LED_BLUE_2_Pin|LED_RED_3_Pin
                          |LED_GREEN_3_Pin|LED_BLUE_3_Pin|LED_RED_4_Pin|LED_GREEN_4_Pin
                          |LED_BLUE_4_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ST7735_DC_Pin|ST7735_CS_Pin|ST7735_RES_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_GREEN_0_Pin|LED_BLUE_0_Pin|LED_RED_1_Pin|LED_GREEN_1_Pin
                          |LED_BLUE_1_Pin|LED_RED_0_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, ANOD_Pin|S1_Pin|OE_Pin|DFU_FORCE_Pin
                          |S0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : FLASH_CS_Pin LED_RED_2_Pin LED_GREEN_2_Pin LED_BLUE_2_Pin
                           LED_RED_3_Pin LED_GREEN_3_Pin LED_BLUE_3_Pin LED_RED_4_Pin
                           LED_GREEN_4_Pin LED_BLUE_4_Pin DSP_BL_Pin V3_PRH_EN_Pin */
  GPIO_InitStruct.Pin = FLASH_CS_Pin|LED_RED_2_Pin|LED_GREEN_2_Pin|LED_BLUE_2_Pin
                          |LED_RED_3_Pin|LED_GREEN_3_Pin|LED_BLUE_3_Pin|LED_RED_4_Pin
                          |LED_GREEN_4_Pin|LED_BLUE_4_Pin|DSP_BL_Pin|V3_PRH_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : BUT_1_Pin BUT_0_Pin */
  GPIO_InitStruct.Pin = BUT_1_Pin|BUT_0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : ST7735_DC_Pin ST7735_CS_Pin ST7735_RES_Pin */
  GPIO_InitStruct.Pin = ST7735_DC_Pin|ST7735_CS_Pin|ST7735_RES_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_GREEN_0_Pin LED_BLUE_0_Pin ANOD_Pin S1_Pin
                           OE_Pin DFU_FORCE_Pin LED_RED_1_Pin LED_GREEN_1_Pin
                           LED_BLUE_1_Pin LED_RED_0_Pin S0_Pin */
  GPIO_InitStruct.Pin = LED_GREEN_0_Pin|LED_BLUE_0_Pin|ANOD_Pin|S1_Pin
                          |OE_Pin|DFU_FORCE_Pin|LED_RED_1_Pin|LED_GREEN_1_Pin
                          |LED_BLUE_1_Pin|LED_RED_0_Pin|S0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : VBUS_DET_Pin */
  GPIO_InitStruct.Pin = VBUS_DET_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(VBUS_DET_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : INT_GYRO_Pin */
  GPIO_InitStruct.Pin = INT_GYRO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(INT_GYRO_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : IRQ_TCH_Pin */
  GPIO_InitStruct.Pin = IRQ_TCH_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(IRQ_TCH_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

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
