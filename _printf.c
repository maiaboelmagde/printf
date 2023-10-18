#include "main.h"
/**
*write_string - a function that writes a string to the standard output
 *@val:variadic arguments
 *Return:the number of characters printed
*/
int write_string(va_list val)
{
	int len;
	int i;
	char *str;

	str = va_arg(val, char *);
	if (str == NULL)
	{
		str = "(null)";
		len = _strlen(str);
		for (i = 0; i < len; i++)
			_putchar(str[i]);
		return (len);
	}
	else
	{
		len = _strlen(str);
		for (i = 0; i < len; i++)
			_putchar(str[i]);
		return (len);
	}
}
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
/**
 *write_specifier - a function that writes a specifier to the standard output
 *@val:variadic arguments
 *Return:the number of characters printed
*/
int write_specifier(va_list args)
{
	(void) args;
	write(STDOUT_FILENO, "%", 1);/*prints single specifier to screen*/

	return (1);
}
/**
*is_specifier - a function that checks if there is a specifier in the format
 *@spacifiers: array of structs containing different conversion specifiers
 *@format: pointer to an array containing the string of chars to be handled
 *Return: -1 in case of reaching the end of format
 *		  (i) in case of finding a match to the specifier
*/
int is_specifier(format_t spacifiers[], char *format)
{
	int i;
	char fchar;

	i = 0;
	if (format[i] == '%')
	{
		if (format[i + 1] == '\0')
			return (-1);/*error*/
		fchar = format[i + 1];
		/*select spacifier function*/
		for (i = 0; i < 14; i++)/*loop through each specifier in array*/
		{
			/*checking for a match in the format given*/
			if (spacifiers[i].ch == fchar)
				return (i);/*return element No. to get the right function*/
		}
	}
	/*not found*/
	return (-2);
}
/**
 *_printf - a function to print a string using a format
 *@format: pointer to an array containing the string of chars to be handled
 *Return: count or error upon failing (-1)
 */
int _printf(const char *format, ...)
{
	int i, s_index, write_count;
	va_list args;
	/*spcifirs array of type specifier_t(struct)with right functions to call*/
	format_t spacifiers[] = {
	  {'s', write_string}, {'c', write_char}
	, {'%', write_specifier}, {'d', print_int}
	, {'i', print_int}, {'b', print_binary}
	, {'r', reverse_string}, {'R', rev_rot13}
	, {'o', print_octal}, {'u', print_unsigned}
	, {'x', print_hex}, {'X', print_Hex}, {'S', print_hex_str}
	, {'p', print_address},};

	if (format == NULL)
		return (-1);

	va_start(args, format);
	write_count = 0;
	for (i = 0; (format != NULL) && (format[i] != '\0'); i++)
	{
		s_index = is_specifier(spacifiers, (char *) (format + i));

		if (s_index == -2)
		{
			write(STDOUT_FILENO, (char *) (format + i), 1);
			write_count++;
		}
		else if (s_index == -1)
		{
			return (-1);
		}
		else
		{
			write_count = write_count + spacifiers[s_index].f(args);
			i++;
		}
	}
	va_end(args);
return (write_count);
}
