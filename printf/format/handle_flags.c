#include "../ft_printf.h"

int	handle_flags(const char *fmt, int i, t_fmtstr *t)
{
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
	return (i);
}
