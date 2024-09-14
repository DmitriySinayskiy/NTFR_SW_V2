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
#include "usb_device.h"

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
ADC_HandleTypeDef hadc1;

I2C_HandleTypeDef hi2c1;

RTC_HandleTypeDef hrtc;

SPI_HandleTypeDef hspi1;
DMA_HandleTypeDef hdma_spi1_rx;
DMA_HandleTypeDef hdma_spi1_tx;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_I2C1_Init(void);
static void MX_RTC_Init(void);
static void MX_SPI1_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM4_Init(void);
static void MX_TIM1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

uint8_t touch_irq = 0;
uint8_t buffread[4]={};
uint8_t but_state_left = BUT_RESET;
uint8_t but_state_right = BUT_RESET;
uint8_t short_state_l = 0;
uint8_t long_state_l = 0;
uint32_t time_key_l = 0;
uint8_t short_state_r = 0;
uint8_t long_state_r = 0;
uint32_t time_key_r = 0;
uint8_t but_flag_ext = 0 ;
uint8_t capreadbuffer[10] = {};
uint8_t pwm_vibro_start = 0;


typedef struct
{
	const uint8_t id;
	uint16_t conductivity;
	uint16_t acidity;
	uint8_t temperature_coeff;

	const uint8_t addr_block_S;	//small size picture of a product
	const uint16_t addr_offset_S;

	const uint8_t addr_block_L;	//large size picture of a product
	const uint16_t addr_offset_L;
	const char * name ;

}product;


