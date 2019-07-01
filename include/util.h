#ifndef UTIL_H
#define UTIL_H

// Standard memcpy
void *memcpy(void *dest, void *src, size_t n);

// Standard memset
void *memset(void *mem, uint8_t byte, size_t n);

// Standard strcpy
char *strcpy(char *dest, char *src);

// Standrad strlen
size_t strlen(char *str);

// Reverse the string 's'
// Returns: s
char *strrev(char *s);

#endif
