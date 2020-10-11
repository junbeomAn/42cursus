#include "libft.h"

int		_abs(int n)
{
	return (n > 0 ? n : -n);
}

void	put_num(int fd, int n)

{

	char c;

	if (n == 0)
		return ;
	put_num(fd, _abs(n / 10));
	c = _abs(n % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)

{
	if (fd < 0)
		return ;
	if (n < 0)
		write(fd, "-", 1);
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	put_num(fd, n);
}
