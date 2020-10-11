#include "libft.h"

static int  get_word_cnt(char const *str, char sep)
{
	int cnt;
	int i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		if (sep != str[i])
		{
			cnt++;
			while (str[i] && sep != str[i])
				i++;
		}
		i++;
	}
	return (cnt);
}

static char **free_on_error(char **mem_block)
{
    unsigned int    i;

    i = 0;
    while (mem_block && mem_block[i])
        free(mem_block[i++]);
    free(mem_block);
    mem_block = NULL;
    return (NULL);
}

char        **put_str_to_array(char **res, char const *str, char sep, int *index)
{
    unsigned int    i;
    unsigned int    start;
    char            *element;

    i = 0;
    while (str[i])
    {
        if (str[i] != sep)
        {
            start = i;
            while (str[i] && str[i] != sep)
                i++;
            if (!(element = ft_substr(str, start, i - start)))
            {
                free(element);
                return (free_on_error(res));
            }
            res[(*index)++] = element;
        }
        i++;
    }
	res[*index] = NULL;
    return (res);
}

char        **ft_split(char const *s, char c)
{
    int     word_cnt;
    int     index;
    char    **result;

    if (!s)
        return (NULL);
    word_cnt = get_word_cnt(s, c);
    if (!(result = (char **)malloc(sizeof(char *) * (word_cnt + 1))))
        return (free_on_error(result));
    index = 0;
    if (!(result = put_str_to_array(result, s, c, &index)))
        return (free_on_error(result));
    result[index] = NULL;
    return (result);
}
