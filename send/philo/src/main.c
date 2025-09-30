/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:00:14 by bde-albu          #+#    #+#             */
/*   Updated: 2025/05/26 17:15:52 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdlib.h>

static void	destroy_all_mutex(t_philo *philos, t_global *global,
		int number_of_philosophers)
{
	int	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_mutex_destroy(&philos[i].fork.left);
		pthread_mutex_destroy(&philos[i].update_time_mutex);
		pthread_mutex_destroy(&philos[i].watchdog_mutex);
		i++;
	}
	pthread_mutex_destroy(&global->print_mutex);
}

static void	set_pthreads(pthread_t *pthread, int number_of_philosophers)
{
	int	i;

	i = 0;
	while (i <= number_of_philosophers)
	{
		pthread_join(pthread[i], NULL);
		i++;
	}
}

int	start_philosophers(t_params s, t_global *global)
{
	t_philo			*philos;
	pthread_t		*pthread;
	t_simulation	simulation;

	pthread = malloc((s.number_of_philosophers + 1) * sizeof(pthread_t));
	if (pthread == NULL)
		return (pthread_mutex_destroy(&global->print_mutex), 1);
	philos = set_philosopher(s, global);
	if (philos == NULL)
		return (free(pthread), pthread_mutex_destroy(&global->print_mutex), 1);
	simulation = set_simulation(philos, global, s.number_of_philosophers);
	if (philosopher_pthread(philos, s, pthread))
		return (destroy_all_mutex(philos, global, s.number_of_philosophers),
			free(pthread), free(philos), 1);
	if (simulation_pthread(&simulation, pthread, s.number_of_philosophers))
		return (destroy_all_mutex(philos, global, s.number_of_philosophers),
			free(pthread), free(philos), 1);
	set_pthreads(pthread, s.number_of_philosophers);
	destroy_all_mutex(philos, global, s.number_of_philosophers);
	free(pthread);
	free(philos);
	return (0);
}

int	initialize(t_params settings)
{
	t_global	global;

	global.watchdog = 1;
	if (pthread_mutex_init(&global.print_mutex, NULL) != 0)
		return (1);
	if (start_philosophers(settings, &global))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_params	settings;

	if (ac == 5 || ac == 6)
	{
		settings = initialize_settings(ac, av);
		if (validate_params(ac, settings))
			return (0);
		if (one_philosopher(settings))
			return (0);
		if (initialize(settings))
			return (1);
	}
	return (0);
}
