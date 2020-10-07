#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
  char *ret;

  if (ft_strlen(s) < start)
    return ('\0');
  if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
    return (NULL);
  ft_memcpy((void *)ret, (const void*)(s + start), len);
  ret[len] = '\0';
  return (ret);
}