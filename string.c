#include "main.h"
/**
 * _strcat - concatenates two strings.
 * @src: source string to copy from
 * @dest: destination string to concatenate to
 * Return: pointer to the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int i, j, k;

	for (i = 0; dest[i] != 0; i++)
		;
	for (j = 0; src[j] != 0; j++)
		;
	for (k = 0; k <= j; k++)
		dest[i++] = src[k];
	return (dest);
}
/**
 * _strcpy - copies the string pointed to by src including the terminating
 *           null byte to the buffer pointed to by dest.
 * @src: the source of the string to copy from
 * @dest: desstination buffer to which we copy our string.
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != 0)
		i++;
	while (i >= 0)
	{
		dest[i] = src[i];
		i--;
	}
	return (dest);
}
/**
 * rev_string - reverses a string
 * @s: the string to reverse
 */
void rev_string(char *s)
{
	char tmp;
	int i = 0, j = 0;

	while (s[i] != 0)
		i++;
	while (j < --i)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j++] = tmp;
	}
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
