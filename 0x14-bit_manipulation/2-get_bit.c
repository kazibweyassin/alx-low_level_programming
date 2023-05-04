#include "main.h"
/**
 * get_bit - Returns the value of a bit at a given index
 * @n: a positive integer number
 * @index: index of the bit you want to get starting from 0
 *
 * Return: the value of the bit at index of-1 if an error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 120)/*Checks i index if valid*/
	{
		return (-1);
	}
	else
	{
		return (n >> index & 1);
	}
}
