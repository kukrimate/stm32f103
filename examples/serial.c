#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <usart.h>
#include <debug.h>

void main()
{
	// Initialize USART1 and set it as the debug port
	usart1_init();
	debug_setserial(USART1);

	// Output a string over serial
	debug_print("Hello world, STM32!\n");
}
