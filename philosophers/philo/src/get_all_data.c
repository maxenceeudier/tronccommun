/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:29:29 by meudier           #+#    #+#             */
/*   Updated: 2022/06/13 16:20:11 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_philos(t_philo_data *philo_data)
{
	int	i;

	i = 0;
	while (i < philo_data->nb)
	{
		philo_data->philos[i].num = i + 1;
		philo_data->philos[i].last_meal = 0;
		philo_data->philos[i].num_of_meal = 0;
		philo_data->philos[i].philo_data = philo_data;
		i++;
	}
	return (1);
}

int	get_philos_and_forks(t_philo_data *philo_data)
{
	int	nb_of_philos;
	int	i;

	nb_of_philos = philo_data->nb;
	philo_data->forks = malloc(sizeof(pthread_mutex_t) * nb_of_philos);
	if (!philo_data->forks)
		return (1);
	i = 0;
	while (i < nb_of_philos)
	{
		pthread_mutex_init(philo_data->forks + i, NULL);
		i++;
	}
	philo_data->philos = malloc(sizeof(t_philo) * (nb_of_philos));
	if (!philo_data->philos)
		return (2);
	init_philos(philo_data);
	return (0);
}
