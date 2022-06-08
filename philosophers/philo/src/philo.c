/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:05:17 by meudier           #+#    #+#             */
/*   Updated: 2022/06/08 16:59:04 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int    print_msg(t_philo *philo, char *str, int state)
{
    int timestamp;
    struct timeval time;
    
    pthread_mutex_lock(philo->print);
    gettimeofday(&time, NULL);
    timestamp = (int)((time.tv_sec * 1000 + time.tv_usec / 1000 )
        - (philo->time.start.tv_sec *1000 + philo->time.start.tv_usec / 1000));
    if (*philo->state.die)
    {
        pthread_mutex_unlock(philo->print);
        return (0);
    }
    else
        printf(" %d %d %s\n", timestamp, philo->num, str);
    if (state == 1)
        philo->time.last_meal = timestamp;
    if (timestamp - philo->time.last_meal >= philo->time.die)
    {
        *(philo->state.die) = 1;
        printf(" %d %d %s\n", timestamp, philo->num, "is dead");
        pthread_mutex_unlock(philo->print);
        usleep(1000);
        return (0);
    }
    pthread_mutex_unlock(philo->print);
    usleep(1000);
    return (1);
}

void    *routine(void *arg)
{
    t_philo *philo;
    int     i;

    philo  = (t_philo *)arg;
    if (philo->num_of_meal)
        i = 0;
    else
        i = -1;
    if (philo->num % 2 == 0)
        usleep(10000);
    while (1 && i < philo->num_of_meal && !*(philo->state.die))
    {
        if (philo->num % 2 != 0)
        {
            pthread_mutex_lock(&philo->forks[philo->num % philo->nb]);
            print_msg(philo, "has taken a fork", 0);
            pthread_mutex_lock(&philo->forks[philo->num - 1]);
            print_msg(philo, "has taken a fork", 0);
            print_msg(philo, "is eating", 1);
            usleep(philo->time.eat * 1000);
            pthread_mutex_unlock(&philo->forks[philo->num % philo->nb]);
            pthread_mutex_unlock(&philo->forks[philo->num - 1]);
        }
        else
        {
            pthread_mutex_lock(&philo->forks[philo->num - 1]);
            print_msg(philo, "has taken a fork", 0);
            pthread_mutex_lock(&philo->forks[philo->num % philo->nb]);
            print_msg(philo, "has taken a fork", 0);
            print_msg(philo, "is eating", 1);
            usleep(philo->time.eat * 1000);
            pthread_mutex_unlock(&philo->forks[philo->num - 1]);
            pthread_mutex_unlock(&philo->forks[philo->num % philo->nb]);
        }
        print_msg(philo, "is sleeping", 0);
        usleep(philo->time.sleep * 1000);
        print_msg(philo, "is thinking", 0);
        if (philo->num_of_meal)
            i++;
    }
    return (NULL);
}

int    get_philos_and_forks(t_philo ***philos, pthread_mutex_t **forks, int ac, char **av, pthread_mutex_t *print, int *die)
{
    int num_of_philos;
    int i;

    num_of_philos = ft_atoi(av[1]);
    *forks = malloc(sizeof(pthread_mutex_t) * num_of_philos);
    if (!*forks)
        return (1);
    i = 0;
    *die = 0;
    while (i < num_of_philos)
    {
        pthread_mutex_init(*forks + i, NULL);
        i++;
    }
    *philos = malloc(sizeof(t_philo *) * (num_of_philos + 1));
    if (!*philos)
        return (2);
    (*philos)[num_of_philos] = NULL;
    i = 0;
    while (i < num_of_philos)
    {
        (*philos)[i] = malloc(sizeof(t_philo));
        if (!(*philos)[i])
        {
            free_tab((void **)*philos);
            return (3);
        }
        (*philos)[i]->num = i + 1;
        (*philos)[i]->nb = num_of_philos;
        (*philos)[i]->print = print;
        (*philos)[i]->state.eat = 0;
        (*philos)[i]->state.think = 1;
        (*philos)[i]->state.sleep = 0;
        (*philos)[i]->state.die = die;
        gettimeofday(&(*philos)[i]->time.start, NULL);
        (*philos)[i]->time.die = ft_atoi(av[2]);
        (*philos)[i]->time.eat = ft_atoi(av[3]);
        (*philos)[i]->time.last_meal = 0;
        (*philos)[i]->time.sleep = ft_atoi(av[4]);
        (*philos)[i]->forks = *forks;
        if (ac == 6)
            (*philos)[i]->num_of_meal = ft_atoi(av[5]);
        else
            (*philos)[i]->num_of_meal = 0;
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    t_philo         **philos;
    pthread_mutex_t *forks;
    pthread_mutex_t print;
    int             num_of_philos;
    int             i;
    int             die;

    i = 0;
    if ((ac != 5 && ac != 6))
    {
        printf("Error : wrong num og args\n");
        return (1);
    }
    num_of_philos = ft_atoi(av[1]);
    if (num_of_philos < 2)
    {
        printf("the philosophers must be two to eat");
        return (0);
    }
    pthread_mutex_init(&print, NULL);
    get_philos_and_forks(&philos, &forks, ac, av, &print, &die);
    while (i < num_of_philos)
    {
        if (pthread_create(&(philos[i]->thread), NULL, &routine, philos[i]))
        {
            printf("Failed to create thread");
            return (2);
        }
        i++;
    }
    i = 0;
    while (i < num_of_philos)
    {
        if (pthread_join(philos[i]->thread, NULL))
            return (3);
        printf("threads %d has finished execution\n", philos[i]->num);
        pthread_mutex_destroy(forks + i);
        i++;
    }
    pthread_mutex_destroy(&print);
    free_tab((void**)philos);
    free(forks);
    return (0);
}