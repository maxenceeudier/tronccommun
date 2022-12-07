/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:42:55 by meudier           #+#    #+#             */
/*   Updated: 2022/05/25 14:49:29 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	door_is_close(char *str)
{
	char	*door;
	int		i;

	i = 0;
	door = "./img/door.xpm";
	while (str[i] == door[i])
	{
		if (str[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_rip(char *str)
{
	char	*rip;
	int		i;

	i = 0;
	rip = "./img/rip.xpm";
	while (str[i] == rip[i])
	{
		if (str[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

int	line_is_first(char *str)
{
	int		i;
	char	*first;

	i = 0;
	first = "first";
	while (str[i] == first[i])
	{
		if (str[i] == 0)
			return (1);
		i++;
	}
	return (0);
}
