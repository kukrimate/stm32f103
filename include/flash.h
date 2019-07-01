#ifndef FLASH_H
#define FLASH_H

struct flash
{
	uint32_t ACR;
	uint32_t KEYR;
	uint32_t OPTKEYR;
	uint32_t SR;
	uint32_t CR;
	uint32_t AR;
	uint32_t OBR;
	uint32_t WRPR;
};

// ACR -> LATENCY
#define FLASH_ACR_LATENCY_0 0
#define FLASH_ACR_LATENCY_1 1
#define FLASH_ACR_LATENCY_2 2

#define FLASH ((struct flash *) 0x40022000)

#endif
