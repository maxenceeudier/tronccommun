/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_radix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:02:27 by meudier           #+#    #+#             */
/*   Updated: 2022/05/12 11:04:24 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	equal_to_i_exist(t_list *lst, int i, int j)
{
	int	count;

	count = 0;
	while (lst)
	{
		if ((lst->data % (10 * j)) / j == i)
			count++;
		lst = lst->next;
	}
	return (count);
}

int	is_the_smallest(t_list *lst, int i, int j, int data)
{
	while (lst)
	{
		if ((lst->data % (10 * j)) / j == i)
			if (lst->data % (10 * j) < data % (10 * j))
				return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_the_bigger(t_list *lst, int i, int j, int data)
{
	while (lst)
	{
		if ((lst->data % (10 * j)) / j == i)
			if (lst->data % (10 * j) > data % (10 * j))
				return (0);
		lst = lst->next;
	}
	return (1);
}

int	fast_way_to_smallest(t_list *lst, int i, int j)
{
	int	count;
	int	other_way;
	int	len;

	count = 0;
	len = ft_lstsize(lst);
	while (lst && !is_the_smallest(lst, i, j, lst->data))
	{
		count++;
		lst = lst->next;
	}
	other_way = len - count;
	if (count <= other_way)
		return (count);
	else
		return (-1 * (other_way));
}

int	fast_way_to_bigger(t_list *lst, int i, int j)
{
	int	count;
	int	other_way;
	int	len;

	count = 0;
	len = ft_lstsize(lst);
	while (lst && !is_the_bigger(lst, i, j, lst->data))
	{
		count++;
		lst = lst->next;
	}
	other_way = len - count;
	if (count <= other_way)
		return (count);
	else
		return (-1 * (other_way));
}
