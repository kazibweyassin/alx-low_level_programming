#include "main.h"
/**
 * print_binary - prints the binary representation of an unsigned long int
 * @n: The number to be printed in binary
 *
 */
void print_binary(unsigned long int n)
{
	int bina = ((n & 1) + '0');

	if (n > 1)
	{
		print_binary(n >> 1);
	}
	_putchar(bina);
}
