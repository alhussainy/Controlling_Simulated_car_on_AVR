/*
 * LCD.c
 *
 * Created: 05/01/2022 01:22:01 م
 *  Author: Alhussainy Khaled Anwar
 */ 

#include "LCD_CFG.h"
#include "LCD.h"
#include "DIO.h"
#include "REG.h"
#define F_CPU    16000000UL
#include <util/delay.h>
//
//void LCD_INIT(void)
//{
	//PIN_MODE(LCD_RW_PIN,OUTPUT);
	//PIN_WRITE(LCD_RW_PIN,LOW);
	//#if LCD_MODE    ==     _8_BIT_MODE
	//PORT_MODE(LCD_DATA_PORT,OUTPUT);
	//PIN_MODE(LCD_RS_PIN,OUTPUT);
	//PIN_MODE(LCD_EN_PIN,OUTPUT);
	///***_THIS_COMMAND_TO_ACTIVE_8_BIT_MODE_***/
	//LCD_WRITE_CMD(0x38);
	//LCD_WRITE_CMD(0x0C);   /***_THIS_COMMAND_TO_TURN_ON_DISPLAY_AND_TURN_OFF_CURSOR_***/
	//LCD_WRITE_CMD(0x01);   /***_THIS_COMMAND_TO_CLEAR_LCD_*****************************/
	//LCD_WRITE_CMD(0x06);   /***_THIS_COMMAND_TO_MOVE_CURSOR_FROM_LEFT_TO_RIGHT_********/
	//LCD_WRITE_CMD(0x02);   /***_THIS_COMMAND_TO_RETURN_HOME_***************************/
	//#elif LCD_MODE   ==   _4_BIT_MODE
	//PIN_MODE(LCD_DATA_PIN_4,OUTPUT);
	//PIN_MODE(LCD_DATA_PIN_5,OUTPUT);
	//PIN_MODE(LCD_DATA_PIN_6,OUTPUT);
	//PIN_MODE(LCD_DATA_PIN_7,OUTPUT);
	//PIN_MODE(LCD_RS_PIN,OUTPUT);
	//PIN_MODE(LCD_EN_PIN,OUTPUT);
	///***_THIS_COMMAND_TO_ACTIVE_4_BIT_MODE_***/
	//LCD_WRITE_CMD(0x33);
	//LCD_WRITE_CMD(0x32);
	//LCD_WRITE_CMD(0x28);
	//
	//LCD_WRITE_CMD(0x0C);   /***_THIS_COMMAND_TO_TURN_ON_DISPLAY_AND_TURN_OFF_CURSOR_***/
	//LCD_WRITE_CMD(0x01);   /***_THIS_COMMAND_TO_CLEAR_LCD_*****************************/
	//LCD_WRITE_CMD(0x06);   /***_THIS_COMMAND_TO_MOVE_CURSOR_FROM_LEFT_TO_RIGHT_********/
	//LCD_WRITE_CMD(0x02);   /***_THIS_COMMAND_TO_RETURN_HOME_***************************/
	//#endif
//
	//
//}
//void LCD_WRITE_CHR(u8 character)
//{
	//#if LCD_MODE    ==     _8_BIT_MODE
	//PIN_WRITE(LCD_RS_PIN,HIGH);
	//PORT_WRITE(LCD_DATA_PORT,character);
	//PIN_WRITE(LCD_EN_PIN,HIGH);
	//_delay_ms(1);
	//PIN_WRITE(LCD_EN_PIN,LOW);
	//_delay_ms(5);
	//#elif LCD_MODE    ==     _4_BIT_MODE	
	//PIN_WRITE(LCD_RS_PIN,HIGH);
	///*to send first half byte*/
	//PORT_WRITE(LCD_DATA_PORT,(((character ) & 0b11110000) | (PORT_READ(LCD_DATA_PORT) & 0b00001111)));
	//PIN_WRITE(LCD_EN_PIN,HIGH);
	//_delay_ms(1);
	//PIN_WRITE(LCD_EN_PIN,LOW);
	//_delay_ms(5);
	///*to send second half byte*/
	//PORT_WRITE(LCD_DATA_PORT,(((character << 4) & 0b11110000) | (PORT_READ(LCD_DATA_PORT) & 0b00001111)));
	//PIN_WRITE(LCD_EN_PIN,HIGH);
	//_delay_ms(1);
	//PIN_WRITE(LCD_EN_PIN,LOW);
	//_delay_ms(5);
	//#endif
