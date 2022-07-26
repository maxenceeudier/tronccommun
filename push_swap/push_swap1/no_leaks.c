/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_leaks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:57:42 by meudier           #+#    #+#             */
/*   Updated: 2022/05/18 13:39:50 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	*clear(t_list **lsta, t_list **lstb, char **rules)
{
	int	i;

	if (rules)
	{
		i = 0;
		while (rules[i])
			free(rules[i++]);
		free(rules);
	}
	if (*lsta)
		ft_lstclear(lsta, &del);
	if (*lstb)
		ft_lstclear(lstb, &del);
	return (NULL);
}

void	del(int *data)
{
	*data = 0;
}

void	*ft_lstclear(t_list **lst, void (*del)(int *))
{
	t_list	*temp;

	if (!del || !lst)
		return (NULL);
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		(*del)(&(temp->data));
		free(temp);
	}
	return (NULL);
}

void	*clear_tab(char **str)
{
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

void	*free_all_alloc(t_list **lst, char **tab)
{
	ft_lstclear(lst, &del);
	clear_tab(tab);
	return (NULL);
}
