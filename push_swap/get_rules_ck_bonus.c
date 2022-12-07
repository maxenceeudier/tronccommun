/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rules_ck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:40:04 by meudier           #+#    #+#             */
/*   Updated: 2022/05/17 11:25:03 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#define BUFFER_SIZE 100000

char	**get_rules(void)
{
	char	**rules;
	char	buffer[BUFFER_SIZE];
	int		rtr;
	int		i;

	rtr = read (0, buffer, 1);
	if (rtr == -1)
		return (NULL);
	i = 0;
	while (rtr > 0 && i < BUFFER_SIZE)
	{
		i++;
		rtr = read (0, buffer + i, 1);
		if (rtr == -1)
			return (NULL);
	}
	buffer[i] = 0;
	rules = ft_split(buffer, '\n');
	return (rules);
}