product product_array[] = {
		{0,1000,2000,100, 1, 2592*0, 3, 2592*13, "APRICOT"},//APRICOT//
		{1,1000,2000,100, 1, 2592*1, 4, 4232*0, "PINEAPPLE"},//PINEAPPLE
		{2,1000,2000,100, 1, 2592*2, 4, 4232*1, "AVOCADO"},//AVOCADO
		{3,1000,2000,100, 1, 2592*3, 4, 4232*2,"WATERMELON"},//WATERMELON
		{4,1000,2000,100, 1, 2592*4, 4, 4232*3, "ORANGE"} ,//ORANGE
		{5,1000,2000,100, 1, 2592*5, 4, 4232*4, "BANANA"} ,//BANANA
		{6,1000,2000,100, 1, 2592*6, 4, 4232*5, "EGGPLANT"} ,//EGGPLANT
		{7,1000,2000,100, 1, 2592*7, 4, 4232*6, "BATAT"} ,//BATAT
		{8,1000,2000,100, 1, 2592*8, 4, 4232*7, "GRAPE"} ,//GRAPE
		{9,1000,2000,100, 1, 2592*9, 4, 4232*8, "PEAR"} ,//PEAR
		{10,1000,2000,100, 1, 2592*10, 4, 4232*9, "GRAPEFRUIT"} ,//GRAPEFRUIT
		{11,1000,2000,100, 1, 2592*11, 4, 4232*10, "GUAVA"} ,//GUAVA
		{12,1000,2000,100, 1, 2592*12, 4, 4232*11, "GUANABANA"} ,//GUANABANA
		{13,1000,2000,100, 1, 2592*13, 4, 4232*12, "GREENS"} ,//GREENS
		{14,1000,2000,100, 1, 2592*14, 4, 4232*13, "MELON"} ,//MELON
		{15,1000,2000,100, 1, 2592*15, 4, 4232*14, "MUSCAT MELON"} ,//MUSCAT MELON
		{16,1000,2000,100, 1, 2592*16, 5, 4232*0, "JACKFRUIT"} ,//JACKFRUIT
		{17,1000,2000,100, 1, 2592*17, 5, 4232*1, "DURIAN"} ,//DURIAN
		{18,1000,2000,100, 1, 2592*18, 5, 4232*2, "GINGER"} ,//GINGER
		{19,1000,2000,100, 1, 2592*19, 5, 4232*3, "EARLY CABBAGE"} ,//EARLY CABBAGE
		{20,1000,2000,100, 1, 2592*20, 5, 4232*4, "LATE CABBAGE"} ,//LATE CABBAGE
		{21,1000,2000,100, 1, 2592*21, 5, 4232*5, "CAULIFLOWER"} ,//CAULIFLOWER
		{22,1000,2000,100, 1, 2592*22, 5, 4232*6, "ZUCCINI"} ,//ZUCCINI
		{23,1000,2000,100, 1, 2592*23, 5, 4232*7, "POTATOES"} ,//POTATOES
		{24,1000,2000,100, 2, 2592*0, 5, 4232*8, "STRAWBERRIES"} ,//STRAWBERRIES
		{25,1000,2000,100, 2, 2592*1, 5, 4232*9, "CORN"} ,//CORN
		{26,1000,2000,100, 2, 2592*2, 5, 4232*10, "LEMON"} ,//LEMON
		{27,1000,2000,100, 2, 2592*3, 5, 4232*11, "LITCHI LATER"} ,//LITCHI LATER
		{28,1000,2000,100, 2, 2592*4, 5, 4232*12, "LIME"} ,//LIME
		{29,1000,2000,100, 2, 2592*5, 5, 4232*13, "LONGAN"} ,//LONGAN
		{30,1000,2000,100, 2, 2592*6, 5, 4232*14, "ONIONS"} ,//ONIONS
		{31,1000,2000,100, 2, 2592*7, 6, 4232*0, "ONION GREEN"} ,//ONION GREEN
		{32,1000,2000,100, 2, 2592*8, 6, 4232*1, "MANGO RIPE"} ,//MANGO RIPE
		{33,1000,2000,100, 2, 2592*9, 6, 4232*2, "MANGOOSTEEN"} ,//MANGOOSTEEN
		{34,1000,2000,100, 2, 2592*10, 6, 4232*3, "MANDARIN"} ,//MANDARIN
		{35,1000,2000,100, 2, 2592*11, 6, 4232*4, "EARLY CARROTS"} ,//EARLY CARROTS
		{36,1000,2000,100, 2, 2592*12, 6, 4232*5, "LATE CARROTS"} ,//LATE CARROTS
		{37,1000,2000,100, 2, 2592*13, 6, 4232*6, "NECTARINE"} ,//NECTARINE
		{38,1000,2000,100, 2, 2592*14, 6, 4232*7, "GROUND CUCUMBER"} ,//GROUND CUCUMBER
		{39,1000,2000,100, 2, 2592*15, 6, 4232*8, "GREENHOUSE CUCUMBER"} ,//GREENHOUSE CUCUMBER
		{40,1000,2000,100, 2, 2592*16, 6, 4232*9, "PAPAYA"} ,//PAPAYA
		{41,1000,2000,100, 2, 2592*17, 6, 4232*10, "PITAHAYA RED"} ,//PITAHAYA RED
		{42,1000,2000,100, 2, 2592*18, 6, 4232*11, "SWEET PEPPER"} ,//SWEET PEPPER
		{43,1000,2000,100, 2, 2592*19, 6, 4232*12, "PEACH"} ,//PEACH
		{44,1000,2000,100, 2, 2592*20, 6, 4232*13, "GROUND TOMATO"} ,//GROUND TOMATO
		{45,1000,2000,100, 2, 2592*21, 6, 4232*14, "GREENHOUSE TOMATO"} ,//GREENHOUSE TOMATO
		{46,1000,2000,100, 2, 2592*22, 7, 4232*0, "CHERRY TOMATO"} ,//CHERRY TOMATO
		{47,1000,2000,100, 2, 2592*23, 7, 4232*1, "RAMBUTAN"} ,//RAMBUTAN
		{48,1000,2000,100, 3, 2592*0, 7, 4232*2, "SPRING RADISH"} ,//SPRING RADISH
		{49,1000,2000,100, 3, 2592*1, 7, 4232*3, "RADISH"} ,//RADISH
		{50,1000,2000,100, 3, 2592*2, 7, 4232*4, "SAPODILLA"} ,//SAPODILLA
		{51,1000,2000,100, 3, 2592*3, 7, 4232*5, "LETTUCE"} ,//LETTUCE
		{52,1000,2000,100, 3, 2592*4, 7, 4232*6, "BEETROOT"} ,//BEETROOT
		{53,1000,2000,100, 3, 2592*5, 7, 4232*7, "RED PLUM"} ,//RED PLUM
		{54,1000,2000,100, 3, 2592*6, 7, 4232*8, "PERSIMMON"} ,//PERSIMMON
		{55,1000,2000,100, 3, 2592*7, 7, 4232*9, "GARLIC"} ,//GARLIC
		{56,1000,2000,100, 3, 2592*8, 7, 4232*10, "CHAMPIGNONS"} ,//CHAMPIGNONS
		{57,1000,2000,100, 3, 2592*9, 7, 4232*11, "APPLE"} ,//APPLE
		{58,1000,2000,100, 3, 2592*10, 7, 4232*12, "FRESH MEAT"} ,//FRESH MEAT
		{59,1000,2000,100, 3, 2592*11, 7, 4232*13, "FRESH FISH"} ,//FRESH FISH
		{60,1000,2000,100, 3, 2592*12, 7, 4232*14, "CHILDREN'NORM"} //CHILDREN'S NORM
    };


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	if (GPIO_Pin == IRQ_TCH_Pin) {

		touch_irq = 1;
	}
}



