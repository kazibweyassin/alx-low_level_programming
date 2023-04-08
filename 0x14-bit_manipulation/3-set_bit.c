#include "main.h"
/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: A pointer to an unsigned long int number
 * @index: index of the bit you want to get
 *
 * Return: 1 if it worked or -1 if an error ocurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 32)
		return (-1);

	*n |= (1 << index);
	return (1);
}
