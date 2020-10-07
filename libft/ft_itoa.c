#include "libft.h"

int abs(int n)
{
    return (n > 0 ? n : -n);
}

int get_num_len(int n)
{
    return 1 + (abs(n / 10) > 0 ? get_num_len(n / 10) : 0);
}

char *ft_itoa(int n)
{
    char *char_num;
    int len;
    int i;

    len = get_num_len(n);
    if (n < 0)
        len++;
    if (!(char_num = (char *)malloc(sizeof(char) * (len + 1))))
    {
        free(char_num);
        return (NULL);
    }
    i = 0;
    while (i < len)
    {
        char_num[len - 1 - i] = abs(n % 10) + 48;
        n /= 10;
        i++;
    }
    char_num[i] = '\0';
    if (char_num[0] == '0' && len > 1)
        char_num[0] = '-';
    return (char_num);
}