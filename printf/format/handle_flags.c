/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junbeoman <junbeoman@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:12:58 by junbeoman         #+#    #+#             */
/*   Updated: 2020/11/23 11:12:59 by junbeoman        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
