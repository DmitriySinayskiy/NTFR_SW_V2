/*
 * page_select.c
 *
 *  Created on: Sep 19, 2024
 *      Author: user
 */

#include "page_select.h"

enum PAGE page;



uint8_t current_page = SELECT_PRODUCT_LIST_PAGE;

// pga_ функция содержащая все действия на странице
void page_select()
{
	uint8_t page = page_select_by_button();
	page_action(page);
}

int page_select_by_button()
{
	if(current_page == SELECT_PRODUCT_LIST_PAGE && but_state_right == BUT_LONG)
	{
		but_state_reset();
		current_page = DISPLAY_PRODUCT_NORM_PAGE;
		return current_page;
	}
	else if(current_page == DISPLAY_PRODUCT_NORM_PAGE && but_state_left == BUT_LONG)
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
		break;

		case DISPLAY_PRODUCT_NORM_PAGE:
			display_product_norm(gl_id_to_display, ENGLISH);
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
