/*
 * USART_Config.h
 *
 *  Created on: Jan 19, 2026
 *      Author: ziad-ahmed
 */

#ifndef MCAL_USART_USART_CONFIG_H_
#define MCAL_USART_USART_CONFIG_H_

// INCLUDES
#include "USART_Register.h"
#include "BitMath.h"
#include "stm_err_t.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include <stdint.h>

// DATATYPES
typedef enum{
	USART_2,
	USART_3
}USART_Channel_t;

typedef enum{
	TX,
	RX
}USART_Mode;

typedef enum{
	NORMAL,
	EXTENDED
}USART_Word_Length;

typedef enum{
	IDLE_LINE,
	ADDRESS_MARK
}USART_Wakeup_Method;

typedef enum{
		ENABLED,
		DISABLED
}USART_Parity_Control;

typedef enum{
		EVEN,
		ODD
}USART_Parity_Selection;

typedef enum{
	ACTIVE,
	MUTE
}USART_RX_WakeUp;

typedef enum{

}USART_STOP_BITS;

typedef struct{
	USART_Mode 				mode;
	uint32_t 				baud_rate;
	USART_Word_Length 		M;
	USART_Wakeup_Method 	WAKE;
	USART_Parity_Control	PCE;
	USART_Parity_Selection	PS;
	USART_RX_WakeUp			RWU;
}USART_Config_t;


// PEIE TXEIE TCIE RXNEIE
typedef struct{

}USART_InterruptConfig_t;

#endif /* MCAL_USART_USART_CONFIG_H_ */
