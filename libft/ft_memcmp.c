#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
  size_t        i;
  unsigned char *s1_temp;
  unsigned char *s2_temp;

  i = 0;
  s1_temp = (unsigned char *)s1;
  s2_temp = (unsigned char *)s2;
  if (*s2_temp == 0)
    return (*s1_temp == 0 ? 0 : 1);
  while (i < n)
  {
    if (s1_temp[i] != s2_temp[i])
      return (s1_temp[i] - s2_temp[i] > 0 ? 1 : -1);
    i++;
  }
  return (0);
}