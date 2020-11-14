#ifndef INCLUDE_FT_PRINTF_H
# define INCLUDE_FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

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

int ft_printf(const char *fmt, ...);

#endif
