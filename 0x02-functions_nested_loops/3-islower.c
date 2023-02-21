#include "main.h"
/**
 *main - Entry point
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
