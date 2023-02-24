#include "main.h"
/**
 * _isdigit - Entry point
 * @c: Variable to be checked
 *Return: return 1 for successuful
 */
int _isdigit(int c)
{
char i = '0';
int x = 0;
for (; i <= '9'; i++)
{
if (i == c)
{
x = 1;
break;
}
}
return (x);
}

