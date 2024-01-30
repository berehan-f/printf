#include "main.h"
/**
 * _abs - computes the absolute value of a number.
 * @x: the number whose absolute value to compute.
 * @is_negative: pointer to negative flag.
 * Return: absolute value of x.
 */
int _abs(int x, int *is_negative)
{
	if (x < 0)
	{
		x *= -1;
		*is_negative = 1;
	}
	return (x);
}
/**
 * check_size - checks the size of buffer used to hold integer digits.
 * @converted_num: the buffer used to hold integer digits.
 * @counter: pointer to index of last element of the buffer converted_num.
 * @digit: the current number of digits in converted_num.
 */
void check_size(char *converted_num, int *counter, int *digit)
{
	const int size = 64;
	static int j = 1;

	if (*digit == size * j - 1)
	{
		converted_num = _realloc(converted_num, size * j, size * (j + 1));
		if (converted_num == 0)
			exit(98);
		j++;
	}
	(*counter)++;
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
	int i, next_digit, num, j = 1, is_negative = 0, digit = 0, size = 64;
	const char base[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	converted_num = malloc(sizeof(char) * size * j);
	num = va_arg(list, int);
	num = _abs(num, &is_negative);
	do {
		check_size(converted_num, counter, &digit);
		converted_num[digit++] = num % 10;
		num /= 10;
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
		check_size(converted_num, counter, &digit);
		converted_num[digit++] = '-';
		check_buffer_fill(buffer, counter, buff_size);
		converted_num[digit] = 0;
	}
	rev_string(converted_num);
	buffer = _strcat(buffer, converted_num);
	free(converted_num);
	return (buffer);
}
