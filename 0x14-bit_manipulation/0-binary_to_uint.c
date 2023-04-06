#include "main.h"
/**
 * binary_to_uint - function to convert the binary to decimal and return
 * @b: pointer variable to store the binary and return
 * Return: alays 0 on success
 */
int binary_to_uint(const char *b)
{
	unsigned int n = 0;

	if (!b)
		return (0);
	while (*b)
	{
		n <<= 1;
		if (*b == '1')
			n += 1;
		else if (*b != '0')
			return (0);
		++b;
	}
	return (n);
}
