/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junbeoman <junbeoman@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:10:36 by junbeoman         #+#    #+#             */
/*   Updated: 2020/11/23 11:11:20 by junbeoman        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		has_precision_dot(t_fmtstr *t)
{
	return (t->precision == -1 ? 0 : 1);
}

int		is_left_aligned(t_fmtstr *t)
{
	return (t->minus == 1 ? 1 : 0);
}

int		ft_min(int a, int b)
{
	return (a >= b ? b : a);
}

int		ft_max(int a, int b)
{
	return (a <= b ? b : a);
}

long	ft_abs(long a)
{
	return (a < 0 ? -a : a);
}
