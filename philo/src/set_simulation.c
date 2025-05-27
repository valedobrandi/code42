/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:45:48 by bde-albu          #+#    #+#             */
/*   Updated: 2025/05/26 17:02:47 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_simulation	set_simulation(t_philo *philos, t_global *global,
		int number_of_philosophers)
{
	t_simulation	watchdog;

	ft_memset(&watchdog, 0, sizeof(t_simulation));
	watchdog.philos = philos;
	watchdog.watchdog = &global->watchdog;
	watchdog.print_mutex = &global->print_mutex;
	watchdog.size = number_of_philosophers;
	return (watchdog);
}
