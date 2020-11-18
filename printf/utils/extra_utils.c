#include "../ft_printf.h"

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

long ft_abs(long a)
{
	return (a < 0 ? -a : a);
}
