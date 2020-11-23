/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junbeoman <junbeoman@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:10:27 by junbeoman         #+#    #+#             */
/*   Updated: 2020/11/23 11:10:28 by junbeoman        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int cnt;

	if (!s)
		return (0);
	cnt = (int)ft_strlen(s);
	return (write(1, s, cnt));
}

int	ft_put_blank(int width, int zero_pad)
{
	char	*blank;
	int		i;

	if (width < 1)
		return (0);
	if (!(blank = (char *)malloc(sizeof(char) * (width + 1))))
		return (0);
	i = 0;
	while (i < width)
	{
		if (zero_pad == 1)
			blank[i] = '0';
		else
			blank[i] = ' ';
		i++;
	}
	blank[i] = 0;
	write(1, blank, width);
	free(blank);
	blank = NULL;
	return (width);
}
