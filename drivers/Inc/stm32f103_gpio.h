/**
* @file stm32f103.h
* @author: Dat
* brief: Config modes for gpio
*
*   Input floating
● 	Input pull-up
● 	Input-pull-down
● 	Analog Input
● 	Output open-drain
● 	Output push-pull
● 	Alternate function push-pull
● 	Alternate function open-drain
*	- have two registers config CRL / CRH (32 bits)
*
*
* @year 2026
 */


#ifndef STM32F103_GPIO_H
#define STM32F130_GPIO_H

#include <stm32f103.h>
/*======================mode=====================*/
#define GPIO_MODE_INPUT        0x0
#define GPIO_MODE_OUTPUT_10MHZ 0x1
#define GPIO_MODE_OUTPUT_2MHZ  0x2
#define GPIO_MODE_OUTPUT_50MHZ 0x3

/*======================CNF*/
  /*========General purpose output*/
#define GPIO_CNF_GP_PP 0x0;
#define GPIO_CNF_GP_OD 0x1;
  /*========Alternative Function output*/
#define GPIO_CNF_AF_PP 0x3;
#define GPIO_CNF_AF_OD 0x4;
  /*===============Input===============*/
#define GPIO_CNF_I_AI  0x0;    // analog input
#define GPIO_CNF_I_IF  0x1;	   // input floating
#define GPIO_CNF_I_PD_PU  0x2;	   // pull-down / pull_up


/*===============full config (CNF | MODE)===========*/

// Push-pull
#define GPIO_OUTPUT_PP_10MHZ  ((GPIO_CNF_GP_PP << 2) | GPIO_MODE_OUTPUT_10MHZ)
#define GPIO_OUTPUT_PP_2MHZ   ((GPIO_CNF_GP_PP << 2) | GPIO_MODE_OUTPUT_2MHZ)
#define GPIO_OUTPUT_PP_50MHZ  ((GPIO_CNF_GP_PP << 2) | GPIO_MODE_OUTPUT_50MHZ)

// Open-drain
#define GPIO_OUTPUT_OD_10MHZ  ((GPIO_CNF_GP_OD << 2) | GPIO_MODE_OUTPUT_10MHZ)
#define GPIO_OUTPUT_OD_2MHZ   ((GPIO_CNF_GP_OD << 2) | GPIO_MODE_OUTPUT_2MHZ)
#define GPIO_OUTPUT_OD_50MHZ  ((GPIO_CNF_GP_OD << 2) | GPIO_MODE_OUTPUT_50MHZ)

// input
#define GPIO_INPUT_FLOATING   ((GPIO_CNF_FLOATING << 2) | GPIO_MODE_INPUT)
#define GPIO_INPUT_PULLUP     ((GPIO_CNF_PU_PD   << 2) | GPIO_MODE_INPUT)
#define GPIO_INPUT_PULLDOWN   ((GPIO_CNF_PU_PD   << 2) | GPIO_MODE_INPUT)


/*===================== Struct GPIO=========================*/

void GPIO_config (GPIO_TypeDef * GPIOx, uint8_t pin, uint8_t config);
void GPIO_Writepin(GPIO_TypeDef * GPIOx, uint8_t pin, uint8_t value);
uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint8_t pin);

#endif // end STM32F103_GPIO_H
