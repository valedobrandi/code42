/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:18:14 by bde-albu          #+#    #+#             */
/*   Updated: 2025/05/26 16:32:39 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	running_simulation(t_philo *philo)
{
	int	active;

	pthread_mutex_lock(&philo->watchdog_mutex);
	active = *(philo->watchdog);
	pthread_mutex_unlock(&philo->watchdog_mutex);
	return (active);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork.left);
	if (running_simulation(philo))
		print_statement("has taken a fork", philo->print_mutex,
			philo->philosopher);
	pthread_mutex_lock(philo->fork.right);
	if (running_simulation(philo))
		print_statement("has taken a fork", philo->print_mutex,
			philo->philosopher);
	if (running_simulation(philo))
		print_statement("is eating", philo->print_mutex, philo->philosopher);
}

void	is_sleeping(t_philo *philosopher)
{
	int	watch_dog;

	pthread_mutex_lock(&philosopher->watchdog_mutex);
	watch_dog = *(philosopher->watchdog);
	pthread_mutex_unlock(&philosopher->watchdog_mutex);
	if (watch_dog)
		print_statement("is sleeping", philosopher->print_mutex,
			philosopher->philosopher);
	smart_usleep(philosopher->time_to_sleep);
}

void	is_thinking(t_philo *philosopher)
{
	int	watch_dog;

	pthread_mutex_lock(&philosopher->watchdog_mutex);
	watch_dog = *(philosopher->watchdog);
	pthread_mutex_unlock(&philosopher->watchdog_mutex);
	if (watch_dog)
		print_statement("is thinking", philosopher->print_mutex,
			philosopher->philosopher);
}

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->update_time_mutex);
	philo->update_time = get_time_in_ms();
	pthread_mutex_unlock(&philo->update_time_mutex);
	smart_usleep(philo->time_to_eat);
	pthread_mutex_unlock(&philo->fork.left);
	pthread_mutex_unlock(philo->fork.right);
}
