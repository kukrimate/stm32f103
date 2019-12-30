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

enum {
	INPUT        = 0,
	OUTPUT_10MHZ = 1,
	OUTPUT_2MHZ  = 2,
	OUTPUT_50MHZ = 3
};

enum {
	INPUT_ANALOG   = 0,
	INPUT_FLOATING = 1,
	INPUT_PULL     = 2
};

enum {
	OUTPUT_G_PUSH_PULL  = 0,
	OUTPUT_G_OPEN_DRAIN = 1,
	OUTPUT_A_PUSH_PULL  = 2,
	OUTPUT_A_OPEN_DRAIN = 3
};

/* setup a GPIO pin to the desired mode */
static inline void gpio_config(struct gpio *port, int pin, int mode, int cnf)
{
	if (pin < 8) {
		port->CRL |= mode << (pin * 4);
		port->CRL |= cnf << (pin * 4 + 2);
	} else {
		port->CRH |= mode << ((pin - 8) * 4);
		port->CRH |= cnf << ((pin - 8) * 4 + 2);
	}
}

/* set a GPIO pin */
static inline void gpio_write(struct gpio *port, int pin, int val)
{
	if (val)
		port->BSRR |= 1 << pin;
	else
		port->BSRR |= 1 << (pin + 16);
}

#endif
