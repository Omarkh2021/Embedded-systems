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
#define lcd_FunctionSet8bit 		 0x38

#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

#define LCD_Data_PORT 		PORTD
#define LCD_CONTROL_PORT 	PORTB

#define LCD_Data_PORT_DDR 		DDRD
#define LCD_CONTROL_PORT_DDR 	DDRB

#define RS_pin	PIN0
#define RW_pin	PIN1
#define E_pin	PIN2

void LCD_voidSendData(u8 copy_u8Data);
void LCD_voidSendCommand(u8 copy_u8Command);
void LCD_voidInti(void);
void LCD_voidSetCursorLocation(u8 copy_u8Row,u8 copy_u8column);
void LCD_voidWriteString(u8 * u8Ptrstring);
void LCD_voidSaveCustomChar(u8 * u8PtrArr,u8 copy_u8Savelocation);
#endif /* LCD_H_ */
