/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junbeoman <junbeoman@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:25:02 by junbeoman         #+#    #+#             */
/*   Updated: 2020/11/23 23:11:48 by junbeoman        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	view_l_align(t_fmtstr *t, intptr_t p, int print_len)
{
	int	ret;

	ret = 0;
	ret += ft_putstr("0x");
	if (p != 0 || t->precision != 0)
		ret += ft_putnbr_base(p, HEXBASE);
	ret += ft_put_blank(t->width - print_len, 0);
	return (ret);
}

static int	view_r_align(t_fmtstr *t, intptr_t p, int print_len)
{
	int	ret;

	ret = 0;
	ret += ft_put_blank(t->width - print_len, 0);
	ret += ft_putstr("0x");
	if (p != 0 || t->precision != 0)
		ret += ft_putnbr_base(p, HEXBASE);
	return (ret);
}

int			handle_pointer(va_list vl, t_fmtstr *t, int ret)
{
	intptr_t	p;
	int			print_len;

	p = (intptr_t)va_arg(vl, void *);
	print_len = get_address_len(p, 16) + 2;
	if (p == 0 && t->precision == 0)
		print_len -= 1;
	if (is_left_aligned(t))
		ret += view_l_align(t, p, print_len);
	else
		ret += view_r_align(t, p, print_len);
	return (ret);
}