void ADC_Select_Channel(uint32_t ch) {
    ADC_ChannelConfTypeDef conf = {
        .Channel = ch,
        .Rank = 1,
        .SamplingTime = ADC_SAMPLETIME_84CYCLES,
    };
    if (HAL_ADC_ConfigChannel(&hadc1, &conf) != HAL_OK) {
        Error_Handler();
    }
}
void SPI_Flash_to_LCD(uint16_t block, uint32_t offset, uint16_t w, uint16_t h, uint16_t x, uint16_t y)

{
	uint32_t img_byte_amount = w*h*2;
	uint16_t img_buffer[img_byte_amount/2];
	W25qxx_ReadBlock(img_buffer, block, offset, img_byte_amount);
	ST7735_DrawImage(x, y, w, h, img_buffer);
}

void button_state_determ()
{

		  uint32_t ms = HAL_GetTick();
		  uint8_t key_state_l = HAL_GPIO_ReadPin(BUT_0_GPIO_Port, BUT_0_Pin);

		  if(key_state_l == 1 && !short_state_l && (ms - time_key_l) > 50)
		  {
		    short_state_l = 1;
		    long_state_l = 0;
		    time_key_l = ms;
		  }
		  else if(key_state_l == 1 && !long_state_l && (ms - time_key_l) > 700)
		  {

		    long_state_l = 1;
		    but_state_left = BUT_LONG;
		   // sleep_counter = 0;
		  }
		  else if(key_state_l == 0 && short_state_l && (ms - time_key_l) > 50)
		  {
		    short_state_l = 0;
		    time_key_l = ms;

		    if(!long_state_l)
		    {
		      // левая кнопка , действие на короткое нажатие
		    	but_state_left = BUT_SHORT;
		    	//sleep_counter = 0;
		    }
		  }
	          ms = HAL_GetTick();
		  	  uint8_t key_state_r = HAL_GPIO_ReadPin(BUT_1_GPIO_Port, BUT_1_Pin);

		  	  if(key_state_r == 1 && !short_state_r && (ms - time_key_r) > 50)
		  	  {
		  	    short_state_r = 1;
		  	    long_state_r = 0;
		  	    time_key_r = ms;
		  	  }
		  	  else if(key_state_r == 1 && !long_state_r && (ms - time_key_r) > 700)
		  	  {
		  		// левая кнопка , действие на длительное нажатие
		  		but_state_right = BUT_LONG;
		  		long_state_r = 1;
		  		//sleep_counter = 0;
		  	  }
		  	  else if(key_state_r == 0 && short_state_r && (ms - time_key_r) > 50)
		  	  {
		  	    short_state_r = 0;
		  	    time_key_r = ms;

		  	 if(!long_state_r)
		  	    {
		  		 	 but_state_right = BUT_SHORT;
		  		 	 //sleep_counter = 0;
		  	    }
		  	  }
		  	 but_flag_ext = 0;
}

void but_state_reset()
{
	    but_state_left = BUT_RESET;
	    but_state_right = BUT_RESET;
}


