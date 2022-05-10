/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rules_ck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:40:04 by meudier           #+#    #+#             */
/*   Updated: 2022/05/10 16:50:06 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#define BUFFER_SIZE 100096

char	**get_rules(void)
{
	char	**rules;
	char	buffer[BUFFER_SIZE];
	int		rtr;
	int		i;

	rtr = read (0, buffer, 1);
	i = 0;
	while (rtr > 0 && i < BUFFER_SIZE)
	{
		i++;
		rtr = read (0, buffer + i, 1);
	}
	buffer[i] = 0;
	rules = ft_split(buffer, '\n');
	return (rules);
}
