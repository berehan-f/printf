#include "main.h"
/**
 * check_buffer_fill - checks if the buffer is full and reallocates new memory.
 * @buffer: the buffer to check.
 * @counter: a pointer to an index of last element of buffer.
 * @buff_size: a pointer to size of buffer.
 */
void check_buffer_fill(char *buffer, int *counter, int *buff_size)
{
	if (*counter == *buff_size)
	{
		(*buff_size) += 1024;
		buffer = realloc(buffer, *buff_size);
	}
}
