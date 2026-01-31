#include "main.h"

int main(void)
{
	STM_CHECK_ERROR(blink_led_init());

	// Enabling Global Interputs
	//__enable_irq();
	/* Loop forever */
	while(1){
		blink_led();
	}
}
