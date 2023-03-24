#include <string.h>
#include "variadic_functions.h"
/**
 * sum_them_all - the sum of all its paremeters
 * @n: number of parameters recieved
 *
 * Return: 0 if n is - of te sum of parameters
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int add = 0, number;

	va_list parameters;

	va_start(parameters, n);

	if (n == 0)
	{
		return (0);
	}
	for (i = 0 ; i < n ; i++)
	{
		number = va_arg(parameters, int);
		add = add + number;
	}
	va_end(parameters);
	return (add);
}
