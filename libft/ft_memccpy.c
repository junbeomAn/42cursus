#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
  size_t i;
  unsigned char *dest_tmp;
  unsigned char *src_tmp;

  i = 0;
  dest_tmp = (unsigned char *)dest;
  src_tmp = (unsigned char *)src;
  while (i < n)
  {
    dest_tmp[i] = src_tmp[i];
    if ((unsigned char)c == dest_tmp[i])
      return (dest_tmp + (i + 1));
    i++;
  }
  return (0);
}