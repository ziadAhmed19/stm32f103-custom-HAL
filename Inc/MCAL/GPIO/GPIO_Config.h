/*
 * GPIO_Config.h
 *
 *  Created on: Dec 17, 2025
 *      Author: ziad-ahmed
 */

#ifndef MCAL_GPIO_GPIO_CONFIG_H_
#define MCAL_GPIO_GPIO_CONFIG_H_

// INCLUDES

#include "BitMath.h"
#include "GPIO_Register.h"
#include <stdint.h>

// Renaming Ports
typedef enum {
	PORTA = 0,
	PORTB = 1,
	PORTC = 2

}GPIO_PORTS;


// Renaming Input Types
typedef enum {
	FLOATING 	= 0,
	PULL_UP 	= 1,
	PULL_DOWN 	= 2,
	ANALOG 		= 3
}INPUT_CNF;

// Renaming Output Types
typedef enum{
	MAX_OUTPUT_SPEED_10MHZ,
	MAX_OUTPUT_SPEED_2MHZ,
	MAX_OUTPUT_SPEED_50MHZ
}OUTPUT_MODE;

typedef enum {
	OPEN_DRAIN 			= 0,
	PUSH_PULL 			= 1,
	ALT_FN_PUSH_PULL 	= 2,
	ALT_FN_OPEN_DRAIN 	= 3
}OUTPUT_CNF;


#endif /* MCAL_GPIO_GPIO_CONFIG_H_ */
