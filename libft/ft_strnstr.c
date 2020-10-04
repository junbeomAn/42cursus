#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t n)
{
  size_t i;
  char *large;
  char *small;
  size_t j;
  
  i = 0;
  large = (char *)haystack;
  small = (char *)needle;
  if (small[0] == '\0')
    return (large); 
  while (large[i] && i < n)
  {
    j = 0;
    if (large[i] == small[j])
    {
      if (ft_memcmp(haystack + i, needle, ft_strlen(needle)) == 0)
        return (large + i);
    }
    i++;
  }
  return (NULL);
}