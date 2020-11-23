/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:23:31 by juan              #+#    #+#             */
/*   Updated: 2020/10/14 22:07:36 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_cnt(char const *str, char sep)
{
	int	cnt;
	int len;
	int i;

	cnt = 0;
	i = 0;
	len = ft_strlen(str);
	while (i < len && str[i])
	{
		if (i < len && str[i] && (sep != str[i]))
		{
			cnt++;
			while (i < len && str[i] && (sep != str[i]))
				i++;
		}
		i++;
	}
	return (cnt);
}

static char	**free_on_error(char **mem_block)
{
	unsigned int	i;

	i = 0;
	while (mem_block && mem_block[i])
		free(mem_block[i++]);
	free(mem_block);
	mem_block = NULL;
	return (NULL);
}

static char	**put_substr(char **res, char const *str, char sep, int *index)
{
	unsigned int	i;
	unsigned int	start;
	char			*element;
	unsigned int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (i < len && (str[i] != sep))
		{
			start = i;
			while (i < len && (str[i] != sep))
				i++;
			if (!(element = ft_substr(str, start, i - start)))
			{
				free(element);
				return (free_on_error(res));
			}
			res[(*index)++] = element;
		}
		i++;
	}
	return (res);
}

char		**ft_split(char const *s, char c)
{
	int		word_cnt;
	int		index;
	char	**result;

	if (!s)
		return (NULL);
	word_cnt = get_word_cnt(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (word_cnt + 1))))
		return (free_on_error(result));
	index = 0;
	if (!(result = put_substr(result, s, c, &index)))
		return (free_on_error(result));
	result[index] = NULL;
	return (result);
}
