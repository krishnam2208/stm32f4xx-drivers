/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: 30-May-2026
 *      Author: Krishna M
 */
#include "stm32f407xx_gpio_driver.h"

void GPIO_PeripheralClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi){


	if(EnorDi == ENABLE){
		if(pGPIOx == GPIOA){
			GPIOA_PCLK_EN();
		}
	}
	else{
		if(pGPIOx == GPIOA){
			GPIOA_PCLK_DI();
		}
	}
}

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
	// configure mode of GPIO PIN
	if(pGPIOHandle->GPIO_pinConfig.GPIO_PinMode <= MODE_ANALOG){
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2* pGPIOHandle->GPIO_pinConfig.GPIO_PinNumber));
           pGPIOHandle->pGPIOx->MODER |= (pGPIOHandle->GPIO_pinConfig.GPIO_PinMode << (2* pGPIOHandle->GPIO_pinConfig.GPIO_PinNumber));
	}
	else{
		// Interrupts Mode configure
	}

	// configure the speed
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2* pGPIOHandle->GPIO_pinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR |= (pGPIOHandle->GPIO_pinConfig.GPIO_PinOPType << (2* pGPIOHandle->GPIO_pinConfig.GPIO_PinNumber));

	// configure the Pupd settings
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2* pGPIOHandle->GPIO_pinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR |= (pGPIOHandle->GPIO_pinConfig.GPIO_PinPuPdControl << (2* pGPIOHandle->GPIO_pinConfig.GPIO_PinNumber));
	//configure the optype
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x3 << pGPIOHandle->GPIO_pinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= (pGPIOHandle->GPIO_pinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_pinConfig.GPIO_PinNumber);
	//configure alt functionality
	if(pGPIOHandle->GPIO_pinConfig.GPIO_PinMode == MODE_ALTFN){
       uint8_t temp1 = pGPIOHandle->GPIO_pinConfig.GPIO_PinNumber / 8;
       uint8_t temp2 = pGPIOHandle->GPIO_pinConfig.GPIO_PinNumber % 8;
       pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2));
       pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_pinConfig.GPIO_PinAltFunMode << (4 * temp2));
	}

}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){
   if(pGPIOx == GPIOA){
	   GPIOA_RESET();
	}
}

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
	uint16_t value ;
	value = (uint16_t)pGPIOx->IDR;
	return value;
}
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){
	uint8_t value ;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 1);
	return value;
}


void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber, uint8_t value){
	if(value == 0){
		pGPIOx->ODR &= ~(1<<PinNumber);
	}
	else{
		pGPIOx->ODR |= (1<<PinNumber);
	}
}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t value){
	pGPIOx->ODR = value;
}


void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber){
	pGPIOx->ODR ^= (1<<PinNumber);
}

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi){

}
void GPIO_IRQHandling(uint8_t PinNumber){

}

