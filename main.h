#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _abs(int x, int *is_negative);
int _putchar(char c);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void rev_string(char *s);

void check_size(char *, int *, int *);
char *convert_int(char *buffer, va_list list, int *counter, int *buff_size);
char *convert_string(char *buffer, va_list list, int *counter, int *buff_size);
char *non_format(char *buffer, char *format, int *counter, int *buff_size);
char *convert_char(char *buffer, va_list list, int *counter, int *buff_size);
void check_buffer_fill(char *buffer, int *counter, int *buff_size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _printf(char *format, ...);
void print_buffer(char *buffer, int counter);
void error(void);

#endif/*PRINTF_H*/
