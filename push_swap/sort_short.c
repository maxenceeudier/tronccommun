/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:26:25 by meudier           #+#    #+#             */
/*   Updated: 2022/05/17 16:53:09 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	the_smallest_exist(t_list *lst, int x)
{
	while (lst)
	{
		if (lst->data == x)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	fast_way_to_smaller(t_list *lst, int x)
{
	int	count1;
	int	count2;

	count1 = 0;
	count2 = 0;
	while (lst)
	{
		if (lst->data != x)
			count1++;
		else
			break ;
		lst = lst->next;
	}
	while (lst)
	{
		if (!the_smallest_exist(lst, x))
			count2++;
		lst = lst->next;
	}
	if (count1 <= count2)
		return (count1);
	else
		return (-1 * (count2 + 1));
}

void	sort_short_heart(t_list **lsta, t_list **lstb, int x)
{
	int		k;

	while (*lsta && the_smallest_exist(*lsta, x)
		&& !lst_is_croissant(*lsta))
	{
		if ((*lsta)->data == x)
			pb (lsta, lstb);
		else
		{
			k = fast_way_to_smaller(*lsta, x);
			if (k >= 0)
				while (k-- > 0)
					ra(lsta);
			else
				while (k++ < 0)
					rra(lsta);
		}
	}
}

void	sort_short(t_list **lsta, t_list **lstb)
{
	int	*tab;
	int	size;
	int	i;

	get_tab(*lsta, &tab);
	size = ft_lstsize(*lsta);
	i = 0;
	while (i < size && !lst_is_croissant(*lsta))
	{
		sort_short_heart(lsta, lstb, tab[i]);
		i++;
	}
	if (*lstb)
	{
		size = ft_lstsize(*lstb);
		i = 0;
		while (i++ < size)
			pa(lstb, lsta);
	}
	free(tab);
}
