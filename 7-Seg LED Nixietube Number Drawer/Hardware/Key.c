#include "stm32f10x.h"                  // Device header

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_9 | GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_0 | GPIO_Pin_9 | GPIO_Pin_10);
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;
	/*  This function is to set key on pin 0,9 and 10.
	    The propouse of key is to:
	Key0: Start drawing a number.
	Key9: Set range of number drawing.
	Key10:Remove or add 0 in number drawing.
	*/
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0) == 0){
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0) == 0);
		KeyNum = 1;
	}
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10) == 0){
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10) == 0);
		KeyNum = 2;
	}
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9) == 0){
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9) == 0);
		KeyNum = 3;
	}
	return KeyNum;
}