void touch_init()
{
	MPR121_setregister(MHD_R,0x01);
	MPR121_setregister(NHD_R,0x01);
	MPR121_setregister(NCL_R,0x00);
	MPR121_setregister(FDL_R,0x00);

	MPR121_setregister(MHD_F,0x01);
	MPR121_setregister(NHD_F,0x01);
	MPR121_setregister(NCL_F,0xFF);
	MPR121_setregister(FDL_F,0x02);

	MPR121_setregister(ELE0_T,TOU_THRESH);
	MPR121_setregister(ELE0_R,TOU_THRESH);

	MPR121_setregister(ELE1_T,TOU_THRESH);
	MPR121_setregister(ELE1_R,TOU_THRESH);

	MPR121_setregister(ELE2_T,TOU_THRESH);
	MPR121_setregister(ELE2_R,TOU_THRESH);

	MPR121_setregister(ELE3_T,TOU_THRESH);
	MPR121_setregister(ELE3_R,TOU_THRESH);

	MPR121_setregister(ELE4_T,TOU_THRESH);
	MPR121_setregister(ELE4_R,TOU_THRESH);

	MPR121_setregister(ELE5_T,TOU_THRESH);
	MPR121_setregister(ELE5_R,TOU_THRESH);

	MPR121_setregister(ELE6_T,TOU_THRESH);
	MPR121_setregister(ELE6_R,TOU_THRESH);

	MPR121_setregister(ELE7_T,TOU_THRESH);
	MPR121_setregister(ELE7_R,TOU_THRESH);

	MPR121_setregister(ELE8_T,TOU_THRESH);
	MPR121_setregister(ELE8_R,TOU_THRESH);

	MPR121_setregister(ELE9_T,TOU_THRESH);
	MPR121_setregister(ELE9_R,TOU_THRESH);

	MPR121_setregister(ELE10_T,TOU_THRESH);
	MPR121_setregister(ELE10_R,TOU_THRESH);

	MPR121_setregister(ELE11_T,TOU_THRESH);
	MPR121_setregister(ELE11_R,TOU_THRESH);

	MPR121_setregister(FIL_CFG,0x04);
	MPR121_setregister(ELE_CFG,0x0C);
	MPR121_setregister(ELE_CFG,0x0C);
	MPR121_setregister(ATO_CFG0,0x0F);
	MPR121_setregister(ATO_CFGU,0xC8);
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
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_RTC_Init();
  MX_SPI1_Init();
  MX_ADC1_Init();
  MX_TIM3_Init();
  MX_TIM2_Init();
  MX_TIM4_Init();
  MX_TIM1_Init();
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 2 */




  HAL_GPIO_WritePin(V3_PRH_EN_GPIO_Port, V3_PRH_EN_Pin, GPIO_PIN_SET);
  ST7735_Init();
  ST7735_InvertColors(0);
  ST7735_FillScreen(ST7735_BLACK);
  HAL_GPIO_WritePin(DSP_BL_GPIO_Port, DSP_BL_Pin, GPIO_PIN_SET);

  W25qxx_Init();
  MX_I2C1_Init();
  touch_init();

  HAL_TIM_Base_Start_IT(&htim4);

  HAL_GPIO_WritePin(OE_GPIO_Port, OE_Pin, GPIO_PIN_RESET); //on mux
  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_RESET);
  HAL_TIM_Base_Start_IT(&htim2);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  TIM1->CCR1 = 50;

  char char_buffer[10];

   uint16_t conduct0 = 0;
   uint16_t conduct1 = 0;
   uint16_t conduct2 = 0;
   uint16_t conduct_avg = 0;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  uint16_t measuring_result = 800;
	  uint8_t id_product_to_display = 1;

	  display_all_measuring_process_and_led(measuring_result, id_product_to_display);


	  uint16_t adc_values[3];
	  	  uint32_t channels[] = {
	  			  ADC_CHANNEL_0,
	  			  ADC_CHANNEL_1,
	  			  ADC_CHANNEL_2,
	  	  };

	  	  ST7735_WriteString(5, 3,  "CH0:", Font_11x18, ST7735_MAGENTA, ST7735_BG_DEF);
	  	  ST7735_WriteString(5, 23, "CH1:", Font_11x18, ST7735_MAGENTA, ST7735_BG_DEF);
	  	  ST7735_WriteString(5, 43, "CH2:", Font_11x18, ST7735_MAGENTA, ST7735_BG_DEF);
	  	  ST7735_WriteString(5, 63, "AVG:", Font_11x18, ST7735_MAGENTA, ST7735_BG_DEF);


	  	  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
	  	  HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_RESET);

	  	  for(int i = 0; i < 3; i++) {
	  		  ADC_Select_Channel(channels[i]);
	  		  HAL_ADC_Start(&hadc1);
	  		  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	  		  adc_values[i] = HAL_ADC_GetValue(&hadc1);
	  		  HAL_ADC_Stop(&hadc1);
	  	  }

	  	  conduct0 = adc_values[1];
	  	  sprintf(char_buffer, "%04d", conduct0);
	  	  ST7735_WriteString(55, 3, char_buffer, Font_11x18, ST7735_FNT_LT_DEF, ST7735_BG_DEF);


	  	  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
	  	  HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_SET);

	  	  for(int i = 0; i < 3; i++) {
	  	  		  ADC_Select_Channel(channels[i]);
	  	  		  HAL_ADC_Start(&hadc1);
	  	  		  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	  	  		  adc_values[i] = HAL_ADC_GetValue(&hadc1);
	  	  		  HAL_ADC_Stop(&hadc1);
	  	  }
	  	  conduct1 = adc_values[1];
	  	  sprintf(char_buffer, "%04d", conduct1);
	  	  ST7735_WriteString(55, 23, char_buffer, Font_11x18, ST7735_FNT_LT_DEF, ST7735_BG_DEF);


	  	  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_SET);
	  	  HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_RESET);

	  	  for(int i = 0; i < 3; i++) {
	  	  		  ADC_Select_Channel(channels[i]);
	  	  		  HAL_ADC_Start(&hadc1);
	  	  		  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	  	  		  adc_values[i] = HAL_ADC_GetValue(&hadc1);
	  	  		  HAL_ADC_Stop(&hadc1);
	  	  }
	  	  conduct2 = adc_values[1];
	  	  sprintf(char_buffer, "%04d", conduct2);
	  	  ST7735_WriteString(55, 43, char_buffer, Font_11x18, ST7735_FNT_LT_DEF, ST7735_BG_DEF);

	  	  conduct_avg = (conduct0+conduct1+conduct2)/3;


  }



    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
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
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_112CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

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
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef sDate = {0};
  RTC_AlarmTypeDef sAlarm = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */

  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */

  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date
  */
  sTime.Hours = 0x0;
  sTime.Minutes = 0x0;
  sTime.Seconds = 0x0;
  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }
  sDate.WeekDay = RTC_WEEKDAY_MONDAY;
  sDate.Month = RTC_MONTH_JANUARY;
  sDate.Date = 0x1;
  sDate.Year = 0x0;

  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }

  /** Enable the Alarm A
  */
  sAlarm.AlarmTime.Hours = 0x0;
  sAlarm.AlarmTime.Minutes = 0x0;
  sAlarm.AlarmTime.Seconds = 0x0;
  sAlarm.AlarmTime.SubSeconds = 0x0;
  sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
  sAlarm.AlarmMask = RTC_ALARMMASK_ALL;
  sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
  sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_DATE;
  sAlarm.AlarmDateWeekDay = 0x1;
  sAlarm.Alarm = RTC_ALARM_A;
  if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

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
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 820-1;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 100-1;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 420-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 100-1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 1680-1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 100-1;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 42000-1;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 25-1;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Stream0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
  /* DMA2_Stream3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream3_IRQn);

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
  HAL_GPIO_WritePin(GPIOB, S1_Pin|OE_Pin|DFU_FORCE_Pin|S0_Pin, GPIO_PIN_RESET);

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

  /*Configure GPIO pins : LED_GREEN_0_Pin LED_BLUE_0_Pin S1_Pin OE_Pin
                           DFU_FORCE_Pin LED_RED_1_Pin LED_GREEN_1_Pin LED_BLUE_1_Pin
                           LED_RED_0_Pin S0_Pin */
  GPIO_InitStruct.Pin = LED_GREEN_0_Pin|LED_BLUE_0_Pin|S1_Pin|OE_Pin
                          |DFU_FORCE_Pin|LED_RED_1_Pin|LED_GREEN_1_Pin|LED_BLUE_1_Pin
                          |LED_RED_0_Pin|S0_Pin;
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
void display_all_measuring_process_and_led(uint16_t measured_value, uint8_t id)
{

	  if(gl_led_pwm_state==LED_PWM_CCR_STABLE)
	  {
		  SPI_Flash_to_LCD(LOADING_1,28,14);
		  SPI_Flash_to_LCD(LOADING_2,80,14);
		  SPI_Flash_to_LCD(LOADING_3,28,14);
		  SPI_Flash_to_LCD(LOADING_2,28,14);
		  SPI_Flash_to_LCD(LOADING_1,80,14);
		  SPI_Flash_to_LCD(LOADING_3,80,14);
	  }
	  if(gl_led_pwm_state ==  LED_PWM_CCR_STABLE)
	  {
		  led_accumulation();
	  }
	  else if(gl_led_pwm_state ==  LED_PWM_CCR_CHANGEBALE && led_1hz_counter && gl_led_color_result_blink_counter <= 3 && !gl_loading_bar_stop_flag )
	  {

		  ST7735_FillScreen(ST7735_BLACK);
		  HAL_TIM_Base_Start_IT(&htim2);

		  uint8_t load_bar_index = (conduct_acidity_loading_bar_calculation(product_array[id].conductivity, product_array[id].temperature_coeff, measured_value));
		  uint8_t result_status = display_loading_status(load_bar_index, product_array[id].id);

		  display_measuring_product(product_array[id].addr_block_S, product_array[id].addr_offset_S, HORIZ_AFTER_MEASURING);
		  display_measuring_text(product_array[id].name , product_array[id].conductivity, measured_value, result_status, ENGLISH);
		  led_measuring_results_reflection(result_status);
		  gl_loading_bar_stop_flag = 1;
	  }
	  else if (gl_led_color_result_blink_counter > 3)
	  {
		  HAL_TIM_Base_Stop_IT(&htim2);
		  led_off();
		  HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);
		  TIM2->CCR3 = 0;
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
