/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:43:38 by bde-albu          #+#    #+#             */
/*   Updated: 2025/05/26 17:17:50 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdlib.h>

static void	set(t_philo *philos, t_params settings, t_global *global, int i)
{
	ft_memset(&philos[i], 0, sizeof(t_philo));
	pthread_mutex_init(&philos[i].fork.left, NULL);
	pthread_mutex_init(&philos[i].update_time_mutex, NULL);
	pthread_mutex_init(&philos[i].watchdog_mutex, NULL);
	philos[i].philosopher = i + 1;
	philos[i].watchdog = &global->watchdog;
	philos[i].print_mutex = &global->print_mutex;
	philos[i].time_to_die = settings.time_to_die;
	philos[i].time_to_eat = settings.time_to_eat;
	philos[i].time_to_sleep = settings.time_to_sleep;
	philos[i].times_must_eat = settings.number_of_times_must_eat;
	philos[i].update_time = get_time_in_ms();
}

t_philo	*set_philosopher(t_params s, t_global *global)
{
	t_philo	*philos;
	int		index;

	index = 0;
	philos = malloc(s.number_of_philosophers * sizeof(t_philo));
	if (philos == NULL)
		return (NULL);
	while (index < s.number_of_philosophers)
	{
		set(philos, s, global, index);
		index++;
	}
	return (philos);
}
