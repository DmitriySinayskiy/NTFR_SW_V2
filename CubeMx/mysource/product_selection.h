/*
 * product_selection.h
 *
 *  Created on: Sep 15, 2024
 *      Author: user
 */

#ifndef PRODUCT_SELECTION_H_
#define PRODUCT_SELECTION_H_

#include "allmyheaders.h"

#define MAIN_PIC 46, 46, 58, 21
#define LEFT_PIC 36, 36, 5, 25
#define RIGHT_PIC 36, 36, 118, 25

extern uint8_t gl_selected_id;

int select_product_id(uint8_t id);
void display_selected_product(uint8_t id);

#endif /* PRODUCT_SELECTION_H_ */
