/*
 * product_struct.h
 *
 *  Created on: Sep 15, 2024
 *      Author: user
 */

#ifndef PRODUCT_STRUCT_H_
#define PRODUCT_STRUCT_H_

#include "allmyheaders.h"

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

extern product product_array[];

#endif /* PRODUCT_STRUCT_H_ */
