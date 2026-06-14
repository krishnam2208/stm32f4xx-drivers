/*
 * stm32f4xx_exti_drivers.h
 *
 *  Created on: 14-Jun-2026
 *      Author: Krishna M
 */

#ifndef INC_STM32F4XX_EXTI_DRIVERS_H_
#define INC_STM32F4XX_EXTI_DRIVERS_H_
#include "stm32f407xx.h"

typedef struct{
  uint8_t pinNumber;
  uint8_t triggerType;
}EXTI_PinConfig_t;

typedef struct{
	EXTI_regDef_t *pEXTI;
	EXTI_PinConfig_t pEXTIConfig;
}EXTI_Handle_t;

void EXTIConfig(EXTI_Handle_t *pEXTIHandle);
void NVIC_ISER_Configure(uint32_t IRQ_Number,NVIC_ISER_regDef_t *IRQ_Handle);
#endif /* INC_STM32F4XX_EXTI_DRIVERS_H_ */
