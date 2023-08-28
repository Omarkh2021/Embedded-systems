/*
 * main.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Omar
 */

#include <avr/io.h>
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/interrupt.h>
#include "LCD.h"
#define ACD_Data *((volatile u16*)(0x24))
void main(){
	f32 angle=70.5;
	f32 DC=6;
	u16 DigitalData=0;
	DDRD=0x20;
	ICR1=20000;
	DC=(angle/180)*5+5;
	OCR1A=(DC/100)*ICR1;
	TCCR1A=0x82;
	TCCR1B=0x19;
	//ini for ACD Ch0
	ADMUX=0;
	//enable for circuit
	SET_BIT(ADCSRA,ADEN);
	LCD_voidInti();
	while(1){
		//start convrsion
		SET_BIT(ADCSRA,ADSC);
		//wait to end
		while(GET_BIT(ADCSRA,ADIF)==0);
		DigitalData=ACD_Data;
		void_LCDWriteNumber(DigitalData);
		//DC=??
		//OCR1A=(DC/100)*ICR1;
		_delay_ms(200);
		LCD_voidSendCommand(Clear_display);
	}

}
