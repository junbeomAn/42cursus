/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:28:05 by juan              #+#    #+#             */
/*   Updated: 2020/10/12 15:28:05 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s);
	if (!(dup = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dup = ft_memcpy(dup, (const void *)s, len);
	dup[len] = '\0';
	return (dup);
}
