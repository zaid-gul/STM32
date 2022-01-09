/**
*********************************************************************************************************
*
*  @file    gpio_driver.c
*  @version 1.0
*  @author  Zaid Gul
*  
*********************************************************************************************************
*/

/***********************************/
#include<stdint.h>
#include "gpio_driver.h"
/***********************************/

/**
	*@brief Initializes GPIO Pin
	*@param *GPIOx   					 : GPIO Port Base Address
	*@param *gpio_port_config  : Pointer to the GPIO_PIN_CONFIG structure
	*@retval None
	*/
void GPIO_INIT(GPIO_TypeDef *GPIOx, GPIO_PIN_CONFIG *gpio_pin_config)
{
	PIN_MODE(GPIOx, gpio_pin_config->Pin, gpio_pin_config->Mode);
	PIN_SPEED(GPIOx, gpio_pin_config->Pin, gpio_pin_config->Speed);
	OUTPUT_TYPE(GPIOx, gpio_pin_config->Pin, gpio_pin_config->OP_Type);
	PULL_UP_DOWN(GPIOx, gpio_pin_config->Pin, gpio_pin_config->Pupdwn);
}

/**
	*@brief Write value to a specific Pin
	*@param *GPIOx   : GPIO Port Base Address
	*@param Pin_No 	 : GPIO Pin Number
	*@param val 	 	 : value to write on pin
	*@retval None
	*/
void GPIO_WRITE(GPIO_TypeDef *GPIOx, uint16_t Pin_no, uint8_t value)
{
	if(value)
			{
				GPIOx->ODR |= (1 << Pin_no);  //set pin to HIGH
			}
	else
			{
				GPIOx->ODR &= ~(1 << Pin_no);  //set pin to LOW
			}
}

/**
	*@brief Read value from Pin
	*@param *GPIOx   : GPIO Port Base Address
	*@param Pin_No 	 : GPIO Pin Number
	*@retval uint8_t : Value read
	*/
uint8_t GPIO_READ(GPIO_TypeDef *GPIOx, uint16_t Pin_no)
{
	uint8_t value = 0;
	value = (GPIOx->IDR & (1 << Pin_no)); 
	return value;
}

/**
	*@brief Alternate function for Pin (ADC, USART, SPI, I2C)
	*@param *GPIOx         : GPIO Port Base Address
	*@param Pin_No 	 			 : GPIO Pin Number
	*@param alt_func_val 	 : alternate function
	*@retval None
	*/
void GPIO_SET_ALT(GPIO_TypeDef *GPIOx, uint16_t Pin_no, uint32_t alt_func_val)
{
	if(Pin_no <= 7)
	{
		GPIOx->AFR[0] |= (alt_func_val << (Pin_no * 4));	
	}
	else
	{		
		GPIOx->AFR[1] |= (alt_func_val << ((Pin_no - 8) * 4));
	}
}

/**
	*@brief  Configures the mode of a pin : input, output, alt or analog mode 
	*@param  *GPIOx : GPIO Port Base Dddress
	*@param  Pin_no : GPIO Pin Number 
	*@param  Mode   : mode to be configured
	*@retval None
	*/
void PIN_MODE(GPIO_TypeDef *GPIOx, uint16_t Pin_no, uint32_t Mode)
{
	GPIOx->MODER &= ~(0x03u << (2 * Pin_no)); //clear bits
	GPIOx->MODER |=  (Mode  << (2 * Pin_no)); //set bits
}

/**
	*@brief  Configures the speed of a pin 
	*@param  *GPIOx : GPIO Port Base Dddress
	*@param  Pin_no : GPIO Pin Number 
	*@param  Mode   : mode to be configured
	*@retval None
	*/
void PIN_SPEED(GPIO_TypeDef *GPIOx, uint16_t Pin_no, uint32_t Speed)
{
	GPIOx->OSPEEDR |=  (Speed  << (2 * Pin_no)); //set bits
}

/**
	*@brief  Configures the output type of a pin 
	*@param  *GPIOx    : GPIO Port Base Dddress
	*@param  Pin_no 	 : GPIO Pin Number 
	*@param  OP_Type   : output type
	*@retval None
	*/
void OUTPUT_TYPE(GPIO_TypeDef *GPIOx, uint16_t Pin_no, uint32_t OP_Type)
{
	GPIOx->OTYPER |=  (OP_Type  << Pin_no); //set bits
}

/**
	*@brief  Activates the internal pull up or pull down resistor
	*@param  *GPIOx 	: GPIO Port Base Dddress
	*@param  Pin_no 	: GPIO Pin Number 
	*@param  Pupdwn   : pull up or pull down resistor 
	*@retval None
	*/
void PULL_UP_DOWN(GPIO_TypeDef *GPIOx, uint16_t Pin_no, uint32_t Pupdwn)
{
	GPIOx->PUPDR |=  (Pupdwn  << (2 * Pin_no)); //set bits
}
