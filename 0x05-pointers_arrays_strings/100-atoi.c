#include "main.h"
/**
 *int _atoi(char *s); convert a string to an integer.
 *
 * Return a srong to an integer
 */

int _atoi(char *s)
{
    int sign = 1;
    int result = 0;
    int i = 0;

    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
           s[i] == '\r' || s[i] == '\f' || s[i] == '\v')
    {
        i++;
    }


    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
    {
        sign = 1;
        i++;
    }

	 while (s[i] >= '0' && s[i] <= '9')
    {
        for overflow
        if (result > INT_MAX / 10 ||
            (result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
        {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        result = result * 10 + (s[i] - '0');
        i++;
    }

    return sign * result;
}
