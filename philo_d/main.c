/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:23:45 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/08 00:15:03 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	main(int argc, char **argv)
{
	t_settings		settings;
	t_pthread_philo	philo;

	if (argc != 5 && argc != 6)
		error("Error: argument error\n");
	init_settings(&argv[1], &settings);
	init_philo(&settings, &philo);
	return (0);
}