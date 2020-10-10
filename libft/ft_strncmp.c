#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
  size_t        i;
  unsigned char *str1;
  unsigned char *str2;

  str1 = (unsigned char *)s1;
  str2 = (unsigned char *)s2;
  i = 0;
  while (i < n && str1[i] && str2[i])
  {
    if (str1[i] != str2[i])
      break;
    i++;
  }
  if (i == n)
    return (0);
  return (str1[i] - str2[i] > 0 ? 1 : -1);
}