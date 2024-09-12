/*
 * measuring.c
 *
 *  Created on: Sep 4, 2024
 *      Author: user
 */
#include "measuring.h"

uint8_t gl_led_increment = 0;
uint8_t gl_led_pwm_state = LED_PWM_CCR_STABLE;
uint8_t gl_loading_bar_stop_flag = 0;



void led_off()
{
	//HAL_GPIO_WritePin(LED_ANOD_GPIO_Port, LED_ANOD_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_BLUE_0_GPIO_Port, LED_BLUE_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_BLUE_1_GPIO_Port, LED_BLUE_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_BLUE_2_GPIO_Port, LED_BLUE_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_BLUE_3_GPIO_Port, LED_BLUE_3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_BLUE_4_GPIO_Port, LED_BLUE_4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_RED_3_GPIO_Port, LED_RED_3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_RED_4_GPIO_Port, LED_RED_4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN_3_GPIO_Port, LED_GREEN_3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN_4_GPIO_Port, LED_GREEN_4_Pin, GPIO_PIN_SET);
};
void led_all_on()
{
	//HAL_GPIO_WritePin(LED_ANOD_GPIO_Port, LED_ANOD_Pin, GPIO_PIN_SET);
	//HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED_BLUE_0_GPIO_Port, LED_BLUE_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_BLUE_1_GPIO_Port, LED_BLUE_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_BLUE_2_GPIO_Port, LED_BLUE_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_BLUE_3_GPIO_Port, LED_BLUE_3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_BLUE_4_GPIO_Port, LED_BLUE_4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_RED_3_GPIO_Port, LED_RED_3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_RED_4_GPIO_Port, LED_RED_4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GREEN_3_GPIO_Port, LED_GREEN_3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GREEN_4_GPIO_Port, LED_GREEN_4_Pin, GPIO_PIN_RESET);
};

void led_measuring_results_reflection(uint8_t status) //conduct or acidity measuarement result
{

	led_off();



	if(status == MEAS_RESULTS_IS_GOOD)
	{
		HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN_4_GPIO_Port, LED_GREEN_4_Pin, GPIO_PIN_RESET);
	}
	else if(status == MEAS_RESULTS_IS_MEDIUM)
	{
		HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN_4_GPIO_Port, LED_GREEN_4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_RED_4_GPIO_Port, LED_RED_4_Pin, GPIO_PIN_RESET);
	}
	else if(status == MEAS_RESULTS_IS_BAD)
	{
		HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_RED_4_GPIO_Port, LED_RED_4_Pin, GPIO_PIN_RESET);
	}

}

