/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:05:17 by meudier           #+#    #+#             */
/*   Updated: 2022/06/10 16:41:02 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	get_data(t_data *data, int ac, char **av)
{
	data->av = av;
	data->ac = ac;
	data->num_of_philos = ft_atoi(av[1]);
}

int	error_msg(char *str)
{
	printf("Error : %s\n", str);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo			**philos;
	t_data			data;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	int				die;

	data.die = &die;
	data.print = &print;
	get_data(&data, ac, av);
	if ((ac != 5 && ac != 6))
		return (error_msg("wrong num of args"));
	if (data.num_of_philos < 1)
		return (error_msg("the philosophers must be two to eat"));
	pthread_mutex_init(data.print, NULL);
	get_philos_and_forks(&philos, &forks, &data);
	create_thread(philos, &data, &data.nurse);
	join_tread(philos, &data, forks, data.nurse);
	pthread_mutex_destroy(data.print);
	free_tab((void **)philos);
	free(forks);
	return (0);
}
