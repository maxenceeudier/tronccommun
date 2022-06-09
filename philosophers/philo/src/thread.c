/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:17:29 by meudier           #+#    #+#             */
/*   Updated: 2022/06/09 16:22:42 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	create_thread(t_philo **philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_create(&(philos[i]->thread), NULL, &routine, philos[i]))
			return (error_msg("failed to create thread"));
		i++;
	}
	return (1);
}

int	join_tread(t_philo **philos, t_data *data, pthread_mutex_t	*forks)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_join(philos[i]->thread, NULL))
			return (0);
		pthread_mutex_destroy(forks + i);
		i++;
	}
	return (1);
}
