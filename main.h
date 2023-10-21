#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define _LONG 2
#define _SHORT 1
#define UNUSED(x) (void)(x)
#define BUFER_SIZE 1024
#define _MINUS 1
#define _PLUS 2
#define _ZERO 4
#define _HASH 8
#define _SPACE 16

/**
 * struct format - match the conversion
 * @format: The char pointer.
 * @f: The pointer to function associated.
 */
struct format
{
	char format;
	int (*f)(va_list, char[], int, int, int, int);
};

typedef struct format format_t;

int _printable(char);
int _hexcode(char, char[], int);
int _digit(char);
long int _sizenum(long int num, int size);
long int _sizeu(unsigned long int num, int size);
int _printf(const char *format, ...);
int _print(const char *format, int *i, va_list list,
char buffer[], int flags, int width, int precision, int size);
int printc(va_list types, char buffer[], int flags,
int width, int precision, int size);
int prints(va_list types, char buffer[], int flags,
int width, int precision, int size);
int printper(va_list types, char buffer[], int flags,
int width, int precision, int size);
int printd(va_list types, char buffer[], int flags,
int width, int precision, int size);
int printb(va_list types, char buffer[], int flags,
int width, int precision, int size);
int printu(va_list types, char buffer[], int flags,
int width, int precision, int size);
int printo(va_list types, char buffer[], int flags,
int width, int precision, int size);
int printh(va_list types, char buffer[],
int flags, int width, int precision, int size);
int printhu(va_list types, char buffer[],
int flags, int width, int precision, int size);
int printhex(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width,
int precision, int size);
int printnpr(va_list types, char buffer[],
int flags, int width, int precision, int size);
int printp(va_list types, char buffer[], int flags,
int width, int precision, int size);
int _flags(const char *format, int *i);
int _width(const char *format, int *i, va_list list);
int _precision(const char *format, int *i, va_list list);
int _size(const char *format, int *i);
int printrev(va_list types, char buffer[], int flags, int width,
int precision, int size);
int _rot13(va_list types, char buffer[], int flags, int width,
int precision, int size);
int writec(char c, char buffer[], int flags, int width,
int precision, int size);
int writed(int is_positive, int ind, char buffer[], int flags,
int width, int precision, int size);
int writen(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int writep(char buffer[], int ind, int length, int width, int flags,
char padd, char extra_c, int padd_start);
int writeu(int is_negative, int ind, char buffer[], int flags, int width,
int precision, int size);
#endif
