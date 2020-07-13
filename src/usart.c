#include <stddef.h>
#include <stdint.h>
#include <rcc.h>
#include <gpio.h>
#include <usart.h>

// Setup USART1
void usart1_init()
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
