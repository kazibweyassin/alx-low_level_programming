#include <stdio.h>
#include <stdlib.h>

/**
 * print_dlistint - Prints the elements in the doubly linked list
 * @h : The pointer te doubly linked list.
 *
 * Return: The number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;
	const dlistint_t *current = h;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		count++;
	}
return (count);
}
