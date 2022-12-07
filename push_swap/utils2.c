/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:21:14 by meudier           #+#    #+#             */
/*   Updated: 2022/05/18 10:13:11 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	get_tab(t_list *lst, int **tab)
{
	int	size;
	int	i;

	if (!lst)
		return ;
	size = ft_lstsize(lst);
	*tab = (int *)malloc(size * sizeof(int));
	if (!*tab)
		return ;
	i = 0;
	while (lst)
	{
		(*tab)[i] = lst->data;
		lst = lst->next;
		i++;
	}
	ft_sort(tab, i);
}

void	ft_sort(int **tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	if (!tab)
		return ;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if ((*tab)[i] - (*tab)[j] > 0)
			{
				temp = (*tab)[i];
				(*tab)[i] = (*tab)[j];
				(*tab)[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	check_doublon(t_list *lst)
{
	int	*tab;
	int	i;
	int	j;
	int	len;

	tab = NULL;
	len = ft_lstsize(lst);
	get_tab(lst, &tab);
	i = 0;
	while (tab && i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] == tab[j])
			{
				free(tab);
				return (0);
			}
			j++;
		}
		i++;
	}
	free (tab);
	return (1);
}
