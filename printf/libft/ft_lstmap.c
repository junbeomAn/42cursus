/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:47:30 by juan              #+#    #+#             */
/*   Updated: 2020/10/12 17:50:45 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_lst;

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
		if (!(new_lst->next = ft_lstnew(f(lst->content))))
		{
			free(new_lst->next);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_lst = new_lst->next;
		lst = lst->next;
	}
	return (head);
}
