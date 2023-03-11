#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	int sum = 0, i = 1;

	if (argc == 1)
		printf("%d\n", argc - 1);
	else
	{
		for (; i <= argc; i++)
		{
			if (!isdigit(argv[i]))
			{
				printf("Error\n");
			return (1);
			}
			else

				sum += atoi(argv[i]);

		}
	printf("%d\n", sum);
	}
	return (0);
}
