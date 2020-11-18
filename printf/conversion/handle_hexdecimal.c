#include "../ft_printf.h"

static int	view_l_align(t_fmtstr *t, char *s, int len, int p_zero, char x)
{
	int ret;

	ret = 0;
	if (has_precision_dot(t))
		ret += ft_put_blank(p_zero, 1);
	if (x == 'x')
		ret += ft_putstr(lower_case(s));
	else
		ret += ft_putstr(upper_case(s));
	ret += ft_put_blank(len, t->zero_pad);
	return (ret);
}

static int	view_r_align(t_fmtstr *t, char *s, int len, int p_zero, char x)
{
	int ret;

	ret = 0;
	ret += ft_put_blank(len, t->zero_pad);
	if (has_precision_dot(t))
		ret += ft_put_blank(p_zero, 1);
	if (x == 'x')
		ret += ft_putstr(lower_case(s));
	else
		ret += ft_putstr(upper_case(s));
	return (ret);
}

static int get_blank_len(t_fmtstr *t, int num_len)
{
	if (!has_precision_dot(t))
		return (t->width - num_len);
	else
		return (t->width - ft_max(t->precision, num_len));
}

int handle_hexdecimal(va_list vl, t_fmtstr *t, int ret, char x)
{
	unsigned int ud;
	char *char_hex;
	int num_len;
	int precision_zero_pad;
	int blank_len;

	ud = (unsigned int)va_arg(vl, unsigned int);
	*char_hex = ft_itoa_base(ud, 16);
	num_len = ft_strlen(char_hex);
	precision_zero_pad = t->precision - num_len;
	blank_len = get_blank_len(t, num_len);
	if (is_left_aligned(t))
		ret += view_l_align(t, char_hex, blank_len, precision_zero_pad, x);
	else
		ret += view_r_align(t, char_hex, blank_len, precision_zero_pad, x);
	free(char_hex);
	return (ret);
}
