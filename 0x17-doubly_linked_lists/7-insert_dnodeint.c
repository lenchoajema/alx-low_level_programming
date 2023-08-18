#include "lists.h"

/**
 * insert_dnodeint_at_index - Insert a new node at a given position
 * @len_h: The head of the list
 * @len_idx: The index, starting at 0
 * @len_n: The value of the new node
 *
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **len_h, unsigned int len_idx, int len_n)
{
	dlistint_t *len_curr = *len_h;
	dlistint_t *len_new;
	unsigned int len_i;

	if (!len_h)
		return (NULL);
	if (*len_h == NULL && len_idx != 0)
		return (NULL);
	len_new = malloc(sizeof(dlistint_t));
	if (len_new == NULL)
		return (NULL);
	len_new->n = len_n;
	if (len_idx == 0)
	{
		if (*len_h)
			len_curr->prev = len_new;
		*len_h = len_new;
		len_new->prev = NULL;
		len_new->next = len_curr;
		return (len_new);
	}
	for (len_i = 1; len_i < len_idx; len_i++)
	{
		len_curr = len_curr->next;
		if (len_curr == NULL)
		{
			free(len_new);
			return (NULL);
		}
	}
	len_new->prev = len_curr;
	len_new->next = len_curr->next;
	if (len_curr->next)
		len_curr->next->prev = len_new;
	len_curr->next = len_new;
	return (len_new);
}