//}
//void LCD_WRITE_CMD(u8 command)
//{
	//#if LCD_MODE    ==     _8_BIT_MODE
	//PIN_WRITE(LCD_RS_PIN,LOW);
	//PORT_WRITE(LCD_DATA_PORT,command);
	//PIN_WRITE(LCD_EN_PIN,HIGH);
	//_delay_ms(1);
	//PIN_WRITE(LCD_EN_PIN,LOW);
	//_delay_ms(5);
	//#elif LCD_MODE    ==     _4_BIT_MODE
	//PIN_WRITE(LCD_RS_PIN,LOW);
	///*to send first half byte*/
	//PORT_WRITE(LCD_DATA_PORT,(((command ) & 0b11110000) | (PORT_READ(LCD_DATA_PORT) & 0b00001111)));
	//PIN_WRITE(LCD_EN_PIN,HIGH);
	//_delay_ms(1);
	//PIN_WRITE(LCD_EN_PIN,LOW);
	//_delay_ms(5);
	///*to send second half byte*/
	//PORT_WRITE(LCD_DATA_PORT,(((command << 4) & 0b11110000) | (PORT_READ(LCD_DATA_PORT) & 0b00001111)));
	//PIN_WRITE(LCD_EN_PIN,HIGH);
	//_delay_ms(1);
	//PIN_WRITE(LCD_EN_PIN,LOW);
	//_delay_ms(5);
	//#endif
//}
//void LCD_WRITE_STR(u8*p)
//{
	//u8 i = 0;
	//while(p[i] != '\0')
	//{
		//LCD_WRITE_CHR(p[i]);
		//i++;
	//}
//}
//void LCD_CLR(void)
//{
	//LCD_WRITE_CMD(0x01);
//}
//void LCD_WRITE_INT(u32 num) 
//{
	//u32 rem = 0;
	//u8 arr [16];
	//s8 i = 0;
	//while(num != 0)
	//{
		//rem = num % 10;
		//arr[i] = rem + 48;
		//i++;
		//num = num / 10;
	//}
	//i--;
	//while(i > -1)
	//{
		//LCD_WRITE_CHR(arr[i]);
		//i--;
	//}
//}
//void LCD_GO_TO(u8 row,u8 col)
//{
	//u8 Loc[2] = {0x80 , 0xC0};
	//LCD_WRITE_CMD(Loc[row]+col);
//}



