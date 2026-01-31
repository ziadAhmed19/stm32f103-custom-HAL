/*
 * GPIO_Private.h
 *
 *  Created on: Dec 17, 2025
 *      Author: ziad-ahmed
 */
#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

#include "GPIO_Config.h"

stm_err_t GPIO_INPUT_CONFIG(GPIO_PORTS ePort, uint8_t nPin, INPUT_CNF eCnf);
stm_err_t GPIO_OUTPUT_CONFIG(GPIO_PORTS ePort, uint8_t nPin, OUTPUT_MODE eMode, OUTPUT_CNF eCnf);

#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
