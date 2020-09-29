#include "libft.h"

void *ft_memset(void *s, int c, size_t n) {
  size_t i;
  unsigned char *temp;

  i = 0;
  temp = s;
  while (i++ < n) {
    *temp = (unsigned char)c;
    temp++;
  }
  return (s);
}