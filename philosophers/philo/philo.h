/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:17:28 by meudier           #+#    #+#             */
/*   Updated: 2022/06/09 16:19:34 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_state
{
	int	*die;
}	t_state;

typedef struct s_time
{
	int				last_meal;
	int				die;
	struct timeval	start;
	int				eat;
	int				sleep;
}	t_time;

typedef struct s_philo
{
	int				num;
	t_state			state;
	t_time			time;
	int				num_of_meal;
	int				nb;
	pthread_t		thread;
	pthread_mutex_t	*print;
	pthread_mutex_t	*forks;
}	t_philo;

typedef struct s_data
{
	int				*die;
	char			**av;
	int				ac;
	int				num_of_philos;
	pthread_mutex_t	*print;
	pthread_mutex_t	**forks;
}	t_data;

int		free_tab(void **tab);
int		ft_atoi(const char *str);
int		get_timestamp(t_philo *philo);
int		timestamp(void);
void	wait(int time, t_philo *philo);
int		get_philos_and_forks(t_philo ***philos, \
pthread_mutex_t **forks, t_data *data);
void	*routine(void *arg);
int		print_msg(t_philo *philo, char *str, int state);
int		create_thread(t_philo **philos, t_data *data);
int		join_tread(t_philo **philos, t_data *data, pthread_mutex_t	*forks);
int		error_msg(char *str);

#endif
