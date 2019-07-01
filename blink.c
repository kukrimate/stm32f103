#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <rcc.h>
#include <gpio.h>
#include <usart.h>
#include <debug.h>

// Setup USART1
static inline void usart1_init()
{ // PA9: USART1_TX; PA10: USART1_RX

	// Enable PORTA
	RCC->APB2ENR |= 4;
	// Enable USART1
	RCC->APB2ENR |= 0x4000;
	// Set PA9 -> AF output, 50MHz, push-pull
	PORTA->CRH |= 0xE0;
	// Set PA10 -> input, floating
	PORTA->CRH |= 0x400;

	// Set baudrate
	USART1->BRR = 72000000 / 115200;
	// Set RE, TE, UE
	USART1->CR1 |= 0x200C;
}

void main()
{
	// Initialize USART1 and set it as the debug port
	usart1_init();
	debug_setserial(USART1);

	// Output a string over serial
	debug_print("Hello world, STM32!\n");

	// Enable PORTC
	RCC->APB2ENR |= 0x10;

	// Configure PC13 as an open-drain output
	PORTC->CRH |= 0x600000;

	for (;;) {
		PORTC->BSRR |= 0x2000;
		for (int i = 2000000; i; --i);
		PORTC->BSRR |= 0x20000000;
		for (int i = 2000000; i; --i);
	}
}
