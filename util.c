#include "main.h"
/**
 * _printable - is a character is printable
 * @c: Character to be evaluated.
 * Return: 1 if c is printable, 0 otherwise
 */
int _printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
/**
 * _hexcode - Append asci in hexadecimal code
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASCI CODE.
 * Return:  3
 */
int _hexcode(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}
/**
 * _digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 * Return: 1 if c is a digit, 0 otherwise
 */
int _digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
/**
 * _sizenum - Cast a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 * Return: Casted value of num
 */
long int _sizenum(long int num, int size)
{
	if (size == _LONG)
		return (num);
	else if (size == _SHORT)
		return ((short)num);

	return ((int)num);
}
/**
 * _sizeu - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 * Return: Casted value of num
 */
long int _sizeu(unsigned long int num, int size)
{
	if (size == _LONG)
		return (num);
	else if (size == _SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
