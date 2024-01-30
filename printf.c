#include "main.h"

/**
 * _printf - prints a formatted string to the standard output.
 * @format: directs how to format the string.
 * Return: the number of characters printed.
 */

int _printf(char *format, ...)
{
	int counter = 0;
	int buff_size = 1024;
	char *buffer = malloc(sizeof(char) * buff_size);
	va_list list;

	buffer[0] = 0;
	va_start(list, format);
	if (format == 0)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				non_format(buffer, format, &counter, &buff_size);
			else if (*format == 'd' || *format == 'i')
				convert_int(buffer, list,  &counter, &buff_size);
			else if (*format == 'c')
				convert_char(buffer, list, &counter, &buff_size);
			else if (*format == 's')
				convert_string(buffer, list, &counter, &buff_size);
		}
		else
			non_format(buffer, format, &counter, &buff_size);
		format++;
	}
	print_buffer(buffer, counter);
	free(buffer);
	return (counter);
}
