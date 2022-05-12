/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_ps_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:31:30 by meudier           #+#    #+#             */
/*   Updated: 2022/05/12 09:26:02 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	pb(t_list **lsta, t_list **lstb)
{
	lst_push(lsta, lstb);
	write (1, "pb\n", 3);
}

void	rb(t_list **lstb)
{
	lst_rotate(lstb);
	write (1, "rb\n", 3);
}

void	rrb(t_list **lstb)
{
	lst_rotate_rev(lstb);
	write (1, "rrb\n", 4);
}

void	sb(t_list **lstb)
{
	lst_swap(lstb);
	write (1, "sb\n", 3);
}

void	ss(t_list **lsta, t_list **lstb)
{
	lst_swap(lstb);
	lst_swap(lsta);
	write (1, "ss\n", 3);
}
