#include "stm32f4xx.h"                  // Device header

int main(void)
{
//to use HSE bit 16 as Clock Source
	RCC->CR |= (1 << 16);
	//wait till HSE RDY bit 17 becomes HIGH (1)
	while(!(RCC->CR & (1 << 17)));
	//select HSE as system clock
	//first clear the bits to set.
	RCC->CFGR &= ~(0x3u << 0);
	//set the required bits. (01) for HSE as system clock set bit 0 to HIGH
	RCC->CFGR |= (1 << 0);
	
	
	return 0;
}
