/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:37:17 by meudier           #+#    #+#             */
/*   Updated: 2022/06/09 15:37:46 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	print_msg(t_philo *philo, char *str, int state)
{
	int				timestamp;

	timestamp = get_timestamp(philo);
	pthread_mutex_lock(philo->print);
	if (*philo->state.die)
	{
		pthread_mutex_unlock(philo->print);
		return (0);
	}
	else
		printf(" %d %d %s\n", timestamp, philo->num, str);
	if (state == 1)
		philo->time.last_meal = timestamp;
	if (timestamp - philo->time.last_meal >= philo->time.die)
	{
		*(philo->state.die) = 1;
		printf(" %d %d %s\n", timestamp, philo->num, "is dead");
		pthread_mutex_unlock(philo->print);
		return (0);
	}
	pthread_mutex_unlock(philo->print);
	return (1);
}
