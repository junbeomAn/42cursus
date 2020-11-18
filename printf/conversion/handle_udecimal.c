#include "../ft_printf.h"

static int	view_l_align(t_fmtstr *t, char *s, int len, int p_zero)
{
	int ret;

	ret = 0;
	if (has_precision_dot(t))
		ret += ft_put_blank(p_zero, 1);
	ret += ft_putstr(s);
	ret += ft_put_blank(len, t->zero_pad);
	return (ret);
}

static int	view_r_align(t_fmtstr *t, char *s, int len, int p_zero)
{
	int ret;

	ret = 0;
	ret += ft_put_blank(len, t->zero_pad);
	if (has_precision_dot(t))
		ret += ft_put_blank(p_zero, 1);
	ret += ft_putstr(s);
	return (ret);
}

static int get_blank_len(t_fmtstr *t, int num_len)
{
	if (!has_precision_dot(t))
		return (t->width - num_len);
	else
		return (t->width - ft_max(t->precision, num_len));
}

int handle_udecimal(va_list vl, t_fmtstr *t, int ret)
{
	unsigned int ud = va_arg(vl, unsigned int);
	char *str_num;
	int	blank_len;
	int num_len;
	int precision_zero_pad;

	str_num = ft_itoa_base(ud, 10);
	num_len = ft_strlen(str_num);
	if (ft_memcmp(str_num, "0", 1) == 0 && t->precision == 0)
		ret += ft_put_blank(t->width, 0);
	else
	{
		precision_zero_pad = t->precision - num_len;
		blank_len = get_blank_len(t, num_len);
		if (is_left_aligned(t))
			ret += view_l_align(t, str_num, blank_len, precision_zero_pad);
		else
			ret += view_r_align(t, str_num, blank_len, precision_zero_pad);
	}
	free(str_num);
	return (ret);
}
