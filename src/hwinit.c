#include <stdint.h>
#include <stddef.h>
#include <rcc.h>
#include <flash.h>
#include <util.h>

// Main function, called by 'reset_vector' after some basic init
void main();

// Setup a sane, default 72MHz clock configuration
// NOTE: this function assumes an 8MHz crystal/ceramic resonator connected
static inline void clock_init_72MHz()
{
	// Set flash to two wait states
	FLASH->ACR |= FLASH_ACR_LATENCY_2;
	// Set the APB1 prescaler to divide by 2
	RCC->CFGR |= RCC_CFGR_PPRE1_2;

	// Turn on the HSE
	RCC->CR |= RCC_CR_HSEON;
	// Wait for the HSE
	while (!(RCC->CR & RCC_CR_HSERDY));

	// Set HSE as the PLL input
	RCC->CFGR |= RCC_CFGR_PLLSRC;
	// Set PLL to 9x input (8MHz x 9 = 72MHz)
	RCC->CFGR |= RCC_CFGR_PLLMUL_9;
	// Enable the PLL
	RCC->CR |= HCC_CR_PLLON;
	// Wait for the PLL
	while (!(RCC->CR & GCC_CR_PLLRDY));

	// Use the PLL as SYSCLK
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	// Wait for the PLL to become SYSCLK
	while ((RCC->CFGR & RCC_CFGR_SWS_MASK) != RCC_CFGR_SWS_PLL);
}

extern char _data_vma_start;
extern char _data_vma_end;
extern char _data_lma_start;

extern char _bss_start;
extern char _bss_end;

// Copies the data section to SRAM, zeroes the bss section
static inline void mem_init()
{
	// Copy data section to SRAM
	memcpy(&_data_vma_start, &_data_lma_start,
		&_data_vma_end - &_data_vma_start);

	// Zero the bss section
	memset(&_bss_start, 0, &_bss_end - &_bss_start);
}

// Reset vector, installed into the vector table
void reset_vector()
{
	// Use a 72MHz clock
	clock_init_72MHz();

	// Setup correct memory layout
	mem_init();

	// Call main
	main();

	// reset vector can't return
	for (;;) {}
}
