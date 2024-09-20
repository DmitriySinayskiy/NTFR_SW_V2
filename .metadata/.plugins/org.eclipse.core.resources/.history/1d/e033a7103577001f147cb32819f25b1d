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

void select_product_list_action();
int select_product_id(uint8_t id);
void display_selected_product(uint8_t id);

typedef struct
{
	uint8_t root;
	uint8_t sub_norm;
	uint8_t sub_history;
	uint8_t sub_rate;
	uint8_t sub_favorite;
} product_select_flag_struct;

extern product_select_flag_struct prod_sel_flag;


#endif /* PRODUCT_SELECTION_H_ */
