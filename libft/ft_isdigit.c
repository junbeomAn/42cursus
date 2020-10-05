#include "libft.h"

int ft_isdigit(int c)
{
  unsigned char s;

  s = (unsigned char)c;
  if ('0' <= s && s <= '9')
    return (1);
  return (0);
}