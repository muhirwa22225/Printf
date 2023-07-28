#include <stdio.h>
#include <stdarg.h>

/**
 * is_digit - checks whether a character is a digit
 * @c: the character to be checked
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 */
#define is_digit(c) ((c) >= '0' && (c) <= '9')

/**
 * get_precision - precision calculation for printing
 * @format: string format that prints the arguments
 * @i: arguments list to print
 * @list: specifier arguments list
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int precision = -1;

if (format[curr_i] != '.')
return (precision);

precision = 0;

for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
{
if (is_digit(format[curr_i]))
{
precision *= 10;
precision += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
precision = va_arg(list, int);
break;
}
else
break;
}

*i = curr_i - 1;
return (precision);
}
