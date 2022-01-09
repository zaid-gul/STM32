/**
*********************************************************************************************************
*
*  @file    led.h
*  @version 1.0
*  @author  Zaid Gul
*  
*********************************************************************************************************
*/
#ifndef LED_H
#define LED_H

/***********************************/
#include "gpio_driver.h"
/***********************************/

/*LED connected to pin PA5*/
#define 	LED 			5 

/*Delay function*/
#define 	DELAY()		for(int i = 0; i < 10000; i++);

/**
	*@brief  Initialize the LED 
	*@param  None
	*@retval None
	*/
void LED_INIT(void);

/**
	*@brief  Turns the LED ON 
	*@param  GPIO Port (example: GPIOA)
	*@param  Pin no (example: PA5)
	*@retval None
	*/
void LED_ON(GPIO_TypeDef *GPIOx, uint16_t Pin_no);

/**
	*@brief  Turns the LED OFF 
	*@param  GPIO Port (example: GPIOA)
	*@param  Pin no (example: PA5)
	*@retval None
	*/
void LED_OFF(GPIO_TypeDef *GPIOx, uint16_t Pin_no);

/**
	*@brief  Toggle the LED
	*@param  GPIO Port (example: GPIOA)
	*@param  Pin no (example: PA5)
	*@retval None
	*/
void LED_TOGGLE(GPIO_TypeDef *GPIOx, uint16_t Pin_no);
#endif
