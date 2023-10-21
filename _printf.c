#include "main.h"

void printbuf(char buffer[], int *buf_ind);
/**
 * _printf - own printf function
 * @format: the format.
 * Return: print_char.
 */
int _printf(const char *format, ...)
{
	int i, print = 0, print_char = 0;
	int flags, width, precision, size, buf_ind = 0;
	va_list list;
	char buffer[BUFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buf_ind++] = format[i];
			if (buf_ind == BUFER_SIZE)
				printbuf(buffer, &buf_ind);
			print_char++;
		}
		else
		{
			printbuf(buffer, &buf_ind);
			flags = _flags(format, &i);
			width = _width(format, &i, list);
			precision = _precision(format, &i, list);
			size = _size(format, &i);
			++i;
			print = _print(format, &i, list, buffer,
				flags, width, precision, size);
			if (print == -1)
				return (-1);
			print_char += print;
		}
	}

	printbuf(buffer, &buf_ind);

	va_end(list);

	return (print_char);
}
/**
 * printbuf - prints content of the buffer
 * @buffer:  chars array
 * @buf_ind: represents the length.
 */
void printbuf(char buffer[], int *buf_ind)
{
	if (*buf_ind > 0)
		write(1, &buffer[0], *buf_ind);

	*buf_ind = 0;
}
