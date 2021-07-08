/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:23:45 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/08 08:44:22 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	wait_philos(t_pthread_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo[0].data.number)
		pthread_join(philo[i].pd, NULL);
}

void	philo_is_die(t_pthread_philo *philo)
{
	int	number;
	int	i;

	i = -1;
	number = philo[0].data.number;
	while (++i < number)
	{
		if (philo[i].data.time_die <= 0)//Точно ли die?
		{
			printf("philosopher %d die\n", i);
			exit(0);
		}
	}
}

int	main(int argc, char **argv)
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
	wait_philos(philo);
	philo_is_die(philo);
	return (0);
}