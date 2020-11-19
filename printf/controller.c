#include "ft_printf.h"

int controller(char spec, t_fmtstr *t, va_list vl)
{
	int ret;

	ret = 0;
	if (spec == 'c' || spec == 'C')
		ret += handle_char(vl, t, ret);
	else if (spec == 'd' || spec == 'D' || spec == 'i')
		ret += handle_decimal(vl, t, ret);
	else if (spec == 'u' || spec == 'U')
		ret += handle_udecimal(vl, t, ret);
	else if (spec == 's')
		ret += handle_str(vl, t, ret);
	else if (spec == 'p')
		ret += handle_pointer(vl, t, ret);
	else if (spec == 'x' || spec == 'X')
		ret += handle_hexdecimal(vl, t, ret, spec);
	else if (spec == '%')
		ret += handle_percent(t, ret);
	return (ret);
}
