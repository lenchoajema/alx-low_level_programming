#include <stdio.h>
/**
 * main - Entry point
 * @argc: variable for the number of arguments
 * @argv: array variable contain arguments
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	if (argv[0] != 0)
	printf("%d\n", argc - 1);
	return (0);
}
