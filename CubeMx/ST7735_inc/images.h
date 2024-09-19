#include "main.h"
//SPI_Flash_to_LCD(uint32_t address, uint32_t offset, uint8_t sector_block, uint32_t img_byte_amount, uint16_t x, uint16_t y, uint16_t w, uint16_t h);
#define RAD_ICON_DRAW block,6050,8,15,55,55
#define PAGE_POINTER_DRAW sector,450,14,73,45,5
#define BAT_INDICATOR_DRAW sector,576,3,3,24,12

#define TIME_ICON_DRAW block,6050,8,15,55,55
#define TIME_SUB_ICON_DRAW 13,47310,block,6050,53,22,55,55
#define TIME_SUB_ICON_DIMRIGHT_DRAW 13,53460, block,5170,112,22,47,55
#define TIME_SUB_ICON_DIMLEFT_DRAW 13,58730, block,5170,0,22,47,55
#define TIME_MAINPART_RIGHT 23, 440*3,sector, 390, 155, 24, 5,39
#define TIME_MAINPART_LEFT 23, 440*4,sector, 390, 0, 24, 5,39

#define LIMIT_MAIN 15,0x6000, block, 6050 ,8,15, 55,55
#define LIMIT_SUBMAIN 15,0x7800, block, 6050 ,52,22, 55,55
#define LIMIT_SUBSIDE_RIGHT 15,0xA440, block, 5170 ,112,22, 47,55
#define LIMIT_SUBSIDE_LEFT 15,0x9000, block, 5170 ,0,22, 47,55
#define LIMIT_ARROW_SIDE 10,0, sector, 456 ,15,55, 12,19
#define LIMIT_ARROW_MAIN 10,500, sector, 456,73,55, 12,19
#define LIMIT_AVG_MAIN 10,1000, sector, 704 ,69,55, 22,16
#define LIMIT_AVG_SIDE 10,1800, sector, 704 ,130,55, 22,16
#define LIMIT_MAINPART_LEFT 10,2994, sector, 390 ,0,24, 5,39
#define LIMIT_MAINPART_RIGHT  10,2554, sector, 390 ,155,24, 5,39

#define STAT_MAIN 13,0, block, 6050 ,8,15, 55,55
#define STAT_SUB_PEAK 16,2272,sector,468,30,10,13,17
#define STAT_SUB_ACCUM_DAILY 16,1820,sector,442,5,10,13,17
#define STAT_SUB_ACCUM_30DAY 16,2750,sector,672,60,10,16,21
#define STAT_ARROW 16,2272,sector, 442, 9, 8, 13, 17
#define STAT_DAILY_ICON 16, 1820, sector, 442, 9, 32, 13, 17
#define STAT_30D_ICON 16, 2750, sector, 672, 9, 55, 16, 21
#define STAT_MAINPART_RIGHT 23, 440,sector, 390, 155, 24, 5,39
#define STAT_MAINPART_LEFT 23, 440*2,sector, 390, 0, 24, 5,39

#define ENERGY_MAIN_ICON 9, 0, block, 6050, 8, 15, 55, 55
#define ENERGY_MAINPART_LEFT 18, 2380, sector,390,0,24,5,39
#define ENERGY_MAINPART_RIGHT 18, 1940, sector,390,155,24,5,39
#define ENERGY_ZIPPER_ICON 17, 3320, sector, 288,70,28,12,12
#define ENERGY_SUBMAIN_ICON 9, 6100, block, 6050, 52, 22, 55, 55
#define ENERGY_SUB_ICON_DIMRIGHT 9, 12200, block, 5170, 112, 22, 47, 55
#define ENERGY_SUB_ICON_DIMLEFT 9, 17420, block, 5170, 0, 22, 47, 55
#define ENERGY_SUBMAIN_ICON_SLEEP 17, 0, sector, 646, 72, 55, 17, 19
#define ENERGY_SUBDIM_ICON_SLEEP 17, 696, sector, 646, 15, 55, 17, 19
#define ENERGY_SUBMAIN_ICON_ECO 17, 1392, sector, 576, 69, 58, 24, 12
#define ENERGY_SUBDIM_ICON_ECO 17, 2018, sector, 576, 130, 58, 24, 12

