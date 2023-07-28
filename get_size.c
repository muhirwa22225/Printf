#include "main.h"

/**
 * get_size - Determines the data size for typecasting an argument.
 * @format: The format string used for printing the arguments.
 * @i: Pointer to the current index in the format string.
 *
 * Return: The data size for typecasting the argument.
 */
int get_size(const char *format, int *i)
{
int curr_i = *i + 1;
int size = 0;

if (format[curr_i] == 'l')
size = S_LONG;
else if (format[curr_i] == 'h')
size = S_SHORT;

if (size == 0)
*i = curr_i - 1;
else
*i = curr_i;
return (size);
}
