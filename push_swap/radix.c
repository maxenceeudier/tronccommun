/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:01:54 by meudier           #+#    #+#             */
/*   Updated: 2022/05/12 11:15:06 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	is_all_zero(t_list *lst, int j)
{
	while (lst)
	{
		if ((lst->data % (10 * j)) / j != 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	radix_a(t_list **lsta, t_list **lstb, int j)
{
	int	i;
	int	k;

	i = 0;
	while (i <= 9 && !lst_is_croissant(*lsta))
	{
		while (equal_to_i_exist(*lsta, i, j)
			&& !lst_is_croissant(*lsta))
		{
			if (is_the_smallest(*lsta, i, j, (*lsta)->data))
				pb (lsta, lstb);
			else
			{
				k = fast_way_to_smallest(*lsta, i, j);
				if (k >= 0)
				{
					while (k > 0)
					{
						ra(lsta);
						k--;
					}
				}
				else
				{
					while (k < 0)
					{
						rra(lsta);
						k++;
					}
				}
			}
		}
		i++;
	}
	if (!lst_is_croissant(*lsta))
		sa(lsta);
}

void	radix_b(t_list **lsta, t_list **lstb, int j)
{
	int	i;
	int	k;

	i = 0;
	while (i <= 9 && *lstb && !lst_is_decroissant(*lstb))
	{
		while (equal_to_i_exist(*lstb, i, j)
			&& *lstb && !(lst_is_decroissant(*lstb)))
		{
			if (is_the_bigger(*lstb, i, j, (*lstb)->data))
				pa(lstb, lsta);
			else
			{
				k = fast_way_to_bigger(*lstb, i, j);
				if (k >= 0)
				{
					while (k > 0)
					{
						rb(lstb);
						k--;
					}
				}
				else
				{
					while (k < 0)
					{
						rrb(lstb);
						k++;
					}
				}
			}
		}
		i++;
	}
	i = ft_lstsize(*lstb);
	if (*lstb && lst_is_decroissant(*lstb))
	{
		while (i >= 0)
		{
			pa(lstb, lsta);
			i--;
		}
	}
}

void	radix(t_list **lsta, t_list **lstb)
{
	int		j;

	j = 1;
	while (!(*lsta && is_all_zero(*lsta, j)
			&& lst_is_croissant(*lsta) && !*lstb) && j < 10000000)
	{
		radix_a (lsta, lstb, j);
		j *= 10;
		radix_b (lsta, lstb, j);
		j *= 10;
	}
}
