/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 23:36:20 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/11 17:48:40 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	func_even(t_pthread_philo *philo)
{
	struct timeval	time;

	// fork
	pthread_mutex_lock(philo->left);
	printf("%d: has taken a left fork\n", philo->i);
	pthread_mutex_lock(philo->right);
	printf("%d: has taken a right fork\n", philo->i);
	// eat
	printf("%d: eating\n", philo->i);
	gettimeofday(&time, NULL);
	// if (time.tv_usec / 1000 >= philo->limit)
	// {
	// 	printf("die : %d\n", time.tv_usec / 1000 - philo->limit);
	// 	exit(1);
	// }
	philo->limit = time.tv_usec / 1000 + philo->data->time_die;
	usleep(philo->data->time_eat);
	// fork
	pthread_mutex_unlock(philo->left);
	printf("%d: left fork down\n", philo->i);
	pthread_mutex_unlock(philo->right);
	printf("%d: right fork down\n", philo->i);
}

void	func_noeven(t_pthread_philo *philo)
{
	struct timeval	time;

	// fork
	pthread_mutex_lock(philo->right);
	printf("%d: has taken a right fork\n", philo->i);
	pthread_mutex_lock(philo->left);
	printf("%d: has taken a left fork\n", philo->i);
	// eat
	printf("%d: eating\n", philo->i);
	gettimeofday(&time, NULL);
	// if (time.tv_usec / 1000 >= philo->limit)
	// {
	// 	printf("die : %d\n", time.tv_usec / 1000 - philo->limit);
	// 	exit(1);
	// }
	philo->limit = time.tv_usec / 1000 + philo->data->time_die;
	usleep(philo->data->time_eat);
	// fork
	pthread_mutex_unlock(philo->right);
	printf("%d: right fork down\n", philo->i);
	pthread_mutex_unlock(philo->left);
	printf("%d: left fork down\n", philo->i);
}

void	*life(void	*arg)
{
	t_pthread_philo	*philo;
	struct timeval	time;

	philo = (t_pthread_philo *)arg;
	pthread_detach(philo->pd);
	gettimeofday(&time, NULL);
	philo->last_eat = time.tv_usec / 1000;
	philo->limit = philo->last_eat + philo->data->time_die;
	while (1)
	{
		if (philo->i % 2)
			func_noeven(philo);
		else
			func_even(philo);
	}
	return (NULL);
}
