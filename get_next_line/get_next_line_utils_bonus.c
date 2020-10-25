/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:38:47 by juan              #+#    #+#             */
/*   Updated: 2020/10/25 20:52:00 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		return (len);
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	total_len;

	if (s1 || s2)
	{
		total_len = ft_strlen(s1) + ft_strlen(s2);
		if (!(new_str = (char *)malloc(sizeof(char) * (total_len + 1))))
			return (NULL);
		i = 0;
		j = 0;
		while (s1 && s1[j])
			new_str[i++] = s1[j++];
		j = 0;
		while (s2 && s2[j])
			new_str[i++] = s2[j++];
		new_str[i] = '\0';
		if (s1)
			free((char *)s1);
		return (new_str);
	}
	return (NULL);
}

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

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s);
	if (!(dup = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memcpy(dup, (const void *)s, len);
	dup[len] = '\0';
	return (dup);
}

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
