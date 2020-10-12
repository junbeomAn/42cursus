/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:28:44 by juan              #+#    #+#             */
/*   Updated: 2020/10/12 15:28:44 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	total_len;

	if (s1 && s2)
	{
		total_len = ft_strlen(s1) + ft_strlen(s2);
		if (!(new_str = (char *)malloc(sizeof(char) * (total_len + 1))))
			return (NULL);
		i = 0;
		while (*s1)
			new_str[i++] = *s1++;
		while (*s2)
			new_str[i++] = *s2++;
		new_str[i] = '\0';
		return (new_str);
	}
	return (NULL);
}
