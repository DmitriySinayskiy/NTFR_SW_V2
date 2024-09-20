#include "touch.h"
extern I2C_HandleTypeDef hi2c1;
//HAL_GPIO_WritePin(DSP_BL_GPIO_Port, DSP_BL_Pin, GPIO_PIN_SET);

uint8_t capreadbuffer[10] = {};
uint8_t test1 = 0x00;
uint8_t touch_thrsh[5] = {THRESH_EL0-3, THRESH_EL1-3, THRESH_EL2-3, THRESH_EL3-3, THRESH_EL4-3};
int8_t first_touch = -1;
int8_t second_touch = -1;
uint8_t left_treshold = 0;
uint8_t right_treshold = 0;
uint8_t touch_direction = 0; //1 -up ,2-down

void MPR121_setregister(uint16_t regaddress, uint8_t value)
{
	 HAL_I2C_Mem_Write(&hi2c1, 0x5A<<1, regaddress, 1,&value, 1, 100);
}
int MPR121_readregister(uint16_t regaddress, uint8_t value)
{
	 HAL_I2C_Mem_Read(&hi2c1, 0x5A<<1, regaddress, 1,&value, 1, 100);
	 return value;
}

void touch_slider()
{
	//HAL_TIM_Base_Start_IT(&htim2);
		  		uint8_t j= 0x04;
		  		for(int i = 0;i<5;i++)
		  		{
		  			capreadbuffer[i] = MPR121_readregister(j,test1);
		  			j+=2;
		  		}

		  		for(int i = 0;i<5;i++)
		  		{
		//  			sprintf(char_buffer, "%03d", capreadbuffer[i]);
		  //			ST7735_WriteString(32*i,0 , char_buffer, Font_7x10, ST7735_WHITE, ST7735_BG_DEF);

		  			if(capreadbuffer[i] <= touch_thrsh[i] && first_touch <= 0)
		  			{
		  				gl_touch_accel = 1;
		  				first_touch = i;
		  		//		sprintf(char_buffer, "%01d", first_touch);
		  		//		ST7735_WriteString(15,63 , char_buffer, Font_11x18, ST7735_WHITE, ST7735_BLACK);
		  //				HAL_TIM_Base_Start_IT(&htim5);
		  				break;
		  			}

		  		}
		  		if(first_touch >= 0 && second_touch!=first_touch) //second_flag == 0)
		  		{
		  			if(second_touch>=0)
		  			{
		  				//sprintf(char_buffer, "%01d", second_touch);
		  				//ST7735_WriteString(40,63 , char_buffer, Font_11x18, ST7735_WHITE, ST7735_BLACK);


		  				if((second_touch-first_touch == -1 || second_touch-first_touch == -2 )&& left_treshold!=1)//
		  				{
		  					gl_touch_change_id = 1;

		  					//touch_accel_to_disp = gl_touch_accel_inc;
		  					//gl_touch_accel = 0;
		  					//gl_touch_accel_inc = 0;

		  					touch_direction = UP;

		  					if(gl_id_to_display<60)
		  					{
		  					//	if(touch_accel_to_disp<250 && id_to_display<57)

		  						//	id_to_display+=3;
		  						//	id_to_displ_fast_scroll = 1 ;
		  					//	}
		  						//else
		  						//{
		  						gl_id_to_display++;
		  						//}
		  					}
		  					else
		  					{
		  						gl_id_to_display = 0;

		  					}
		  					touch_irq = 0;
		  				//	HAL_TIM_Base_Stop_IT(&htim2);
		  				}
		  				else if((second_touch-first_touch == 1 || second_touch-first_touch == 2)&& right_treshold!=1)//
		  				{
		  					gl_touch_change_id = 1;

		  						  					//touch_accel_to_disp = gl_touch_accel_inc;
		  						  							gl_touch_accel = 0;
		  						  							gl_touch_accel_inc = 0;
		  					touch_direction = DOWN;
		  					if(gl_id_to_display>0)
		  					{
	//	  						if(touch_accel_to_disp<250 && id_to_display>3)
	//	  						{
	//	  							id_to_display-=3;
	//	  							//id_to_displ_fast_scroll = 2 ;
	//	  						}
	//	  						else
		  					//	{
		  						gl_id_to_display--;//id_changed_by_touch = 0;
		  						//}


		  					}
		  					else
		  					{
		  						gl_id_to_display = 60;

		  					}
		  					touch_irq = 0;
		  				//	HAL_TIM_Base_Stop_IT(&htim2);

		  				}

		  			}
		  			if(left_treshold==1)
		  			{
		  				if((first_touch == 1 ||  first_touch == 2) && second_touch == 0)
		  				{
		  					left_treshold = 2;
		  				}
		  				else
		  				{
		  					left_treshold  = 0;
		  				}
		  			}
		  			if(first_touch == 0 && second_touch == 1)
		  			{
		  				left_treshold = 1;
		  			}

		  			if(right_treshold==1)
		  			{
		  				if((first_touch == 3 ||  first_touch == 2) && second_touch == 4)
		  				{
		  					right_treshold = 2;
		  				}
		  				else
		  				{
		  					right_treshold  = 0;
		  				}
		  			}
		  			if(first_touch == 4 && second_touch == 3)
		  			{
		  				right_treshold = 1;
		  			}
		  			second_touch = first_touch;
		  		}

		  		else if(touch_direction == NONE)
		  		{

		  		}
		  		first_touch = -100;
}

