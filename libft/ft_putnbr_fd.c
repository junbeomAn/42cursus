#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
    char    *str_num;
    int     len;

    if (fd < 0)
        return ;
    str_num = ft_itoa(n);
    len = ft_strlen(str_num);
    write(fd, str_num, len);
}