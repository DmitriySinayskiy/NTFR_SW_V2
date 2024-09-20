/*
 * page_select.c
 *
 *  Created on: Sep 19, 2024
 *      Author: user
 */

#include "page_select.h"

enum PAGE page;



uint16_t current_page = SELECT_PRODUCT_LIST_PAGE;

// pga_ функция содержащая все действия на странице
void page_select()
{
	page_select_by_button();
	page_action(current_page);
}

int page_select_by_button()
{
	if(current_page == SELECT_PRODUCT_LIST_PAGE && but_state_right == BUT_LONG)
	{
		but_state_reset();
		current_page = DISPLAY_PRODUCT_NORM_PAGE;
		//return DISPLAY_PRODUCT_NORM_PAGE;
	}
	else if(current_page == DISPLAY_PRODUCT_NORM_PAGE && but_state_left == BUT_LONG)
	{
		but_state_reset();
		current_page = SELECT_PRODUCT_LIST_PAGE;
		//return SELECT_PRODUCT_LIST_PAGE;
	}
	else if(current_page == DISPLAY_PRODUCT_NORM_PAGE && gl_product_detect)
	{
		gl_product_detect = 0;
		but_state_reset();
		current_page = MEASURING_PROCESS_PAGE;

	}
	else if(current_page == MEASURING_PROCESS_PAGE && but_state_right == BUT_LONG)
	{
		but_state_reset();
		current_page = SELECT_PRODUCT_LIST_PAGE;
		return current_page;
	}

}

void page_action(uint8_t page)
{
	switch(page)
	{
		case SELECT_PRODUCT_LIST_PAGE:
			select_product_list_action();
			prod_sel_flag.sub_norm = 0;
			gl_led_pwm_state = LED_PWM_CCR_STABLE;
			led_off();
		break;

		case DISPLAY_PRODUCT_NORM_PAGE:
			display_norm_action();
			prod_sel_flag.root = 0;
			prod_sel_flag.sub_sub_meas_process = 0;

		break;

		case MEASURING_PROCESS_PAGE:
			measuring_process();
			prod_sel_flag.sub_norm = 0;
			prod_sel_flag.root = 0;
		break;
	}//default:

}

void SPI_Flash_to_LCD(uint16_t block, uint32_t offset, uint16_t w, uint16_t h, uint16_t x, uint16_t y)

{
	uint32_t img_byte_amount = w*h*2;
	uint16_t img_buffer[img_byte_amount/2];
	W25qxx_ReadBlock(img_buffer, block, offset, img_byte_amount);
	ST7735_DrawImage(x, y, w, h, img_buffer);
}
