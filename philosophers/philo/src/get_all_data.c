/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:29:29 by meudier           #+#    #+#             */
/*   Updated: 2022/06/09 15:35:14 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_philos(int num_of_philos, t_philo ***philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
	{
		(*philos)[i] = malloc(sizeof(t_philo));
		if (!(*philos)[i])
			return (free_tab((void **)*philos));
		(*philos)[i]->num = i + 1;
		(*philos)[i]->nb = num_of_philos;
		(*philos)[i]->print = data->print;
		(*philos)[i]->state.die = data->die;
		gettimeofday(&(*philos)[i]->time.start, NULL);
		(*philos)[i]->time.die = ft_atoi(data->av[2]);
		(*philos)[i]->time.eat = ft_atoi(data->av[3]);
		(*philos)[i]->time.last_meal = 0;
		(*philos)[i]->time.sleep = ft_atoi(data->av[4]);
		(*philos)[i]->forks = *data->forks;
		if (data->ac == 6)
			(*philos)[i]->num_of_meal = ft_atoi(data->av[5]);
		else
			(*philos)[i]->num_of_meal = 0;
		i++;
	}
	return (1);
}

int	get_philos_and_forks(t_philo ***philos, \
pthread_mutex_t **forks, t_data *data)
{
	int	num_of_philos;
	int	i;

	num_of_philos = ft_atoi(data->av[1]);
	*forks = malloc(sizeof(pthread_mutex_t) * num_of_philos);
	if (!*forks)
		return (1);
	i = 0;
	*data->die = 0;
	data->forks = forks;
	while (i < num_of_philos)
	{
		pthread_mutex_init(*forks + i, NULL);
		i++;
	}
	*philos = malloc(sizeof(t_philo *) * (num_of_philos + 1));
	if (!*philos)
		return (2);
	(*philos)[num_of_philos] = NULL;
	get_philos(num_of_philos, philos, data);
	return (0);
}
