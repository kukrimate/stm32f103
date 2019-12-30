#ifndef RCC_H
#define RCC_H

struct rcc
{
	uint32_t CR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t APB2RSTR;
	uint32_t APB1RSTR;
	uint32_t AHBENR;
	uint32_t APB2ENR;
	uint32_t APB1ENR;
	uint32_t BDCR;
	uint32_t CSR;
};

// CR -> HSEON
#define RCC_CR_HSEON (1 << 16)
// CR -> HSERDY
#define RCC_CR_HSERDY (1 << 17)
// CR -> PLLON
#define HCC_CR_PLLON (1 << 24)
// CR -> PPLRDY
#define GCC_CR_PLLRDY (1 << 25)

// CFGR -> SW
#define RCC_CFGR_SW_MASK 3

#define RCC_CFGR_SW_HSI 0
#define RCC_CFGR_SW_HSE 1
#define RCC_CFGR_SW_PLL 2

// CFGR -> SWS
#define RCC_CFGR_SWS_MASK (3 << 2)

#define RCC_CFGR_SWS_HSI (0 << 2)
#define RCC_CFGR_SWS_HSE (1 << 2)
#define RCC_CFGR_SWS_PLL (2 << 2)

// CFGR -> PPRE1
#define RCC_CFGR_PPRE1_MASK (7 << 8)

#define RCC_CFGR_PPRE1_1  (0 << 8)
#define RCC_CFGR_PPRE1_2  (4 << 8)
#define RCC_CFGR_PPRE1_4  (5 << 8)
#define RCC_CFGR_PPRE1_8  (6 << 8)
#define RCC_CFGR_PPRE1_16 (7 << 8)

// CFGR -> PLLSRC
#define RCC_CFGR_PLLSRC (1 << 16)

// CFGR -> PLLMUL
#define RCC_CFGR_PLLMUL_MASK (15 << 18)

#define RCC_CFGR_PLLMUL_2  (0 << 18)
#define RCC_CFGR_PLLMUL_3  (1 << 18)
#define RCC_CFGR_PLLMUL_4  (2 << 18)
#define RCC_CFGR_PLLMUL_5  (3 << 18)
#define RCC_CFGR_PLLMUL_6  (4 << 18)
#define RCC_CFGR_PLLMUL_7  (5 << 18)
#define RCC_CFGR_PLLMUL_8  (6 << 18)
#define RCC_CFGR_PLLMUL_9  (7 << 18)
#define RCC_CFGR_PLLMUL_10 (8 << 18)
#define RCC_CFGR_PLLMUL_11 (9 << 18)
#define RCC_CFGR_PLLMUL_12 (10 << 18)
#define RCC_CFGR_PLLMUL_13 (11 << 18)
#define RCC_CFGR_PLLMUL_14 (12 << 18)
#define RCC_CFGR_PLLMUL_15 (13 << 18)
#define RCC_CFGR_PLLMUL_16 (14 << 18)
// #define RCC_CFGR_PLLMUL_16 (15 << 18)

#define RCC_AHBENR_OTGFSEN (1 << 12)

#define RCC_CFGR_OTGFSPRE (1 << 22)

#define RCC ((struct rcc *) 0x40021000)

#endif
