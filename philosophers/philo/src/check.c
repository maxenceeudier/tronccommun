/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:27:35 by meudier           #+#    #+#             */
/*   Updated: 2022/06/10 16:15:34 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*check(void *arg)
{
	t_philo	**philos;
	int		i;

	philos = ((t_check *)arg)->philos;
	while (!*philos[0]->state.die)
	{
		i = 0;
		while (philos[i])
		{
			if (get_timestamp(philos[0]) - \
			philos[i]->time.last_meal >= philos[i]->time.die)
			{
				if (!philos[0]->nb_of_meal
					|| philos[i]->num_of_meal != philos[i]->nb_of_meal)
				{
					*philos[i]->state.die = 1;
					print_msg(philos[i], "is ded", 2);
				}
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
