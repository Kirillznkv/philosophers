/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:23:45 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/11 20:40:11 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	main(int argc, char **argv)//Убрать exit
{
	t_settings		settings;
	t_pthread_philo	*philo;
	pthread_mutex_t	*mutex;

	if (argc != 5 && argc != 6)
		return (error("Error: argument error\n"));
	if (init_settings(&argv[1], &settings))
		return (1);
	if (init_mutex(&mutex, settings.number))
		return (1);
	if (go_treads(&settings, &philo, mutex))
		return (free_all(mutex, philo));
	free_all(mutex, philo);
	return (0);
}