void LCD_INIT(void)
{
	#if LCD_MODE    ==     _8_BIT_MODE
	PORT_MODE(LCD_DATA_PORT,OUTPUT);
	PIN_MODE(LCD_RS_PIN,OUTPUT);
	PIN_MODE(LCD_EN_PIN,OUTPUT);
	/***_THIS_COMMAND_TO_ACTIVE_8_BIT_MODE_***/
	LCD_WRITE_CMD(0x38);
	LCD_WRITE_CMD(0x0C);   /***_THIS_COMMAND_TO_TURN_ON_DISPLAY_AND_TURN_OFF_CURSOR_***/
	LCD_WRITE_CMD(0x01);   /***_THIS_COMMAND_TO_CLEAR_LCD_*****************************/
	LCD_WRITE_CMD(0x06);   /***_THIS_COMMAND_TO_MOVE_CURSOR_FROM_LEFT_TO_RIGHT_********/
	LCD_WRITE_CMD(0x02);   /***_THIS_COMMAND_TO_RETURN_HOME_***************************/
	#elif LCD_MODE   ==   _4_BIT_MODE
	PIN_MODE(LCD_DATA_PIN_4,OUTPUT);
	PIN_MODE(LCD_DATA_PIN_5,OUTPUT);
	PIN_MODE(LCD_DATA_PIN_6,OUTPUT);
	PIN_MODE(LCD_DATA_PIN_7,OUTPUT);
	PIN_MODE(LCD_RS_PIN,OUTPUT);
	PIN_MODE(LCD_EN_PIN,OUTPUT);
	/***_THIS_COMMAND_TO_ACTIVE_4_BIT_MODE_***/
	LCD_WRITE_CMD(0x33);
	LCD_WRITE_CMD(0x32);
	LCD_WRITE_CMD(0x28);
	
	LCD_WRITE_CMD(0x0C);   /***_THIS_COMMAND_TO_TURN_ON_DISPLAY_AND_TURN_OFF_CURSOR_***/
	LCD_WRITE_CMD(0x01);   /***_THIS_COMMAND_TO_CLEAR_LCD_*****************************/
	LCD_WRITE_CMD(0x06);   /***_THIS_COMMAND_TO_MOVE_CURSOR_FROM_LEFT_TO_RIGHT_********/
	LCD_WRITE_CMD(0x02);   /***_THIS_COMMAND_TO_RETURN_HOME_***************************/
	#endif
}
void LCD_WRITE_CHR(u8 character)
{
	#if LCD_MODE    ==     _8_BIT_MODE
	PIN_WRITE(LCD_RS_PIN,HIGH);
	PORT_WRITE(LCD_DATA_PORT,character);
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#elif LCD_MODE    ==     _4_BIT_MODE
	PIN_WRITE(LCD_RS_PIN,HIGH);
	/*to send first half byte*/
	PORT_WRITE(LCD_DATA_PORT,(((character >> 1) & 0b01111000) | (PORT_READ(LCD_DATA_PORT) & 0b10000111)));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(5);
	/*to send second half byte*/
	PORT_WRITE(LCD_DATA_PORT,(((character << 3) & 0b01111000) | (PORT_READ(LCD_DATA_PORT) & 0b10000111)));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#endif
}
void LCD_WRITE_CMD(u8 command)
{
	#if LCD_MODE    ==     _8_BIT_MODE
	PIN_WRITE(LCD_RS_PIN,LOW);
	PORT_WRITE(LCD_DATA_PORT,command);
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#elif LCD_MODE    ==     _4_BIT_MODE
	PIN_WRITE(LCD_RS_PIN,LOW);
	/*to send first half byte*/
	PORT_WRITE(LCD_DATA_PORT,(((command >> 1) & 0b01111000) | (PORT_READ(LCD_DATA_PORT) & 0b10000111)));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(5);
	/*to send second half byte*/
	PORT_WRITE(LCD_DATA_PORT,(((command << 3) & 0b01111000) | (PORT_READ(LCD_DATA_PORT) & 0b10000111)));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#endif
}
void LCD_WRITE_STR(u8*p)
{
	u8 i = 0;
	while(p[i] != '\0')
	{
		LCD_WRITE_CHR(p[i]);
		i++;
	}
}
void LCD_CLR(void)
{
	LCD_WRITE_CMD(0x01);
}
void LCD_WRITE_INT(u32 num)
{
	u32 rem = 0;
	u8 arr [16];
	s8 i = 0;
	while(num != 0)
	{
		rem = num % 10;
		arr[i] = rem + 48;
		i++;
		num = num / 10;
	}
	i--;
	while(i > -1)
	{
		LCD_WRITE_CHR(arr[i]);
		i--;
	}
}
void LCD_GO_TO(u8 row,u8 col)
{
	u8 Loc[2] = {0x80 , 0xC0};
	LCD_WRITE_CMD(Loc[row]+col);
}
