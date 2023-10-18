#include "main.h"

/**
 * printf_pointer - prints an hexgecimal number.
 * @val: arguments.
 * Return: counter.
 */
int printf_pointer(va_list val)
{
	void *ptr;
	char *str = "(nil)";
	int len;
	int i;
	va_list dest;

	va_copy(dest, val);
	ptr = va_arg(val, void*);
	if (ptr == NULL)
	{
		i = 0;
		while (*str)
		{
			_putchar(*str);
			str++;
			i++;
		}
		va_end(dest);
		return (i);
	}
	_putchar('0');
	_putchar('x');
	len = printf_hex_aux(dest);
	va_end(dest);
	return (len + 2);

}
