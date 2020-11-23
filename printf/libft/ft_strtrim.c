/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:38:57 by juan              #+#    #+#             */
/*   Updated: 2020/10/12 15:38:57 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	left;
	size_t	right;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	left = 0;
	right = len - 1;
	while (left <= right && s1[left] && ft_strchr(set, s1[left]))
		left++;
	while (left <= right && s1[right] && ft_strchr(set, s1[right]))
		right--;
	if (!(new_str = ft_substr(s1, left, right - left + 1)))
		return (NULL);
	return (new_str);
}
