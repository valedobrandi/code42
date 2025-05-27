/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_pthread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:20:48 by bde-albu          #+#    #+#             */
/*   Updated: 2025/05/26 17:18:08 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <unistd.h>

static void	*end_simulation(t_simulation *watchdog, int i)
{
	pthread_mutex_lock(&watchdog->philos[i].watchdog_mutex);
	*(watchdog->watchdog) = 0;
	pthread_mutex_unlock(&watchdog->philos[i].watchdog_mutex);
	print_statement("died", watchdog->print_mutex,
		watchdog->philos[i].philosopher);
	return (NULL);
}

static int	has_eat_times(t_simulation *watchdog)
{
	int	eat_times;
	int	i;

	i = 0;
	while (i < watchdog->size)
	{
		pthread_mutex_lock(&watchdog->philos[i].watchdog_mutex);
		eat_times = watchdog->philos[i].times_must_eat;
		pthread_mutex_unlock(&watchdog->philos[i].watchdog_mutex);
		if (eat_times != 0)
			return (1);
		i++;
	}
	return (0);
}

static t_watch	watch_eat_update(t_simulation *watchdog, int i)
{
	long	get_last_update;
	t_watch	watch;

	pthread_mutex_lock(&watchdog->philos[i].update_time_mutex);
	get_last_update = watchdog->philos[i].update_time;
	pthread_mutex_unlock(&watchdog->philos[i].update_time_mutex);
	watch.elapse_time = get_time_in_ms() - get_last_update;
	pthread_mutex_lock(&watchdog->philos[i].watchdog_mutex);
	watch.eat_times = watchdog->philos[i].times_must_eat;
	pthread_mutex_unlock(&watchdog->philos[i].watchdog_mutex);
	return (watch);
}

static void	*watch_simulation(void *args)
{
	t_simulation	*watchdog;
	t_watch			watch;
	int				i;

	watchdog = (t_simulation *)args;
	while (has_eat_times(watchdog))
	{
		i = 0;
		while (i < watchdog->size)
		{
			watch = watch_eat_update(watchdog, i);
			if (watch.elapse_time > watchdog->philos[i].time_to_die
				&& watch.eat_times != 0)
				return (end_simulation(watchdog, i));
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

int	simulation_pthread(t_simulation *simulation, pthread_t *pthread,
		int number_of_philosophers)
{
	if (pthread_create(&simulation->pthread, NULL, watch_simulation,
			(void *)simulation) != 0)
		return (1);
	pthread[number_of_philosophers] = simulation->pthread;
	return (0);
}
