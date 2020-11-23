/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junbeoman <junbeoman@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:10:31 by junbeoman         #+#    #+#             */
/*   Updated: 2020/11/23 11:11:02 by junbeoman        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			zero_init(char *arr)
{
	int	i;

	i = 0;
	while (i < 127)
	{
		arr[i] = 0;
		i++;
	}
}

unsigned int	is_valid_base(char *base)
{
	char			ascii[127];
	unsigned int	i;

	i = 0;
	zero_init(ascii);
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ascii[(int)base[i]])
		{
			return (0);
		}
		ascii[(int)base[i]] = 1;
		i++;
	}
	return (i);
}

int				base_convert(intptr_t nbr, char *base, unsigned int len)
{
	intptr_t	div;
	intptr_t	mod;
	int			ret;

	if (!nbr)
		return (0);
	ret = 0;
	div = nbr / len;
	mod = nbr % len;
	ret = base_convert(div, base, len);
	if (mod < 0)
		mod = -mod;
	ret += write(1, &base[mod], 1);
	return (ret);
}

int				ft_putnbr_base(intptr_t nbr, char *base)
{
	unsigned int	len;

	len = is_valid_base(base);
	if (!len)
		return (0);
	if (nbr == 0)
		write(1, "0", 1);
	if (nbr < 0)
		write(1, "-", 1);
	return (base_convert(nbr, base, len));
}
