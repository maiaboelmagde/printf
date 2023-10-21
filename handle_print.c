#include "main.h"
/**
 * _print - Prints an argument
 * @format: Formatted string
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int _print(const char *format, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	format_t fmt_types[] = {
		{'c', printc}, {'s', prints}, {'%', printper},
		{'i', printd}, {'d', printd}, {'b', printb},
		{'u', printu}, {'o', printo}, {'x', printh},
		{'X', printhu}, {'p', printp}, {'S', printnpr},
		{'r', printrev}, {'R', _rot13}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].format != '\0'; i++)
		if (format[*ind] == fmt_types[i].format)
			return (fmt_types[i].f(list, buffer, flags, width, precision, size));

	if (fmt_types[i].format == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &format[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
