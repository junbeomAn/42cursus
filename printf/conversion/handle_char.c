#include "../ft_printf.h"

static int	view_l_align(t_fmtstr *t, char c)
{
	int ret;

	ret = 0;
	ret += ft_putchar(c);
	ret += ft_put_blank(t->width - 1, t->zero_pad);
	return (ret);
}

static int	view_r_align(t_fmtstr *t, char c)
{
	int ret;

	ret = 0;
	ret += ft_put_blank(t->width - 1, t->zero_pad);
	ret += ft_putchar(c);
	return (ret);
}

int handle_char(va_list vl, t_fmtstr *t, int ret)
{
	int c = va_arg(vl, int);
	if (is_left_aligned(t)) // t->minus == 1
		ret += view_l_align(t, c);
	else
		ret += view_r_align(t, c);
	return (ret);
}
