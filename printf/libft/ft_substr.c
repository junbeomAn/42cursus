/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:39:45 by juan              #+#    #+#             */
/*   Updated: 2020/10/12 15:39:45 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup("\0"));
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memcpy((void *)ret, (const void*)(s + start), len);
	ret[len] = '\0';
	return (ret);
}
