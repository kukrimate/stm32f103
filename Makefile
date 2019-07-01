# Tools
PREFIX  := arm-none-eabi-
CC      := $(PREFIX)gcc
OBJCOPY := $(PREFIX)objcopy

# Flags
CFLAGS  := -mcpu=cortex-m3 -mthumb -ffreestanding -Iinclude
LDFLAGS := -nostdlib -T stm32f103.ld

# Objects
OBJ = vector_table.o hwinit.o blink.o util.o debug.o

blink.bin: blink.elf
	$(OBJCOPY) $^ $@ -O binary

blink.elf: $(OBJ) stm32f103.ld
	$(CC) $(LDFLAGS) $(OBJ) -o $@

# Compile rules
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
%.o: %.S
	$(CC) $(CFLAGS) -c $^ -o $@

# Turn an elf into a flat binary
%.bin: %.elf
	$(OBJCOPY) $^ -o $@ -O binary

.PHONY: write
write: blink.bin
	st-flash erase
	st-flash write $^ 0x08000000

.PHONY: clean
clean:
	rm -f *.o *.elf *.bin
