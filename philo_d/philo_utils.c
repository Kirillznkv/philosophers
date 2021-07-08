/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 23:36:20 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/08 06:56:15 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	*func(void	*arg)
{
	arg = NULL;
	printf("Hello!\n");
	return (arg);
}

int		get_arg(char *str)
{
	char	*test;
	int		i;
	int		res;

	test = NULL;
	res = ft_atoi(str, &test);
	i = 0;
	while (test && test[i] == ' ')
		i++;
	if (res <= 0 || (test && test[i] != '\0'))
		error("Error: its not a valid arguments\n");
	return (res);
}

void	init_settings(char **argv, t_settings *tmp)
{
	tmp->number = get_arg(argv[0]);
	tmp->time_die = get_arg(argv[1]);
	tmp->time_eat = get_arg(argv[2]);
	tmp->time_sleep = get_arg(argv[3]);
	if (argv[4])
		tmp->column_eat_for_die = get_arg(argv[4]);
	else
		tmp->column_eat_for_die = -1;
}

void	init_philo(t_settings *settings, t_pthread_philo **philo)
{
	int	i;

	*philo = (t_pthread_philo *)malloc(sizeof(t_pthread_philo) * settings->number);
	i = -1;
	while (++i < settings->number)
	{
		(*philo)[i].data.number = settings->number;
		(*philo)[i].data.column_eat_for_die = settings->column_eat_for_die;
		(*philo)[i].data.time_die = settings->time_die;
		(*philo)[i].data.time_eat = settings->time_eat;
		(*philo)[i].data.time_sleep = settings->time_sleep;
		if (pthread_create(&((*philo)[i].pd), NULL, func, (void *)NULL))//func
			error("Error: pthread_creale error\n");
	}
}
