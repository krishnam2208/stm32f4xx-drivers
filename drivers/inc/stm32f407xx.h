/*
 * stm32f407xx.h
 *
 *  Created on: 27-May-2026
 *      Author: Krishna M
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#define __vo  volatile


#define FLASH_BASEADDR          0x08000000U
#define SRAM1_BASEADDR          0x20000000U
#define SRAM2_BASEADDR          0x2001C000U
#define ROM_BASEADDR            0x1FFF0000U
#define SRAM                    SRAM1_BASEADDR

#define PERIPH_BASEADDR         0x40000000U
#define APB1PERIPH_BASEADDR     PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR     0x40010000U
#define AHB1PERIPH_BASEADDR     0x40020000U
#define AHB2PERIPH_BASEADDR     0x50000000U
#define NVIC_ISER_BASEADDR      0xE000E100U

#define GPIOA_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0000U)
#define GPIOB_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0400U)
#define GPIOC_BASEADDR	   		(AHB1PERIPH_BASEADDR + 0x0800U)
#define GPIOD_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0C00U)
#define GPIOE_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1000U)
#define GPIOF_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1400U)
#define GPIOG_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1800U)
#define GPIOH_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1C00U)
#define GPIOI_BASEADDR			(AHB1PERIPH_BASEADDR + 0x2000U)
#define GPIOJ_BASEADDR          (AHB1PERIPH_BASEADDR + 0x2400U)
#define GPIOK_BASEADDR			(AHB1PERIPH_BASEADDR + 0x2800U)

#define RCC_BASEADDR            (AHB1PERIPH_BASEADDR + 0x3800U)

#define I2C1_BASEADDR           (APB1PERIPH_BASEADDR + 0x5400U)
#define I2C2_BASEADDR			(APB1PERIPH_BASEADDR + 0x5800U)
#define I2C3_BASEADDR			(APB1PERIPH_BASEADDR + 0x5C00U)

#define SPI2_BASEADDR			(APB1PERIPH_BASEADDR + 0x3800U)
#define SPI3_BASEADDR			(APB1PERIPH_BASEADDR + 0x3C00U)

#define USART2_BASEADDR			(APB1PERIPH_BASEADDR + 0x4400U)
#define USART3_BASEADDR			(APB1PERIPH_BASEADDR + 0x4800U)
#define UART4_BASEADDR			(APB1PERIPH_BASEADDR + 0x4C00U)
#define UART5_BASEADDR			(APB1PERIPH_BASEADDR + 0x5000U)

#define EXTI_BASEADDR			(APB2PERIPH_BASEADDR + 0x3C00U)
#define SPI1_BASEADDR			(APB2PERIPH_BASEADDR + 0x3000U)
#define SYSCFG_BASEADDR			(APB2PERIPH_BASEADDR + 0x3800U)
#define USART1_BASEADDR			(APB2PERIPH_BASEADDR + 0x1000U)
#define USART6_BASEADDR			(APB2PERIPH_BASEADDR + 0x1400U)


typedef struct{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
} GPIO_RegDef_t;

typedef struct{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	__vo uint32_t RESERVED0;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t RESERVED1[2];
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	__vo uint32_t RESERVED2;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t RESERVED3[2];
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	__vo uint32_t RESERVED4;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	__vo uint32_t RESERVED5[2];
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t RESERVED6[2];
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;

}RCC_RegDef_t;

typedef struct{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
	__vo uint32_t CMPCR;
}SYSCONFIG_regDef_t;

typedef struct{
	__vo uint32_t EXTI_IMR;
	__vo uint32_t EXTI_EMR;
	__vo uint32_t EXTI_RTSR;
	__vo uint32_t EXTI_FTSR;
	__vo uint32_t EXTI_SWIER;
	__vo uint32_t EXTI_PR;
}EXTI_regDef_t;

typedef struct{
	__vo uint32_t NVIC_ISERx[8];
}NVIC_ISER_regDef_t;

#define GPIOA                  ((GPIO_RegDef_t *) GPIOA_BASEADDR)
#define GPIOB                  ((GPIO_RegDef_t *) GPIOB_BASEADDR)
#define GPIOC                  ((GPIO_RegDef_t *) GPIOC_BASEADDR)
#define GPIOD                  ((GPIO_RegDef_t *) GPIOD_BASEADDR)
#define GPIOE                  ((GPIO_RegDef_t *) GPIOE_BASEADDR)
#define GPIOF                  ((GPIO_RegDef_t *) GPIOF_BASEADDR)
#define GPIOG                  ((GPIO_RegDef_t *) GPIOG_BASEADDR)
#define GPIOH                  ((GPIO_RegDef_t *) GPIOH_BASEADDR)
#define GPIOI                  ((GPIO_RegDef_t *) GPIOI_BASEADDR)
#define GPIOJ                  ((GPIO_RegDef_t *) GPIOJ_BASEADDR)
#define GPIOK                  ((GPIO_RegDef_t *) GPIOK_BASEADDR)

#define RCC                    ((RCC_RegDef_t *) RCC_BASEADDR)

#define SYSCFG                 ((SYSCONFIG_regDef_t *)SYSCFG_BASEADDR)

#define EXTI                   ((EXTI_regDef_t *)EXTI_BASEADDR)
#define NVIC_ISER			   ((NVIC_ISER_regDef_t *)NVIC_ISER_BASEADDR)

//Clock Enable for GPIOA
#define  GPIOA_PCLK_EN()       (RCC->AHB1ENR |= (1<<0));
//GPIOD
#define  GPIOD_PCLK_EN()       (RCC->AHB1ENR |= (1<<3));

//Clock Disable for GPIOA
#define  GPIOA_PCLK_DI()       (RCC->AHB1ENR &= ~(1<<0));
#define  GPIOD_PCLK_DI()       (RCC->AHB1ENR &= ~(1<<3));

//Clock Enable for I2C1

#define SYSCONFIG_PCLK_EN()    (RCC->APB2ENR |= (1<<14));
#define  SYSCONFIG_PCLK_DI()       (RCC->APB2ENR &= ~(1<<14));

#define SYSCONFIG_PCLK_EN()    (RCC->APB2ENR |= (1<<14));
#define  SYSCONFIG_PCLK_DI()       (RCC->APB2ENR &= ~(1<<14));




#define  GPIOA_RESET()      do{RCC->AHB1RSTR |= (1<<0); RCC->AHB1RSTR &= ~(1<<0);}while(0)

//Some Generic macros
#define ENABLE     1
#define DISABLE    0
#define RT         1
#define FT         2
#define RTFT       3
















#endif /* INC_STM32F407XX_H_ */
