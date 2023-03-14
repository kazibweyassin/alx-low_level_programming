#include "main.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * str_concat - concatenate two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: a pointer to a newly allocated space in memory which
 * contains the concatenated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
    int len1, len2, i, j;
    char *concat;

    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";

    len1 = _strlen(s1);
    len2 = _strlen(s2);

    concat = malloc(sizeof(char) * (len1 + len2 + 1));
    if (concat == NULL)
        return (NULL);

    for (i = 0; i < len1; i++)
        concat[i] = s1[i];

    for (j = 0; j < len2; j++)
        concat[i + j] = s2[j];

    concat[i + j] = '\0';

    free(s1);

    return (concat);
}

