/*
 * page_select.h
 *
 *  Created on: Sep 19, 2024
 *      Author: user
 */

#ifndef PAGE_SELECT_H_
#define PAGE_SELECT_H_

#include "allmyheaders.h"

enum PAGE {
	SELECT_PRODUCT_LIST_PAGE = 1,
	MEASURING_PROCESS_PAGE ,
	DISPLAY_PRODUCT_NORM_PAGE,
	EMPTYTEST
};




extern enum PAGE page;


void page_action(uint8_t page);
void page_select();
int page_select_by_button();


void SPI_Flash_to_LCD(uint16_t block, uint32_t offset, uint16_t w, uint16_t h, uint16_t x, uint16_t y);

#endif /* PAGE_SELECT_H_ */
