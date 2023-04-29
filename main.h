#ifndef WOKDWODKWD_H
#define WOKDWODKWD_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

int _printf(const char *format, ...);
void *_realloc(void *myptsiq, unsigned int old_size, unsigned int new_size);
unsigned int premyintwqi(int ooqiw);
int _putchar(char c);

unsigned int print_unsigned(unsigned int n);
unsigned int print_hexadecimal(unsigned int n, int a);
unsigned int print_unprintable(char *s);
unsigned int print_string(char *s);
unsigned int print_base(unsigned int n, int base);

#endif
