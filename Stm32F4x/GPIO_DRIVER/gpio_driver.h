#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "stm32f4xx.h"                  // Device header


/***************************************************************************************************************************************************************/
/*																																																																														 */
/*											          Macros used for GPIO pin Initialization																																									 */
/*																																																																														 */
/***************************************************************************************************************************************************************/

/* GPIO Mode Register (GPIOx_MODER) */
#define GPIO_INPUT_MODE                       ((uint32_t) (0 << 0))
#define GPIO_OUTPUT_MODE                      ((uint32_t) (1 << 0))
#define GPIO_ALT_MODE                         ((uint32_t) (1 << 1))

/* GPIO Output type Register (GPIOx_OTYPER) */
#define OUTPUT_PUSH_PULL                       ((uint32_t) (0 << 0))
#define OUTPUT_OPEN_DRAIN                      ((uint32_t) (1 << 0))

/* GPIO Output speed Register (GPIOx_OSPEEDR) */
#define GPIO_LOW_SPEED                         ((uint32_t) (0 << 0))
#define GPIO_MEDIUM_SPEED                      ((uint32_t) (1 << 0))
#define GPIO_FAST_SPEED                        ((uint32_t) (1 << 1))
#define GPIO_HIGH_SPEED                        ((uint32_t) (1 << 0) | (1 << 1))

/* GPIO Pull up/Pull down Register (GPIOx_PUPDR) */
#define GPIO_NO_PUP_DWN                         ((uint32_t) (0 << 0))
#define GPIO_PULL_UP                            ((uint32_t) (1 << 0))
#define GPIO_PULL_DOWN                          ((uint32_t) (1 << 1))

/* Enable Clock for different GPIO Ports (RCC_AHB1ENR) */
#define GPIOA_CLK_ENABLE()                      (RCC->AHB1ENR |= (1 << 0)) 
#define GPIOB_CLK_ENABLE()                      (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_CLK_ENABLE()                      (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_CLK_ENABLE()                      (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_CLK_ENABLE()                      (RCC->AHB1ENR |= (1 << 4)) 
#define GPIOF_CLK_ENABLE()                      (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_CLK_ENABLE()                      (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_CLK_ENABLE()                      (RCC->AHB1ENR |= (1 << 7))


/***************************************************************************************************************************************************************/
/*																																																																														 */
/*											          Data Structure for GPIO pin Initialization																																									 */
/*																																																																														 */
/***************************************************************************************************************************************************************/

typedef struct
{
	uint32_t Pin;   					//GPIO pin to be configured
	uint32_t Mode;  					//operating mode for the specific pin
	uint32_t OP_Type;   			//Output type for the selected pin 
	uint32_t Speed;     			//operating speed of the pin
	uint32_t Pupdwn;    			//pull up or pull down activation for the selected pin
	uint32_t Alternate_Func;  //alternate function (USART, ADC, SPI, I2C)
}GPIO_PIN_CONFIG;


/***************************************************************************************************************************************************************/
/*																																																																														 */
/*											          Driver exposed APIs																																									 */
/*																																																																														 */
/***************************************************************************************************************************************************************/
/**
	*@brief Initializes GPIO Pin
	*@param *GPIOx   					 : GPIO Port Base Address
	*@param *gpio_port_config  : Pointer to the GPIO_PIN_CONFIG structure
	*@retval None
	*/
void GPIO_INIT(GPIO_TypeDef *GPIOx, GPIO_PIN_CONFIG *gpio_pin_config);

/**
	*@brief Read value from Pin
	*@param *GPIOx   : GPIO Port Base Address
	*@param Pin_No 	 : GPIO Pin Number
	*@retval uint8_t : Value read
	*/
uint8_t GPIO_READ(GPIO_TypeDef *GPIOx, uint16_t Pin_no);

/**
	*@brief Write value to a specific Pin
	*@param *GPIOx   : GPIO Port Base Address
	*@param Pin_No 	 : GPIO Pin Number
	*@param val 	 	 : value to write on pin
	*@retval None
	*/
void GPIO_WRITE(GPIO_TypeDef *GPIOx, uint16_t Pin_no, uint8_t value);

/**
	*@brief Alternate function for Pin (ADC, USART, SPI, I2C)
	*@param *GPIOx         : GPIO Port Base Address
	*@param Pin_No 	 			 : GPIO Pin Number
	*@param alt_func_val 	 : alternate function
	*@retval None
	*/
void GPIO_SET_ALT(GPIO_TypeDef *GPIOx, uint16_t Pin_no, uint16_t alt_func_val);



#endif
