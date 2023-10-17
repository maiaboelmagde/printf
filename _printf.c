#include "main.h"
/**
 * print_string - print inpuit as string
 * @ap: va_list variable
 * Return:void
 */
int print_string(va_list ap)
{
	char *ch;
	int len;

	ch = va_arg(ap, char *);
	if (ch == NULL)
		ch = "(null)";
	len = 0;
	while (*ch != '\0')
	{
		_putchar((unsigned char) *ch);
		ch++;
		len++;
	}
	return (len);

}

/**
 * print_char - print input as char
 * @ap:pointer
 * Return:len of char
 */
int print_char(va_list ap)
{
	_putchar(va_arg(ap, int));
	return (1);
}
/**
 * print_mod - print %
 * @ap: va_lis variable
 * Return:1
 */
int print_mod(va_list ap)
{
	(void)ap;
	_putchar('%');
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
	  {'s', print_string}, {'c', print_char}
	, {'%', print_mod}, {'d', print_int}
	, {'i', print_int}, {'b', print_binary}
	, {'r', reverse_string}
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
