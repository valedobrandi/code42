/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:07:51 by bde-albu          #+#    #+#             */
/*   Updated: 2025/05/26 17:16:14 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_fork
{
	pthread_mutex_t	left;
	pthread_mutex_t	*right;
}					t_fork;

typedef struct s_params
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_philosophers;
	int				number_of_times_must_eat;
}					t_params;

typedef struct s_global
{
	pthread_mutex_t	print_mutex;
	int				watchdog;
}					t_global;

typedef struct s_philo
{
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	update_time_mutex;
	pthread_mutex_t	watchdog_mutex;
	pthread_t		pthread;
	t_fork			fork;
	long			update_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philosopher;
	int				times_must_eat;
	int				*watchdog;
}					t_philo;

typedef struct s_simulation
{
	pthread_t		pthread;
	pthread_mutex_t	*print_mutex;
	t_philo			*philos;
	int				size;
	int				*watchdog;
}					t_simulation;

typedef struct s_watch
{
	long			elapse_time;
	int				eat_times;
}					t_watch;

void				*ft_memset(void *str, int c, size_t n);
int					ft_atoi(const char *nptr);
t_params			initialize_settings(int ac, char **av);
int					validate_params(int ac, t_params settings);
int					one_philosopher(t_params params);
t_philo				*set_philosopher(t_params s, t_global *global);
t_simulation		set_simulation(t_philo *philos, t_global *global,
						int number_of_philosophers);
int					simulation_pthread(t_simulation *simulation,
						pthread_t *pthread, int number_of_philosophers);
int					philosopher_pthread(t_philo *philos, t_params s,
						pthread_t *pthread);
int					running_simulation(t_philo *philo);
void				take_forks(t_philo *philo);
void				is_sleeping(t_philo *philosopher);
void				is_thinking(t_philo *philosopher);
void				is_eating(t_philo *philo);
long				get_time_in_ms(void);
void				smart_usleep(long duration_ms);
void				print_statement(char *action, pthread_mutex_t *mutex,
						int philosopher);

#endif