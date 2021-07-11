/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:30:55 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/11 22:46:46 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_settings	*init_settings(char **argv)
{
	int	flag;
	t_settings	*settings;

	settings = (t_settings *)malloc(sizeof(t_settings));
	if (!settings)
	{
		error("Error: malloc error\n");
		return (NULL);
	}
	flag = 0;
	settings->number = get_arg(argv[0], &flag);
	settings->time_die = get_arg(argv[1], &flag);
	settings->time_eat = get_arg(argv[2], &flag);
	settings->time_sleep = get_arg(argv[3], &flag);
	if (argv[4])
		settings->column_eat_for_die = get_arg(argv[4], &flag);
	else
		settings->column_eat_for_die = -1;
	if (flag)
	{
		free(settings);
		error("Error: its not a valid arguments\n");
		return (NULL);
	}
	return (settings);
}

pthread_mutex_t	*init_mutex(int number)
{
	int	i;
	pthread_mutex_t *mutex;

	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * number);
	if (!mutex)
	{
		error("Error: malloc error\n");
		return (NULL);
	}
	i = -1;
	while (++i < number)
	{
		pthread_mutex_init(&(mutex[i]), NULL);
	}
	return (mutex);
}

int	init(char **argv, t_pthread_philo **p_philo)//free settings у нулевого //free mutex у нулевого левая вилка
{
	t_settings		*settings;
	t_pthread_philo	*philo;
	pthread_mutex_t	*mutex;

	philo = *p_philo;
	settings = init_settings(argv);
	if (!settings)
		return (1);
	mutex = init_mutex(settings->number);
	if (!mutex)
		return (1);
	return (0);
}