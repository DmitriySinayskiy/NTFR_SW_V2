/*
 * main_menu_probe.c
 *
 *  Created on: Sep 24, 2024
 *      Author: user
 */
#include <main_menu.h>

menu_page_flag menu_flag;

static void main_menu_probe_flag()
{
	menu_flag.main_probe = 1;
	menu_flag.main_info = 0;
	menu_flag.main_settings = 0;
	menu_flag.sub_probe = 0;
}
static void main_menu_settings_flag()
{
	menu_flag.main_settings = 1;
	menu_flag.main_probe = 0;
	menu_flag.main_info = 0;
	menu_flag.sub_settings_lang = 0;
	menu_flag.sub_settings_sleep = 0;
}
static void main_menu_info_flag()
{
	menu_flag.main_info = 1;
	menu_flag.main_probe = 0;
	menu_flag.main_settings = 0;
	menu_flag.sub_info = 0;
}


void main_menu_probe_action()
{
	if(!menu_flag.main_probe && menu_flag.last_page != MAIN_MENU_SETTINGS)
	{
		main_menu_probe_flag();
		ST7735_FillScreen(ST7735_BLACK);
		SPI_Flash_to_LCD(MAIN_MENU_NO3);
		SPI_Flash_to_LCD(9, 14304, 36, 55, 77 ,11);
		SPI_Flash_to_LCD(9, 6384, 36, 55, 119 ,11);

		SPI_Flash_to_LCD(8, 59218, 8, 14, 2 ,33);
	}
	else if(!menu_flag.main_probe && menu_flag.last_page == MAIN_MENU_SETTINGS)
	{
		main_menu_probe_flag();

		SPI_Flash_to_LCD(9, 14304, 36, 55, 77 ,11);
		ST7735_FillRectangle(6, 55, 71, 11, ST7735_BLACK);
		SPI_Flash_to_LCD(MAIN_MENU_NO3);

		SPI_Flash_to_LCD(8, 59218, 8, 14, 2 ,33);
	}
//	SPI_Flash_to_LCD(MAIN_MENU_NO3);
//	SPI_Flash_to_LCD(9, 14304, 36, 55, 77 ,11);
//	SPI_Flash_to_LCD(9, 6384, 36, 55, 119 ,11);



}

void main_menu_settings_action()
{


	if(!menu_flag.main_settings && menu_flag.last_page == MAIN_MENU_PROBE)
	{
		main_menu_settings_flag();

		SPI_Flash_to_LCD(9, 10344, 36, 55, 16 ,11);
		ST7735_FillRectangle(6, 55, 52, 11, ST7735_BLACK);
		SPI_Flash_to_LCD(9, 36414, 55, 55, 58, 11);
	}
	else if (!menu_flag.main_settings && menu_flag.last_page == MAIN_MENU_INFO)
	{
		main_menu_settings_flag();

		SPI_Flash_to_LCD(9, 6384, 36, 55, 119 ,11);
		ST7735_FillRectangle(6, 55, 113, 11, ST7735_BLACK);
		SPI_Flash_to_LCD(9, 36414, 55, 55, 58, 11);
	}

}

void main_menu_info_action()
{


	if(!menu_flag.main_info)
	{
		main_menu_info_flag();

		SPI_Flash_to_LCD(9, 14304, 36, 55, 58 ,11);
		ST7735_FillRectangle(6, 55, 94, 11, ST7735_BLACK);
		SPI_Flash_to_LCD(9, 18264, 55, 55, 100, 11);
	}

}


