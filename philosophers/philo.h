/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:07:51 by bde-albu          #+#    #+#             */
/*   Updated: 2025/05/23 15:11:06 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <sys/time.h>

typedef struct s_fork
{
    pthread_mutex_t left;
    pthread_mutex_t *right;
} t_fork;

typedef struct s_params
{
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_philosophers;
    int number_of_times_must_eat;
} t_params;

typedef struct s_global
{
    pthread_mutex_t update_time_mutex;
    pthread_mutex_t watchdog_mutex;
    pthread_mutex_t print_mutex;
    int watchdog;
} t_global;

typedef struct s_philo
{
    pthread_mutex_t *update_time_mutex;
    pthread_mutex_t *watchdog_mutex;
    pthread_mutex_t *print_mutex;
    pthread_t pthread;
    t_fork fork;
    long update_time;
    int *watchdog;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int philopher;
    int times_must_eat;
} t_philo;

typedef struct s_simulation
{
    pthread_t pthread;
    pthread_mutex_t *update_time_mutex;
    pthread_mutex_t *print_mutex;
    pthread_mutex_t *watchdog_mutex;
    t_philo *philos;
    int size;
    int *watchdog;
} t_simulation;

void *ft_memset(void *str, int c, size_t n);
int ft_atoi(const char *nptr);

#endif