/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:17:29 by meudier           #+#    #+#             */
/*   Updated: 2022/06/12 18:53:16 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	create_thread(t_philo_data *philo_data, pthread_t *checker)
{
	int			i;
	
	i = 0;
	pthread_create(checker, NULL, &check, philo_data->philos);
	while (i < philo_data->nb)
	{
		if (pthread_create(&(philo_data->philos[i].thread), NULL, &routine, &philo_data->philos[i]))
			return (error_msg("failed to create thread"));
		i++;
	}
	return (1);
}

int	join_tread(t_philo_data *philo_data, pthread_t checker)
{
	int	i;

	i = 0;
	while (i < philo_data->nb)
	{
		if (pthread_join(philo_data->philos[i].thread, NULL))
			return (0);
		i++;
	}
	pthread_join(checker, NULL);
	i = 0;
	while (i < philo_data->nb)
		pthread_mutex_destroy(philo_data->forks + i++);
	return (1);
}
