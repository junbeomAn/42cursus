/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:38:13 by juan              #+#    #+#             */
/*   Updated: 2020/10/12 13:38:13 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	int		*ptr;
	size_t	i;

	if (!(ptr = (int *)malloc(num * size)))
		return (NULL);
	i = 0;
	while (i < num * size)
		ptr[i++] = 0;
	return (void *)ptr;
}
