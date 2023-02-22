#include <stdio.h>
/**
 * main - Entry point
 * Return: return 1 on success
 */
int main(void)
{
int sum = 0;
for (int i = 0; i < 1024; i++)
{
  if ((i % 3) == 0 || (i % 5) == 0)
sum += i;
}
printf(" the sum of all the multiples of 3 or 5 below 1024: %d\n", sum);
return (0);
}
