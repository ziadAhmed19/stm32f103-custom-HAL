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



#endif /* MCAL_USART_USART_CONFIG_H_ */
