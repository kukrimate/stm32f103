.PHONY: all
all:
	make -C library/ all
	make -C examples/ all

.PHONY: clean
clean:
	make -C library/ clean
	make -C examples/ clean
