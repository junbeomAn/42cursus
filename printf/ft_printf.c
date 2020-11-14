#include "ft_printf.h"

#include <stdio.h>


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
////////////////////////////////////////////////////////////////////////
long	_abs(long n)
{
	return (n > 0 ? n : -n);
}

int		get_num_len(long n, int base)
{
	return (1 + (_abs(n / base) > 0 ? get_num_len(n / base, base) : 0));
}

char	*ft_itoa_base(long n, int base)
{
	char	*char_num;
	int		len;
	int		i;
	int		digit;

	len = get_num_len(n, base);
	if (n < 0)
		len++;
	if (!(char_num = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		digit = _abs(n % base);
		char_num[len - 1 - i] = (digit > 9 ? 'a' + digit - 10 : '0' + digit);
		n /= base;
		i++;
	}
	char_num[i] = '\0';
	if (char_num[0] == '0' && len > 1)
		char_num[0] = '-';
	return (char_num);
}
////////////////////////////////////////////////////////////////////////////////
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	int cnt;

	if (!s || fd < 0)
		return ;
	cnt = (int)ft_strlen(s);
	write(fd, s, cnt);
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

void ft_put_blank(int width, int zero_pad)
{
	char *blank;
	int i;

	if (width < 1)
		return ;
	if (!(blank = (char *)malloc(sizeof(char) * width)))
		return ;
	i = 0;
	while (i < width)
	{
		if (zero_pad == 1)
			blank[i] = '0';
		else
			blank[i] = ' ';
		i++;
	}
	write(1, blank, width);
	free(blank);
	blank = NULL;
}

int has_precision_dot(t_fmtstr *t)
{
	return (t->precision == -1 ? 0 : 1);
}

int is_left_aligned(t_fmtstr *t)
{
	return (t->minus == 1 ? 1 : 0);
}

int ft_min(int a, int b)
{
	return (a >= b ? b : a);
}

int ft_max(int a, int b)
{
	return (a <= b ? b : a);
}

int ft_abs(int a)
{
	return (a < 0 ? -a : a);
}

//////////////////////////////////////////////////////

void	zero_init(char *arr)
{
	int i;

	i = 0;
	while (i < 127)
	{
		arr[i] = 0;
		i++;
	}
}

unsigned int		is_valid_base(char *base)
{
	char	ascii[127];
	unsigned int		i;

	i = 0;
	zero_init(ascii);
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ascii[(int)base[i]])
		{
			return (0);
		}
		ascii[(int)base[i]] = 1;
		i++;
	}
	return (i);
}

void	base_convert(unsigned long nbr, char *base, unsigned int len)
{
	unsigned long div;
	unsigned long mod;

	if (!nbr)
		return ;
	div = nbr / len;
	mod = nbr % len;
	base_convert(div, base, len);
	if (mod < 0)
		mod = -mod;
	write(1, &base[mod], 1);
}

void	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned int len;

	len = is_valid_base(base);
	if (!len)
		return ;
	if (nbr == 0)
		write(1, "0", 1);
	if (nbr < 0)
		write(1, "-", 1);
	base_convert(nbr, base, len);
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


