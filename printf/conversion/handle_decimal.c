#include "../ft_printf.h"


static int	view_l_align(t_fmtstr *t, char *s, int p_zero, int len, int ld)
{
	int ret;

	ret = 0;
	if (ld < 0)
		ret += ft_putchar('-');
	if (has_precision_dot(t))
		ret += ft_put_blank(p_zero, 1);
	ret += ft_putstr(s);
	ret += ft_put_blank(len, t->zero_pad);
	return (ret);
}

static int	view_r_align(t_fmtstr *t, char *s, int p_zero, int len, int ld)
{
	int ret;

	ret = 0;
	if (ld < 0)
	{
		if (t->zero_pad == 1)
		{
			ret += ft_putchar('-');
			ret += ft_put_blank(len, t->zero_pad);
		}
		else
		{
			ret += ft_put_blank(len, t->zero_pad);
			ret += ft_putchar('-');
		}
	}
	else
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

int handle_decimal(va_list vl, t_fmtstr *t, int ret)
{
	long ld = (long)va_arg(vl, int);
	char *str_num;
	int	blank_len;
	int num_len;
	int precision_zero_pad;

	str_num = ft_itoa_base(ft_abs(ld), 10);
	num_len = ft_strlen(str_num);
	if (ft_memcmp(str_num, "0", 1) == 0 && t->precision == 0)
		ret += ft_put_blank(t->width, 0);
	else
	{
		precision_zero_pad = t->precision - num_len;
		blank_len = get_blank_len(t, num_len);
		if (ld < 0)
			blank_len -= 1;
		if (is_left_aligned(t))
			ret += view_l_align(t, str_num, precision_zero_pad, blank_len, ld);
		else
			ret += view_r_align(t, str_num, precision_zero_pad, blank_len, ld);
	}
	free(str_num);
	return (ret);
}
