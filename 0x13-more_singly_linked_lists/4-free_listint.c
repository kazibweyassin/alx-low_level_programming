#include "lists.h"
/**
 * free_listint - thi functon will free a list
 * @head: will point to the struct
 *
 * Return: The number of elements
 */
void free_listint(listint_t *head)
{
	listint_t *fee;

	while (head != NULL)
	{
		fee = head;
		head = fee->next;
		free(fee);
	}
}
