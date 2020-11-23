/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_udecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junbeoman <junbeoman@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:25:55 by junbeoman         #+#    #+#             */
/*   Updated: 2020/11/23 13:28:35 by junbeoman        ###   ########.fr       */
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

static int	view_l_align(t_fmtstr *t, char *s)
{
	int ret;
	int	blank_len;
	int	num_len;
	int	precision_zero_pad;

	ret = 0;
	num_len = ft_strlen(s);
	precision_zero_pad = t->precision - num_len;
	blank_len = get_blank_len(t, num_len);
	if (has_precision_dot(t))
		ret += ft_put_blank(precision_zero_pad, 1);
	ret += ft_putstr(s);
	ret += ft_put_blank(blank_len, t->zero_pad);
	return (ret);
}

static int	view_r_align(t_fmtstr *t, char *s)
{
	int ret;
	int	blank_len;
	int	num_len;
	int	precision_zero_pad;

	ret = 0;
	num_len = ft_strlen(s);
	precision_zero_pad = t->precision - num_len;
	blank_len = get_blank_len(t, num_len);
	ret += ft_put_blank(blank_len, t->zero_pad);
	if (has_precision_dot(t))
		ret += ft_put_blank(precision_zero_pad, 1);
	ret += ft_putstr(s);
	return (ret);
}

int			handle_udecimal(va_list vl, t_fmtstr *t, int ret)
{
	unsigned int	ud;
	char			*str_num;

	ud = va_arg(vl, unsigned int);
	str_num = ft_itoa_base(ud, 10);
	if (ft_memcmp(str_num, "0", 1) == 0 && t->precision == 0)
		ret += ft_put_blank(t->width, 0);
	else
	{
		if (is_left_aligned(t))
			ret += view_l_align(t, str_num);
		else
			ret += view_r_align(t, str_num);
	}
	free(str_num);
	return (ret);
}
