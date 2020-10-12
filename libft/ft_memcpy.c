/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:59:19 by juan              #+#    #+#             */
/*   Updated: 2020/10/12 13:59:19 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	if (!dest && !src)
		return (0);
	i = 0;
	temp = dest;
	while (i < n)
	{
		*temp = *((const unsigned char *)src);
		temp++;
		src++;
		i++;
	}
	return (dest);
}
