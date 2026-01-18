/*
 * blink_led.c
 *
 *  Created on: Jan 7, 2026
 *      Author: ziad-ahmed
 */

#include "blink_led.h"

stm_err_t blink_led_init(){

	stm_err_t err = GPIO_OUTPUT_CONFIG(PORTC, 13, MAX_OUTPUT_SPEED_2MHZ, PUSH_PULL);
	STM_CHECK_ERROR(err);

	return STM_OK ;
}

stm_err_t blink_led(){

	stm_err_t err = GPIO_OUTPUT_WRITE(PORTC, 13, HIGH);
	STM_CHECK_ERROR(err);

	return STM_OK ;
}
