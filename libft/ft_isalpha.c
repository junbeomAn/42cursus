#include "libft.h"

int ft_isalpha(int c)
{
  unsigned char s;

  s = (unsigned char)c;
  if (('a' <= s && s <= 'z') || ('A' <= s && s <= 'Z'))
    return (1);
  return (0);
}