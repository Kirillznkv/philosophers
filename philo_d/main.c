/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:23:45 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/10 15:18:33 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	main(int argc, char **argv)//Убрать exit
{
	t_settings		settings;
	t_pthread_philo	*philo;
	pthread_mutex_t	*mutex;
	//struct timeval	time;

	if (argc != 5 && argc != 6)
		return (error("Error: argument error\n"));
	//gettimeofday(&time, NULL);
	if (init_settings(&argv[1], &settings))
		return (1);
	if (init_mutex(&mutex, settings.number))
		return (1);
	if (go_treads(&settings, &philo, mutex))
		return (free_all(mutex, philo));
	while (1)
		;//printf("------>(%d) (%d) (%d) (%d)\n", philo->col_eat, philo[1].col_eat, philo[2].col_eat, philo[3].col_eat);
	return (0);
}