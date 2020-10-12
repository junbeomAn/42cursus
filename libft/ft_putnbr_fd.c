/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:12:10 by juan              #+#    #+#             */
/*   Updated: 2020/10/12 14:12:10 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_abs(int n)
{
	return (n > 0 ? n : -n);
}

void	put_num(int fd, int n)
{
	char c;

	if (n == 0)
		return ;
	put_num(fd, _abs(n / 10));
	c = ft_abs(n % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
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
