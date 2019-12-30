include ../tools/Makefile.stm32f103

# Library objects
LIBRARY_OBJ = hwinit.o util.o debug.o usart.o

.PHONY: all
all: library.a

# Build library
library.a: $(LIBRARY_OBJ)
	$(AR) -cr $@ $^

.PHONY: clean
clean:
	rm -f *.o *.a *.elf *.bin
