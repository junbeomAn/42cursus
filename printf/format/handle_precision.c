/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junbeoman <junbeoman@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:12:56 by junbeoman         #+#    #+#             */
/*   Updated: 2020/11/23 20:22:25 by junbeoman        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	is_number(char c)
{
	return ('0' <= c && c <= '9');
}

int	handle_precision(const char *fmt, int i, t_fmtstr *t, va_list vl)
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
	while (0 <= t->precision && (is_number(fmt[i]) || fmt[i] == '*'))
	{
		if (fmt[i] == '*')
			t->precision = va_arg(vl, int);
		else
			t->precision = (t->precision * 10) + (fmt[i] - '0');
		if (t->precision < 0 && t->zero_pad_ignrd == 1)
			t->zero_pad = 1;
		i++;
	}
	return (i);
}
