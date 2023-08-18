#include "lists.h"

/**
 * len_sum_dlistint - Return the sum of all the data (n) in a dlistint_t list
 * @len_head: The head of the list
 *
 * Return: The sum of the data (n)
 */
int len_sum_dlistint(dlistint_t *len_head)
{
	int len_sum = 0;

	while (len_head)
	{
		len_sum += len_head->n;
		len_head = len_head->next;
	}

	return (len_sum);
}