#define SETTING_MAINPART_RIGHT 23, 0, sector, 390, 155, 24, 5,39
#define SETTINGS_MAIN_ICON 10, 13630, block, 6050, 8, 15, 55, 55
#define SETTINGS_MAIN_UNIT_ICON 22, 0, sector, 384, 70, 30, 16, 12
#define SETTINGS_MAIN_SOUND_ICON 22, 434, sector, 384, 90, 40, 16, 12
#define SETTINGS_MAIN_LIGHT_ICON 22, 434*2, sector, 544, 110, 40, 16, 17

#define SETTINGS_SUBMAIN_ICON 10, 19730, block, 6050, 52, 22, 55, 55
#define SETTINGS_SUBDIM_RIGHT 10, 31050, block, 5170, 112, 22, 47, 55
#define SETTINGS_SUBDIM_LEFT 10, 25830, block, 5170, 0, 22, 47, 55

#define SETTIGNS_SUBMAIN_UNIT 19, 0, sector, 720, 69, 55, 24, 15
#define SETTINGS_SUBDIM_UNIT 19, 770, sector, 720, 9, 55, 24, 15

#define SETTINGS_SUBMAIN_SOUND 19, 1540, sector, 900, 69, 55, 25, 18
#define SETTINGS_SUBDIM_RIGHT_SOUND 19, 2490, sector, 900, 130, 55, 25, 18
#define SETTINGS_SUBDIM_LEFT_SOUND 19, 2490, sector, 900, 9, 55, 25, 18


#define SETTINGS_SUBMAIN_LIGHT 11, 0, sector, 800, 69, 54, 20, 20
#define SETTINGS_SUBDIM_RIGHT_LIGHT 11, 810, sector, 800, 130, 54 , 20, 20
#define SETTINGS_SUBDIM_LEFT_LIGHT 11, 810, sector, 800, 11, 54 , 20, 20

#define SETTINGS_SUBMAIN_RESET 20, 1544, sector, 720, 69, 55, 20, 18
#define SETTINGS_SUBDIM_RESET 20, 2314, sector, 720, 130, 55, 20, 18

#define FLASHLIGHT 11,1610, sector, 512, 141, 60, 16, 16

#define PLUS 11, 2150, sector, 200, 135, 35, 10, 10
#define PLUS_mini 11, 2370, sector, 200, 135, 35, 10, 10
#define MINUS 11, 2590, sector, 200 , 20, 35, 10,10
#define MINUS_mini 11,2810, sector,200, 20, 35, 10, 10


//  W25qxx_WriteSector(Frame_1483,11,2150,200);// time PLUS
//  W25qxx_WriteSector(Frame_1483_mini,11,2370,200);// time PLUS mini
//  W25qxx_WriteSector(Frame_1484,11,2570,200);// time MINUS
//  W25qxx_WriteSector(Frame_1484_mini,11,2790,200);// time MINUS mini

//#define SETTINGS_SUBMAIN_INFO 21
//#define SETTINGS_SUBDIM_INFO 21

#define MIRA_LOGO 8, 0, block, 2760, 50,30, 69, 20
#define MILERD_LOGO 8, 3000, block, 2208, 35,35, 92,12
#define MILERD_HISTAND_LOGO_TOP 8, 5500, block, 1136, 25,25,71,8
#define MILERD_HISTAND_LOGO_BOT 8, 6800, block, 5198, 25,34,113,23


/////////LANGUAGE START

#define SETTINGS_MAIN_OFF  0, block, 840
#define SETTINGS_MAIN_ON  840, block, 840
#define SETTINGS_MAIN_uSV  1680, block, 840, 66, 30, 30, 14
#define SETTINGS_MAIN_uR  2520, block, 840, 66, 30, 30, 14
#define SETTINGS_MAIN_CPM  3360, block, 840, 66, 30, 30, 14

//#define LIMIT_uSv  4200, block, 1224, 0, 0, 34, 18
//#define LIMIT_uR  5424, block, 1224, 0, 0, 34, 18
//#define LIMIT_CPM  6648, block, 1224, 0, 0, 34, 18
//make it smaller like in settings

