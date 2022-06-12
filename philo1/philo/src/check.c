/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:27:35 by meudier           #+#    #+#             */
/*   Updated: 2022/06/12 19:05:20 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*check(void *arg)
{
	t_philo	*philos;
	int		i;
	int		nb_of_philos;
	int		all_ate;

	philos = ((t_philo *)arg);
	nb_of_philos = philos[0].philo_data->nb;
	while (1)
	{	
		i = 0;
		while (i < nb_of_philos)
		{
			pthread_mutex_lock(&philos[i].philo_data->check_meal);
			if (get_timestamp(&philos[i]) - \
			philos[i].last_meal >= philos[i].philo_data->time.die || philos[i].philo_data->die)
			{
				if (!philos[i].philo_data->nb_of_meal || philos[i].num_of_meal != philos[i].philo_data->nb_of_meal)
				{
					//*philos[i]->state.die = 1;
					pthread_mutex_unlock(&philos[i].philo_data->check_meal);
					print_msg(&philos[i], "", 2);
					return (NULL);
				}
				
				pthread_mutex_unlock(&philos[i].philo_data->check_meal);
				return (NULL);
			}
			if (philos[i].num_of_meal == philos[i].philo_data->nb_of_meal)
			{
				all_ate++;
			}
			if (all_ate == nb_of_philos)
			{
				pthread_mutex_unlock(&philos[i].philo_data->check_meal);
				return (NULL);
			}
			pthread_mutex_unlock(&philos[i].philo_data->check_meal);
			usleep(100);
			i++;
		}
	}
	return (NULL);
}
