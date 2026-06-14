/*
 * stm32f407xx_sysconfig_driver.cpp
 *
 *  Created on: 14-Jun-2026
 *      Author: Krishna M
 */
#include "stm32f407xx_sysconfig_driver.h"


void SYSCONFIG_PeripheralClockControl(SYSCONFIG_regDef_t *pSYSCONFIG,uint8_t EnorDi){
	if(EnorDi == ENABLE){
		if(pSYSCONFIG == SYSCFG){
			SYSCONFIG_PCLK_EN();
		}
	}
	else{
			SYSCONFIG_PCLK_DI();
	}
}

void SYSCONFIG_ENABLE_EXTI(SYSCONFIG_Handle_t *pSYSCONFIGHandle,
                           uint8_t value)
{
    uint8_t pinNumber;
    uint8_t regIndex;
    uint8_t bitPos;

    pinNumber = pSYSCONFIGHandle->SYSCONFIG_pinConfig.SYSCONFIG_PinNumber;

    /* EXTICR register selection */
    regIndex = pinNumber / 4;

    /* Bit position within EXTICR */
    bitPos = (pinNumber % 4) * 4;

    /* Clear existing EXTI configuration */
    //pSYSCONFIGHandle->pSYSCONFIG->EXTICR[regIndex] &= ~(0xF << bitPos);

    /* Configure GPIO port source */
    pSYSCONFIGHandle->pSYSCONFIG->EXTICR[regIndex] |= (value << bitPos);
}

