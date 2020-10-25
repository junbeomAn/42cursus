/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:36:52 by juan              #+#    #+#             */
/*   Updated: 2020/10/22 23:00:56 by juan             ###   ########.fr       */
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

char	*get_first_line(char *history)
{
	int	i;

	i = 0;
	if (!history)
		return (ft_strdup("\0"));
	i = find_first_lb(history);
	if (history[i] == '\0')
		return (ft_strdup(history));
	return (ft_substr(history, 0, i));
}

char	*update_history(char *history)
{
	int		i;
	char	*result;

	i = 0;
	if (!history)
		return (ft_strdup("\0"));
	i = find_first_lb(history);
	if (history[i] == '\0')
		return (ft_strdup("\0"));
	result = ft_strdup(history + i + 1);
	free(history);
	return (result);
}

int		get_next_line(int fd, char **line)
{
	static char		*read_history;
	char			*buffer;
	int				bytes_read;

	if (!line || fd < 0 || BUFFER_SIZE < 0)
		return (-1);
	if (!(buffer = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	bytes_read = 1;
	while (!(ft_strchr(read_history, '\n')) && ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		buffer[bytes_read] = '\0';
		read_history = ft_strjoin(read_history, buffer);
	}
	free(buffer);
	if (bytes_read == -1)
		return (-1);
	*line = get_first_line(read_history);
	read_history = update_history(read_history);
	return (bytes_read == 0 ? 0 : 1);
}
