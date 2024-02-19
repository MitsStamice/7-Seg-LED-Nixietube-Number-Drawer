/*
by Mits Stamice,2024.2.19

Instructions:
This is a munber drawer to select a number from 0 to a number less than 10.
It is initially setted to draw number from 0 to 9.
Please press the key on Pin_A0(abbreviated as Key0) to start drawing.
And press it again to stop it.
If you want to change the upper limit number,press Key10 to set it.
If you don't want '0' in number selecting,press Key9 to remove or undo it.
*/
#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"

uint8_t Key;

int main(void)
{
	int Num = 9,ifOne = 0,i = 1,j = 0;
	//'Num' is the biggest number in number drawing.
	//'ifOne' is judgement if zero should be removed.
	//'i','j','k' is a temporary loop variable.
	LED_Init();
	Key_Init();
	//Init key and LED.
	
	LED_Set(Num);
	
	for(;;){
		Key = Key_GetNum();
		if(Key == 1){
			j = (j+1)%2;
		}
		if(j == 1){
		    i++;
			if(i > Num) i = ifOne;
			Delay_ms(10);
		}
		if(Key == 2 && j == 0){
		    Num = i;
			if(i == 9) Num = ifOne;
			Num++;
			i = Num;
		}
		if(Key == 3 && j == 0){
			ifOne = (ifOne + 1) % 2;
			if(i == 1){
				i++; Num++;
			}
		}
		LED_Set(i);
	}
}
