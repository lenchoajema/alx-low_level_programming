#include <stdio.h>

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the number whose bit will be cleared.
 * @index: The index of the bit to be cleared.
 *
 * Return: 1 if the operation is successful, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
unsigned int max_index = sizeof(unsigned long int) * 8 - 1;
if (index > max_index)
return (-1);
*n &= ~(1ul << index);
return (1);
}
