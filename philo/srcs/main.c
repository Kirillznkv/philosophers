/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:52:12 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/15 04:59:30 by user             ###   ########.fr       */
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
		;
	return (0);
}