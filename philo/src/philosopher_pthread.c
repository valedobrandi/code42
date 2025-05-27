/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_pthread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:29:09 by bde-albu          #+#    #+#             */
/*   Updated: 2025/05/27 08:41:42 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <unistd.h>

static void	*routine(void *args)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)args;
	while (running_simulation(philosopher))
	{
		pthread_mutex_lock(&philosopher->watchdog_mutex);
		if (philosopher->times_must_eat > 0)
			philosopher->times_must_eat--;
		else if (philosopher->times_must_eat == 0)
		{
			pthread_mutex_unlock(&philosopher->watchdog_mutex);
			break ;
		}
		pthread_mutex_unlock(&philosopher->watchdog_mutex);
		take_forks(philosopher);
		is_eating(philosopher);
		is_sleeping(philosopher);
		is_thinking(philosopher);
	}
	return (NULL);
}

static void	set_fork(t_philo *philos, int number_of_philosophers)
{
	int	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		philos[i].fork.right = &philos[(i + 1)
			% number_of_philosophers].fork.left;
		i++;
	}
}

static int	set(t_philo *philos, pthread_t *pthread, int number_of_philosophers)
{
	int	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		if (pthread_create(&philos[i].pthread, NULL, routine,
				(void *)&philos[i]) != 0)
			return (1);
		usleep(1000);
		pthread[i] = philos[i].pthread;
		i++;
	}
	return (0);
}

int	philosopher_pthread(t_philo *philos, t_params s, pthread_t *pthread)
{
	set_fork(philos, s.number_of_philosophers);
	if (set(philos, pthread, s.number_of_philosophers))
		return (1);
	return (0);
}
