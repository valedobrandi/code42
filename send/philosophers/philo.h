/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:07:51 by bde-albu          #+#    #+#             */
/*   Updated: 2025/05/23 15:11:06 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_stack
{
	void			**arr;
	int				top;
	int				size;
}					t_stack;

typedef struct s_fork
{
	pthread_mutex_t	left;
	pthread_mutex_t	*right;
}					t_fork;

typedef struct s_settings
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
}					t_settings;

typedef struct s_philo
{
	pthread_t		pthread;
	t_fork			fork;
	void			*print;
	long			update_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philopher;
	int				*simulation;
}					t_philo;

typedef struct s_simulation
{
	t_philo			*philos;
	pthread_t		pthread;
	int				*simulation;
	int				size;
	void			*print;
}					t_simulation;

void				*ft_memset(void *str, int c, size_t n);
int					ft_atoi(const char *nptr);

void				*pop(t_stack *stack);
void				push(t_stack *stack, void *value);
int					init_stack(t_stack *stack, int capacity);

#endif