#include <stdio.h>

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to the number whose bit will be set.
 * @index: The index of the bit to be set.
 *
 * Return: 1 if the operation is successful, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
unsigned int max_index = sizeof(unsigned long int) * 8 - 1;
if (index > max_index)
return (-1);
*n |= (1ul << index);
return (1);
}
