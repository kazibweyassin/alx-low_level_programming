#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * malloc_checked checks  malloc
 * @b : integar to check?
 *
 * Return: a pointer or void
 */
void *malloc_checked(unsigned int b)
{
	void *t = malloc(b);

	if (t == NULL)
		exit(98);

	return (t);
}
