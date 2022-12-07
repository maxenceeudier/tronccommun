/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_ck_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:29:14 by meudier           #+#    #+#             */
/*   Updated: 2022/05/18 12:27:22 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_lst_swap(char *rule, t_list **lsta, t_list **lstb)
{
	if (rule[1] == 'a' && !rule[2])
		lst_swap(lsta);
	else if (rule[1] == 'b' && !rule[2])
		lst_swap(lstb);
	else if (rule[1] == 's' && !rule[2])
	{
		lst_swap(lstb);
		lst_swap(lsta);
	}
	else
		return (0);
	return (1);
}

int	ft_lst_rotate(char *rule, t_list **lsta, t_list **lstb)
{
	if (rule[1] == 'a' && !rule[2])
		lst_rotate(lsta);
	else if (rule[1] == 'b' && !rule[2])
		lst_rotate(lstb);
	else if (rule[1] == 'r' && !rule[2])
	{
		lst_rotate(lstb);
		lst_rotate(lsta);
	}
	else if (rule[1] == 'r' && rule[2] == 'a' && !rule[3])
		lst_rotate_rev(lsta);
	else if (rule[1] == 'r' && rule[2] == 'b' && !rule[3])
		lst_rotate_rev(lstb);
	else if (rule[1] == 'r' && rule[2] == 'r' && !rule[3])
	{
		lst_rotate_rev(lstb);
		lst_rotate_rev(lsta);
	}
	else
		return (0);
	return (1);
}

int	ft_lst_push(char *rule, t_list **lsta, t_list **lstb)
{
	if (rule[1] == 'a' && !rule[2])
		lst_push(lstb, lsta);
	else if (rule[1] == 'b' && !rule[2])
		lst_push(lsta, lstb);
	else
		return (0);
	return (1);
}

int	appli_rules(char **rules, t_list **lsta, t_list **lstb)
{
	int	i;

	i = 0;
	if (!rules || !lsta)
		return (0);
	while (rules[i])
	{
		if (rules[i][0] == 's')
			if (!ft_lst_swap(rules[i], lsta, lstb))
				return (0);
		if (rules[i][0] == 'r')
			if (!ft_lst_rotate(rules[i], lsta, lstb))
				return (0);
		if (rules[i][0] == 'p')
			if (!ft_lst_push(rules[i], lsta, lstb))
				return (0);
		if (rules[i][0] != 'p' && rules[i][0] != 'r'
				&& rules[i][0] != 's')
			return (0);
		i++;
	}
	return (1);
}
