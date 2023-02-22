#include "main.h"
/**
 *_islower- Entry point
 *@c- called parameter from
 *Return: return 0 on success
 */
int _islower(int c)
{
int lower = 0;
if (c >= 'a' && c <= 'z')
lower = 1;
else
lower = 0;
return (lower);
}
