#include "main.h"
/**
 *write_char - a function that writes a char to the standard output
 *@val:variadic arguments
 *Return:the number of characters printed
*/
int write_char(va_list val)
{
	char str;

	str = va_arg(val, int);
	_putchar(str);
	return (1);
}
