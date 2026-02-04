/* author : Vandat
 *
 * year: 2026
 *
 */
#include <stm32f103_gpio.h>
#include <stm32f103.h>

#ifndef STM32_GPIO_C
#define STM32_GPIO_C

// function config gpio
/*
 * GPIOx → GPIOA / GPIOB / GPIOC
```pin → 0 → 15
   config → mode + cnf (input/output)
 * */
void GPIO_config(GPIO_TypeDef * GPIOx, uint8_t pin, uint8_t config)
{
	volatile uint32_t *config_reg;
	uint8_t shift;

	if (pin < 8)
	{
		config_reg = &GPIOx->CRL;
		shift = pin*4;
	}else
	{
		config_reg=&GPIOx->CRH;
		shift =(pin-8)*4;
	}
    *config_reg &= ~(0xF << shift);
    *config_reg |= (configeee<<shift);
}

void GPIO_Writepin(GPIO_TypeDef * GPIOx, uint8_t pin, uint8_t value)
{
	volatile uint32_t *reg;
}

#endif
