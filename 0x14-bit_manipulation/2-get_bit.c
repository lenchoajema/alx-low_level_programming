#include "main.h"
/**
 * get_bit - function to return the index of bit
 * Return: -1 for unsucess and index for sucess
 */
int get_bit(unsigned long int n, unsigned intindex)
{
        if (index >= sizeof(n) * 8)
                return (-1);
        return (1 & (n >> index));
} 
