/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:36:17 by juan              #+#    #+#             */
/*   Updated: 2020/10/12 13:36:17 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	val;

	i = 0;
	val = 0;
	temp = s;
	while (i++ < n)
	{
		*temp = val;
		temp++;
	}
}
