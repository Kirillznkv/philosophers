/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 23:36:20 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/08 08:29:52 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	*func(void	*arg)
{
	t_pthread_philo	*philo;

	philo = (t_pthread_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(philo->left);
		printf("%d: has taken a left fork\n", philo->data.i);
		pthread_mutex_lock(philo->right);
		printf("%d: has taken a right fork\n", philo->data.i);
		//
		printf("Hello\n");
		//
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
	}
	return (NULL);
}
