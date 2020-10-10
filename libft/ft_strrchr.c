#include "libft.h"

char  *ft_strrchr(const char *s, int c)
{
  int   rear;
  char  *from;
  char  target;

  rear = (int)(ft_strlen(s) - 1);
  from = (char *)s;
  target = (char)c;
  if (target == '\0')
    return (from + rear + 1);
  while (rear >= 0)
  {
    if (*(from + rear) == target)
      return (from + rear);
    rear--;
  }
  return (NULL);
}