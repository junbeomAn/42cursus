#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))

{
	t_list  *head;
	t_list  *new_lst;
	t_list  *temp;
	void    *new_content;

	if (!lst || !f)
		return (NULL);
	if (!(new_lst = ft_lstnew(f(lst->content))))
	{
		free(new_lst);
		return (NULL);
	}
	head = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_content = f(lst->content);
		if (!(temp = ft_lstnew(new_content)))
		{
			free(temp);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}            
		new_lst->next = temp;
		new_lst = new_lst->next;
		lst = lst->next;
	}
	return (head);
}
