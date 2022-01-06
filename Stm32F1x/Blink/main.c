#include "stm32f10x.h"                  // Device header

int main()
{
	RCC->APB2ENR |= (1 << 4);  //enable clock for PortC 
	GPIOC->CRH 
	return 0;
}
