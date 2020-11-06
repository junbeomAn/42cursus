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

int is_empty_str(const char *str)
{
	if (!str[0])
	{
		write(1, "", 1);
		return (1);
	}
	return (0);
}

int		_abs(long n)
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
		char_num[len - 1 - i] = (digit > 9 ? 'A' + digit - 10 : '0' + digit);
		n /= base;
		i++;
	}
	char_num[i] = '\0';
	if (char_num[0] == '0' && len > 1)
		char_num[0] = '-';
	return (char_num);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
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

int ft_printf(const char *fmt, ...)
{
	va_list vl;
	t_fmtstr *t;
	int i;
	int fmtlen;

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
						if (t->minus != 1)
							t->zero_pad = 1;
					else
					{
						t->minus = 1;
						if (t->zero_pad == 1)
							t->zero_pad = 0;
					}
					i++;
				}

				// handle width
				while (('1' <= fmt[i] && fmt[i] <= '9') || fmt[i] == '*') // mininum numbers to be printed
				{
					if (fmt[i] == '*')
					{
						t->width = va_arg(vl, int);
						t->minus = t->width < 0 ? 1 : t->minus;
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
					t->zero_pad = 0;
					i++;
				}

				while (t->precision == 0 && ('1' <= fmt[i] && fmt[i] <= '9') || fmt[i] == '*') // mininum numbers to be printed
				{
					if (fmt[i] == '*')
						t->precision = va_arg(vl, int);
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
					if (is_left_aligned(t->minus)) // t->minus == 1
					{
						c ? ft_putchar_fd(c, 1) : ft_putstr_fd("^@", 1);
						ft_put_blank(t->width - 1, t->zero_pad);
					}
					else
					{
						ft_put_blank(t->width - 1, t->zero_pad);
						c ? ft_putchar_fd(c, 1) : ft_putstr_fd("^@", 1);
					}
				}
				else if (fmt[i] == 'd' || fmt[i] == 'D' || fmt[i] == 'i')
				{
					int d = va_arg(vl, int);
					char *char_num = ft_itoa_base(d, 10);
					int num_len = ft_strlen(char_num);
					int precision_zero_pad;
					int blank_len;

					precision_zero_pad = t->precision - num_len;
					if (precision_zero_pad >= 0)
						blank_len = t->width - t->precision;
					else if (!has_precision_dot(t) || precision_zero_pad < 0)
						blank_len = t->width - num_len;

					if (is_left_aligned(t->minus))
					{
						if (has_precision_dot(t)) //t->precision != -1
							ft_put_blank(precision_zero_pad, 1);
						ft_putstr_fd(char_num, 1);
						ft_put_blank(blank_len, t->zero_pad);
					}
					else
					{
						ft_put_blank(blank_len, t->zero_pad);
						if (has_precision_dot(t)) //t->precision != -1
							ft_put_blank(precision_zero_pad, 1);
						ft_putstr_fd(char_num, 1);
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
					char *s = va_arg(vl, char *);
					if (s)
						ft_putstr_fd(s, 1);
					else
						ft_putstr_fd("(null)", 1);
				}
				else if (fmt[i] == 'p')
				{
					unsigned long p = (unsigned long)va_arg(vl, void *);
					write(1, "0x", 2);
					ft_putnbr_base(p, HEXBASE);
				}
				else if (fmt[i] == 'x' && fmt[i] == 'X')
				{
					int ud = va_arg(vl, unsigned int);
					// unsigned int 범위 넘어갈때 처리.
					char *char_hex = ft_itoa_base(ud, 16);
					if (fmt[i] == 'x')
						ft_putstr_fd(lower_case(char_hex), 1);
					else
						ft_putstr_fd(char_hex, 1);
					free(char_hex);
				}
				else if (fmt[i] == '%')
				{
					ft_putchar_fd('%', 1);
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
}
