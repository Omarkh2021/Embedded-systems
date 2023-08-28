/*
 * LCD.h
 *
 *  Created on: Aug 13, 2023
 *      Author: omar
 */

#ifndef LCD_H_
#define LCD_H_

#define Clear_display 				 0x01
	#define Return_home 				 0x02
	#define Entry_mode_set 				 0x06
	#define Display_OFF_Control		     0x08
	#define Display_ON_Control		     0x0C
	#define Cursor_or_Display_Shift		 0x80
	#define lcd_FunctionReset  			 0x30
	#define lcd_FunctionSet8bit 		 0x38â€�

#define LCD_DATA_PORT     PORTC
#define LCD_CONTROL_PORT  PORTD

#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

#define RS_PIN PIN0
#define E_PIN  PIN2
#define RW_PIN PIN1

#define LCD_DATA_PORT_DDR       DDRC
#define LCD_CONTROL_PORT_DDR    DDRD

void LCD_VOID_SEND_DATA(u8 COPY_U8_DATA);

void LCD_VOID_SEND_COMMAND(u8 COPY_U8_COMMAND);

void LCD_VOID_INIT(void);

void LCD_VOID_SET_CURSOR_LOCATION(u8 COPY_u8ROW,u8 COPY_U8COLUMN);

#endif /* LCD_H_ */
