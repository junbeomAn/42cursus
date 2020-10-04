#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
  size_t i;

  i = 0;
  while (i < size - 1)
  {
    if (src[i])
      dst[i] = src[i];
    i++;
  }
  if (size > 0)
    dst[i] = '\0';
  while (src[i])
    i++;
  return (i);
}