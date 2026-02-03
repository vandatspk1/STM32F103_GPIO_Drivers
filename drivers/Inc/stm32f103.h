/**
* @file stm32f103.h
* @author: Dat
* brief STM32103 Memory map & peripheral addresses
* @year 2026
 */

// register maps  - base address - macro

#ifndef  STM32F103_H
#define  STM32F103_H

#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

/* =================== MEMORY MAP==================================*/
#define SRAM_BASE   		0x20000000U
#define FLAS_BASE  			0x08000000U
#define PERIPHRAL_BASE  	0x40000000U

/*==================== BUS MAP=====================================*/
#define APB1_BASE 			PERIPHRAL_BASE
#define APB2_BASE			0x40010000U
#define AHB_BASE   			0x40018000U

/* ================== APB1 Peripherals ============================*/
#define TIM2_BASE      (APB1_BASE + 0x0000U)
#define TIM3_BASE      (APB1_BASE + 0x0400U)
#define TIM4_BASE      (APB1_BASE + 0x0800U)
#define TIM5_BASE      (APB1_BASE + 0x0C00U)
#define TIM6_BASE      (APB1_BASE + 0x1000U)
#define TIM7_BASE      (APB1_BASE + 0x1400U)

#define RTC_BASE       (APB1_BASE + 0x2800U)
#define WWDG_BASE      (APB1_BASE + 0x2C00U)
#define IWDG_BASE      (APB1_BASE + 0x3000U)

#define SPI2_BASE      (APB1_BASE + 0x3800U)
#define SPI3_BASE      (APB1_BASE + 0x3C00U)

#define USART2_BASE    (APB1_BASE + 0x4400U)
#define USART3_BASE    (APB1_BASE + 0x4800U)
#define UART4_BASE     (APB1_BASE + 0x4C00U)
#define UART5_BASE     (APB1_BASE + 0x5000U)

#define I2C1_BASE      (APB1_BASE + 0x5400U)
#define I2C2_BASE      (APB1_BASE + 0x5800U)

#define USB_BASE       (APB1_BASE + 0x5C00U)
#define CAN_BASE       (APB1_BASE + 0x6400U)
#define BKP_BASE       (APB1_BASE + 0x6C00U)
#define PWR_BASE       (APB1_BASE + 0x7000U)
#define DAC_BASE       (APB1_BASE + 0x7400U)
#define RESERVED_BASE  (APB1_BASE + 0x7800U)



/* ================== APB2 Peripherals ================== */
#define AFIO_BASE        (APB2_BASE + 0x0000U)
#define EXTI_BASE        (APB2_BASE + 0x0400U)

#define GPIOA_BASE       (APB2_BASE + 0x0800U)
#define GPIOB_BASE       (APB2_BASE + 0x0C00U)
#define GPIOC_BASE       (APB2_BASE + 0x1000U)
/* GPIO D/E/F/G: NOT PRESENT on STM32F103C6 */

#define ADC1_BASE        (APB2_BASE + 0x2400U)
#define ADC2_BASE        (APB2_BASE + 0x2800U)
/* ADC3: NOT PRESENT */

#define TIM1_BASE        (APB2_BASE + 0x2C00U)
#define SPI1_BASE        (APB2_BASE + 0x3000U)

#define USART1_BASE      (APB2_BASE + 0x3800U)

/* ================== AHB Peripherals ================== */
#define DMA1_BASE        (AHB_BASE + 0x0000U)
#define RCC_BASE         (AHB_BASE + 0x1000U)
#define FLASH_REG_BASE   (AHB_BASE + 0x2000U)
#define CRC_BASE         (AHB_BASE + 0x3000U)
/* DMA2, USB, ETH, SDIO: NOT PRESENT on STM32F103C6 */


#define __IO volatile    // r/w
#define __I  volatile const /*!<Read only>*/
#define __O  volatile

/*=================== REGISTORS MAP======================*/


/*====================CRC REGISTOR=======================*/
typedef struct {
    __IO uint32_t DR;
    __IO uint32_t IDR;
    __IO uint32_t CR;
}CRC_TypeDef;


/*================== PWR REGISTER========================*/
typedef struct {
    __IO uint32_t CR;
    __IO uint32_t CSR;
} PWR_TypeDef;


/*==================GPIO REGISTOR=========================*/
typedef struct {
	__IO uint32_t DR1;
	__IO uint32_t DR2;
	__IO uint32_t DR3;
    __IO uint32_t DR5;
    __IO uint32_t DR8;
    __IO uint32_t DR9;
    __IO uint32_t DR10;
    __IO uint32_t RTCCR;
    __IO uint32_t CR;
    __IO uint32_t CSR;
} BKP_TypeDef;



