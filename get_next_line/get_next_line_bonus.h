/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:41:35 by juan              #+#    #+#             */
/*   Updated: 2020/10/25 20:51:24 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_GET_NEXT_LINE_BONUS_H
# define INCLUDE_GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
