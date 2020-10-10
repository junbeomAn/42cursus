#include "libft.h"

void    ft_putstr_fd(char *s, int fd)
{
    int cnt;

    if (fd < 0)
        return ;
    cnt = (int)ft_strlen(s);
    write(fd, s, cnt);    
}