/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexdecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junbeoman <junbeoman@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:23:38 by junbeoman         #+#    #+#             */
/*   Updated: 2020/11/23 12:56:22 by junbeoman        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	get_blank_len(t_fmtstr *t, int num_len)
{
	if (!has_precision_dot(t))
		return (t->width - num_len);
	else
		return (t->width - ft_max(t->precision, num_len));
}

static int	view_l_align(t_fmtstr *t, char *s, char x)
{
	int	ret;
	int	num_len;
	int	precision_zero_pad;
	int	blank_len;

	ret = 0;
	num_len = ft_strlen(s);
	precision_zero_pad = t->precision - num_len;
	blank_len = get_blank_len(t, num_len);
	if (has_precision_dot(t))
		ret += ft_put_blank(precision_zero_pad, 1);
	if (x == 'x')
		ret += ft_putstr(lower_case(s));
	else
		ret += ft_putstr(upper_case(s));
	ret += ft_put_blank(blank_len, t->zero_pad);
	return (ret);
}

static int	view_r_align(t_fmtstr *t, char *s, char x)
{
	int	ret;
	int	num_len;
	int	precision_zero_pad;
	int	blank_len;

	ret = 0;
	num_len = ft_strlen(s);
	precision_zero_pad = t->precision - num_len;
	blank_len = get_blank_len(t, num_len);
	ret += ft_put_blank(blank_len, t->zero_pad);
	if (has_precision_dot(t))
		ret += ft_put_blank(precision_zero_pad, 1);
	if (x == 'x')
		ret += ft_putstr(lower_case(s));
	else
		ret += ft_putstr(upper_case(s));
	return (ret);
}

int			handle_hexdecimal(va_list vl, t_fmtstr *t, int ret, char x)
{
	unsigned int	ud;
	char			*str_num;

	ud = (unsigned int)va_arg(vl, unsigned int);
	str_num = ft_itoa_base(ud, 16);
	if (is_left_aligned(t))
		ret += view_l_align(t, str_num, x);
	else
		ret += view_r_align(t, str_num, x);
	free(str_num);
	return (ret);
}
