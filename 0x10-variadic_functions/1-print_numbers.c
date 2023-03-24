#include <stdarg.h>
#include "variandic_functions.h"
/**
 * print_numbers-  prints numbers
 * @separator: string between numbers
 * @n:number of parameters recieved
 *
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;

	va_list numbers;

	va_start(number, n);

	for (i = 0 ; i < n ; i++)
	{
		printf("%d", va_arg(number, int));

		if (seperator != NULL && i < n - 1)
		{
			printf("%s", seperator);
		}


	}
	va_end(number);
	printf("\n");
}
