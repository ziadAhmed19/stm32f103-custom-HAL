/*
 * blink_led.h
 *
 *  Created on: Jan 7, 2026
 *      Author: ziad-ahmed
 */

#ifndef BLINK_LED_BLINK_LED_H_
#define BLINK_LED_BLINK_LED_H_

#include "stm_err_t.h"
#include "GPIO_Interface.h"


stm_err_t blink_led_init();
stm_err_t blink_led();

#endif /* BLINK_LED_BLINK_LED_H_ */
