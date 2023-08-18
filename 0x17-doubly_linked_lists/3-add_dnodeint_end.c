#include "lists.h"

/**
 * add_dnodeint_end - Add a new node at the end of a dlistint_t list
 * @len_head: The head of the list
 * @n: The value of the new node
 *
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **len_head, const int n)
{
	dlistint_t *last = *len_head;
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*len_head == NULL)
	{
		new->prev = NULL;
		*len_head = new;
		return (new);
	}

	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;

	return (new);
}
