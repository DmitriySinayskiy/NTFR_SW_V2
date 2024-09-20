/*
 * button.c
 *
 *  Created on: Sep 20, 2024
 *      Author: user
 */
#include "button.h"

void button_state_determ();

uint8_t but_state_left = BUT_RESET;
uint8_t but_state_right = BUT_RESET;
uint8_t short_state_l = 0;
uint8_t long_state_l = 0;
uint32_t time_key_l = 0;
uint8_t short_state_r = 0;
uint8_t long_state_r = 0;
uint32_t time_key_r = 0;
uint8_t but_flag_ext = 0 ;

void button_state_determ()
{

		  uint32_t ms = HAL_GetTick();
		  uint8_t key_state_l = HAL_GPIO_ReadPin(BUT_0_GPIO_Port, BUT_0_Pin);

		  if(key_state_l == 1 && !short_state_l && (ms - time_key_l) > 50)
		  {
		    short_state_l = 1;
		    long_state_l = 0;
		    time_key_l = ms;
		  }
		  else if(key_state_l == 1 && !long_state_l && (ms - time_key_l) > 700)
		  {

		    long_state_l = 1;
		    but_state_left = BUT_LONG;
		   // sleep_counter = 0;
		  }
		  else if(key_state_l == 0 && short_state_l && (ms - time_key_l) > 50)
		  {
		    short_state_l = 0;
		    time_key_l = ms;

		    if(!long_state_l)
		    {
		      // левая кнопка , действие на короткое нажатие
		    	but_state_left = BUT_SHORT;
		    	//sleep_counter = 0;
		    }
		  }
	          ms = HAL_GetTick();
		  	  uint8_t key_state_r = HAL_GPIO_ReadPin(BUT_1_GPIO_Port, BUT_1_Pin);

		  	  if(key_state_r == 1 && !short_state_r && (ms - time_key_r) > 50)
		  	  {
		  	    short_state_r = 1;
		  	    long_state_r = 0;
		  	    time_key_r = ms;
		  	  }
		  	  else if(key_state_r == 1 && !long_state_r && (ms - time_key_r) > 700)
		  	  {
		  		// левая кнопка , действие на длительное нажатие
		  		but_state_right = BUT_LONG;
		  		long_state_r = 1;
		  		//sleep_counter = 0;
		  	  }
		  	  else if(key_state_r == 0 && short_state_r && (ms - time_key_r) > 50)
		  	  {
		  	    short_state_r = 0;
		  	    time_key_r = ms;

		  	 if(!long_state_r)
		  	    {
		  		 	 but_state_right = BUT_SHORT;
		  		 	 //sleep_counter = 0;
		  	    }
		  	  }
		  	 but_flag_ext = 0;
}

void but_state_reset()
{
	    but_state_left = BUT_RESET;
	    but_state_right = BUT_RESET;
}
