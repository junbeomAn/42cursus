/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junbeoman <junbeoman@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:12:10 by juan              #+#    #+#             */
/*   Updated: 2020/11/21 23:39:57 by junbeoman        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	return (n > 0 ? n : -n);
}

void		put_num(int fd, int n)
{
	char c;

	if (n == 0)
		return ;
	put_num(fd, ft_abs(n / 10));
	c = ft_abs(n % 10) + '0';
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n < 0)
		write(fd, "-", 1);
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	put_num(fd, n);
}
