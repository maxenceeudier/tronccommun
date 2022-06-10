/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:37:17 by meudier           #+#    #+#             */
/*   Updated: 2022/06/10 16:12:19 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	print_msg(t_philo *philo, char *str, int state)
{
	int				timestamp;

	timestamp = get_timestamp(philo);
	pthread_mutex_lock(philo->print);
	if (*philo->state.die && state != 2)
	{
		pthread_mutex_unlock(philo->print);
		return (0);
	}
	else if (state != 2)
		printf(" %d %d %s\n", timestamp, philo->num, str);
	if (state == 1)
		philo->time.last_meal = timestamp;
	if (state == 2)
	{
		printf(" %d %d %s\n", timestamp, philo->num, "is dead");
		pthread_mutex_unlock(philo->print);
		return (0);
	}
	pthread_mutex_unlock(philo->print);
	return (1);
}
