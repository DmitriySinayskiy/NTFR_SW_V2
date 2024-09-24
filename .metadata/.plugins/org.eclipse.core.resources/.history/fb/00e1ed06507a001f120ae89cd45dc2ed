#ifndef __ALLMYHEADERS_H__
#define __ALLMYHEADERS_H__
//systemheaders
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdbool.h>
#include "main.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_it.h"

//myheaders
#include "touch.h"
#include "measuring.h"
#include "product_struct.h"
#include "product_selection.h"
#include "page_select.h"
#include "button.h"

//other libs
#include "images.h"
#include "st7735.h"
#include "w25qxx.h"
#include "w25qxxConf.h"


//extern

extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim2;

extern uint16_t gl_counter_1000hz_tim2;
extern uint8_t gl_int_5hz_tim2;
extern uint8_t gl_int_5hz_tim2_for_pic;

extern uint8_t gl_led_pwm_state;
extern uint8_t gl_int_1hz_tim2;
extern uint8_t led_1hz_counter;
extern uint8_t gl_led_color_result_blink_counter;
extern uint8_t gl_loading_bar_stop_flag;
extern uint8_t but_state_left;
extern uint8_t but_state_right;

extern uint16_t gl_selected_pause;
extern uint8_t gl_selected_flag;
extern uint8_t gl_touch_change_id;
extern uint16_t gl_touch_accel;
extern uint8_t touch_irq;
extern uint8_t gl_id_to_display;

extern uint16_t adc_probe_meas[9];


extern uint16_t gl_touch_accel_inc;
extern uint16_t gl_measured_result;
extern uint8_t gl_product_detect;

extern uint16_t current_page;
//externs for interrupts END

#define ENGLISH 1
#define RUSSIAN 2


#endif //__ALLDOZHEADERS_H__
