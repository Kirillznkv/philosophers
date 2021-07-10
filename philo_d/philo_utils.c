/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 23:36:20 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/08 10:59:42 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	func_even(t_pthread_philo *philo)
{
	printf("------->%d start11\n", philo->i);
	pthread_mutex_lock(philo->left);
	printf("%d: has taken a left fork\n", philo->i);
	pthread_mutex_lock(philo->right);
	printf("%d: has taken a right fork\n", philo->i);
	//
	printf("Hello\n");
	//
	pthread_mutex_unlock(philo->left);
	printf("%d: left fork down\n", philo->i);
	pthread_mutex_unlock(philo->right);
	printf("%d: right fork down\n", philo->i);
}

void	func_noeven(t_pthread_philo *philo)
{
	printf("------->%d start22\n", philo->i);
	pthread_mutex_lock(philo->right);
	printf("%d: has taken a right fork\n", philo->i);
	pthread_mutex_lock(philo->left);
	printf("%d: has taken a left fork\n", philo->i);
	//
	printf("Hello\n");
	//
	pthread_mutex_unlock(philo->right);
	printf("%d: right fork down\n", philo->i);
	pthread_mutex_unlock(philo->left);
	printf("%d: left fork down\n", philo->i);
}

void	*func(void	*arg)
{
	t_pthread_philo	*philo;
	struct timeval	time;

	philo = (t_pthread_philo *)arg;
	pthread_detach(philo->pd);
	gettimeofday(&time, NULL);
	philo->last_eat = time.tv_usec;
	while (1)
	{
		if (philo->i % 2)
			func_noeven(philo);
		else
			func_even(philo);
	}
	printf("WHY?\n");
	return (NULL);
}
