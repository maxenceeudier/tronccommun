/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:17:28 by meudier           #+#    #+#             */
/*   Updated: 2022/06/13 16:20:50 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

struct	s_rules;

typedef struct s_time
{
	int				die;
	struct timeval	start;
	int				eat;
	int				sleep;
}	t_time;

typedef struct s_philo
{
	int					num;
	int					num_of_meal;
	int					last_meal;
	pthread_t			thread;
	struct s_philo_data	*philo_data;
}	t_philo;

typedef struct s_philo_data
{
	int				nb_of_meal;
	int				die;
	int				nb;
	t_time			time;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	check_meal;
	t_philo			*philos;
}	t_philo_data;

typedef struct s_check
{
	t_philo	*philos;
}	t_check;

int			free_tab(void **tab);
long long	ft_atoi(const char *str);
int			get_timestamp(t_philo *philo);
int			timestamp(void);
int			wait(int time, t_philo *philo);
int			get_philos_and_forks(t_philo_data *data);
void		*routine(void *arg);
int			print_msg(t_philo *philo, char *str, int state);
int			create_thread(t_philo_data *philo_data, pthread_t *checker);
int			join_tread(t_philo_data *philo_data, pthread_t checker);
int			error_msg(char *str);
void		*check(void *arg);
int			ft_isdigit(char *str);

#endif
