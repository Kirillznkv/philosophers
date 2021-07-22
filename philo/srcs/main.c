/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:52:12 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/19 00:27:53 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_pthread_philo *philo;

	philo = NULL;
	if (argc != 5 && argc != 6)
		return (error("Error: argument error\n"));
	if (init(&(argv[1]), &philo))
		return (all_free(philo));
	if (go_treads(philo))
		return (all_free(philo));
	while (1)
	{
		//printf("---->(%d)(%d)\n", philo->col_eat, philo[1].col_eat);
		// usleep(1000);
		;
	}

	// long int time = get_time();
	// my_sleep(20);
	// printf("time = %ld\n", get_time() - time);

	return (0);
}