#define LIMIT_uSv  1680, block, 840, 124, 36, 30, 14
#define LIMIT_uR  2520, block, 840, 124, 36, 30, 14
#define LIMIT_CPM  3360, block, 840, 124, 36, 30, 14

#define TIME_HOURS_DIM  7872, block, 1600
#define TIME_MIN_DIM  9472, block, 1600
#define TIME_DAYS_DIM  11072, block, 1600
#define TIME_MONTH_DIM  12672, block, 1600
#define TIME_YEARS_DIM  14272, block, 1600

#define TIME_HOURS  20672, block, 1640, 60, 52, 41, 20
#define TIME_MIN  22312, block, 1640, 60, 52, 41, 20
#define TIME_DAYS  23952, block, 1640, 60, 52, 41, 20
#define TIME_MONTH  25592, block, 1640, 60, 52, 41, 20
#define TIME_YEARS  27232, block, 1640, 60 ,52, 41, 20

#define SETTINGS_SUB_RES_DIM_RIGHT  28872, block, 1840, 120, 29, 40, 23
#define SETTINGS_SUB_INF_DIM_RIGHT  30712, block, 1840, 120, 29, 40, 23
#define SETTINGS_SUB_ON_DIM_RIGHT  32552, block, 1840, 120, 29, 40, 23
#define SETTINGS_SUB_OFF_DIM_RIGHT  34392, block, 1840, 120, 29, 40, 23
#define SETTINGS_SUB_uSv_DIM_LEFT  36232, block, 1840, 0, 29, 40, 23
#define SETTINGS_SUB_uR_DIM_LEFT  38072, block, 1840, 0, 29, 40, 23
#define SETTINGS_SUB_CPM_DIM_LEFT  39912, block, 1840, 0, 29, 40, 23
#define SETTINGS_SUB_ON_DIM_LEFT  41752, block, 1840, 0, 29, 40, 23
#define SETTINGS_SUB_OFF_DIM_LEFT  43592, block, 1840, 0, 29, 40, 23
#define SETTINGS_SUB_RES_DIM_LEFT 45432, block, 1840, 0, 29, 40, 23

#define SETTINGS_SUB_uSv  0, block, 2070, 58, 29, 45, 23
#define SETTINGS_SUB_uR  2070, block, 2070, 58, 29, 45, 23
#define SETTINGS_SUB_CPM  4140, block, 2070, 58, 29, 45, 23
#define SETTINGS_SUB_ON  6210, block, 2070, 58, 29, 45, 23
#define SETTINGS_SUB_OFF  8280, block, 2070, 58, 29, 45, 23
#define SETTINGS_SUB_INF  10350, block, 2070, 58, 29, 45, 23
#define SETTINGS_SUB_RES  12420, block, 2070, 58, 29, 45, 23
#define SETTINGS_SUB_LANG  14490, block, 2070, 58, 29, 45, 23

#define ENERGY_SUB_ON  16560, block, 2070, 57, 28, 45, 23
#define ENERGY_SUB_OFF  18630, block, 2070, 57, 28, 45, 23



#define FIRSTPAGE_uSv  47272, block, 2400, 60, 56, 60, 20
#define FIRSTPAGE_uR  49672, block, 2400, 60, 56, 60, 20
#define FIRSTPAGE_CPM  52072, block, 2400, 60, 56, 60, 20

#define LIMIT_downtext  54472, block, 2400, 69, 60, 60, 20

#define LIMIT_TEXT  21450, block, 2820, 66, 4, 94, 15
#define STAT_TEXT  24270, block, 2820, 66, 4, 94, 15
#define TIME_TEXT  27090, block, 2820, 66, 4, 94, 15
#define ENERGY_TEXT  29910, block, 2820, 66, 4, 94, 15
#define SETTINGS_TEXT  32730, block, 2820, 66, 4, 94, 15

#define LIMIT_SUB_DAY_TEXT_1  35550, block, 2880, 0, 0, 80, 18
#define LIMIT_SUB_DAY_TEXT_2  17280, block, 2880, 80, 0, 80, 18

