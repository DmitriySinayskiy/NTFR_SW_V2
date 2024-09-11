#include "touch.h"
extern I2C_HandleTypeDef hi2c1;
//HAL_GPIO_WritePin(DSP_BL_GPIO_Port, DSP_BL_Pin, GPIO_PIN_SET);

void MPR_Init()
{
	//i2c bus number
	//mpr_adress
	//size
	//timeout

}
void MPR121_get_touch_status()
{
	//1- touch; 0 - release
	//HAL_I2C_Master_Receive(hi2c, DevAddress, pData, Size, Timeout)
}
void MPR121_get_data() //Electrode Data Register (0x04~0x1D
{

}
void MPR121_get_filtered_data() //Baseline Value Register (0x1E~0x2A
{

}
void MPR121_setregister(uint16_t regaddress, uint8_t value)
{
	 HAL_I2C_Mem_Write(&hi2c1, 0x5A<<1, regaddress, 1,&value, 1, 100);
}
int MPR121_readregister(uint16_t regaddress, uint8_t value)
{
	 HAL_I2C_Mem_Read(&hi2c1, 0x5A<<1, regaddress, 1,&value, 1, 100);
	 return value;
}
