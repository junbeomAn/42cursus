#include "../ft_printf.h"

int handle_precision(char *fmt, int i, t_fmtstr *t, va_list vl)
{
	while (fmt[i] == '.')
	{
		t->precision = 0;
		if (t->zero_pad == 1)
		{
			t->zero_pad = 0;
			t->zero_pad_ignrd = 1;
		}
		i++;
	}
	while (0 <= t->precision && (('0' <= fmt[i] && fmt[i] <= '9') || fmt[i] == '*'))
	{
		if (fmt[i] == '*')
			t->precision = va_arg(vl, int);
		else
			t->precision = (t->precision * 10) + (fmt[i] - '0');
		i++;
	}
	return (i);
}