int ft_printf(const char *fmt, ...)
{
	va_list vl;
	t_fmtstr *t;
	int i;
	int fmtlen;
	int blank_len;

	va_start(vl, fmt);
	fmtlen = ft_strlen(fmt);
	if (!(t = (t_fmtstr *)malloc(sizeof(t_fmtstr))))
		return (-1);
	ft_bzero(t, sizeof(t_fmtstr)); // init t_fmtstr
	t->precision = -1;
	if (is_empty_str(fmt))
		return (-1);
	if (fmtlen == 1 && fmt[0] == '%') // fmt == "%"
		return (-1);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] && ft_strchr(ALLCHARS, fmt[i + 1]))
		{
			i += 1;
			// while (fmt[i])
			// {
				// handle flag
				while (fmt[i] == '0' || fmt[i] == '-')
				{
					if (fmt[i] == '0')
					{
						if (t->minus != 1)
							t->zero_pad = 1;
					}
					else
					{
						t->minus = 1;
						if (t->zero_pad == 1)
							t->zero_pad = 0;
					}
					i++;
				}

				// handle width
				while (('0' <= fmt[i] && fmt[i] <= '9') || fmt[i] == '*') // mininum numbers to be printed
				{
					if (fmt[i] == '*')
					{
						t->width = va_arg(vl, int); // long으로 받아야하나?
						if (t->width < 0)
						{
							t->minus = 1;
							t->width = ft_abs(t->width);
						}
					}
					else
						t->width = (t->width * 10) + (fmt[i] - '0');
					if (t->width < 0)
						t->minus = 1;
					i++;
				}

				// handle precision
				while (fmt[i] == '.') //think about string specifier
				{
					t->precision = 0;
					if (t->zero_pad == 1)
					{
						t->zero_pad = 0;
						t->zero_pad_ignrd = 1;
					}
					i++;
				}
				// 0일때도 처리!!!
				while (0 <= t->precision && (('0' <= fmt[i] && fmt[i] <= '9') || fmt[i] == '*')) // mininum numbers to be printed
				{
					if (fmt[i] == '*')
						t->precision = va_arg(vl, int);// long으로 받아야하나?
					else
						t->precision = (t->precision * 10) + (fmt[i] - '0');
					if (t->precision < 0)
						t->precision = 0;
					i++;
				}

				// handle specifier
				if (fmt[i] == 'c' || fmt[i] == 'C') // precision ignored
				{
					int c = va_arg(vl, int);
					if (is_left_aligned(t)) // t->minus == 1
					{
						// c ? ft_putchar_fd(c, 1) : ft_putchar_fd(0, 1);
						ft_putchar_fd(c, 1);
						ft_put_blank(t->width - 1, t->zero_pad);
					}
					else
					{
						ft_put_blank(t->width - 1, t->zero_pad);
						ft_putchar_fd(c, 1);
						// c ? ft_putchar_fd(c, 1) : ft_putchar_fd(0, 1);
					}
				}
				else if (fmt[i] == 'd' || fmt[i] == 'D' || fmt[i] == 'i')
				{
					long ld = (long)va_arg(vl, int);
					int minus_num;
					char *char_num;

					minus_num = 0;
					if (ld < 0)
					{
						minus_num = 1;
						ld = -ld;
					}
					char_num = ft_itoa_base(ld, 10);
					int num_len = ft_strlen(char_num);
					int precision_zero_pad;

					if (ft_memcmp(char_num, "0", 1) == 0 && t->precision == 0)
						ft_put_blank(t->width, 0);
					else
					{
						precision_zero_pad = t->precision - num_len;
						if (!has_precision_dot(t)) // 없어도 되지만 가독성을 위한..
							blank_len = t->width - num_len;
						else
							blank_len = t->width - ft_max(t->precision, num_len);
						if (minus_num == 1)
							blank_len -= 1;
						if (is_left_aligned(t))
						{
							if (minus_num == 1)
								ft_putchar_fd('-', 1);
							if (has_precision_dot(t))
								ft_put_blank(precision_zero_pad, 1);
							ft_putstr_fd(char_num, 1);
							ft_put_blank(blank_len, t->zero_pad);
						}
						else
						{
							if (minus_num == 1)
							{
								if (t->zero_pad == 1)
								{
									ft_putchar_fd('-', 1);
									ft_put_blank(blank_len, t->zero_pad);
								}
								else
								{
									ft_put_blank(blank_len, t->zero_pad);
									ft_putchar_fd('-', 1);
								}
							}
							else
								ft_put_blank(blank_len, t->zero_pad);
							if (has_precision_dot(t))
								ft_put_blank(precision_zero_pad, 1);
							ft_putstr_fd(char_num, 1);
						}
					}
					free(char_num);
				}
				else if (fmt[i] == 'u' || fmt[i] == 'U')
				{
					unsigned int ud = va_arg(vl, unsigned int);
					char *char_num = ft_itoa_base(ud, 10);
					// d, i와 동일.
					ft_putstr_fd(char_num, 1);
					free(char_num);
				}
				else if (fmt[i] == 's') // zero_pad is not defined with 's'
				{
					char *s;
					int str_len;
					char *print_str;
					int print_len;

					// s가 null 일때
					s = va_arg(vl, char *);
					str_len = ft_strlen(s);
					if (s == NULL)
					{
						str_len = ft_strlen("(null)");
						s = "(null)";
					}
					print_len = ft_min(t->precision, str_len);
					print_str = ft_substr(s, 0, print_len);
					if (print_len < t->width)
					{
						if (is_left_aligned(t))
						{
							ft_putstr_fd(print_str, 1);
							ft_put_blank(t->width - print_len, 0);
						}
						else
						{
							ft_put_blank(t->width - print_len, 0);
							ft_putstr_fd(print_str, 1);
						}
					}
					else // no space for blank so no align is applied.
						ft_putstr_fd(print_str, 1);
					free(print_str);
				}
				else if (fmt[i] == 'p')
				{
					intptr_t p = (intptr_t)va_arg(vl, void *);
					int print_len;

					print_len = get_address_len(p, 16) + 2;
					if (t->width > print_len)
					{
						if (is_left_aligned(t))
						{
							ft_putstr_fd("0x", 1);
							ft_putnbr_base(p, HEXBASE);
							ft_put_blank(t->width - print_len, 0);
						}
						else
						{
							ft_put_blank(t->width - print_len, 0);
							ft_putstr_fd("0x", 1);
							ft_putnbr_base(p, HEXBASE);
						}
					}
					else
					{
						// blank unavailable
						ft_putstr_fd("0x", 1);
						ft_putnbr_base(p, HEXBASE);
					}
				}
				else if (fmt[i] == 'x' || fmt[i] == 'X')
				{
					int ud = (unsigned int)va_arg(vl, unsigned int);
					char *char_hex = ft_itoa_base(ud, 16);
					int num_len;
					int precision_zero_pad;
					int blank_len;

					num_len = ft_strlen(char_hex);
					precision_zero_pad = t->precision - num_len;
					if (!has_precision_dot(t)) // 없어도 되지만 가독성을 위한..
						blank_len = t->width - num_len;
					else
						blank_len = t->width - ft_max(t->precision, num_len);
					if (is_left_aligned(t))
					{
						ft_put_blank(precision_zero_pad, 1);
						if (fmt[i] == 'x')
							ft_putstr_fd(lower_case(char_hex), 1);
						else
							ft_putstr_fd(char_hex, 1);
						if (has_precision_dot(t))
							ft_put_blank(blank_len, t->zero_pad);
					}
					else
					{
						if (has_precision_dot(t))
							ft_put_blank(blank_len, 0);
						ft_put_blank(precision_zero_pad, 1);
						if (fmt[i] == 'x')
							ft_putstr_fd(lower_case(char_hex), 1);
						else
							ft_putstr_fd(char_hex, t->zero_pad);
					}
					free(char_hex);
				}
				else if (fmt[i] == '%')
				{// left align....
					if (is_left_aligned(t))
					{
						ft_putchar_fd('%', 1);
						ft_put_blank(t->width - 1, (t->zero_pad || t->zero_pad_ignrd));
					}
					else
					{
						ft_put_blank(t->width - 1, (t->zero_pad || t->zero_pad_ignrd));
						ft_putchar_fd('%', 1);
					}

				}
				// i++;
			// }
		}
		else
		{
			// just write character
			ft_putchar_fd(fmt[i], 1);
		}
		i++;
	}
	va_end(vl);
	return (0);
}

int main(void)
{
	char c;
	c = 'f';
	// error cases
	// ft_printf("%0*d\n",20, -1234506789); // 000000000000-15
	// printf("%0*d\n",20, -1234506789); // -000000000000015
	// ft_printf("%*.11d\n",20, -1234506789); // 000000000000-15
	// printf("%*.11d\n",20, -1234506789); // -000000000000015
	ft_printf("%-*d\n",9, -12345678); // 000000000000-15
	printf("%-*d\n",9,  -12345678); // -000000000000015

	// ft_printf("%*.*d\n",15, 6, -15);
	// printf("%*.*d\n",15, 6, -15);

	// ft_printf("%*.d\n",20, 0);
	// printf("%*.d\n",20, 0);

	ft_printf("%-9.5d\n",-9999);
	printf("%-9.5d\n",-9999);
	return (0);
}
