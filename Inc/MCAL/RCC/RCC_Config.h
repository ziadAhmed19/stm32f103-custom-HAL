/*
 * RCC_Config.h
 *
 *  Created on: Jan 18, 2026
 *      Author: ziad-ahmed
 */

#ifndef MCAL_RCC_RCC_CONFIG_H_
#define MCAL_RCC_RCC_CONFIG_H_

// Includes

#include "BitMath.h"
#include "stm_err_t.h"
#include "RCC_Register.h"
#include  <stdint.h>

// Datatypes

typedef enum {
    RCC_GPIOA,
    RCC_GPIOB,
    RCC_GPIOC,
    RCC_USART2,
    RCC_USART3,
    RCC_TIM2
} RCC_Peripheral_t;

typedef enum{
	HSI_CLK,
	HSE_CLK
}RCC_SystemClock;

typedef struct {
    volatile uint32_t* en_reg;
    volatile uint32_t* rst_reg;
    uint8_t bit;
} RCC_Map_t;

#endif /* MCAL_RCC_RCC_CONFIG_H_ */
