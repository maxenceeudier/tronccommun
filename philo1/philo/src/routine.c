/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:35:37 by meudier           #+#    #+#             */
/*   Updated: 2022/06/12 19:16:57 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eat_even(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_data->forks[philo->num % philo->philo_data->nb]);
	if (!print_msg(philo, "has taken a fork", 0))
		return (0);
	pthread_mutex_lock(&philo->philo_data->forks[philo->num - 1]);
	if (!print_msg(philo, "has taken a fork", 0))
		return (0);
	if (!print_msg(philo, "is eating", 1))
		return (0);
	if (!wait(philo->philo_data->time.eat, philo))
		return (0);
	pthread_mutex_unlock(&philo->philo_data->forks[philo->num % philo->philo_data->nb]);
	pthread_mutex_unlock(&philo->philo_data->forks[philo->num - 1]);
	return (1);
}

int	eat_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_data->forks[philo->num - 1]);
	if (!print_msg(philo, "has taken a fork", 0))
		return (0);
	if (philo->philo_data->nb != 1)
	{
		pthread_mutex_lock(&philo->philo_data->forks[philo->num % philo->philo_data->nb]);
		if (!print_msg(philo, "has taken a fork", 0))
			return (0);
		if (!print_msg(philo, "is eating", 1))
			return (0);
		if (!wait(philo->philo_data->time.eat, philo))
			return (0);
		pthread_mutex_unlock(&philo->philo_data->forks[philo->num - 1]);
		pthread_mutex_unlock(&philo->philo_data->forks[philo->num % philo->philo_data->nb]);
	}
	else
	{
		usleep((philo->philo_data->time.die) * 1000);
		return (0);
	}
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	if (philo->philo_data->nb_of_meal)
		i = 0;
	else
		i = -1;
	if (philo->num % 2 == 0)
		usleep(15000);
	while (i < philo->philo_data->nb_of_meal && !philo->philo_data->die)
	{
		if (!(philo->num % 2 == 0 || philo->num == philo->philo_data->nb))
		{
			if (!eat_even(philo))
				return (NULL);
		}	
		else
		{
			if (!eat_odd(philo))
				return (NULL);
		}
		if (!print_msg(philo, "is sleeping", 0))
			return (NULL);
		if (!wait(philo->philo_data->time.sleep, philo))
			return (NULL);
		if (!print_msg(philo, "is thinking", 0))
			return (NULL);
		usleep(2000);
		if (philo->philo_data->nb_of_meal > 0)
			i++;
	}
	return (NULL);
}
