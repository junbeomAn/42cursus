#include "ft_printf.h"

int is_empty_str(const char *str)
{
	if (!str[0])
	{
		write(1, "", 1);
		return (1);
	}
	return (0);
}

int		get_address_len(intptr_t n, int base)
{
	int i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char *lower_case(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char *upper_case(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
