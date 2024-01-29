#include "main.h"
/**
 * _abs - computes the absolute value of a number.
 * @x: the number whose absolute value to compute.
 * Return: absolute value of x.
 */
int _abs(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}
/**
 * convert_int - converts int to string and concatenates it to buffer.
 * @buffer: the buffer to concatenate converted string to.
 * @list: variable length list of arguements.
 * @counter: pointer to last index of the buffer.
 * @buff_size: pointer to size of the buffer.
 * Return: pointer to the converted string.
 */
char *convert_int(char *buffer, va_list list, int *counter, int *buff_size)
{
	char *converted_num;
	int i, next_digit, num, is_negative = 0, digit = 0, size = 64;
	const char base[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	converted_num = malloc(sizeof(char) * size);
	num = va_arg(list, int);
	if (num < 0)
		is_negative = 1;
	num = _abs(num);
	do {
		if (digit == size - 1)
			converted_num = realloc(converted_num, size += 64);
		converted_num[digit++] = num % 10;
		num /= 10;
		(*counter)++;
		check_buffer_fill(buffer, counter, buff_size);
		converted_num[digit] = 0;
	} while (num);

	for (i = digit - 1; i >= 0; i--)
	{
		next_digit = converted_num[i];
		converted_num[i] = base[next_digit];
	}
	if (is_negative)
	{
		if (digit == size - 1)
			converted_num = realloc(converted_num, size += 64);
		converted_num[digit++] = '-';
		(*counter)++;
		check_buffer_fill(buffer, counter, buff_size);
		converted_num[digit] = 0;
	}
	rev_string(converted_num);
	buffer = _strcat(buffer, converted_num);
	free(converted_num);
	return (buffer);
}
