#ifndef INCLUDE_FT_PRINTF_H
# define INCLUDE_FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include "libft/libft.h"

# define ALLCHARS "cspdiuxX%-0.*123456789"
# define CONVERSIONS "%cspdiuxX"
# define HEXBASE "0123456789abcdef"

typedef struct	s_fmtstr
{
	int			minus;
	int			zero_pad;
	int			width;
	int			precision;
	int			p_width;
	int			length;
	int			zero_pad_ignrd;
}				t_fmtstr;

int		has_precision_dot(t_fmtstr *t);
int		is_left_aligned(t_fmtstr *t);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
long	ft_abs(long a);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_put_blank(int width, int zero_pad);
int		is_empty_str(const char *str);
int		get_address_len(intptr_t n, int base);
char	*lower_case(char *str);
char	*upper_case(char *str);
char	*ft_itoa_base(long n, int base);
int		ft_putnbr_base(intptr_t nbr, char *base);
int		controller(char spec, t_fmtstr *t, va_list vl);
int		ft_printf(const char *fmt, ...);
int		handle_flags(const char *fmt, int i, t_fmtstr *t);
int		handle_precision(const char *fmt, int i, t_fmtstr *t, va_list vl);
int		handle_width(const char *fmt, int i, t_fmtstr *t, va_list vl);
int		handle_char(va_list vl, t_fmtstr *t, int ret);
int		handle_decimal(va_list vl, t_fmtstr *t, int ret);
int		handle_hexdecimal(va_list vl, t_fmtstr *t, int ret, char x);
int		handle_percent(t_fmtstr *t, int ret);
int		handle_pointer(va_list vl, t_fmtstr *t, int ret);
int		handle_str(va_list vl, t_fmtstr *t, int ret);
int		handle_udecimal(va_list vl, t_fmtstr *t, int ret);

#endif
