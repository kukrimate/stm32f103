include ../tools/Makefile.stm32f103

STMFLASH_OBJ := stmflash.o

.PHONY: all
all: stmflash.bin

stmflash.bin: stmflash.elf
	$(OBJCOPY) $^ $@ -O binary

stmflash.elf: $(STMFLASH_OBJ) $(LIBS) $(LDSCRIPT)
	$(CC) $(LDFLAGS) $(STMFLASH_OBJ) $(LIBS) -o $@

.PHONY: write
write: stmflash.bin
	st-flash erase
	st-flash write $^ 0x08000000

.PHONY: clean
clean:
	rm -f *.o *.a *.elf *.bin
