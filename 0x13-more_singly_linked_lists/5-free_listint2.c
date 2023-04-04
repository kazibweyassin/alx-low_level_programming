#include "lists.h"
/**
 * free_listint2 - this function will frees the list
 * @head: this points to the struct
 *
 * Return: this will return number of elements
 */
void free_listint2(listint_t **head)
{
	listint_t *feee;

	if (head == NULL)
	{
		return;
	}

	while (*head != NULL)
	{
		fr = *head;
		*head = feee->next;
		free(feee);
	}
}

