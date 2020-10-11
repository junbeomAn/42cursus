#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_lst;
    t_list  *temp;
    void    *new_content;

    if (!lst || !f || !del)
        return (NULL);
    new_lst = NULL;
    while (lst)
    {
        new_content = f(lst->content);
        if (!(temp = ft_lstnew(new_content)))
        {
            free(temp);
            ft_lstclear(&new_lst, del);
            return (NULL);
        }            
        ft_lstadd_back(&new_lst, temp);
        lst = lst->next;
    }
    return (new_lst);
}
