#include "lists.h"
/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: the pointer to the struct
 * @n: integer in the struct
 * @idx: index of the list where the new node should be added
 *
 * Return: the address of the new node or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newestnode, *move = *head;
	unsigned int index;

	newestnode = malloc(sizeof(listint_t));

	if (newestnode == NULL)
	{
		return (NULL);
	}

	newestnode->n = n;

	if (idx == 0)
	{
		newestnode->next = *head;
		*head = newestnode;
	}
	else
	{
		for (index = 0 ; index < idx - 1 ; index++)
		{
			move = move->next;
			if (move == NULL)
			{
				free(newestnode);
				return (NULL);
			}
		}
		newestnode->next = move->next;
		move->next = newestnode;
	}
	return (newestnode);
}
