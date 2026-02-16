/*
 * USART_Program.c
 *
 *  Created on: Jan 19, 2026
 *      Author: ziad-ahmed
 */

#include "USART_Private.h"
#include "USART_Interface.h"


// Step 5  : Partiy Control Enable 		USART_CR1 -> PCE
// Step 6  : Parity Selection 			USART_CR1 -> PS
// Step 7  : Set USART_CR1 -> PEIE to enable USART Interrputs
// Step 8  : If USART_CR1 -> TE is seleted Set USART_CR1 -> TXEIE & USART_CR1 -> TCIE to enable USART Interrputs
// Step 9  : If USART_CR1 -> RE is selected set USART_CR1 -> RXNEIE
// Step 10 : Optional IDLEIE by default 0
// Step 11 : Optional RWE  by default 0
// Step 12 : Optional Send Break
// Step 13 : Enable Perph

stm_err_t USART_Config(USART_Channel_t channel, USART_Config_t *config){

	volatile uint32_t* USART_CR1 ;

	// Enable RCC

	switch (channel) {
		case USART_2: RCC_EnablePeripheral(RCC_USART2); USART_CR1 = &USART2_CR1;  break;
		case USART_3: RCC_EnablePeripheral(RCC_USART3); USART_CR1 = &USART3_CR1;  break;
		default: return STM_ERR_INVALID_ARG; break;
	}

	// Disable Peripherals

	CLR_BIT(*USART_CR1,13);

	// Selection Phase

	switch (config->mode)
	{
		case TX: CLR_BIT(*USART_CR1,3);SET_BIT(*USART_CR1,3); break;
		case RX: CLR_BIT(*USART_CR1,2);SET_BIT(*USART_CR1,2); break;
		default: return STM_ERR_INVALID_ARG; break;
	}

	switch(config->M)
	{
		case NORMAL: 	CLR_BIT(*USART_CR1,12); break;
		case EXTENDED: 	SET_BIT(*USART_CR1,12); break;
		default: return STM_ERR_INVALID_ARG; break;
	}

	switch(config->WAKE)
	{
		case IDLE_LINE: 	CLR_BIT(*USART_CR1,11); break;
		case ADDRESS_MARK: 	SET_BIT(*USART_CR1,11); break;
		default: return STM_ERR_INVALID_ARG; break;
	}

	switch(config->PCE)
	{
		case DISABLED: 	CLR_BIT(*USART_CR1,10); break;
		case ENABLED: 	SET_BIT(*USART_CR1,10);
		switch(config->PS)
		{
			case EVEN: 	CLR_BIT(*USART_CR1,9); break;
			case ODD: 	SET_BIT(*USART_CR1,9); break;
			default: return STM_ERR_INVALID_ARG; break;
		}
		break;
		default: return STM_ERR_INVALID_ARG; break;
	}
	switch(config->RWU)
	{
		case ACTIVE: 	CLR_BIT(*USART_CR1,1); break;
		case MUTE:		SET_BIT(*USART_CR1,1); break;
	}
	// Enable Peripherals

	SET_BIT(*USART_CR1,13);
	return STM_OK;
}
