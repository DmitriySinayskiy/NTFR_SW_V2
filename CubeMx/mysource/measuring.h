/*
 * measuring.h
 *
 *  Created on: Sep 4, 2024
 *      Author: user
 */

#ifndef MEASURING_H_
#define MEASURING_H_

#include "allmyheaders.h"

#define LED_AMOUNT 5
#define MEAS_RESULTS_IS_GOOD 1
#define MEAS_RESULTS_IS_MEDIUM 2
#define MEAS_RESULTS_IS_BAD	3

#define LED_PWM_CCR_STABLE  1
#define LED_PWM_CCR_CHANGEBALE  2
#define LED_PWM_STOP 0
#define REF_TEMP_COEFF 100 // Температурный коэффициент при нормальной комнатной температуре (25 градусов)
#define HORIZ_AFTER_MEASURING 36,36,7,3
#define HORIZ_BEFORE_MEASURING 46,46,7,15
#define VERT_AFTER_MEASURING
#define VERT_BEFORE_MEASURING

void led_off();
void led_all_on();
void led_accumulation();
void led_measuring_results_reflection(uint8_t c_a_result);
int conduct_acidity_loading_bar_calculation(uint16_t reference_acidity_conductivity, uint8_t temperature_correction_coef,uint16_t measured_acidity_conductivity );
int display_loading_status(uint8_t bar_index,uint8_t id );

void display_measuring_product(const uint8_t block, const uint16_t offset, uint8_t w, uint8_t h, uint8_t x, uint8_t y);
void display_measuring_text(char*name , uint16_t reference_value, uint16_t measured_value, uint8_t status, uint8_t language);
void display_product_norm(uint16_t reference_value, uint8_t language);
void display_all_measuring_process_and_led(uint16_t measured_value, uint8_t id);



#endif /* MEASURING_H_ */
