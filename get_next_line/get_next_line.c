/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junbeoman <junbeoman@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:36:52 by juan              #+#    #+#             */
/*   Updated: 2020/12/02 11:06:14 by junbeoman        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	target;
	char	*from;

	if (!s)
		return (NULL);
	target = (char)c;
	from = (char *)s;
	if (target == '\0')
		return (from + ft_strlen(s));
	while (*from != '\0' && (*from != target))
		from++;
	return (*from ? from : NULL);
}

int		find_first_lb(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && (str[i] != '\n'))
		i++;
	return (i);
}

char	*get_first_line(char *record)
{
	int	i;

	i = 0;
	if (!record)
		return (ft_strdup("\0"));
	i = find_first_lb(record);
	if (record[i] == '\0')
		return (ft_strdup(record));
	return (ft_substr(record, 0, i));
}

char	*update_record(char *record)
{
	int		i;
	char	*res;

	i = 0;
	if (!record)
		return (ft_strdup("\0"));
	i = find_first_lb(record);
	if (record[i] == '\0')
	{
		free(record);
		record = NULL;
		return (ft_strdup("\0"));
	}
	res = ft_strdup(record + i + 1);
	free(record);
	record = NULL;
	return (res);
}

int		get_next_line(int fd, char **line)
{
	static char		*record;
	char			*buf;
	int				res;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	res = 1;
	while (!ft_strchr(record, '\n') && (res = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[res] = '\0';
		record = ft_strjoin(record, buf);
	}
	free(buf);
	*line = get_first_line(record);
	record = update_record(record);
	if (res == 0 || res == -1)
	{
		free(record);
		record = NULL;
		return (res);
	}
	return (1);
}
