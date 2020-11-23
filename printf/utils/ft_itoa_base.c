/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junbeoman <junbeoman@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:10:33 by junbeoman         #+#    #+#             */
/*   Updated: 2020/11/23 11:10:34 by junbeoman        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		get_num_len(long n, int base)
{
	return (1 + (ft_abs(n / base) > 0 ? get_num_len(n / base, base) : 0));
}

char	*ft_itoa_base(long n, int base)
{
	char	*char_num;
	int		len;
	int		i;
	int		digit;

	len = get_num_len(n, base);
	if (n < 0)
		len++;
	if (!(char_num = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		digit = ft_abs(n % base);
		char_num[len - 1 - i] = (digit > 9 ? 'a' + digit - 10 : '0' + digit);
		n /= base;
		i++;
	}
	char_num[i] = '\0';
	if (char_num[0] == '0' && len > 1)
		char_num[0] = '-';
	return (char_num);
}
