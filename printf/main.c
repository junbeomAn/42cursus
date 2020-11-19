#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char c;
	c = 'f';
	int m;
	int n;
	// char *s = "abcdefg";
	// error cases
	// m = ft_printf("%0*X\n",20, 0xabc); // 000000000000-15
	// n = printf("%0*X\n",20, 0xabc); // -000000000000015
	// m = ft_printf("%0*.*i\n",15, 9, 1234566); // 000000000000-15
	// n = printf("%0*.*i\n", 15, 9,1234566); // -000000000000015
	// m = ft_printf("asd%*.*sbbb\n", 13, 4, NULL); // 000000000000-15
	// n = printf("asd%*.*sbbb\n",13, 4, NULL); // -000000000000015
	// m = ft_printf("%*.c\n",-4, c); // 000000000000-15
	// n = printf("%*.c\n", -4,c); // -000000000000015
	// m = ft_printf("%013.u\n", 0); // 000000000000-15
	// n = printf("%013.u\n", 0); // -000000000000015

	// m = ft_printf("%09p\n", &c); // 000000000000-15
	n = printf("%09p\n", &c); // -000000000000015

	// m = ft_printf("%*.*%\n", -20, 15); // 000000000000-15
	// n = printf("%*.*%\n", -20, 15); // -000000000000015

	if (m == n)
		printf("same");
	else
	{
		printf("diff m: %d, n: %d", m, n);
	}

	// char *a = "zbss;";
	// int w = -20;
	// int pre = 5;
	// ft_printf("%\n");
	// printf("%\n");
	// unsigned int n = 4294967295;
	// ft_printf("%*.*u\n", 13, -5, n);
	// printf("%*.*u\n",13 ,-5, n);

	return (0);
}
