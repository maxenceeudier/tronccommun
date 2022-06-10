/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:29:29 by meudier           #+#    #+#             */
/*   Updated: 2022/06/10 16:07:35 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	get_one_philo(t_philo *philo, t_data *data, int i, int nb_of_philos)
{
	philo->num = i + 1;
	philo->nb = nb_of_philos;
	philo->print = data->print;
	philo->state.die = data->die;
	gettimeofday(&philo->time.start, NULL);
	philo->time.die = ft_atoi(data->av[2]);
	philo->time.eat = ft_atoi(data->av[3]);
	philo->time.last_meal = 0;
	philo->time.sleep = ft_atoi(data->av[4]);
	philo->forks = *data->forks;
	philo->num_of_meal = 0;
	if (data->ac == 6)
		philo->nb_of_meal = ft_atoi(data->av[5]);
	else
		philo->nb_of_meal = 0;
}

int	get_philos(int nb_of_philos, t_philo ***philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < nb_of_philos)
	{
		(*philos)[i] = malloc(sizeof(t_philo));
		if (!(*philos)[i])
			return (free_tab((void **)*philos));
		get_one_philo((*philos)[i], data, i, nb_of_philos);
		i++;
	}
	return (1);
}

int	get_philos_and_forks(t_philo ***philos, \
pthread_mutex_t **forks, t_data *data)
{
	int	nb_of_philos;
	int	i;

	nb_of_philos = ft_atoi(data->av[1]);
	*forks = malloc(sizeof(pthread_mutex_t) * nb_of_philos);
	if (!*forks)
		return (1);
	i = 0;
	*data->die = 0;
	data->forks = forks;
	while (i < nb_of_philos)
	{
		pthread_mutex_init(*forks + i, NULL);
		i++;
	}
	*philos = malloc(sizeof(t_philo *) * (nb_of_philos + 1));
	if (!*philos)
		return (2);
	(*philos)[nb_of_philos] = NULL;
	get_philos(nb_of_philos, philos, data);
	return (0);
}
