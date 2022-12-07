/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:53:58 by meudier           #+#    #+#             */
/*   Updated: 2022/05/18 13:41:27 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*create_elem(int data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

int	push_back(t_list **lst, int data)
{
	t_list	*last;

	last = *lst;
	while (last->next)
		last = last->next;
	last->next = create_elem(data);
	if (!last->next)
		return (0);
	return (1);
}

static void	*get_lst(int ac, char *num, int *index, t_list **lst)
{
	int			i;
	long long	nbr;

	nbr = ft_atoi(num);
	if (nbr < -2147483648 || nbr > 2147483647)
		return (NULL);
	if (ac > 2)
		i = 1;
	else
		i = 0;
	if (*index == i)
	{
		*lst = create_elem((int)nbr);
		if (!*lst)
			return (NULL);
	}
	else
		if (!push_back(lst, (int)nbr))
			return (NULL);
	(*index)++;
	return ("ok");
}

void	*get_lst_when_string(t_list **lst, char **av, int ac)
{
	char	**tab_value;
	int		i;

	i = 0;
	tab_value = ft_split(av[1], ' ');
	if (!tab_value)
		return (NULL);
	i = 0;
	while (tab_value[i])
		if (!ft_isdigit(tab_value[i])
			|| !get_lst(ac, tab_value[i], &i, lst))
			return (free_all_alloc(lst, tab_value));
	clear_tab(tab_value);
	return ("ok");
}

t_list	*init_list(int ac, char **av)
{
	int		i;
	t_list	*lst;

	lst = NULL;
	if (ac > 2)
	{
		i = 1;
		while (i < ac)
			if (!ft_isdigit(av[i]) || !get_lst(ac, av[i], &i, &lst))
				return (ft_lstclear(&lst, &del));
		return (lst);
	}
	if (ac == 2)
	{
		if (!get_lst_when_string(&lst, av, ac))
			return (NULL);
		return (lst);
	}
	return (NULL);
}
