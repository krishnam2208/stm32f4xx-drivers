


#ifndef INC_STM32F407XX_SYSCONFIG_DRIVER_H_
#define INC_STM32F407XX_SYSCONFIG_DRIVER_H_
#include "stm32f407xx.h"


typedef struct{
	uint8_t SYSCONFIG_PinNumber;
}SYSCONFIG_PinConfig_t;

//GPIO Handle Structure
typedef struct{
	SYSCONFIG_regDef_t *pSYSCONFIG;
	SYSCONFIG_PinConfig_t SYSCONFIG_pinConfig;
}SYSCONFIG_Handle_t;

void SYSCONFIG_PeripheralClockControl(SYSCONFIG_regDef_t *pSYSCONFIG,uint8_t EnorDi);

void SYSCONFIG_ENABLE_EXTI(SYSCONFIG_Handle_t *pSYSCONFIGHandle,
                           uint8_t value);



#endif 