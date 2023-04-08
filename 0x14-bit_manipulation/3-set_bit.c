#include "main.h"
/**
 * set_bin - function to set index to 1
 * @n: pointer to hold data
 * @index: a variable to show the position
 * Return: -l if any error or 1 on success
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (!n || index >= sizeof(*n) * 8)
		return (-1);
	*n |= 1 << index;
	return (1);
}
