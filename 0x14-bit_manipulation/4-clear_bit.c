#include "main.h"
/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: a pointer to an unsigned long int number
 * @index: index of the bit you want to set to 0, starting from 0
 *
 * Return: 1 if it worked or -1 if an error ocurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 32)
	{
		return (-1);
	}

	*n &= ~(1 << index);
		return (1);
}
