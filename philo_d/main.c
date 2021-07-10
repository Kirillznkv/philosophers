/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:23:45 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/08 10:54:00 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	main(int argc, char **argv)//Убрать exit
{
	t_settings		settings;
	t_pthread_philo	*philo;
	pthread_mutex_t	*mutex;
	struct timeval	time;

	if (argc != 5 && argc != 6)
		error("Error: argument error\n");
	gettimeofday(&time, NULL);
	printf("-->%d\n", time.tv_usec / 1000);
	init_settings(&argv[1], &settings);
	init_mutex(&mutex, settings.number);
	init_philo(&settings, &philo, mutex);
	for(int i=0; i< settings.number;i++)
		pthread_join(philo[i].pd, NULL);
	return (0);
}