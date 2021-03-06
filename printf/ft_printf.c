/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junbeoman <junbeoman@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:38:52 by junbeoman         #+#    #+#             */
/*   Updated: 2020/11/24 12:08:31 by junbeoman        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_fmtstr *t)
{
	ft_bzero(t, sizeof(t_fmtstr));
	t->precision = -1;
}

int		handle_fmt_string(const char *fmt, t_fmtstr *t, va_list vl)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] && ft_strchr(ALLCHARS, fmt[i + 1]))
		{
			i += 1;
			i = handle_flags(fmt, i, t);
			i = handle_width(fmt, i, t, vl);
			i = handle_precision(fmt, i, t, vl);
			ret += controller(fmt[i], t, vl);
			init_info(t);
		}
		else
			ret += ft_putchar(fmt[i]);
		i++;
	}
	return (ret);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		vl;
	t_fmtstr	*t;
	int			fmtlen;
	int			ret;

	va_start(vl, fmt);
	fmtlen = ft_strlen(fmt);
	if (!(t = (t_fmtstr *)malloc(sizeof(t_fmtstr))))
		return (-1);
	init_info(t);
	if (is_empty_str(fmt))
		return (0);
	if (fmtlen == 1 && fmt[0] == '%')
		return (-1);
	ret = handle_fmt_string(fmt, t, vl);
	va_end(vl);
	return (ret);
}
