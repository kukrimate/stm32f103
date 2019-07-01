#ifndef GPIO_H
#define GPIO_H

struct gpio
{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t BRR;
	uint32_t LCKR;
};

#define PORTA ((struct gpio *) 0x40010800)
#define PORTB ((struct gpio *) 0x40010c00)
#define PORTC ((struct gpio *) 0x40011000)

#endif
