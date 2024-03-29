#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * linear_search - performs linear search
 * @array: the integer array
 * @size: number of elements
 * @value: value to search for
 *
 * Return: The index found of -1
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	if (!array)
		return (-1);
	while (i < size)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
