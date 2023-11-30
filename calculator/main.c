/*
 * main.c
 *
 *  Created on: Sep 6, 2023
 *      Author: engy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "KPD_interface.h"
#include "LCD_interface.h"

int main()
{
	LCD_VidInit();
	KPD_VidInit();
	LCD_VidSendString_XY("WELCOME", 0, 4);
	LCD_VidSendString_XY("CALCULATOR", 1, 3);
	_delay_ms(50);
	LCD_VidClearScreen();

	u8 PressedKey,Operator = '\0';
	f32 Num1 = 0, Num2 = 0, Res;

	while (1)
	{
		PressedKey = Kpd_U8GetPressedKey();

		if (PressedKey >= '0' && PressedKey <= '9')
		{
			LCD_VidSendChar(PressedKey);
			if (Operator == '\0')
			{
				Num1 = Num1 * 10 + (PressedKey - '0');
			}
			else
			{
				Num2 = Num2 * 10 + (PressedKey - '0');
			}
		}
		else if (PressedKey == '+' || PressedKey == '-' || PressedKey == '*' || PressedKey == '/')
		{
			LCD_VidSendChar(PressedKey);
			Operator = PressedKey;
		}
		else if (PressedKey == '=')
		{
			LCD_VidSendChar(PressedKey);
			switch (Operator)
			{
				case '+':
					Res = Num1 + Num2;
					break;
				case '-':
					Res = Num1 - Num2;
					break;
				case '*':
					Res = Num1 * Num2;
					break;
				case '/':
					if (Num2 != 0)
					{
						Res = Num1 / Num2;
					}
					else
					{
						LCD_VidClearScreen();
						LCD_VidSendString("Division By Zero");
						continue;
					}
					break;
				default:
					LCD_VidClearScreen();
					LCD_VidSendString("Invalid Operator!");
			}

			LCD_VidSendFloat(Res);
			Num1 = Res;
			Num2 = 0;
			Operator = '\0';
		}
		else if (PressedKey == 'C')
		{
			LCD_VidClearScreen();
			Num1 = 0;
			Num2 = 0;
			Operator = '\0';
		}
	}

	return 0;
}

