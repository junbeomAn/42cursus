/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junbeoman <junbeoman@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:24:56 by junbeoman         #+#    #+#             */
/*   Updated: 2020/11/23 11:25:46 by junbeoman        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	get_print_len(t_fmtstr *t, int str_len)
{
	if (t->precision > -1)
		return (ft_min(t->precision, str_len));
	else
		return (str_len);
}

static int	view_l_align(t_fmtstr *t, char *print_str, int print_len)
{
	int	ret;

	ret = 0;
	ret += ft_putstr(print_str);
	ret += ft_put_blank(t->width - print_len, 0);
	return (ret);
}

static int	view_r_align(t_fmtstr *t, char *print_str, int print_len)
{
	int	ret;

	ret = 0;
	ret += ft_put_blank(t->width - print_len, 0);
	ret += ft_putstr(print_str);
	return (ret);
}

int			handle_str(va_list vl, t_fmtstr *t, int ret)
{
	char	*s;
	char	*print_str;
	int		print_len;

	s = (char *)va_arg(vl, char *);
	if (s == NULL)
		s = "(null)";
	print_len = get_print_len(t, ft_strlen(s));
	print_str = ft_substr(s, 0, print_len);
	if (print_len < t->width)
	{
		if (is_left_aligned(t))
			ret += view_l_align(t, print_str, print_len);
		else
			ret += view_r_align(t, print_str, print_len);
	}
	else
		ret += ft_putstr(print_str);
	free(print_str);
	return (ret);
}
