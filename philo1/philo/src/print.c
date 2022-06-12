/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:37:17 by meudier           #+#    #+#             */
/*   Updated: 2022/06/12 19:19:00 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	print_msg(t_philo *philo, char *str, int state)
{
	int				timestamp;

	pthread_mutex_lock(&philo->philo_data->print);
	timestamp = get_timestamp(philo);
	
	if (philo->philo_data->die && state != 2)
	{
		pthread_mutex_unlock(&philo->philo_data->print);
		return (0);
	}
	if (state != 2)
	{
		printf(" %d %d %s\n", timestamp, philo->num, str);
	}
	if (state == 1)
	{
		pthread_mutex_lock(&philo->philo_data->check_meal);
		philo->last_meal = timestamp;
		philo->num_of_meal++;
		pthread_mutex_unlock(&philo->philo_data->check_meal);
	}
	if (state == 2)
	{
		philo->philo_data->die = 1;
		printf(" %d %d %s\n", timestamp, philo->num, "died");
		pthread_mutex_unlock(&philo->philo_data->print);
		return (0);
	}
	pthread_mutex_unlock(&philo->philo_data->print);
	return (1);
}
