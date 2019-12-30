#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <rcc.h>
#include <nvic.h>
#include <usart.h>
#include <debug.h>
#include <gpio.h>

/* main function */
void main()
{
	/* setup serial debugging */
	usart1_init();
	debug_setserial(USART1);

	debug_print("STMFlash firmware v0.1\n");

	/* enable TIM2 */
	/*RCC->APB1ENR |= 1;*/

	/* setup USB clock */
	// debug_print("Setting up USB...\n");
	// RCC->CFGR &= ~RCC_CFGR_OTGFSPRE;
	// RCC->AHBENR |= RCC_AHBENR_OTGFSEN;
}
