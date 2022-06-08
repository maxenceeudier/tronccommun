/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:17:28 by meudier           #+#    #+#             */
/*   Updated: 2022/06/08 15:36:33 by meudier          ###   ########.fr       */
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
    int eat;
    int think;
    int sleep;
    int *die;
}   t_state;

typedef struct s_time
{
    int last_meal;
    int die;
    struct timeval start;
    int eat;
    int sleep;
}   t_time;

typedef struct s_philo
{
    int             num;
    t_state         state;
    t_time          time;
    int             num_of_meal;
    int             nb;
    pthread_t       thread;
    pthread_mutex_t *print;
    pthread_mutex_t *forks;
}   t_philo;

int     ft_atoi(const char *str);
void    free_tab(void **tab);

#endif