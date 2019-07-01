#ifndef DEBUG_H
#define DEBUG_H

// Set the debug serial port
void debug_setserial(struct usart *serport);

// Print a character to the debug console
void debug_putchar(char c);

// Print a string to the debug console
void debug_puts(const char *s);

// Heavily stripped-down debugging printf
void debug_print(char *format, ...);

#endif
