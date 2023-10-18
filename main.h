#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


/**
 * struct format - Struct for format
 * @ch: Struct format
 * @f: The function associated
 */

typedef struct format
{
	char ch;
	int (*f)(va_list);
} format_t;

void print_hexadecimal(unsigned int num, int *p);
int print_address(va_list ap);
int print_binary(va_list ap);
int print_unsigned(va_list ap);
int print_octal(va_list ap);
int print_hex_str(va_list ap);
int print_hex_ptr(va_list ap);
int print_hex(va_list ap);
int print_Hex(va_list ap);
int reverse_string(va_list ap);
int rev_rot13(va_list args);
int len_int(int ap);
int _printf(const char *format, ...);
int _putchar(char c);
int write_char(va_list val)
int write_string(va_list args)
int print_int(va_list ap);
int _strlen(char *str);
int _strlenc(const char *str);

#endif
