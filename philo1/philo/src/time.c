/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:30:36 by meudier           #+#    #+#             */
/*   Updated: 2022/06/12 17:36:27 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_timestamp(t_philo *philo)
{
	int				now;
	int				start;
	int				m;
	struct timeval	time;

	m = 1000;
	gettimeofday(&time, NULL);
	now = (int)(time.tv_sec * m + time.tv_usec / m);
	start = (int)(philo->philo_data->time.start.tv_sec * m + philo->philo_data->time.start.tv_usec / m);
	return (now - start);
}

int	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((int)time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	wait(int time, t_philo *philo)
{
	int	i;

	i = timestamp();
	while (!philo->philo_data->die)
	{
		if (timestamp() - i >= time)
			return (1);
		usleep(100);
	}
	return (1);
}
