#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main -entry point 
 *
 * Return:always return 0
 *
 */
int main(void)
		{
		int n;

		srand(time(0));
		n = rand()- RAND_MAX/2;
		if (n<0)
		{
		print ("%d is negative\n" n);
		} else if (n == 0 )
		{
		printf("%dis zero\n", n)
		} else
		{
		print("%d s positive\n" , n);
		}
		return (0);
		}



