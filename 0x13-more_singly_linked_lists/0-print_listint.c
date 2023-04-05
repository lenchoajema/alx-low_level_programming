#include "lists.h"
/**
* print_listint - prints the elements in a linked list
*@l: a pointer to the first node
*Return: the always 0 successful
*/
size_t print_listint(const listint_t *l)
{
	if (l)
	{
		printf("%d\n", l->n);
		return (print_listint(l->next) + 1);
	}
	return (0);
}
