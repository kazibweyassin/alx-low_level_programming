#include "lists.h"
/**
 * delete_nodeint_at_index - this functions will delete the node at index of a linked list
 * @head: this point to the struct
 * @index: this is the index of the node that should be deleted
 *
 * Return: this will return 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp, *pre_tmp = *head;
	unsigned int i;

	if (_ == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		*head = (*head)->next;
		free(_);
		return (1);
	}

	for (i = 0 ; i < (index - 1) ; i++)
	{
		if (_->next == NULL)
		{
			return (-1);
		}
		_ = _->next;
	}
	tmp = _->next;
	_->next = tmp->next;
	free(tmp);
	
