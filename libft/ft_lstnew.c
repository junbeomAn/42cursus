#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list  *new_lst;

    if (!(new_lst = (t_list *)malloc(sizeof(t_list))))
    {
        free(new_lst);
        return (NULL);
    }
    new_lst->next = NULL;
    new_lst->content = content;
    return (new_lst);
}