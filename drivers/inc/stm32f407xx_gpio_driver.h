/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: 30-May-2026
 *      Author: Krishna M
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_
#include "stm32f407xx.h"

typedef struct{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

//GPIO Handle Structure
typedef struct{
	//Pointer to hold the address of GPIO Peripheral
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_pinConfig;
}GPIO_Handle_t;

//Clock
void GPIO_PeripheralClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber, uint8_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t value);


void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);

//GPIO Mode Register macro
#define MODE_INPUT        0
#define MODE_OUTPUT       1
#define MODE_ALTFN        2
#define MODE_ANALOG       3
#define MODE_INT_FT       4
#define MODE_INT_RT       5
#define MODE_INT_FRT      6

//GPIO OTYPER Register macro
#define OTYPER_PP         0
#define OTYPER_OD         1

//GPIO OSPEEDR Register macro
#define OSPEEDR_LS        0
#define OSPEEDR_MS        1
#define OSPEEDR_HS        2
#define OSPEEDR_VHS       3


//GPIO PUPDR Register macro
#define PUPDR_NPU         0
#define PUPDR_PU          1
#define PUPDR_PD          3







#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
