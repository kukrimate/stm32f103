include ../tools/Makefile.stm32f103

# blink example object file
BLINK_OBJ := blink.o
# serial example object files
SERIAL_OBJ := serial.o

.PHONY: all
all: blink.bin serial.bin

blink.bin: blink.elf
	$(OBJCOPY) $^ $@ -O binary

blink.elf: $(BLINK_OBJ) $(LIBS) $(LDSCRIPT)
	$(CC) $(LDFLAGS) $(BLINK_OBJ) $(LIBS) -o $@

serial.bin: serial.elf
	$(OBJCOPY) $^ $@ -O binary

serial.elf: $(SERIAL_OBJ) $(LIBS) $(LDSCRIPT)
	$(CC) $(LDFLAGS) $(SERIAL_OBJ) $(LIBS) -o $@

.PHONY: write
write: blink.bin
	st-flash erase
	st-flash write $^ 0x08000000

.PHONY: clean
clean:
	rm -f *.o *.a *.elf *.bin
