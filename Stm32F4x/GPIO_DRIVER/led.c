/**
*********************************************************************************************************
*
*  @file    led.c
*  @version 1.0
*  @author  Zaid Gul
*  
*********************************************************************************************************
*/
/***********************************/
#include "led.h"
#include<stdint.h>
#include "gpio_driver.h"
/***********************************/

/**
	*@brief  Initialize the LED 
	*@param  None
	*@retval None
	*/
void LED_INIT(void)
{
	/*Enable Port A clock*/
	GPIOA_CLK_ENABLE(); 
	
	/*LED Configuration*/
	GPIO_PIN_CONFIG LED_PIN;
	LED_PIN.Pin = LED;
	LED_PIN.Mode = GPIO_OUTPUT_MODE;
	LED_PIN.OP_Type = GPIO_NO_PUP_DWN;
	LED_PIN.Speed = GPIO_FAST_SPEED;
	
	GPIO_INIT(GPIOA, &LED_PIN);
}

/**
	*@brief  Turns the LED ON 
	*@param  GPIO Port (example: GPIOA)
	*@param  Pin no (example: PA5)
	*@retval None
	*/
void LED_ON(GPIO_TypeDef *GPIOx, uint16_t Pin_no)
{
	GPIO_WRITE(GPIOx, Pin_no, 1);
}

/**
	*@brief  Turns the LED OFF 
	*@param  GPIO Port (example: GPIOA)
	*@param  Pin no (example: PA5)
	*@retval None
	*/
void LED_OFF(GPIO_TypeDef *GPIOx, uint16_t Pin_no)
{
	GPIO_WRITE(GPIOx, Pin_no, 0);
}

/**
	*@brief  Toggle the LED
	*@param  GPIO Port (example: GPIOA)
	*@param  Pin no (example: PA5)
	*@retval None
	*/
void LED_TOGGLE(GPIO_TypeDef *GPIOx, uint16_t Pin_no);
