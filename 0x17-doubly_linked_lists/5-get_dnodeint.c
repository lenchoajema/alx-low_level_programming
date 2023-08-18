#include "lists.h"

/**
 * len_get_dnodeint_at_index - Return the nth node of a dlistint_t linked list
 * @len_head: The head of the list
 * @len_index: The index of the node, starting from 0
 *
 * Return: The nth node, or NULL if it doesn't exist
 */
dlistint_t *len_get_dnodeint_at_index(dlistint_t *len_head, unsigned int len_index)
{
	unsigned int len_i;

	if (len_head == NULL)
		return (NULL);

	for (len_i = 0; len_i < len_index; len_i++)
	{
		len_head = len_head->next;
		if (len_head == NULL)
			return (NULL);
	}

	return (len_head);
}
