#include "../philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L) + (tv.tv_usec / 1000L);
}

void	*stop_simulation(void *args)
{
	long			current_time_ms;
	long			elapsed_time_ms;
	t_simulation	*run;
	t_philo			philo;
	int				i;

	run = (t_simulation *)args;
	i = 0;
	while (*(run->simulation))
	{
		while (1)
		{
			philo = run->philos[(0 + i) % run->size];
			current_time_ms = get_time_in_ms();
			elapsed_time_ms = current_time_ms - philo.update_time;
			if (elapsed_time_ms > philo.time_to_die)
			{
				*(run->simulation) = 0;
				pthread_mutex_lock(run->print);
				printf("%ld %d died\n", get_time_in_ms(), philo.philopher);
				return (NULL);
			}
			i++;
		}
		usleep(10);
	}
	return (NULL);
}

void	*routine(void *args)
{
	t_philo	*philo;
	long	eat_time;
	long	sleep_time;
	long	take_fork_time;

	philo = (t_philo *)args;
	while (*(philo->simulation))
	{
		pthread_mutex_lock(&philo->fork.left);
		pthread_mutex_lock(philo->fork.right);
		take_fork_time = get_time_in_ms();
		eat_time = get_time_in_ms();
		usleep(philo->time_to_eat * 1000);
		philo->update_time = get_time_in_ms();
		pthread_mutex_unlock(&philo->fork.left);
		pthread_mutex_unlock(philo->fork.right);
		sleep_time = get_time_in_ms();
		usleep(philo->time_to_sleep * 1000);
		pthread_mutex_lock(philo->print);
		printf("%ld %d has taken a fork\n", take_fork_time, philo->philopher);
		printf("%ld %d is eating\n", eat_time, philo->philopher);
		printf("%ld %d is sleeping\n", sleep_time, philo->philopher);
		printf("%ld %d is thinking\n", get_time_in_ms(), philo->philopher);
		pthread_mutex_unlock(philo->print);
	}
	return (NULL);
}

void	philopsophers_pthread(void)
{
	while (i < settings.number_of_philosophers)
	{
		ft_memset(&philos[i], 0, sizeof(t_philo));
		pthread_mutex_init(&philos[i].fork.left, NULL);
		philos[i].philopher = i + 1;
		philos[i].print = &print;
		philos[i].time_to_die = settings.time_to_die;
		philos[i].time_to_eat = settings.time_to_eat;
		philos[i].time_to_sleep = settings.time_to_sleep;
		philos[i].simulation = &run_simulation;
		philos[i].update_time = get_time_in_ms();
		i++;
	}
	i = 0;
	while (i < settings.number_of_philosophers)
	{
		philos[i].fork.right = &philos[(i + 1)
			% settings.number_of_philosophers].fork.left;
		i++;
	}
	i = 0;
	while (i < settings.number_of_philosophers)
	{
		pthread_create(&philos[i].pthread, NULL, routine, (void *)&philos[i]);
		i++;
	}
}

t_philo	*initialize(t_settings settings, pthread_t *pthread)
{
	t_philo			*philos;
	t_simulation	simulation;
	pthread_mutex_t	*print;
	int				*run_simulation;
	int				i;

	philos = malloc(settings.number_of_philosophers * sizeof(t_philo));
	if (philos == NULL)
		return (NULL);
	print = malloc(sizeof(pthread_mutex_t));
	if (print == NULL)
		return (NULL);
	run_simulation = malloc(sizeof(int));
	if (run_simulation == NULL)
		return (NULL);
	pthread_mutex_init(&print, NULL);
	run_simulation = 1;
	/////////////////////////////////////////////////////////////////////////
	simulation.size = settings.number_of_philosophers;
	simulation.print = &print;
	simulation.philos = philos;
	simulation.simulation = &run_simulation;
	pthread_create(&simulation.pthread, NULL, stop_simulation,
		(void *)&simulation);
	pthread_join(simulation.pthread, NULL);
	return (philos);
}

int	main(int ac, char **av)
{
	t_settings settings;
	pthread_t *pthread;
	t_stack stack;

	if (ac == 5)
	{
		t_philo *philos;

		settings.number_of_philosophers = ft_atoi(av[1]);
		settings.time_to_die = ft_atoi(av[2]);
		settings.time_to_eat = ft_atoi(av[3]);
		settings.time_to_sleep = ft_atoi(av[4]);
		pthread = malloc((settings.number_of_philosophers + 1)
				* sizeof(pthread_t));
		if (pthread == NULL)
			return (NULL);
		init_stack(&stack, 2);
		if (stack.arr == NULL)
			return (NULL);
		philos = initialize(settings, pthread);
		int i = 0;
		while (i < settings.number_of_philosophers)
		{
			pthread_join(philos[i].pthread, NULL);
			i++;
		}
		i = 0;
		while (i < settings.number_of_philosophers)
		{
			pthread_mutex_destroy(&philos[i].fork.left);
			i++;
		}
	}

	return (0);
}