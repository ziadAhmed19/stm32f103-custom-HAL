/*
 * RCC_Program.c
 *
 *  Created on: Jan 18, 2026
 *      Author: ziad-ahmed
 *
 *      Phase 1
 *      1- Peripheral clock control (EN - DIS)
 *      2- Peripheral clock Reset
 *
 *      Phase 2
 *      1- Minimal system clock
 *
 */

#include "RCC_Interface.h"
#include "RCC_Private.h"

// Defining Maps

const static RCC_Map_t GPIOA 	= {&RCC_APB2ENR, &RCC_APB2RSTR, 2};
const static RCC_Map_t GPIOB 	= {&RCC_APB2ENR, &RCC_APB2RSTR, 3};
const static RCC_Map_t GPIOC 	= {&RCC_APB2ENR, &RCC_APB2RSTR, 4};

const static RCC_Map_t USART2 	= {&RCC_APB1ENR, &RCC_APB1RSTR, 17};
const static RCC_Map_t USART3 	= {&RCC_APB1ENR, &RCC_APB1RSTR, 18};

const static RCC_Map_t TIM2 	= {&RCC_APB1ENR, &RCC_APB1RSTR, 0};

stm_err_t RCC_EnablePeripheral(RCC_Peripheral_t per){

	switch (per) {
		case RCC_GPIOA: SET_BIT(*GPIOA.en_reg, GPIOA.bit);
			break;
		case RCC_GPIOB: SET_BIT(*GPIOB.en_reg, GPIOB.bit);
			break;
		case RCC_GPIOC: SET_BIT(*GPIOC.en_reg, GPIOC.bit);
			break;
		case RCC_USART2: SET_BIT(*USART2.en_reg, USART2.bit);
			break;
		case RCC_USART3: SET_BIT(*USART3.en_reg, USART3.bit);
			break;
		case RCC_TIM2: SET_BIT(*TIM2.en_reg, TIM2.bit);
			break;

		default:return STM_ERR_INVALID_ARG;
			break;
	}
	return STM_OK;
}

stm_err_t RCC_DisablePeripheral(RCC_Peripheral_t per){
	switch (per) {
		case RCC_GPIOA: CLR_BIT(*GPIOA.en_reg, GPIOA.bit);
			break;
		case RCC_GPIOB: CLR_BIT(*GPIOB.en_reg, GPIOB.bit);
			break;
		case RCC_GPIOC: CLR_BIT(*GPIOC.en_reg, GPIOC.bit);
			break;
		case RCC_USART2: CLR_BIT(*USART2.en_reg, USART2.bit);
			break;
		case RCC_USART3: CLR_BIT(*USART3.en_reg, USART3.bit);
			break;
		case RCC_TIM2: 	CLR_BIT(*TIM2.en_reg, TIM2.bit);
			break;

		default:return STM_ERR_INVALID_ARG;
			break;
	}
	return STM_OK;
}

stm_err_t RCC_ResetPeripheral(RCC_Peripheral_t per){

	switch (per) {
		case RCC_GPIOA:
			SET_BIT(*GPIOA.rst_reg, GPIOA.bit);
			CLR_BIT(*GPIOA.rst_reg, GPIOA.bit);
			break;
		case RCC_GPIOB:
			SET_BIT(*GPIOB.rst_reg, GPIOB.bit);
			CLR_BIT(*GPIOB.rst_reg, GPIOB.bit);
			break;
		case RCC_GPIOC:
			SET_BIT(*GPIOC.rst_reg, GPIOC.bit);
			CLR_BIT(*GPIOC.rst_reg, GPIOC.bit);
			break;
		case RCC_USART2:
			SET_BIT(*USART2.rst_reg, USART2.bit);
			CLR_BIT(*USART2.rst_reg, USART2.bit);
			break;
		case RCC_USART3:
			SET_BIT(*USART3.rst_reg, USART3.bit);
			CLR_BIT(*USART3.rst_reg, USART3.bit);
			break;
		case RCC_TIM2:
			SET_BIT(*TIM2.rst_reg, TIM2.bit);
			CLR_BIT(*TIM2.rst_reg, TIM2.bit);
			break;
		default:return STM_ERR_INVALID_ARG;
			break;
	}
	return STM_OK;
}

stm_err_t RCC_SetSystemClock(RCC_SystemClock clk){

	// Reset the System Clock Switch

	CLR_BITS(RCC_CFGR,0x3,0);

	switch(clk)
	{
		case HSI_CLK:
			SET_BIT(RCC_CR,0);
			while(!GET_BIT(RCC_CR,1));

			WRITE_BITS(RCC_CFGR,0b00,0);
			while(((RCC_CFGR >> 2) & 0x3) != 0b00);
			break;

		case HSE_CLK:
			SET_BIT(RCC_CR,16);
			while(!GET_BIT(RCC_CR,17));

			WRITE_BITS(RCC_CFGR,0b01,0);
			while(((RCC_CFGR >> 2) & 0x3) != 0b01);
			break;

		default: return STM_ERR_INVALID_ARG; break;
	}
	return STM_OK;
}

uint32_t RCC_GetAPB1Clock(void){



}
