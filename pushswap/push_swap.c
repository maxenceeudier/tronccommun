/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 08:18:25 by meudier           #+#    #+#             */
/*   Updated: 2022/05/17 16:23:02 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	super_short(t_list **lsta)
{
	while (!lst_is_croissant(*lsta))
	{
		if ((*lsta)->next && (*lsta)->data > (*lsta)->next->data)
			sa(lsta);
		else
			rra(lsta);
	}
}

void	sort_medium_and_big(t_list **lsta, t_list **lstb)
{
	q_sort_a(lsta, lstb);
	q_sort_bb(lsta, lstb);
	q_sort_a(lsta, lstb);
	q_sort_b(lsta, lstb);
}

int	main(int ac, char **av)
{
	t_list	*lsta;
	t_list	*lstb;
	int		len;

	lstb = NULL;
	lsta = init_list(ac, av);
	if (!lsta || !check_doublon(lsta))
	{
		if (ac > 1)
			write (2, "Error\n", 6);
		clear (&lsta, &lstb, NULL);
		return (0);
	}
	len = ft_lstsize(lsta);
	if (len <= 3)
		super_short(&lsta);
	else if (len <= 10)
		sort_short(&lsta, &lstb);
	else
		sort_medium_and_big(&lsta, &lstb);
	clear(&lsta, &lstb, NULL);
	return (0);
}

/*
 ***-----affiche les stacks -----***
 radix(&lsta, &lstb);
 t_list *lst_a = lsta;
 while (lst_a)
 {
 printf("%d\n", lst_a->data);
 lst_a = lst_a->next;
 }
 printf("\n-------\n");
 t_list *lst_b = lstb;
 while (lst_b)
 {
 printf("%d\n", lst_b->data);
 lst_b = lst_b->next;
 }
 */
