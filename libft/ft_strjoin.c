#include "libft.h"

char  *ft_strjoin(char const *s1, char const *s2)
{
  char    *new_str;
  size_t  i;
  
  if (s1 && s2)
  {
    if (!(new_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
      return (NULL);
    i = 0;
    while (*s1)
      new_str[i++] = *s1++;
    while (*s2)
      new_str[i++] = *s2++;
    new_str[i] = '\0';
    return (new_str);
  }
  return (NULL);  
}