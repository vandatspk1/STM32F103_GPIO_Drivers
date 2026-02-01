/**
* @file stm32f103.h
* @author Dat
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
#define SRAM_BASE   		0x20000000UL
#define FLAS_BASE  			0x08000000UL
#define PERIPHRAL_BASE  	0x40000000UL
/*==================== BUS MAP=====================================*/
#define APB1_BASE 			PERIPHRAL_BASE
#define APB2_BASE			0x40010000U
#define AHP1_BASE			0x40018000U
#define AHP2_BASE			0x40028000U

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
#define RESERVERD_BASE (ABP1_BASE + 0x7800U)


/* ================== APB2 Peripherals ================== */
#define AFIO_BASE        (APB2_BASE + 0x0000UL)
#define EXTI_BASE        (APB2_BASE + 0x0400UL)

#define GPIOA_BASE       (APB2_BASE + 0x0800UL)
#define GPIOB_BASE       (APB2_BASE + 0x0C00UL)
#define GPIOC_BASE       (APB2_BASE + 0x1000UL)
/* GPIOD/E/F/G: NOT PRESENT on STM32F103C6 */

#define ADC1_BASE        (APB2_BASE + 0x2400UL)
#define ADC2_BASE        (APB2_BASE + 0x2800UL)
/* ADC3: NOT PRESENT */

#define TIM1_BASE        (APB2_BASE + 0x2C00UL)
#define SPI1_BASE        (APB2_BASE + 0x3000UL)

#define USART1_BASE      (APB2_BASE + 0x3800UL)

/* ================== AHB Peripherals ================== */
#define DMA1_BASE        (AHB_BASE + 0x0000UL)
#define RCC_BASE         (AHB_BASE + 0x1000UL)
#define FLASH_REG_BASE   (AHB_BASE + 0x2000UL)
#define CRC_BASE         (AHB_BASE + 0x3000UL)
/* DMA2, USB, ETH, SDIO: NOT PRESENT on STM32F103C6 */



#endif  // STM32F103_H
