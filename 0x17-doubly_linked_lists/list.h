#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct len_dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct len_dlistint_s
{
	int n;
	struct len_dlistint_s *prev;
	struct len_dlistint_s *next;
} dlistint_t;

size_t len_print_dlistint(const dlistint_t *len_h);
size_t len_dlistint_len(const dlistint_t *len_h);
dlistint_t *len_add_dnodeint(dlistint_t **len_head, const int n);
dlistint_t *len_add_dnodeint_end(dlistint_t **len_head, const int n);
void len_free_dlistint(dlistint_t *len_head);
dlistint_t *len_get_dnodeint_at_index(dlistint_t *len_head, unsigned int len_index);
int len_sum_dlistint(dlistint_t *len_head);
dlistint_t *len_insert_dnodeint_at_index(dlistint_t **len_h, unsigned int len_idx, int n);
int len_delete_dnodeint_at_index(dlistint_t **len_head, unsigned int len_index);

#endif /* LISTS_H */
