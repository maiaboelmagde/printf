#include "main.h"
/**
 * printu - Prints an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int printu(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = _sizeu(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (writeu(0, i, buffer, flags, width, precision, size));
}
/**
 * printo - Prints an unsigned number in octal
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of chars
 */
int printo(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = _sizeu(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & _HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (writeu(0, i, buffer, flags, width, precision, size));
}
/**
 * printh - Prints an unsigned number in hexadecimal
 * @types: Lista of arguments
 * @buffer: Buffer array
 * @flags: active flags
 * @width: get width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of chars
 */
int printh(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (printhex(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/**
 * printhu - Prints an unsigned number in upper hexadecimal
 * @types: Lista of arguments
 * @buffer: Buffer array
 * @flags: active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int printhu(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (printhex(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/**
 * printhex - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int printhex(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = _sizeu(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & _HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (writeu(0, i, buffer, flags, width, precision, size));
}
