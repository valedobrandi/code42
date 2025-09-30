/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_settings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:37:51 by bde-albu          #+#    #+#             */
/*   Updated: 2025/05/26 17:10:01 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_params	initialize_settings(int ac, char **av)
{
	t_params	settings;

	ft_memset(&settings, 0, sizeof(t_params));
	settings.number_of_philosophers = ft_atoi(av[1]);
	settings.time_to_die = ft_atoi(av[2]);
	settings.time_to_eat = ft_atoi(av[3]);
	settings.time_to_sleep = ft_atoi(av[4]);
	settings.number_of_times_must_eat = -1;
	if (ac == 6)
		settings.number_of_times_must_eat = ft_atoi(av[5]);
	return (settings);
}
