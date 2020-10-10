#include "libft.h"

int ft_isspace(char c)
{
  if (c == ' ' || c == '\n' || c == '\t'
               || c == '\r' || c == '\v' || c == '\f')
      return (1);
  return (0);
}

int ft_isnum(char c)
{
  if ('0' <= c && c <= '9')
    return (1);
  return (0);
}

int ft_atoi(const char *nptr)
{
  int sign;
  unsigned long long res;
  int i;

  i = 0;
  while (nptr[i] != '\0' && ft_isspace(nptr[i]))
    i++;
  sign = 1;
  if (nptr[i] == '-' || nptr[i] == '+')
    sign = (nptr[i++] == '-' ? -1 : 1);
  res = 0;
  while (nptr[i] && ft_isnum(nptr[i]))
  {
    res = (res * 10) + (nptr[i] - 48);
	if (res >= 9223372036854775807 && sign == 1)
		return (-1);
	else if (res > 9223372036854775807 && sign == -1)
		return (0);
    i++;
  }  
  return (res * sign);
}