#define TIME_SUB_HOURS_TEXT_1  38430, block, 2880, 0, 0, 80, 18
#define TIME_SUB_HOURS_TEXT_2  23040, block, 2880, 80, 0, 80, 18

#define SETTINGS_SUB_UNIT_TEXT_1  41310, block, 2880, 0, 0, 80, 18
#define SETTINGS_SUB_UNIT_TEXT_2  46080, block, 2880, 80, 0, 80, 18

#define ENERGY_SUB_SLEEP_TEXT_1  44190, block, 2880, 0, 0, 80, 18
#define ENERGY_SUB_SLEEP_TEXT_2  37440, block, 2880, 80, 0, 80, 18

//#define ENERGY_SUB_ECO_TEXT_1
//#define ENERGY_SUB_ECO_TEXT_2

//#define ENERGY_SUB_SOLAR_BAT_TEXT_1
//#define ENERGY_SUB_SOLAR_BAT_TEXT_2

#define LIMIT_SUB_AVG_TEXT_1  52830, block, 2880, 0, 0, 80, 18
#define LIMIT_SUB_AVG_TEXT_2  20160, block, 2880, 80, 0, 80, 18

#define TIME_SUB_MIN_TEXT_1  55710, block, 2880, 0, 0, 80, 18
#define TIME_SUB_MIN_TEXT_2  25920, block, 2880, 80, 0, 80, 18

#define SETTINGS_SUB_SOUND_TEXT_1  58590, block, 2880, 0, 0, 80, 18
#define SETTINGS_SUB_SOUND_TEXT_2  48960, block, 2880, 80, 0, 80, 18

#define TIME_SUB_DAY_TEXT_1  61470, block, 2880, 0, 0, 80, 18
#define TIME_SUB_DAY_TEXT_2  28800, block, 2880, 80, 0, 80, 18

#define SETTINGS_SUB_LIGHT_TEXT_1  0, block, 2880, 0, 0, 80, 18
#define SETTINGS_SUB_LIGHT_TEXT_2  51840, block, 2880, 80, 0, 80, 18

#define TIME_SUB_MONTH_TEXT_1  2880, block, 2880, 0, 0, 80, 18
#define TIME_SUB_MONTH_TEXT_2  31680, block, 2880, 80, 0, 80, 18

#define SETTINGS_SUB_RES_TEXT_1  5760, block, 2880, 0, 0, 80, 18
#define SETTINGS_SUB_RES_TEXT_2  54720, block, 2880, 80, 0, 80, 18

#define TIME_SUB_YEAR_TEXT_1  8640, block, 2880, 0, 0, 80, 18
#define TIME_SUB_YEAR_TEXT_2  34560, block, 2880, 80, 0, 80, 18

#define SETTINGS_SUB_INF_TEXT_1  11520, block, 2880, 0, 0, 80, 18
#define SETTINGS_SUB_INF_TEXT_2  57600, block, 2880, 80, 0, 80, 18

#define SETTINGS_SUB_LANG_TEXT_1 14400, block, 2880, 0, 0, 80, 18
#define SETTINGS_SUB_LANG_TEXT_2  60480, block, 2880, 80, 0, 80, 18

/////////LANGUAGE END




///////NITRATE Картинки продуктов START//////////////////////////

