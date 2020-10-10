#include "libft.h"

void  *ft_memcpy(void *dest, const void *src, size_t n)
{
  size_t        i;
  unsigned char *temp;

  i = 0;
  temp = dest;
  while (i < n)
  {
    *temp = *((const unsigned char *)src);
    temp++;
    src++;
    i++;
  }
  return (dest);
}
