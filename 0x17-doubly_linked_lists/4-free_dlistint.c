#include "lists.h"

/**
 * free_dlistint - Free a dlistint_t list
 * @len_head: The head of the list
 */
void free_dlistint(dlistint_t *len_head)
{
	dlistint_t *temp;

	while (len_head)
	{
		temp = len_head;
		len_head = len_head->next;
		free(temp);
	}
}
