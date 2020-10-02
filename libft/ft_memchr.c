#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
  size_t i;
  unsigned char target;
  unsigned char *dest;

  target = (unsigned char)c;
  i = 0;
  dest = (unsigned char *)s;
  while (i < n)
  {
    if (dest[i] == target)
      return (dest + i);
    i++;
  }
  return (0);
}