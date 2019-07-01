/* Cortex-M3 vector table */
.section .vector_table,"a"

.word _initial_sp			// initial sp
.word _reset_vector			// reset vector
.word 0						// NMI
.word 0						// hard fault
.word 0						// MM fault
.word 0						// bus fault
.word 0						// usage fault
.word 0						// reserved
.word 0						// reserved
.word 0						// reserved
.word 0						// reserved
.word 0						// svcall
.word 0						// debug reserved
.word 0						// reserved
.word 0						// pendsv
.word 0						// systick
//.word 0						// IRQ0
//.word 0						// IRQ1
//.....

.section .text

.thumb_func
_reset_vector:
bl reset_vector
b .
