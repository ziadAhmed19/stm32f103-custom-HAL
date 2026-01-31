/*
 * GPIO_Interface.h
 *
 *  Created on: Dec 13, 2025
 *      Author: ziad-ahmed
 */
#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

#include "GPIO_Config.h"


// FUNCTION PROTOTYPES
stm_err_t GPIO_ConfigPin(GPIO_Direction_t direction, GPIO_Config_t *config);
stm_err_t GPIO_READ(GPIO_PORTS ePort, uint8_t nPin);
stm_err_t GPIO_WRITE(GPIO_PORTS ePort, uint8_t nPin, logicLevel_t logicLevel);
stm_err_t GPIO_TOGGLE(GPIO_PORTS ePort, uint8_t nPin);

#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
