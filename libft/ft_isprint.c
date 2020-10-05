#include "libft.h"

int ft_isprint(int c)
{
  return ((c < 32 || 127 < c) ? 0 : 1);
}