/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_ck_and_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:28:33 by meudier           #+#    #+#             */
/*   Updated: 2022/05/17 16:50:50 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if (!last)
		return ;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	lst_push(t_list **lst1, t_list **lst2)
{
	t_list	*temp;

	temp = *lst1;
	if (!*lst2 && *lst1)
	{
		*lst2 = *lst1;
		*lst1 = (*lst1)->next;
		(*lst2)->next = NULL;
	}
	else if (*lst1)
	{
		*lst1 = (*lst1)->next;
		temp->next = (*lst2);
		*lst2 = temp;
	}
}

void	lst_swap(t_list **lst)
{
	t_list	*temp;

	if (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		temp->next = temp->next->next;
		(*lst)->next = temp;
	}
}

void	lst_rotate(t_list **lst)
{
	t_list	*temp;

	if (*lst && (*lst)->next)
	{
		temp = *lst;
		*lst = (*lst)->next;
		temp->next = NULL;
		ft_lstadd_back(lst, temp);
	}
}

void	lst_rotate_rev(t_list **lst)
{
	t_list	*last;

	if (*lst && (*lst)->next)
	{
		last = *lst;
		while (last->next->next)
			last = last->next;
		last->next->next = *lst;
		*lst = last->next;
		last->next = NULL;
	}
}
