#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>


void	zero_init(char *arr)
{
	int i;

	i = 0;
	while (i < 127)
	{
		arr[i] = 0;
		i++;
	}
}

unsigned int		is_valid_base(char *base)
{
	char	ascii[127];
	unsigned int		i;

	i = 0;
	zero_init(ascii);
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ascii[(int)base[i]])
		{
			return (0);
		}
		ascii[(int)base[i]] = 1;
		i++;
	}
	return (i);
}

void	base_convert(unsigned long nbr, char *base, unsigned int len)
{
	unsigned long div;
	unsigned long mod;

	if (!nbr)
		return ;
	div = nbr / len;
	mod = nbr % len;
	base_convert(div, base, len);
	if (mod < 0)
		mod = -mod;
	write(1, &base[mod], 1);
}

void	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned int len;

	len = is_valid_base(base);
	if (!len)
		return ;
	if (nbr == 0)
		write(1, "0", 1);
	if (nbr < 0)
		write(1, "-", 1);
	base_convert(nbr, base, len);
}



//////////////////////////////////////////////////////////////////


long	_abs( long n)
{
	return (n > 0 ? n : -n);
}

int		get_num_len(long n, int base)
{
	return (1 + (_abs(n / base) > 0 ? get_num_len(n / base, base) : 0));
}

char	*ft_itoa_base(long n, int base)
{
	char	*char_num;
	int		len;
	int		i;
	int		digit;

	len = get_num_len(n, base);
	if (n < 0)
		len++;
	if (!(char_num = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		digit = _abs(n % base);
		char_num[len - 1 - i] = (digit > 9 ? 'a' + digit - 10 : '0' + digit);
		n /= base;
		i++;
	}
	char_num[i] = '\0';
	if (char_num[0] == '0' && len > 1)
		char_num[0] = '-';
	return (char_num);
}


void print(const char *a, ...)
{
	va_list vl;

	va_start(vl, a);
	for (int i = 0; i < 1; i++)
	{
		unsigned int c = (unsigned int)va_arg(vl, unsigned int);

		// intptr_t p = (intptr_t)va_arg(vl, void *);
		printf("%s\n", ft_itoa_base(c, 16));


	}
	va_end(vl);
}

// void ft_put_blank(int width, int zero_pad)
// {
// 	char *blank;
// 	int i;

// 	if (!(blank = (char *)malloc(sizeof(char) * width)))
// 		return ;
// 	i = 0;
// 	while (i < width)
// 	{
// 		if (zero_pad == 1)
// 			blank[i] = '0';
// 		else
// 			blank[i] = ' ';
// 		i++;
// 	}
// 	write(1, blank, width);
// 	free(blank);
// 	blank = NULL;
// }


int main(void)
{
	// printf("%d %z ", 42, 50);
	// printf("%s", ft_itoa_base(164, 16));
	// printf("\n%x", 164);
	// char *c1;
	int a;
	// char c2 = 2;
	// char c3 = 3;
	a = (0 | 2);
	// print("abc", );
	// c1 = NULL;
	// if (!c1)
	// 	c1 = "(null";
	// width > precision
	// a = printf("%.*d", 7, 1234);
	// ft_putnbr_base(140732751947680, "0123456789abcdef");
	ft_puthex_lower((long)140732751947680, 16);
	// printf("%ld\n", ((long)140732751947680)/16/16/16/16/16/16/16/16/16/16/16);
	//7ffee5b027a0

	// printf("%ld\n", k /16/16/16/16/16/16/16/16/16/16/16/16);
	// a = 2147483650;
	// a = printf("%20p\n", &c2);
	// a = printf("%s\n", ft_itoa_base(0, 10));
	// a = printf("%020.19x\n", (unsigned int)3147483649 );
	// print("abc", -3);
	// printf("\n%d\n", a);

}


// flags width precision (length) specifier
