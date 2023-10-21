#include "main.h"
/**
 * _flags - Calculates the number of active flags
 * @format: Formatted string
 * @a:  parameter.
 * Return: Flags:
 */
int _flags(const char *format, int *a)
{
	int b, cur_a;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {_MINUS, _PLUS, _ZERO, _HASH, _SPACE, 0};

	for (cur_a = *a + 1; format[cur_a] != '\0'; cur_a++)
	{
		for (b = 0; FLAGS_CH[b] != '\0'; b++)
			if (format[cur_a] == FLAGS_CH[b])
			{
				flags |= FLAGS_ARR[b];
				break;
			}

		if (FLAGS_CH[b] == 0)
			break;
	}

	*a = cur_a - 1;

	return (flags);
}
