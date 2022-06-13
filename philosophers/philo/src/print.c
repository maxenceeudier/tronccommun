/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:37:17 by meudier           #+#    #+#             */
/*   Updated: 2022/06/13 17:06:41 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	update_meal(t_philo *philo, int timestamp)
{
	pthread_mutex_lock(&philo->philo_data->check_meal);
	philo->last_meal = timestamp;
	philo->num_of_meal++;
	pthread_mutex_unlock(&philo->philo_data->check_meal);
	usleep(100);
}

static int	kill_philo(t_philo *philo, int timestamp)
{
	philo->philo_data->die = 1;
	printf(" %d %d %s\n", timestamp, philo->num, "died");
	pthread_mutex_unlock(&philo->philo_data->print);
	return (0);
}

int	print_msg(t_philo *philo, char *str, int state)
{
	int	timestamp;

	pthread_mutex_lock(&philo->philo_data->print);
	timestamp = get_timestamp(philo);
	if (state != 2)
	{
		if ((philo->philo_data->die
				|| (philo->philo_data->nb_of_meal
					&& philo->num_of_meal == \
					philo->philo_data->nb_of_meal)))
		{
			pthread_mutex_unlock(&philo->philo_data->print);
			return (0);
		}
		printf(" %d %d %s\n", timestamp, philo->num, str);
	}
	if (state == 1)
		update_meal(philo, timestamp);
	if (state == 2)
		return (kill_philo(philo, timestamp));
	pthread_mutex_unlock(&philo->philo_data->print);
	return (1);
}
