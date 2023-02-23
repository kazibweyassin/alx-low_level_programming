#include "main.h"
/**
 * print_diagonal -draws a diagonal line on the terminal
 * @n: the number of times that the special character must be print
 *
 * Return: a diagonal
 */
void print_diagonal(int n)
{
	if (n <= 0)
	{
		_puthchar('\n')
	} else
	{
		int i, j;
		for (i = 0 ; i < n ; a++)
		{
			for (j = 0 ; j < n; j++)
			{
				if (j == i)
					_putchar('\\');
				esle if (j < i)
					_putchar('\\');
			}
			_putchar('\n');
		}	
}	}

