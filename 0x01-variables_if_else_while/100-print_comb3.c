#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int d, e;

	for (d = 0, e=1; d < e; d++, e++)
	{
		putchar((d / 10) + '1');
		putchar((e % 10) + '1');
		if (d != 89)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');

	return (0);
}
