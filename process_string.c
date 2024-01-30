#include "main.h"
/**
 * convert_string - concatenates a string arguement to buffer.
 * @buffer: the buffer to which to concatenate a string.
 * @list: variable length list of arguements.
 * @counter: the number of characters in buffer.
 * @buff_size: size of buffer.
 * Return: buffer.
 */
char *convert_string(char *buffer, va_list list, int *counter, int *buff_size)
{
	char *str = va_arg(list, char *);

	if (str == NULL)
		exit(98);
	while (*str)
	{
		buffer[(*counter)++] = *str++;
		check_buffer_fill(buffer, counter, buff_size);
	}
	buffer[*counter] = 0;
	return (buffer);
}
/**
 * convert_char - concatenates a character arguement to buffer.
 * @buffer: the buffer to which we concatenate a character.
 * @list: variable length list of arguements.
 * @counter: the number of characters in buffer.
 * @buff_size: size of buffer.
 * Return: buffer.
 */
char *convert_char(char *buffer, va_list list, int *counter, int *buff_size)
{
	char c = va_arg(list, int);

	buffer[(*counter)++] = c;
	check_buffer_fill(buffer, counter, buff_size);
	buffer[*counter] = 0;
	return (buffer);
}
/**
 * non_format - concatenates a non format specifier character
 *                      from the fomrat string to buffer.
 * @buffer: the buffer to which we concatenate a character.
 * @format: the character or string to concatenate to buffer.
 * @counter: the number of characters in buffer.
 * @buff_size: size of buffer.
 * Return: buffer.
 */
char *non_format(char *buffer, char *format, int *counter, int *buff_size)
{
	buffer[(*counter)++] = *format;
	check_buffer_fill(buffer, counter, buff_size);
	buffer[*counter] = 0;
	return (buffer);
}
/**
 * print_buffer - prints a string of characters to a selected stream.
 * @buffer: the buffer to print.
 * @counter: the number of characters to print.
 */
void print_buffer(char *buffer, int counter)
{
	write(1, buffer, counter);
}
