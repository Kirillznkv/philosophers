/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:52:12 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/11 22:30:27 by kshanti          ###   ########.fr       */
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
	return (0);
}