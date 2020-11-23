/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:31:57 by juan              #+#    #+#             */
/*   Updated: 2020/10/12 15:31:57 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	unsigned int	res;

	i = 0;
	res = 0;
	while (dst[i] && i < size)
		i++;
	res += i;
	while (*src && i + 1 < size)
	{
		dst[i] = *src++;
		res++;
		i++;
	}
	if (size > i)
		dst[i] = '\0';
	while (*src++)
		res++;
	return (res);
}
