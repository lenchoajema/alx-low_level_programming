#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0 (success)
 */
int main(int argc, char *argv[])
{
int num1, num2, mul = 0;
if (argc != 3)
{
if (argc == 1)
	printf("%d\n", argc - 1);
else
	printf("Error\n");
return (1);
}
else
{
num1 = atoi(argv[1]);
num2 = atoi(argv[2]);
mul = num1 *num2;
printf("%d\n", mul);
}
return (0);
}
