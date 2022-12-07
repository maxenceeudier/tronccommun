/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:05:17 by meudier           #+#    #+#             */
/*   Updated: 2022/06/13 16:18:18 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	get_data(t_philo_data *philo_data, int ac, char **av)
{
	if (ac == 6)
		philo_data->nb_of_meal = (int)ft_atoi(av[5]);
	else
		philo_data->nb_of_meal = 0;
	philo_data->die = 0;
	philo_data->nb = ft_atoi(av[1]);
	gettimeofday(&philo_data->time.start, NULL);
	philo_data->time.eat = (int)ft_atoi(av[3]);
	philo_data->time.sleep = (int)ft_atoi(av[4]);
	philo_data->time.die = (int)ft_atoi(av[2]);
}

int	error_msg(char *str)
{
	write (2, str, 19);
	return (1);
}

int	check_error(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) < 0 || !ft_isdigit(av[i]))
			return (0);
		if (i == 1 && ft_atoi(av[i]) == 0)
			return (0);
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philo_data	philo_data;
	pthread_t		checker;

	if ((ac != 5 && ac != 6) || !check_error(ac, av))
		return (error_msg("Error: wrong args.\n"));
	pthread_mutex_init(&philo_data.print, NULL);
	pthread_mutex_init(&philo_data.check_meal, NULL);
	get_data(&philo_data, ac, av);
	get_philos_and_forks(&philo_data);
	create_thread(&philo_data, &checker);
	join_tread(&philo_data, checker);
	pthread_mutex_destroy(&philo_data.print);
	pthread_mutex_destroy(&philo_data.check_meal);
	free(philo_data.philos);
	free(philo_data.forks);
	return (0);
}
