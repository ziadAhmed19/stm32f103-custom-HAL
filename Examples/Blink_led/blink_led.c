/*
 * blink_led.c
 *
 *  Created on: Jan 7, 2026
 *      Author: ziad-ahmed
 */

#include "blink_led.h"

stm_err_t blink_led_init(){

	GPIO_Config_t led_config = {
			.ePort 				= PORTC,
			.nPin 				= 13,
			.eOutput_mode 		= MAX_OUTPUT_SPEED_2MHZ,
			.eOutput_config 	= PUSH_PULL
	};

	stm_err_t err = GPIO_ConfigPin(GPIO_OUTPUT, &led_config);
	STM_CHECK_ERROR(err);

	return STM_OK ;
}

stm_err_t blink_led(){

	stm_err_t err = GPIO_TOGGLE(PORTC, 13);
	STM_CHECK_ERROR(err);
	for(int i = 0 ; i < 50000; i++);;

	return STM_OK ;
}