/*===================RCC REGISTOR DEFINITION==========================*/
typedef struct {
    __IO uint32_t CR;        // 0x00 -offset
    __IO uint32_t CFGR;      // 0x04
    __IO uint32_t CIR;       // 0x08
    __IO uint32_t APB2RSTR;  // 0x0C
    __IO uint32_t APB1RSTR;  // 0x10
    __IO uint32_t AHBENR;    // 0x14
    __IO uint32_t APB2ENR;   // 0x18
    __IO uint32_t APB1ENR;   // 0x1C
    __IO uint32_t BDCR;      // 0x20
    __IO uint32_t CSR;       // 0x24
} RCC_TypeDef;


/*==========================GPIO===========================*/

typedef struct {
	__IO uint32_t CRL;   	//offset : 0x00
	__IO uint32_t CRH;		//0x04
	__IO uint32_t IDR;		//0x08
	__IO uint32_t ODR;		//0x0c
	__IO uint32_t BSRR;		//0x010
	__IO uint32_t BRR;		//0x014
	__IO uint32_t LCKR;		//0x018
}GPIO_TypeDef;

/*==========================AFIO===========================*/
typedef struct {
    __IO uint32_t EVCR;      // 0x00
    __IO uint32_t MAPR;      // 0x04
    __IO uint32_t EXTICR[4]; // 0x08 - 0x14
    uint32_t      RESERVED0;
    __IO uint32_t MAPR2;     // 0x1C (high density only, vẫn khai báo cho align)
} AFIO_TypeDef;
/*==========================ISR===========================*/
typedef struct {
    __IO uint32_t IMR;   // 0x00
    __IO uint32_t EMR;   // 0x04
    __IO uint32_t RTSR;  // 0x08
    __IO uint32_t FTSR;  // 0x0C
    __IO uint32_t SWIER; // 0x10
    __IO uint32_t PR;    // 0x14
} EXTI_TypeDef;
/*==========================DMA===========================*/
typedef struct {
    __IO uint32_t CCR;
    __IO uint32_t CNDTR;
    __IO uint32_t CPAR;
    __IO uint32_t CMAR;
} DMA_Channel_TypeDef;

typedef struct {
    __IO uint32_t SR;     // 0x00
    __IO uint32_t CR1;    // 0x04
    __IO uint32_t CR2;    // 0x08
    __IO uint32_t SMPR1;  // 0x0C
    __IO uint32_t SMPR2;  // 0x10
    __IO uint32_t JOFR1;
    __IO uint32_t JOFR2;
    __IO uint32_t JOFR3;
    __IO uint32_t JOFR4;
    __IO uint32_t HTR;
    __IO uint32_t LTR;
    __IO uint32_t SQR1;
    __IO uint32_t SQR2;
    __IO uint32_t SQR3;
    __IO uint32_t JSQR;
    __IO uint32_t JDR1;
    __IO uint32_t JDR2;
    __IO uint32_t JDR3;
    __IO uint32_t JDR4;
    __IO uint32_t DR;
} ADC_TypeDef;
/*==========================AFIO===========================*/

/*==========================ISR===========================*/

/*==========================TIM===========================*/

typedef struct {
    __IO uint32_t CR1;
    __IO uint32_t CR2;
    __IO uint32_t SMCR;
    __IO uint32_t DIER;
    __IO uint32_t SR;
    __IO uint32_t EGR;
    __IO uint32_t CCMR1;
    __IO uint32_t CCMR2;
    __IO uint32_t CCER;
    __IO uint32_t CNT;
    __IO uint32_t PSC;
    __IO uint32_t ARR;
    __IO uint32_t RCR;
    __IO uint32_t CCR1;
    __IO uint32_t CCR2;
    __IO uint32_t CCR3;
    __IO uint32_t CCR4;
    __IO uint32_t BDTR;
    __IO uint32_t DCR;
    __IO uint32_t DMAR;
} TIM_TypeDef;


#define CRC ((CRC_TypeDef*) CRC_BASE)

#define PWR ((PWR_TypeDef *) PWR_BASE)

#define BKP ((BKP_TypeDef*) BKP_BASE)

#define RCC ((RCC_TypeDef *) RCC_BASE)

#define GPIOA ((GPIO_TypeDef*) GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef*) GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef*) GPIOC_BASE)

#define AFIO  ((AFIO_TypeDef *) AFIO_BASE)

#define EXTI  ((EXTI_TypeDef *) EXTI_BASE)

#define DMA1  ((DMA_TypeDef *) DMA1_BASE)

#define ADC1 ((ADC_TypeDef *) ADC1_BASE)

#define TIM2 ((TIM_TypeDef *) TIM2_BASE)
#define TIM3 ((TIM_TypeDef *) TIM3_BASE)
#define TIM4 ((TIM_TypeDef *) TIM4_BASE)

#endif  // STM32F103_H
