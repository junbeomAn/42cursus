/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:36:52 by juan              #+#    #+#             */
/*   Updated: 2020/10/21 20:44:33 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>


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

char *get_first_line(char *history)
{
	int i;

	i = 0;
	if (!history)
		return (ft_strdup("\0"));
	while (history[i] != '\0' && (history[i] != '\n'))
		i++;
	if (history[i] == '\0')
		return (ft_strdup(history));
	return (ft_substr(history, 0, i));
}

char *update_history(char *history)
{
	int i;

	i = 0;
	if (!history)
		return (ft_strdup("\0"));
	while (history[i] != '\0' && (history[i] != '\n'))
		i++;
	if (history[i] == '\0')
		return (ft_strdup("\0"));
	return (ft_strdup(history + i + 1));
}

int	get_next_line(int fd, char **line)
{
	static char		*read_history;
	char			*buffer;
	int				bytes_read;
	char			*temp;

	if (!line || fd < 0 || BUFFER_SIZE < 0)
		return (-1);
	if (!(buffer = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!ft_strchr(read_history, '\n') && (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		read_history = ft_strjoin(read_history, buffer);
	}
	free(buffer);
	if (bytes_read == -1)
		return (-1);
	*line = get_first_line(read_history);
	temp = read_history;
	read_history = update_history(read_history);
	free(temp);
	if (bytes_read == 0)
		return (0);
	return (1);
}
