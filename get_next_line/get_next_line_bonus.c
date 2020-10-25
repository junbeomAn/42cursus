/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:38:53 by juan              #+#    #+#             */
/*   Updated: 2020/10/25 20:51:42 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	i = 0;
	if (!record)
		return (ft_strdup("\0"));
	i = find_first_lb(record);
	if (record[i] == '\0')
		return (ft_strdup("\0"));
	return (ft_strdup(record + i + 1));
}

int		get_next_line(int fd, char **line)
{
	static char		*rec[OPEN_MAX];
	char			*buf;
	int				res;
	char			*temp;

	if (!line || fd < 0 || BUFFER_SIZE <= 0 || OPEN_MAX < 0)
		return (-1);
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	res = 1;
	while (!ft_strchr(rec[fd], '\n') && (res = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[res] = '\0';
		rec[fd] = ft_strjoin(rec[fd], buf);
	}
	free(buf);
	if (res == -1)
		return (-1);
	*line = get_first_line(rec[fd]);
	temp = rec[fd];
	rec[fd] = update_record(rec[fd]);
	free(temp);
	return (res == 0 ? 0 : 1);
}