void touch_init()
{
	MPR121_setregister(MHD_R,0x01);
	MPR121_setregister(NHD_R,0x01);
	MPR121_setregister(NCL_R,0x00);
	MPR121_setregister(FDL_R,0x00);

	MPR121_setregister(MHD_F,0x01);
	MPR121_setregister(NHD_F,0x01);
	MPR121_setregister(NCL_F,0xFF);
	MPR121_setregister(FDL_F,0x02);

	MPR121_setregister(ELE0_T,TOU_THRESH);
	MPR121_setregister(ELE0_R,TOU_THRESH);

	MPR121_setregister(ELE1_T,TOU_THRESH);
	MPR121_setregister(ELE1_R,TOU_THRESH);

	MPR121_setregister(ELE2_T,TOU_THRESH);
	MPR121_setregister(ELE2_R,TOU_THRESH);

	MPR121_setregister(ELE3_T,TOU_THRESH);
	MPR121_setregister(ELE3_R,TOU_THRESH);

	MPR121_setregister(ELE4_T,TOU_THRESH);
	MPR121_setregister(ELE4_R,TOU_THRESH);

	MPR121_setregister(ELE5_T,TOU_THRESH);
	MPR121_setregister(ELE5_R,TOU_THRESH);

	MPR121_setregister(ELE6_T,TOU_THRESH);
	MPR121_setregister(ELE6_R,TOU_THRESH);

	MPR121_setregister(ELE7_T,TOU_THRESH);
	MPR121_setregister(ELE7_R,TOU_THRESH);

	MPR121_setregister(ELE8_T,TOU_THRESH);
	MPR121_setregister(ELE8_R,TOU_THRESH);

	MPR121_setregister(ELE9_T,TOU_THRESH);
	MPR121_setregister(ELE9_R,TOU_THRESH);

	MPR121_setregister(ELE10_T,TOU_THRESH);
	MPR121_setregister(ELE10_R,TOU_THRESH);

	MPR121_setregister(ELE11_T,TOU_THRESH);
	MPR121_setregister(ELE11_R,TOU_THRESH);

	MPR121_setregister(AFE_CFG1,0x15);

	MPR121_setregister(FIL_CFG,0x04);
	MPR121_setregister(ELE_CFG,0x0C);
	MPR121_setregister(ELE_CFG,0x0C);
	MPR121_setregister(ATO_CFG0,0x0F);
	MPR121_setregister(ATO_CFGU,0xC8);
}
