#include "libft.h"

#include <stdio.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    size_t len;
    char *new_str;
    unsigned int i;

    if (!s || !f)
        return (NULL);
    len = ft_strlen(s);
    if (!(new_str = (char *)malloc(sizeof(char) * (len + 1))))
    {
        free(new_str);
        return (NULL);
    }
    i = 0;
    while (*s)
    {
        new_str[i] = f(i, *s++);
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}