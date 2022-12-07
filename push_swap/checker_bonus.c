/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:39:42 by meudier           #+#    #+#             */
/*   Updated: 2022/05/17 14:38:47 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	check(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	error(int ac, t_list **lsta, t_list **lstb)
{
	clear(lsta, lstb, NULL);
	if (ac > 1)
		write (2, "Error\n", 6);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*lsta;
	t_list	*lstb;
	char	**rules;

	lstb = NULL;
	lsta = init_list(ac, av);
	if (!lsta || !check_doublon(lsta))
		return (error(ac, &lsta, &lstb));
	rules = get_rules();
	if (!rules || !appli_rules(rules, &lsta, &lstb))
		return (error(ac, &lsta, &lstb));
	if (check(lsta) && !lstb)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	clear(&lsta, &lstb, rules);
	return (1);
}
