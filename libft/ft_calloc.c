/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:38:13 by juan              #+#    #+#             */
/*   Updated: 2020/10/14 20:21:00 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*ptr;

	if (!(ptr = (char *)malloc(num * size)))
		return (NULL);
	ft_memset(ptr, 0, size * num);
	return (ptr);
}
