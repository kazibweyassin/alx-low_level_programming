#include "function_pointers.h"
#include  <stdlib.h>

/**
 *print_name - print a name
 * void print_name: prints name
 * @name:the string to print
 * @f:pointer to function
 * * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (f)
	{
		(*f)(name);
	}

}

