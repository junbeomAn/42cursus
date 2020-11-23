/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junbeoman <junbeoman@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:25:08 by junbeoman         #+#    #+#             */
/*   Updated: 2020/11/23 11:25:09 by junbeoman        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_percent(t_fmtstr *t, int ret)
{
	if (is_left_aligned(t))
	{
		ret += ft_putchar('%');
		ret += ft_put_blank(t->width - 1, (t->zero_pad || t->zero_pad_ignrd));
	}
	else
	{
		ret += ft_put_blank(t->width - 1, (t->zero_pad || t->zero_pad_ignrd));
		ret += ft_putchar('%');
	}
	return (ret);
}
