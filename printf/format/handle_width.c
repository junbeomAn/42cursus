/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junbeoman <junbeoman@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:12:51 by junbeoman         #+#    #+#             */
/*   Updated: 2020/11/23 11:12:52 by junbeoman        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_width(const char *fmt, int i, t_fmtstr *t, va_list vl)
{
	while (('0' <= fmt[i] && fmt[i] <= '9') || fmt[i] == '*')
	{
		if (fmt[i] == '*')
		{
			t->width = va_arg(vl, int);
			if (t->width < 0)
			{
				t->minus = 1;
				t->width = ft_abs(t->width);
			}
		}
		else
			t->width = (t->width * 10) + (fmt[i] - '0');
		if (t->width < 0)
			t->minus = 1;
		i++;
	}
	return (i);
}
