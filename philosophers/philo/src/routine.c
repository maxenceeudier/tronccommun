/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:35:37 by meudier           #+#    #+#             */
/*   Updated: 2022/06/09 15:36:22 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat_even(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->num % philo->nb]);
	print_msg(philo, "has taken a fork", 0);
	pthread_mutex_lock(&philo->forks[philo->num - 1]);
	print_msg(philo, "has taken a fork", 1);
	print_msg(philo, "is eating", 0);
	wait(philo->time.eat, philo);
	pthread_mutex_unlock(&philo->forks[philo->num % philo->nb]);
	pthread_mutex_unlock(&philo->forks[philo->num - 1]);
}

void	eat_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->num - 1]);
	print_msg(philo, "has taken a fork", 0);
	pthread_mutex_lock(&philo->forks[philo->num % philo->nb]);
	print_msg(philo, "has taken a fork", 1);
	print_msg(philo, "is eating", 0);
	wait(philo->time.eat, philo);
	pthread_mutex_unlock(&philo->forks[philo->num - 1]);
	pthread_mutex_unlock(&philo->forks[philo->num % philo->nb]);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	if (philo->num_of_meal)
		i = 0;
	else
		i = -1;
	if (philo->num % 2 == 0)
		usleep(1000);
	while (1 && i < philo->num_of_meal && !*(philo->state.die))
	{
		if (!(philo->num % 2 == 0 || philo->num == philo->nb))
			eat_even(philo);
		else
			eat_odd(philo);
		print_msg(philo, "is sleeping", 1);
		wait(philo->time.sleep, philo);
		print_msg(philo, "is thinking", 0);
		usleep(1000);
		if (philo->num_of_meal)
			i++;
	}
	return (NULL);
}
