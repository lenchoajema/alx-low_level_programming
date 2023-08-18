#include "lists.h"

/**
 * print_dlistint - Print all the elements of a dlistint_t list
 * @len_h: The list
 *
 * Return: The number of nodes
 */
size_t print_dlistint(const dlistint_t *len_h)
{
	size_t len_count = 0;

	while (len_h)
	{
		printf("%d\n", len_h->n);
		len_count++;
		len_h = len_h->next;
	}

	return (len_count);
}

