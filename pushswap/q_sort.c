/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:41:42 by meudier           #+#    #+#             */
/*   Updated: 2022/05/17 16:33:00 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	q_sort_a(t_list **lsta, t_list **lstb)
{
	int	mid;
	int	chunk;

	mid = 0;
	chunk = 0;
	while (*lsta && !lst_is_croissant(*lsta))
	{
		if (!get_mid_and_chunck(*lsta, &mid, &chunk))
			return ;
		while (ft_lstsize(*lstb) != chunk)
		{
			if ((*lsta)->data < mid)
				pb (lsta, lstb);
			else
				ra(lsta);
		}
	}
}

void	q_sort_bb(t_list **lsta, t_list **lstb)
{
	int	mid;
	int	chunk;
	int	size;

	mid = 0;
	size = ft_lstsize(*lstb) / 4;
	chunk = ft_lstsize(*lsta);
	while (ft_lstsize(*lstb) > size && !lst_is_decroissant(*lstb))
	{
		if (!get_mid_and_chunck_b(*lstb, &mid, &chunk))
			return ;
		while (ft_lstsize(*lsta) != chunk)
		{
			if ((*lstb)->data > mid)
				pa (lstb, lsta);
			else
				rb(lstb);
		}
	}
}

void	q_sort_heart(t_list **lsta, t_list **lstb, int x)
{
	int		k;

	while (the_smallest_exist(*lstb, x))
	{
		if ((*lstb)->data == x)
			pa (lstb, lsta);
		else
		{
			k = fast_way_to_smaller(*lstb, x);
			if (k >= 0)
				while (k-- > 0)
					rb(lstb);
			else
				while (k++ < 0)
					rrb(lstb);
		}
	}
}

void	q_sort_b(t_list **lsta, t_list **lstb)
{
	int	*tab;
	int	size;
	int	i;

	get_tab(*lstb, &tab);
	size = ft_lstsize(*lstb);
	i = size - 1;
	while (i >= 0)
	{
		q_sort_heart(lsta, lstb, tab[i]);
		i--;
	}
	free(tab);
}
