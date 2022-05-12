/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 08:18:25 by meudier           #+#    #+#             */
/*   Updated: 2022/05/12 16:01:34 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	main(int ac, char **av)
{
	t_list	*lsta;
	t_list	*lstb;
	int		len;

	lstb = NULL;
	lsta = init_list(ac, av);
	len = ft_lstsize(lsta);
	if (!lsta)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	if (len <= 10)
		sort_short(&lsta, &lstb);
	else
	{
		q_sort_a(&lsta, &lstb);
		q_sort_bb(&lsta, &lstb);
		q_sort_a(&lsta, &lstb);
		q_sort_b(&lsta, &lstb);
	}
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