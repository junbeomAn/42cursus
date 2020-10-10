#include "libft.h"

char  *ft_strdup(const char *s)
{
  char    *dup;
  size_t  len;

  len = ft_strlen(s);
  if (!(dup = malloc(sizeof(char) * (len + 1))))
    return (NULL);
  dup = ft_memcpy(dup, (const void *)s, len);
  dup[len] = '\0';
  return (dup);
}
