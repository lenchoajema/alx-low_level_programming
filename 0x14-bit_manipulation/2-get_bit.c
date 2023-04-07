#include "main.h"
/**
 * get_bit - function to return the index of bit
 * @index: indicate bit location
 * @n:variable for the bits
 * Return: -1 for unsucess and index for sucess
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);
	return (1 & (n >> index));
}
