/*
 * product_selection.c
 *
 *  Created on: Sep 15, 2024
 *      Author: user
 */
#include "product_selection.h"

uint8_t gl_selected_id = 55;
uint16_t gl_selected_pause = 0;
uint8_t gl_selected_flag = 1;


int select_product_id(uint8_t id)
{
	//Select product using buttons
	 if(but_state_right == BUT_SHORT)
		  {
//		 	 HAL_GPIO_WritePin(VIBRO_GPIO_Port, VIBRO_Pin, GPIO_PIN_SET);
//		 	 HAL_Delay(42);
//		 	 HAL_GPIO_WritePin(VIBRO_GPIO_Port, VIBRO_Pin, GPIO_PIN_RESET);
			  if(id<60){

				  id++;
			  }
			  else
			  {
				  id = 0;
			  }
			  gl_selected_flag = 1;
			  gl_selected_pause = 0;
			  //gl_selected_pause = 1;
			  but_state_reset();

		  }
		  else if(but_state_left==BUT_SHORT)
		  {
			 // HAL_GPIO_WritePin(VIBRO_GPIO_Port, VIBRO_Pin, GPIO_PIN_SET);
		//	  HAL_Delay(42);
		//	  HAL_GPIO_WritePin(VIBRO_GPIO_Port, VIBRO_Pin, GPIO_PIN_RESET);
			  if(id>0)
			  {
				  id--;
			  }
			  else
			  {
				  id = 60;
			  }
			  gl_selected_flag = 1;
			  gl_selected_pause = 0;
			 // gl_selected_pause = 1;
			  but_state_reset();
		  }
	 //Select product using touch slider sensor

	 return id;
}

void display_selected_product(uint8_t id)
{

	ST7735_WriteString(50, 2,  product_array[id].name, Font_11x18, ST7735_WHITE, ST7735_BLACK);
	if(id == 0)
	{
		SPI_Flash_to_LCD(product_array[id].addr_block_L, product_array[id].addr_offset_L , MAIN_PIC);
		SPI_Flash_to_LCD(product_array[id+1].addr_block_S, product_array[id+1].addr_offset_S , RIGHT_PIC);
		ST7735_FillRectangle(LEFT_PIC, ST7735_BLACK);

		ST7735_FillRectangle(8, 2, 46+id, 75, ST7735_WHITE);// ползунок
		ST7735_FillRectangle(60,2, 46+8+id,75, ST7735_BG_DEF); // правый прямоугольник
	}
	else if(id>0 && id<60)
	{
		SPI_Flash_to_LCD(product_array[id].addr_block_L, product_array[id].addr_offset_L , MAIN_PIC);
		SPI_Flash_to_LCD(product_array[id+1].addr_block_S, product_array[id+1].addr_offset_S , RIGHT_PIC);
		SPI_Flash_to_LCD(product_array[id-1].addr_block_S, product_array[id-1].addr_offset_S , LEFT_PIC);

		ST7735_FillRectangle(60-id,2, 46+8+id,75, ST7735_BG_DEF);// правый прямоугольник
		ST7735_FillRectangle(8, 2, 46+id, 75, ST7735_WHITE);// ползунок
		ST7735_FillRectangle(id,2, 46,75, ST7735_BG_DEF);// левый прямоугольник
	}
	else if(id==60)
	{
		SPI_Flash_to_LCD(product_array[id].addr_block_L, product_array[id].addr_offset_L , MAIN_PIC);
		SPI_Flash_to_LCD(product_array[id-1].addr_block_S, product_array[id-1].addr_offset_S , LEFT_PIC);
		ST7735_FillRectangle(RIGHT_PIC, ST7735_BLACK);

		ST7735_FillRectangle(8, 2, 46+id, 75, ST7735_WHITE);// ползунок
		ST7735_FillRectangle(id,2, 46,75, ST7735_BG_DEF);// левый прямоугольник
	}
	//HAL_TIM_Base_Start_IT(&htim2);

	//gl_selected_pause = 1;

	gl_selected_flag = 0;
}
