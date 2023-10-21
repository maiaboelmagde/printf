#include "main.h"
/**
 * _size - Calculates the size
 * @format: Formatted string
 * @i: List of arguments to be printed.
 * Return: Precision.
 */
int _size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = _LONG;
	else if (format[curr_i] == 'h')
		size = _SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
