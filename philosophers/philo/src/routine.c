/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:35:37 by meudier           #+#    #+#             */
/*   Updated: 2022/06/13 17:40:04 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eat_even(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_data->\
	forks[philo->num % philo->philo_data->nb]);
	if (print_msg(philo, "has taken a fork", 0))
	{
		pthread_mutex_lock(&philo->philo_data->forks[philo->num - 1]);
		print_msg(philo, "has taken a fork", 0);
		print_msg(philo, "is eating", 1);
		wait(philo->philo_data->time.eat, philo);
		pthread_mutex_unlock(&philo->philo_data->\
		forks[philo->num % philo->philo_data->nb]);
		pthread_mutex_unlock(&philo->philo_data->forks[philo->num - 1]);
	}
	else
	{
		pthread_mutex_unlock(&philo->philo_data->\
		forks[philo->num % philo->philo_data->nb]);
		return (0);
	}
	return (1);
}

int	eat_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_data->forks[philo->num - 1]);
	if (print_msg(philo, "has taken a fork", 0)
		&& philo->philo_data->nb != 1)
	{
		pthread_mutex_lock(&philo->philo_data->\
		forks[philo->num % philo->philo_data->nb]);
		print_msg(philo, "has taken a fork", 0);
		print_msg(philo, "is eating", 1);
		wait(philo->philo_data->time.eat, philo);
		pthread_mutex_unlock(&philo->philo_data->forks[philo->num - 1]);
		pthread_mutex_unlock(&philo->philo_data->\
		forks[philo->num % philo->philo_data->nb]);
	}
	else
	{
		pthread_mutex_unlock(&philo->philo_data->forks[philo->num - 1]);
		return (0);
	}
	return (1);
}

void	sieste_digestive(t_philo *philo)
{
	print_msg(philo, "is sleeping", 0);
	wait(philo->philo_data->time.sleep, philo);
	print_msg(philo, "is thinking", 0);
	usleep(2000);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	i = 0;
	if (philo->num % 2 == 0)
		usleep(15000);
	while (i <= philo->philo_data->nb_of_meal && !philo->philo_data->die)
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
		sieste_digestive(philo);
		if (philo->philo_data->nb_of_meal)
			i++;
	}
	return (NULL);
}
