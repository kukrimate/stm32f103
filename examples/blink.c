#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <rcc.h>
#include <gpio.h>

void main()
{
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
