#include "libft.h"

char *ft_strchr(const char *s, int c)
{
  char target;
  char *from;

  target = (char)c;
  from = (char *)s;
  if (target == '\0')
    return (from + ft_strlen(s));
  while (*from != '\0' && (*from != target))
    from++;
  return (*from ? from : NULL);
}