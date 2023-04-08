#include "main.h"
/**
 * clear_bit - to clear the value
 * @n: to store the the bit data
 * @index: it shows the position ot place
 * Return: 1 on successful else -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{       
        if (!n || index >= sizeof(*n) * 8)
                return (-1);
        *n &= ~(1 << index);
        return (1);
}       
