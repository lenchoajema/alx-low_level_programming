#include "lists.h"

/**
 * add_dnodeint - Add a new node at the beginning of a dlistint_t list
 * @len_head: The head of the list
 * @n: The value of the new node
 *
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **len_head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = *len_head;
	new->prev = NULL;
	if (*len_head)
		(*len_head)->prev = new;
	*len_head = new;

	return (new);
}