void led_accumulation()
{



	if(gl_int_5hz_tim2)
	{
		HAL_TIM_Base_Start_IT(&htim2);
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
		TIM2->CCR3 = 350;
		gl_int_5hz_tim2 = 0;

		if(gl_led_increment < 15 && gl_led_increment > 0)
		{
			gl_led_increment++;
		}

		switch(gl_led_increment)
		{
		case 0:

			led_off();
			gl_led_increment++;
			break;
		case 2:


			HAL_GPIO_WritePin(LED_BLUE_0_GPIO_Port, LED_BLUE_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(LED_BLUE_0_GPIO_Port, LED_BLUE_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_BLUE_1_GPIO_Port, LED_BLUE_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(LED_BLUE_1_GPIO_Port, LED_BLUE_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_BLUE_2_GPIO_Port, LED_BLUE_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(LED_BLUE_2_GPIO_Port, LED_BLUE_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_BLUE_3_GPIO_Port, LED_BLUE_3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_3_GPIO_Port, LED_RED_3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_3_GPIO_Port, LED_GREEN_3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_BLUE_0_GPIO_Port, LED_BLUE_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(LED_BLUE_3_GPIO_Port, LED_BLUE_3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_3_GPIO_Port, LED_RED_3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_3_GPIO_Port, LED_GREEN_3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_BLUE_4_GPIO_Port, LED_BLUE_4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_4_GPIO_Port, LED_RED_4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_4_GPIO_Port, LED_GREEN_4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_BLUE_1_GPIO_Port, LED_BLUE_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_BLUE_0_GPIO_Port, LED_BLUE_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);
			break;
		case 7:

			HAL_GPIO_WritePin(LED_BLUE_1_GPIO_Port, LED_BLUE_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_BLUE_2_GPIO_Port, LED_BLUE_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(LED_BLUE_2_GPIO_Port, LED_BLUE_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_BLUE_3_GPIO_Port, LED_BLUE_3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_3_GPIO_Port, LED_RED_3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_3_GPIO_Port, LED_GREEN_3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_BLUE_0_GPIO_Port, LED_BLUE_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(LED_BLUE_0_GPIO_Port, LED_BLUE_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_BLUE_1_GPIO_Port, LED_BLUE_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
			break;
		case 10:
			HAL_GPIO_WritePin(LED_BLUE_1_GPIO_Port, LED_BLUE_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_BLUE_2_GPIO_Port, LED_BLUE_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
			break;
		case 11:
			HAL_GPIO_WritePin(LED_BLUE_0_GPIO_Port, LED_BLUE_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_RESET);
			break;
		case 12:
			HAL_GPIO_WritePin(LED_BLUE_0_GPIO_Port, LED_BLUE_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_BLUE_1_GPIO_Port, LED_BLUE_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
			break;
		case 13:
			HAL_GPIO_WritePin(LED_BLUE_0_GPIO_Port, LED_BLUE_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_BLUE_1_GPIO_Port, LED_BLUE_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
			break;
		case 14:
			HAL_GPIO_WritePin(LED_BLUE_0_GPIO_Port, LED_BLUE_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_RESET);
			break;

		case 15:
			led_1hz_counter = 0;
			gl_led_pwm_state = LED_PWM_CCR_CHANGEBALE;
			HAL_TIM_Base_Stop_IT(&htim2);
			break;
		}
	}
};

int conduct_acidity_loading_bar_calculation(uint16_t reference_acidity_conductivity,  uint8_t temperature_correction_coef , uint16_t measured_acidity_conductivity )
{

	//Кол-во секций(уровней) заполенения бара загрузки = 13 . От 0 до 100 с щагом 10 и от 100 до 200 с шагом 50(100,150,200).

	uint32_t reference_acidity_conductivity_mul_100 = reference_acidity_conductivity * REF_TEMP_COEFF;  // Референсный
	uint32_t measured_value_with_temp_coeff = measured_acidity_conductivity * temperature_correction_coef;
	uint16_t ref_value_10th_part = reference_acidity_conductivity_mul_100 /10;  // десятая часть

	uint8_t bar_index_value = 0;

	if (ref_value_10th_part > measured_value_with_temp_coeff)
		{
			bar_index_value = 0;
		}
	else if (ref_value_10th_part <= measured_value_with_temp_coeff)
	{
		if(measured_value_with_temp_coeff/ref_value_10th_part<=10)
		{
			bar_index_value = measured_value_with_temp_coeff/ref_value_10th_part;
		}
		else if(measured_value_with_temp_coeff/ref_value_10th_part >10 && measured_value_with_temp_coeff/ref_value_10th_part<=15)
		{
			bar_index_value = 11;
		}
		else if(measured_value_with_temp_coeff/ref_value_10th_part > 15 )
		{
			bar_index_value = 12;
		}
	}

	return bar_index_value;


}

int display_loading_status(uint8_t bar_index,uint8_t id )
{
	SPI_Flash_to_LCD(LOADING_BAR,16224 + 1800 * bar_index, 100, 9, 48, 55);
	for(int i = 54 ;i<76; i++)
	{
		ST7735_DrawPixel(127, i, ST7735_RED);
	}
	//uint16_t symbol_status_offset = 0;
	if(bar_index<=8)
	{
		SPI_Flash_to_LCD(CHECK_MARK_M, 8, 44);
		return MEAS_RESULTS_IS_GOOD;
	}
	else if(bar_index==9)
	{
		SPI_Flash_to_LCD(EXCLAMATION_MARK_M, 8, 44);
		return MEAS_RESULTS_IS_MEDIUM;
	}
	else if(bar_index>9)
	{
		SPI_Flash_to_LCD(CROSS_MARK_M, 8, 44);
		return MEAS_RESULTS_IS_BAD;
	}
}
void display_measuring_product(const uint8_t block, const uint16_t offset, uint8_t w, uint8_t h, uint8_t x, uint8_t y)
{
	SPI_Flash_to_LCD(block, offset, w, h, x, y);
	SPI_Flash_to_LCD(ARROW_MAIN_LIGHT_RIGHT);
}
 display_product_norm(uint16_t reference_value, uint8_t language, uint8_t id)
{
	char char_buffer[5] = {};
	sprintf(char_buffer, "%d", reference_value );

	SPI_Flash_to_LCD(9, 0 , 76, 42, 60, 30);

	ST7735_WriteString(77, 52, char_buffer, Font_11x18, ST7735_NITRAT_NORM, ST7735_BLACK);
	ST7735_WriteString(77, 34, "NORM", Font_11x18, ST7735_NITRAT_NORM, ST7735_BLACK);
	SPI_Flash_to_LCD(ARROW_MAIN_LIGHT_RIGHT);
}
void display_measuring_text(char*name ,uint16_t reference_value, uint16_t measured_value, uint8_t status, uint8_t language)
{
	ST7735_WriteString(50, 4,  name, Font_11x18, ST7735_WHITE, ST7735_BLACK);

	char char_buffer[5] = {};



	sprintf(char_buffer, "%d", reference_value );
	ST7735_WriteString(130, 67, char_buffer, Font_7x10, ST7735_FNT_LT_DEF, ST7735_BLACK);

	sprintf(char_buffer, "%d", measured_value );

	if(status == MEAS_RESULTS_IS_GOOD)
	{
		ST7735_WriteString(50, 27, char_buffer, Font_16x26, ST7735_NITRAT_GREEN, ST7735_BLACK);
	}
	else if(status == MEAS_RESULTS_IS_MEDIUM)
	{
		ST7735_WriteString(50, 27, char_buffer, Font_16x26, ST7735_NITRAT_YELLOW, ST7735_BLACK);
	}
	else if(status == MEAS_RESULTS_IS_BAD)
	{
		ST7735_WriteString(50, 27, char_buffer, Font_16x26, ST7735_NITRAT_RED, ST7735_BLACK);
	}

	if(language == ENGLISH)
	{
		ST7735_WriteString(50, 67, "ppm", Font_7x10, ST7735_FNT_LT_DEF, ST7735_BLACK);
	}

}

