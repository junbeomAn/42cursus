/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:56:23 by juan              #+#    #+#             */
/*   Updated: 2020/10/12 13:56:23 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_has_cycle(t_list *lst)
{
	t_list	*fast;
	t_list	*slow;

	if (!lst)
		return (0);
	fast = lst->next;
	slow = lst;
	while (slow != fast)
	{
		if (!fast || !fast->next)
			return (0);
		fast = fast->next->next;
		slow = slow->next;
	}
	return (1);
}

int	ft_cyclesize(t_list *lst)
{
	t_list	*start;
	t_list	*curr;
	int		size;

	if (!lst)
		return (0);
	start = lst;
	curr = lst->next;
	size = 1;
	while (start != curr)
	{
		curr = curr->next;
		size++;
	}
	return (size);
}

int	ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*curr;

	if (!lst)
		return (0);
	if (ft_has_cycle(lst))
	{
		return (ft_cyclesize(lst));
	}
	cnt = 0;
	curr = lst;
	while (curr)
	{
		curr = curr->next;
		cnt++;
	}
	return (cnt);
}
