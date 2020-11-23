/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:02:28 by juan              #+#    #+#             */
/*   Updated: 2020/10/12 14:02:28 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	if (dest == src)
		return (dest);
	i = 0;
	if (dest < src)
	{
		while (i++ < n)
			*dest_tmp++ = *src_tmp++;
	}
	else
	{
		src_tmp = (unsigned char *)(src + (n - 1));
		dest_tmp = (unsigned char *)(dest + (n - 1));
		while (i++ < n)
			*dest_tmp-- = *src_tmp--;
	}
	return (dest);
}
