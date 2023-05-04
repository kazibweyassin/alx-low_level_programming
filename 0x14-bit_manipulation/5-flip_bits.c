#include "main.h"
/**
 * flip_bits - returns number of bits you would need to flip to get from one
 * number to another
 * @n: value 1
 * @m: value 2
 *
 * Return: number of bits to flip to get from one number to another
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flipbit;
	unsigned long int xore;

	flipbit = 0;
	xore = n ^ m;
	while (xore)
	{
		flipbit += xore & 1;
		xore >>= 1;
	}
	return (flipbit);
}
