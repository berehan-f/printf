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
/**
 * _realloc - reallocates a memory block using malloc and free.
 * @ptr: a pointer to the memory previously allocated with a call to malloc.
 * @old_size: the size, in bytes, of the allocated space for ptr.
 * @new_size: the new size, in bytes of the new memory block.
 * Return: pointer to the newly allocated memory.
 *         ptr if new_size == old_size.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i, min;
	char *new_ptr;

	if (ptr == NULL)
		return (malloc(new_size));
	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	if (old_size < new_size)
		min = old_size;
	else
		min = new_size;

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	for (i = 0; i < min; i++)
		new_ptr[i] = ((char *) ptr)[i];

	free(ptr);
	return ((void *) new_ptr);
}
