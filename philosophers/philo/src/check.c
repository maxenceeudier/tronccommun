/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:27:35 by meudier           #+#    #+#             */
/*   Updated: 2022/06/13 17:18:31 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	*kill_philo(t_philo *philos, int i)
{
	if (!philos[i].philo_data->nb_of_meal
		|| philos[i].num_of_meal != \
		philos[i].philo_data->nb_of_meal)
		print_msg(&philos[i], "", 2);
	pthread_mutex_unlock(&philos[i].philo_data->check_meal);
	return (NULL);
}

void	*check(void *arg)
{
	t_philo	*philos;
	int		i;
	int		nb_of_philos;

	philos = ((t_philo *)arg);
	nb_of_philos = philos[0].philo_data->nb;
	while (1)
	{	
		i = 0;
		while (i < nb_of_philos)
		{
			pthread_mutex_lock(&philos[i].philo_data->check_meal);
			if (get_timestamp(&philos[i]) - \
			philos[i].last_meal >= philos[i].philo_data->time.die)
				return (kill_philo(philos, i));
			pthread_mutex_unlock(&philos[i].philo_data->check_meal);
			usleep(100);
			i++;
		}
	}
	return (NULL);
}
