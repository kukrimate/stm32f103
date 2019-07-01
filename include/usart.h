#ifndef USART_H
#define USART_H

struct usart
{
	uint32_t SR;
	uint32_t DR;
	uint32_t BRR;
	uint32_t CR1;
	uint32_t CR2;
	uint32_t CR3;
	uint32_t GTPR;
};

#define USART1 ((struct usart *) 0x40013800)
#define USART2 ((struct usart *) 0x40004400)
#define USART3 ((struct usart *) 0x40004800)

#endif
