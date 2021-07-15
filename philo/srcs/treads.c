/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treads.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 23:51:07 by user              #+#    #+#             */
/*   Updated: 2021/07/15 04:48:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// void	func_even(t_pthread_philo *philo)
// {
// 	struct timeval	time;

// 	// fork
// 	pthread_mutex_lock(philo->left);
// 	printf("%d: has taken a left fork\n", philo->i);
// 	pthread_mutex_lock(philo->right);
// 	printf("%d: has taken a right fork\n", philo->i);
// 	// eat
// 	printf("%d: eating\n", philo->i);
// 	gettimeofday(&time, NULL);
// 	// if (time.tv_usec / 1000 >= philo->limit)
// 	// {
// 	// 	printf("die : %d\n", time.tv_usec / 1000 - philo->limit);
// 	// 	exit(1);
// 	// }
// 	philo->limit = time.tv_sec * 1000 + time.tv_usec / 1000 + philo->data->time_die;
// 	//usleep(philo->data->time_eat);
// 	my_sleep(philo->data->time_eat);
// 	// sleep
// 	//usleep(philo->data->time_sleep);
// 	my_sleep(philo->data->time_sleep);
// 	// fork
// 	pthread_mutex_unlock(philo->left);
// 	printf("%d: left fork down\n", philo->i);
// 	pthread_mutex_unlock(philo->right);
// 	printf("%d: right fork down\n", philo->i);
// }

// void	func_noeven(t_pthread_philo *philo)
// {
// 	struct timeval	time;

// 	// fork
// 	pthread_mutex_lock(philo->right);
// 	printf("%d: has taken a right fork\n", philo->i);
// 	pthread_mutex_lock(philo->left);
// 	printf("%d: has taken a left fork\n", philo->i);
// 	// eat
// 	printf("%d: eating\n", philo->i);
// 	// if (time.tv_usec / 1000 >= philo->limit)
// 	// {
// 	// 	printf("die : %d\n", time.tv_usec / 1000 - philo->limit);
// 	// 	exit(1);
// 	// }
// 	gettimeofday(&time, NULL);
// 	philo->limit = time.tv_sec * 1000 + time.tv_usec / 1000 + philo->data->time_die;
// 	//usleep(philo->data->time_eat);
// 	my_sleep(philo->data->time_eat);
// 	// sleep
// 	//usleep(philo->data->time_sleep);
// 	my_sleep(philo->data->time_sleep);
// 	// fork
// 	pthread_mutex_unlock(philo->right);
// 	printf("%d: right fork down\n", philo->i);
// 	pthread_mutex_unlock(philo->left);
// 	printf("%d: left fork down\n", philo->i);
// }

void    eating(t_pthread_philo *philo)
{
    long int    start_time;

    start_time = philo->data->start_time;
    if (philo->i % 2)
    {
        pthread_mutex_lock(philo->right);
        printf(YELLOW"%4ld: "RESET"%d "GREEN"philo has taken a right fork\n"RESET, get_time() - start_time, philo->i);
        pthread_mutex_lock(philo->left);
        printf(YELLOW"%4ld: "RESET"%d "GREEN"philo has taken a left fork\n"RESET, get_time() - start_time, philo->i);
    }
    else
    {
        pthread_mutex_lock(philo->left);
        printf(YELLOW"%4ld: "RESET"%d "GREEN"philo has taken a left fork\n", get_time() - start_time, philo->i);
        pthread_mutex_lock(philo->right);
        printf(YELLOW"%4ld: "RESET"%d "GREEN"philo has taken a right fork\n", get_time() - start_time, philo->i);
    }
    printf(YELLOW"%4ld: "RESET"%d "CYAN"philo eating\n", get_time() - start_time, philo->i);
	philo->limit = get_time() + philo->data->time_die;
    my_sleep(philo->data->time_eat);
	pthread_mutex_unlock(philo->right);
	printf(YELLOW"%4ld: "RESET"%d "RED"philo right fork down\n", get_time() - start_time, philo->i);
	pthread_mutex_unlock(philo->left);
	printf(YELLOW"%4ld: "RESET"%d "RED"philo left fork down\n", get_time() - start_time, philo->i);
}

void    sleeping(t_pthread_philo *philo)
{
    long int    start_time;

    start_time = philo->data->start_time;
    printf(YELLOW"%4ld: "RESET"%d "BLUE"philo sleeping\n", get_time() - start_time, philo->i);
    my_sleep(philo->data->time_sleep);
}

void	*life(void	*arg)
{
	t_pthread_philo	*philo;

	philo = (t_pthread_philo *)arg;
	// pthread_detach(philo->pd);
	philo->last_eat = get_time();
	philo->limit = philo->last_eat + philo->data->time_die;
	while (1)
	{
		eating(philo);
        sleeping(philo);
        // thinking(philo);
	}
	return (NULL);
}

int go_treads(t_pthread_philo *philo)
{
    int         i;
    int         number;
    pthread_t   *pd;

    number = philo->data->number;
    pd = (pthread_t *)malloc(sizeof(pthread_t) * number);
	if (!pd)
		return (error("Error: malloc error\n"));
    i = -1;
    while (++i < number)
    {
		if (pthread_create(&(pd[i]), NULL, life, (void *)&(philo[i])))//func
			return (error("Error: pthread_create error\n"));
    }
    return (0);
}