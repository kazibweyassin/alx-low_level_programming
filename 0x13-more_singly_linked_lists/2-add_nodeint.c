#include "lists.h"
/**
 * add_nodeint - this function adds a new node at the beginning of a list
 * @head: the pointer that points to the struct
 * @n: integer in the struct
 *
 * Return: the adress of the new element
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newNode;

	newNode = malloc(sizeof(listint_t));

	if (newNode == NULL)
	{
		return (NULL);
	}

	newNode->n = n;
	newNode->next = *head;
	*head = newNode;
	return (*head);
}