extern const uint16_t L1_data[];
extern const uint16_t L10_data[];
extern const uint16_t L11_data[];
extern const uint16_t L12_data[];
extern const uint16_t L13_data[];
extern const uint16_t L14_data[];
extern const uint16_t L15_data[];
extern const uint16_t L16_data[];
extern const uint16_t L17_data[];
extern const uint16_t L18_data[];
extern const uint16_t L19_data[];
extern const uint16_t L2_data[];
extern const uint16_t L20_data[];
extern const uint16_t L21_data[];
extern const uint16_t L22_data[];
extern const uint16_t L23_data[];
extern const uint16_t L24_data[];
extern const uint16_t L25_data[];
extern const uint16_t L26_data[];
extern const uint16_t L27_data[];
extern const uint16_t L28_data[];
extern const uint16_t L29_data[];
extern const uint16_t L3_data[];
extern const uint16_t L30_data[];
extern const uint16_t L31_data[];
extern const uint16_t L32_data[];
extern const uint16_t L33_data[];
extern const uint16_t L34_data[];
extern const uint16_t L35_data[];
extern const uint16_t L36_data[];
extern const uint16_t L37_data[];
extern const uint16_t L38_data[];
extern const uint16_t L39_data[];
extern const uint16_t L4_data[];
extern const uint16_t L40_data[];
extern const uint16_t L41_data[];
extern const uint16_t L42_data[];
extern const uint16_t L43_data[];
extern const uint16_t L44_data[];
extern const uint16_t L45_data[];
extern const uint16_t L46_data[];
extern const uint16_t L47_data[];
extern const uint16_t L48_data[];
extern const uint16_t L49_data[];
extern const uint16_t L5_data[];
extern const uint16_t L50_data[];
extern const uint16_t L51_data[];
extern const uint16_t L52_data[];
extern const uint16_t L53_data[];
extern const uint16_t L54_data[];
extern const uint16_t L55_data[];
extern const uint16_t L56_data[];
extern const uint16_t L57_data[];
extern const uint16_t L58_data[];
extern const uint16_t L59_data[];
extern const uint16_t L6_data[];
extern const uint16_t L60_data[];
extern const uint16_t L61_data[];
extern const uint16_t L7_data[];
extern const uint16_t L8_data[];
extern const uint16_t L9_data[];
extern const uint16_t M1_data[];
extern const uint16_t M10_data[];
extern const uint16_t M11_data[];
extern const uint16_t M12_data[];
extern const uint16_t M13_data[];
extern const uint16_t M14_data[];
extern const uint16_t M15_data[];
extern const uint16_t M16_data[];
extern const uint16_t M17_data[];
extern const uint16_t M18_data[];
extern const uint16_t M19_data[];
extern const uint16_t M2_data[];
extern const uint16_t M20_data[];
extern const uint16_t M21_data[];
extern const uint16_t M22_data[];
extern const uint16_t M23_data[];
extern const uint16_t M24_data[];
extern const uint16_t M25_data[];
extern const uint16_t M26_data[];
extern const uint16_t M27_data[];
extern const uint16_t M28_data[];
extern const uint16_t M29_data[];
extern const uint16_t M3_data[];
extern const uint16_t M30_data[];
extern const uint16_t M31_data[];
extern const uint16_t M32_data[];
extern const uint16_t M33_data[];
extern const uint16_t M34_data[];
extern const uint16_t M35_data[];
extern const uint16_t M36_data[];
extern const uint16_t M37_data[];
extern const uint16_t M38_data[];
extern const uint16_t M39_data[];
extern const uint16_t M4_data[];
extern const uint16_t M40_data[];
extern const uint16_t M41_data[];
extern const uint16_t M42_data[];
extern const uint16_t M43_data[];
extern const uint16_t M44_data[];
extern const uint16_t M45_data[];
extern const uint16_t M46_data[];
extern const uint16_t M47_data[];
extern const uint16_t M48_data[];
extern const uint16_t M49_data[];
extern const uint16_t M5_data[];
extern const uint16_t M50_data[];
extern const uint16_t M51_data[];
extern const uint16_t M52_data[];
extern const uint16_t M53_data[];
extern const uint16_t M54_data[];
extern const uint16_t M55_data[];
extern const uint16_t M56_data[];
extern const uint16_t M57_data[];
extern const uint16_t M58_data[];
extern const uint16_t M59_data[];
extern const uint16_t M6_data[];
extern const uint16_t M60_data[];
extern const uint16_t M61_data[];
extern const uint16_t M7_data[];
extern const uint16_t M8_data[];
extern const uint16_t M9_data[];

///////NITRATE Картинки продуктов END//////////////////////////

#define LOADING_1 8,0,52,52
#define LOADING_2 8,5408,52,52
#define LOADING_3 8,10816,52,52

#define LOADING_BAR 8
#define LOADING_BAR_AMOUNT 10

#define CHECK_MARK_M 8,39774, 32, 30
#define EXCLAMATION_MARK_M 8,41664, 32, 30
#define CROSS_MARK_M 8,43584, 32, 30
#define ARROW_MAIN_LIGHT_RIGHT 8, 58770, 8, 14, 147, 33



