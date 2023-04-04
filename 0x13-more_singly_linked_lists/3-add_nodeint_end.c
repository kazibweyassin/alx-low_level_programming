#include "lists.h"
/**
 * add_nodeint_end - this function adds a new node at the end of a list
 * @head: the pointer that points to the struct
 * @n: integer in the struct
 *
 * Return: the adress of the new element
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newnode;
	listint_t *lastnode;

	if (&*head == NULL)
	{
		return (NULL);
	}
	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->n = n;
	newnode->next = NULL;
	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		lastnode = *head;

		while (lastnode->next != NULL)
		{
			lastnode = lastnode->next;
		}
		lastnode->next = newnode;
	}
	return (*head);
}
