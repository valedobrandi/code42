#include "../philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long get_time_in_ms(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000L) + (tv.tv_usec / 1000L);
}

void smart_usleep(long duration_ms)
{
    long start = get_time_in_ms();
    while (get_time_in_ms() - start < duration_ms)
        usleep(100);
}

void print_statement(char *action, pthread_mutex_t *mutex, int philosopher)
{
    long time;

    time = get_time_in_ms();
    pthread_mutex_lock(mutex);
    printf("%ld %d %s\n", time, philosopher, action);
    pthread_mutex_unlock(mutex);
}

void *end_simulation(t_simulation *watchdog, int index)
{
    pthread_mutex_lock(watchdog->watchdog_mutex);
    *(watchdog->watchdog) = 0;
    pthread_mutex_unlock(watchdog->watchdog_mutex);
    print_statement("died", watchdog->print_mutex, watchdog->philos[index].philopher);
    return (NULL);
}

void *watch_simulation(void *args)
{
    t_simulation *watchdog;
    long get_last_update;
    long elapse_time;
    int i;

    watchdog = (t_simulation *)args;
    while (1)
    {
        i = 0;
        while (i < watchdog->size)
        {
            pthread_mutex_lock(watchdog->update_time_mutex);
            get_last_update = watchdog->philos[i].update_time;
            pthread_mutex_unlock(watchdog->update_time_mutex);
            elapse_time = get_time_in_ms() - get_last_update;
            if (elapse_time > watchdog->philos[i].time_to_die)
                return (end_simulation(watchdog, i));
            i++;
        }
        usleep(100);
    }
    return (NULL);
}

int is_simulation_active(t_philo *philo)
{
    int active;

    pthread_mutex_lock(philo->watchdog_mutex);
    active = *(philo->watchdog);
    pthread_mutex_unlock(philo->watchdog_mutex);
    return active;
}

void take_forks(t_philo *philo)
{
    if (philo->philopher % 2 == 1)
    {
        pthread_mutex_lock(&philo->fork.left);
        if (is_simulation_active(philo))
            print_statement("has taken a fork", philo->print_mutex, philo->philopher);
        pthread_mutex_lock(philo->fork.right);
        if (is_simulation_active(philo))
            print_statement("has taken a fork", philo->print_mutex, philo->philopher);
        if (is_simulation_active(philo))
            print_statement("is eating", philo->print_mutex, philo->philopher);
    }
    else
    {
        pthread_mutex_lock(philo->fork.right);
        if (is_simulation_active(philo))
            print_statement("has taken a fork", philo->print_mutex, philo->philopher);
        pthread_mutex_lock(&philo->fork.left);
        if (is_simulation_active(philo))
            print_statement("has taken a fork", philo->print_mutex, philo->philopher);
        if (is_simulation_active(philo))
            print_statement("is eating", philo->print_mutex, philo->philopher);
    }
}

void is_sleeping(t_philo *philosipher)
{
    int watch_dog;

    pthread_mutex_lock(philosipher->watchdog_mutex);
    watch_dog = *(philosipher->watchdog);
    pthread_mutex_unlock(philosipher->watchdog_mutex);
    if (watch_dog)
        print_statement("is sleeping", philosipher->print_mutex, philosipher->philopher);
    smart_usleep(philosipher->time_to_sleep);
}

void is_thinking(t_philo *philosipher)
{
    int watch_dog;

    pthread_mutex_lock(philosipher->watchdog_mutex);
    watch_dog = *(philosipher->watchdog);
    pthread_mutex_unlock(philosipher->watchdog_mutex);
    if (watch_dog)
        print_statement("is thinking", philosipher->print_mutex, philosipher->philopher);
}

void is_eating(t_philo *philo)
{
    pthread_mutex_lock(philo->update_time_mutex);
    philo->update_time = get_time_in_ms();
    pthread_mutex_unlock(philo->update_time_mutex);
    smart_usleep(philo->time_to_eat);
    pthread_mutex_unlock(&philo->fork.left);
    pthread_mutex_unlock(philo->fork.right);
}

void *routine(void *args)
{
    t_philo *philosopher;
    int count_eat;

    count_eat = 0;
    philosopher = (t_philo *)args;
    while (is_simulation_active(philosopher))
    {
        if (count_eat != -1 && philosopher->times_must_eat == count_eat)
            return (NULL);
        take_forks(philosopher);
        is_eating(philosopher);
        is_sleeping(philosopher);
        is_thinking(philosopher);
        count_eat++;
    }
    return (NULL);
}

