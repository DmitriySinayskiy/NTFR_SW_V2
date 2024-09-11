#ifndef __ALLMYHEADERS_H__
#define __ALLMYHEADERS_H__
//systemheaders
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "main.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_it.h"

//myheaders
#include "touch.h"
#include "measuring.h"

//other libs
#include "images.h"
#include "st7735.h"
#include "w25qxx.h"
#include "w25qxxConf.h"


//externs for interrupts START
extern uint16_t gl_counter_1000hz_tim2;
extern uint8_t gl_int_5hz_tim2;
extern uint8_t gl_int_5hz_tim2_for_pic;
extern TIM_HandleTypeDef htim2;
extern uint8_t gl_led_pwm_state;
extern uint8_t gl_int_1hz_tim2;
extern uint8_t led_1hz_counter;
extern uint8_t gl_led_color_result_blink_counter;
extern uint8_t gl_loading_bar_stop_flag;
//externs for interrupts END

#define ENGLISH 1
#define RUSSIAN 2


#endif //__ALLDOZHEADERS_H__
