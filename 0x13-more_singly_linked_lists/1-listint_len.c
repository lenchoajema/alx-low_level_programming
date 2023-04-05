#include "lists.h"
/**
 * listint_len - count the element in a linked list
 * @l: a pointer to the first node
 * Return: the number or list elements
 */
size_t listint_len(const listint_t *l)
{
return (l ? listint_len(l->next) + 1 : 0);
}
