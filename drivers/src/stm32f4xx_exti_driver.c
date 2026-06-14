/*
 * stm32f4xx_exti_driver.c
 *
 *  Created on: 14-Jun-2026
 *      Author: Krishna M
 */
#include "stm32f4xx_exti_drivers.h"

void EXTIConfig(EXTI_Handle_t *pEXTIHandle){
	pEXTIHandle->pEXTI->EXTI_IMR |= (1<<pEXTIHandle->pEXTIConfig.pinNumber);

	if(pEXTIHandle->pEXTIConfig.triggerType == RT){
		pEXTIHandle->pEXTI->EXTI_RTSR |= (1<<pEXTIHandle->pEXTIConfig.pinNumber);
	}
	else if(pEXTIHandle->pEXTIConfig.triggerType == FT){
		pEXTIHandle->pEXTI->EXTI_FTSR |= (1<<pEXTIHandle->pEXTIConfig.pinNumber);
	}

}

void NVIC_ISER_Configure(uint32_t IRQ_Number,NVIC_ISER_regDef_t *IRQ_Handle){
	uint32_t Register = IRQ_Number / 32;

	uint32_t Position  = IRQ_Number % 32;

	IRQ_Handle->NVIC_ISERx[Register] |= (1<<Position);
}
