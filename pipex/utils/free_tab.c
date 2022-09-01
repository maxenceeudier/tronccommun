/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:09:39 by meudier           #+#    #+#             */
/*   Updated: 2022/06/02 09:52:04 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}	
	free(tab);
	return (0);
}

int	free_tab_int(int **tab, int size)
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (i < size)
		free (tab[i++]);
	free(tab);
	return (0);
}
