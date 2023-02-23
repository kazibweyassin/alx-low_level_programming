#include "main.h"
/**
 * _isdigit - checks for a digit are 0 - 9
 * @c: the parameter to print
 *
 * Return: 1 or 0
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= 9)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
