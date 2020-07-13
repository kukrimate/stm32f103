#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <usart.h>
#include <util.h>

// Debug console

static struct usart *debug_serport = NULL;

void debug_setserial(struct usart *serport)
{
	debug_serport = serport;
}

void debug_putchar(char c)
{
	if (!debug_serport)
		return;
	if (c == '\n')
		debug_putchar('\r');
	while (!(debug_serport->SR & 0x80));
	debug_serport->DR = c & 0xff;
}

void debug_puts(const char *s)
{
	for (; *s; ++s)
		debug_putchar(*s);
}

// Convert numbers to strings

static const char num_lookup[] = "0123456789abcdef";

static void debug_printptr(uintptr_t ptr)
{
	debug_puts("0x");
	for (int i = sizeof(ptr) * 8; i; i -= 4) {
		debug_putchar(num_lookup[(ptr >> (i - 4)) & 0xf]);
	}
}

static void debug_printusig(unsigned n, unsigned b)
{
	char buf[10], *p = buf;

	do {
		*p++ = num_lookup[n % b];
	} while (n /= b);

	--p;
	for (; buf <= p; --p)
		debug_putchar(*p);
}

static void debug_printsig(int n, unsigned b)
{
	if (n < 0) {
		n *= -1;
		debug_putchar('-');
	}
	debug_printusig(n, b);
}

// Debug print

void debug_print(char *format, ...)
{
	va_list ap;

	va_start(ap, format);

	for (; *format; ++format) {
		if (*format == '%')
			switch (*++format) {
			case 'c':
				debug_putchar((char) va_arg(ap, int));
				break;
			case 's':
				debug_puts(va_arg(ap, const char *));
				break;
			case 'p':
				debug_printptr(va_arg(ap, uintptr_t));
				break;
			case 'x':
				debug_printusig(va_arg(ap, unsigned), 16);
				break;
			case 'd':
				debug_printsig(va_arg(ap, int), 10);
				break;
			case 'u':
				debug_printusig(va_arg(ap, unsigned), 10);
				break;
			default:
				debug_putchar('?');
				break;
			}
		else
			debug_putchar(*format);
	}

	va_end(ap);
}