void set_philosophers(t_philo *philos, t_params settings, t_global *global)
{
    int i;

    i = 0;
    while (i < settings.number_of_philosophers)
    {
        ft_memset(&philos[i], 0, sizeof(t_philo));
        pthread_mutex_init(&philos[i].fork.left, NULL);
        philos[i].philopher = i + 1;
        philos[i].watchdog = &global->watchdog;
        philos[i].print_mutex = &global->print_mutex;
        philos[i].watchdog_mutex = &global->watchdog_mutex;
        philos[i].update_time_mutex = &global->update_time_mutex;
        philos[i].time_to_die = settings.time_to_die;
        philos[i].time_to_eat = settings.time_to_eat;
        philos[i].time_to_sleep = settings.time_to_sleep;
        philos[i].times_must_eat = settings.number_of_times_must_eat;
        philos[i].update_time = get_time_in_ms();
        i++;
    }
}

t_simulation set_simulation(t_philo *philos, t_global *global, int number_of_philosophers)
{
    t_simulation watchdog;

    ft_memset(&watchdog, 0, sizeof(t_simulation));
    watchdog.philos = philos;
    watchdog.watchdog = &global->watchdog;
    watchdog.print_mutex = &global->print_mutex;
    watchdog.watchdog_mutex = &global->watchdog_mutex;
    watchdog.update_time_mutex = &global->update_time_mutex;
    watchdog.size = number_of_philosophers;

    return (watchdog);
}

void set_fork(t_philo *philos, int number_of_philosophers)
{
    int i;

    i = 0;
    while (i < number_of_philosophers)
    {
        philos[i].fork.right = &philos[(i + 1) % number_of_philosophers].fork.left;
        i++;
    }
}

void philopsophers_pthread(t_philo *philos, pthread_t *pthread, int number_of_philosophers)
{
    int i;

    i = 0;
    while (i < number_of_philosophers)
    {
        pthread_create(&philos[i].pthread, NULL, routine, (void *)&philos[i]);
        pthread[i] = philos[i].pthread;
        i++;
        if (number_of_philosophers == 2)
            usleep(1000);
    }
}

void simulation_pthread(t_simulation *simulation, pthread_t *pthread, int number_of_philosophers)
{

    pthread_create(&simulation->pthread, NULL, watch_simulation, (void *)simulation);
    pthread[number_of_philosophers] = simulation->pthread;
}
t_philo *set_phtread_philosopher(t_params params, t_global *global)
{
    t_philo *philos;

    philos = malloc(params.number_of_philosophers * sizeof(t_philo));
    if (philos == NULL)
        return (NULL);

    set_philosophers(philos, params, global);
    return (philos);
}

void philosopher_pthread(t_philo *philos, t_params params, pthread_t *pthread)
{
    set_fork(philos, params.number_of_philosophers);
    philopsophers_pthread(philos, pthread, params.number_of_philosophers);
}

void start_pthreads(pthread_t *pthread, int number_of_philosophers)
{
    int i = 0;

    while (i <= number_of_philosophers)
    {
        pthread_join(pthread[i], NULL);
        i++;
    }
}

t_params initialize_settings(int ac, char **av)
{
    t_params settings;

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

void destroy_mutex(t_philo *philos, t_global *global, int number_of_philosophers)
{
    int i = 0;

    while (i < number_of_philosophers)
    {
        pthread_mutex_destroy(&philos[i].fork.left);
        i++;
    }
    pthread_mutex_destroy(&global->print_mutex);
    pthread_mutex_destroy(&global->watchdog_mutex);
    pthread_mutex_destroy(&global->update_time_mutex);
}

void initialize_global_mutex(t_global *global)
{
    pthread_mutex_init(&global->print_mutex, NULL);
    pthread_mutex_init(&global->watchdog_mutex, NULL);
    pthread_mutex_init(&global->update_time_mutex, NULL);
}

int main(int ac, char **av)
{
    t_philo *philos;
    pthread_t *pthread;
    t_global global;
    t_params params;
    t_simulation simulation;

    if (ac == 5 || ac == 6)
    {
        params = initialize_settings(ac, av);
        pthread = malloc((params.number_of_philosophers + 1) * sizeof(pthread_t));
        if (pthread == NULL)
            return (1);
        global.watchdog = 1;
        initialize_global_mutex(&global);
        philos = set_phtread_philosopher(params, &global);
        simulation = set_simulation(philos, &global, params.number_of_philosophers);
        philosopher_pthread(philos, params, pthread);
        simulation_pthread(&simulation, pthread, params.number_of_philosophers);
        start_pthreads(pthread, params.number_of_philosophers);
        destroy_mutex(philos, &global, params.number_of_philosophers);
        free(philos);
    }

    return (0);
}
