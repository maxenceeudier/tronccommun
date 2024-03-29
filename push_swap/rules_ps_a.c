/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_ps_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:30:38 by meudier           #+#    #+#             */
/*   Updated: 2022/05/17 16:52:12 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	pa(t_list **lstb, t_list **lsta)
{
	lst_push(lstb, lsta);
	write (1, "pa\n", 3);
}

void	ra(t_list **lsta)
{
	lst_rotate(lsta);
	write (1, "ra\n", 3);
}

void	rra(t_list **lsta)
{
	lst_rotate_rev(lsta);
	write (1, "rra\n", 4);
}

void	sa(t_list **lsta)
{
	lst_swap(lsta);
	write (1, "sa\n", 3);
}
