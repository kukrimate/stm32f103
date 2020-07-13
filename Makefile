# Tools
PREFIX	:= arm-none-eabi
CC	:= $(PREFIX)-gcc
OBJCOPY	:= $(PREFIX)-objcopy

# Flags
CFLAGS	:= -Iinclude -mcpu=cortex-m3 -mthumb -ffreestanding
LDFLAGS	:= -nostdlib -T stm32f103.ld

# Compile rules
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
%.o: %.S
	$(CC) $(CFLAGS) -c $^ -o $@

# Turn an elf into a flat binary
%.bin: %.elf
	$(OBJCOPY) $^ -o $@ -O binary

OBJ := \
	src/util.o \
	src/hwinit.o \
	src/usart.o \
	src/debug.o \
	src/stmflash.o

.PHONY: all
all: stmflash.bin

stmflash.bin: stmflash.elf
	$(OBJCOPY) $^ $@ -O binary

stmflash.elf: $(OBJ) $(LIBS) $(LDSCRIPT)
	$(CC) $(LDFLAGS) $(OBJ) $(LIBS) -o $@

.PHONY: write
write: stmflash.bin
	st-flash erase
	st-flash write $^ 0x08000000

.PHONY: clean
clean:
	rm -f $(OBJ) *.elf *.bin
