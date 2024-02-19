#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_All);
}
void LED_Set(int a)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_All);
	if(a == 0) GPIO_SetBits(GPIOA,((uint16_t)0x003f));
	else if(a == 1) GPIO_SetBits(GPIOA,((uint16_t)0x0006));
	else if(a == 2) GPIO_SetBits(GPIOA,((uint16_t)0x005b));
	else if(a == 3) GPIO_SetBits(GPIOA,((uint16_t)0x004f));
	else if(a == 4) GPIO_SetBits(GPIOA,((uint16_t)0x0066));
	else if(a == 5) GPIO_SetBits(GPIOA,((uint16_t)0x006d));
	else if(a == 6) GPIO_SetBits(GPIOA,((uint16_t)0x007d));
	else if(a == 7) GPIO_SetBits(GPIOA,((uint16_t)0x0007));
	else if(a == 8) GPIO_SetBits(GPIOA,((uint16_t)0x007f));
	else if(a == 9) GPIO_SetBits(GPIOA,((uint16_t)0x006f));
	else GPIO_SetBits(GPIOA,((uint16_t)0x0040));
}

