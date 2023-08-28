#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include <avr/io.h>
#include <avr/delay.h>
#include"LCD.h"
#include"main.h"
#define F_CPU 1000000
/*C1->P0,C2->P1,C3->P2,C4->P3(PORTA)*/
void main(){
	DDRA=0x0F;
	s8 counter;
	u8 pins[5]={3,0,1,2,3};
	while(1){

		for(counter=0;counter<5;counter++){
			SET_BIT(PORTA,pins[counter+1]);
			CLR_BIT(PORTA,pins[counter]);
			_delay_ms(300);
			_delay_us(500);
		}
		_delay_ms(500);

		for(counter=5;counter>=0;counter--){
					SET_BIT(PORTA,pins[counter]);
					CLR_BIT(PORTA,pins[counter+1]);
					_delay_ms(300);
					_delay_us(500);
				}
		_delay_ms(500);
}
}
