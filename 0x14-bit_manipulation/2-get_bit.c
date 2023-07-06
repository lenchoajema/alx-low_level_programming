#include <stdio.h>

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number to retrieve the bit from.
 * @index: The index of the bit to be retrieved.
 *
 * Return: The value of the bit at the given index or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int max_index = sizeof(unsigned long int) * 8 - 1;

	if (index > max_index)
		return -1;

	return (n >> index) & 1;
}
