#include "lists.h"

/**
 * dlistint_len - Return the number of elements in a linked dlistint_t list
 * @len_h: The list
 *
 * Return: The number of nodes
 */
size_t dlistint_len(const dlistint_t *len_h)
{
	size_t len_count = 0;

	while (len_h)
	{
		len_count++;
		len_h = len_h->next;
	}

	return (len_count);
}
