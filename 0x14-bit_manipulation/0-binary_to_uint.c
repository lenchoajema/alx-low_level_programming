#include "main.h"
/**
 * binary_to_uint: - function to convert the binary to decimal and return
 * @len1: pointer variable to store the binary and return
 * Return: alays 0 on success
 */
int binary_to_uint(const char *len1)
{
	unsigned int n = 0;

	if (!len1)
		return (0);
	while (*len1)
	{
		n <<= 1;
		if (*len1 == '1')
			n += 1;
		else if (*len1 != '0')
			return (0);
		++len1;
	}
	return (n);
}
