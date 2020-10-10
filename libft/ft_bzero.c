#include "libft.h"

void  ft_bzero(void *s, size_t n)
{
  size_t        i;
  unsigned char *temp;
  unsigned char val;

  i = 0;
  val = 0;
  temp = s;
  while (i++ < n)
  {
    *temp = val;
    temp++;
  }
}