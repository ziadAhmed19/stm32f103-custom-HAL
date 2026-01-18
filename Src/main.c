#include "Blink_led/blink_led.h"

int main(void)
{
	if (blink_led_init() != STM_OK) while(1);
    /* Loop forever */
	while(1){
		blink_led();
	}
}
