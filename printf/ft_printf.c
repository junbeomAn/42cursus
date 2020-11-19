#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	val;

	i = 0;
	val = 0;
	temp = s;
	while (i++ < n)
	{
		*temp = val;
		temp++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;

	i = 0;
	s1_temp = (unsigned char *)s1;
	s2_temp = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_temp[i] != s2_temp[i])
			return (s1_temp[i] - s2_temp[i]);
		i++;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	char	target;
	char	*from;

	target = (char)c;
	from = (char *)s;
	if (target == '\0')
		return (from + ft_strlen(s));
	while (*from != '\0' && (*from != target))
		from++;
	return (*from ? from : NULL);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	if (!dest && !src)
		return (0);
	i = 0;
	temp = dest;
	while (i < n)
	{
		*temp = *((const unsigned char *)src);
		temp++;
		src++;
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s);
	if (!(dup = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dup = ft_memcpy(dup, (const void *)s, len);
	dup[len] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup("\0"));
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memcpy((void *)ret, (const void*)(s + start), len);
	ret[len] = '\0';
	return (ret);
}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////


int	handle_fmt_string(const char *fmt, t_fmtstr *t, va_list vl)
{
	int ret;
	int	i;

	ret = 0;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] && ft_strchr(ALLCHARS, fmt[i + 1]))
		{
			i += 1;
			i = handle_flags(fmt, i, t);
			i = handle_width(fmt, i, t, vl);
			i = handle_precision(fmt, i, t, vl);
			ret += controller(fmt[i], t, vl);
		}
		else
			ret += ft_putchar(fmt[i]);
		i++;
	}
	return (ret);
}

int ft_printf(const char *fmt, ...)
{
	va_list vl;
	t_fmtstr *t;
	int fmtlen;
	int ret;

	va_start(vl, fmt);
	fmtlen = ft_strlen(fmt);
	if (!(t = (t_fmtstr *)malloc(sizeof(t_fmtstr))))
		return (-1);
	ft_bzero(t, sizeof(t_fmtstr));
	t->precision = -1;
	if (is_empty_str(fmt))
		return (-1);
	if (fmtlen == 1 && fmt[0] == '%') // fmt == "%"
		return (-1);
	ret = handle_fmt_string(fmt, t, vl);
	va_end(vl);
	return (ret);
}
