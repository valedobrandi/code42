/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:53:09 by bde-albu          #+#    #+#             */
/*   Updated: 2025/05/27 08:27:54 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdio.h>
#include <unistd.h>

long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
}

void	smart_usleep(long duration_ms)
{
	long	start;
	long	now;

	start = get_time_in_ms();
	now = get_time_in_ms();
	while (now - start < duration_ms)
	{
		usleep(5000);
		now = get_time_in_ms();
	}
}

void	print_statement(char *action, pthread_mutex_t *mutex, int philosopher)
{
	long	time;

	time = get_time_in_ms();
	pthread_mutex_lock(mutex);
	printf("%ld %d %s\n", time, philosopher, action);
	pthread_mutex_unlock(mutex);
}

int	one_philosopher(t_params params)
{
	if (params.number_of_philosophers == 1)
	{
		printf("%ld %d has taken a fork\n", get_time_in_ms(), 1);
		smart_usleep(params.time_to_die);
		printf("%ld %d has died\n", get_time_in_ms(), 1);
		return (1);
	}
	return (0);
}

int	validate_params(int ac, t_params settings)
{
	if (settings.number_of_philosophers < 0 || settings.time_to_die < 0
		|| settings.time_to_eat < 0 || settings.time_to_sleep < 0)
		return (1);
	if (ac == 6 && settings.number_of_times_must_eat < 0)
		return (1);
	return (0);
}
