#include "lists.h"
/**
 * dlistint_len - returns the number of elements in a list
 * @h: ThE Pointer to the struct
 *
 * Return: the number of elements in alist
 */
size_t dlistint_len(const dlistint_t *h)
{	int elementaln = 0;

	while (h != NULL)
	{
		h = h->next;
		elementaln++;
	}
	return (elementaln);
}
