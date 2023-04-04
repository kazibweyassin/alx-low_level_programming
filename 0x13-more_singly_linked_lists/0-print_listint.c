#include "lists.h"
/**
 * print_listint - list function prints all the elements of a lis
 *@h: is the pointer that points to struct
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
	int element = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		element++;
	}
	return (element);
}
