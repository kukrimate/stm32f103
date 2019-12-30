/* Linker script for the STM32F103xx MCUs */

/* Flash base and size */
_flash_base = 0x08000000;
_flash_size = 64K; /* NOTE: if you're MCU has more flash change it here */

/* SRAM base and size */
_sram_base = 0x20000000;
_sram_size = 20K;

/* Initial stack pointer */
_initial_sp = _sram_base + _sram_size;

MEMORY
{
	FLASH (RX)  : ORIGIN = _flash_base, LENGTH = _flash_size
	SRAM  (RWX) : ORIGIN = _sram_base,  LENGTH = _sram_size
}

/* this isn't strictly necessary, but a linker ignores our library otherwise */
ENTRY(reset_vector)

SECTIONS
{
	.vector_table _flash_base :
	{
		LONG(_initial_sp);
		LONG(reset_vector | 1);

		/* leave space for the rest */
		. = . + 0x148;
	} >FLASH

	.text :
	{
		. = ALIGN(4);
		_text_start = .;

		*(.text*)

		. = ALIGN(4);
		_text_end = .;
	} >FLASH

	.rodata :
	{
		. = ALIGN(4);
		_rodata_start = .;

		*(.rodata*)

		. = ALIGN(4);
		_rodata_end = .;
	} >FLASH

	.data :
	{
		. = ALIGN(4);
		_data_vma_start = .;

		/* HACK NOTE: this is kind of ugly, because technically
		   this will ignore the starting alingment of this section,
		   but since the end of rodata is aligned this will not be a problem
		*/
		_data_lma_start = LOADADDR(.data);

		*(.data*)

		. = ALIGN(4);
		_data_vma_end = .;
	} >SRAM AT >FLASH

	.bss :
	{
		. = ALIGN(4);
		_bss_start = .;

		*(.bss*)
		*(COMMON)

		. = ALIGN(4);
		_bss_end = .;
	} >SRAM

	/DISCARD/ :
	{
		*(*)
	}
}
