/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 08:15:38 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/08 08:45:53 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

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

void	setting_mutex(t_pthread_philo *philo, pthread_mutex_t *mutex, int i)
{
	if (i != 0)
		philo->left = &(mutex[i - 1]);
	else
		philo->left = &(mutex[philo->data.number - 1]);
	philo->right = &(mutex[i]);
}

void	init_philo(t_settings *settings, t_pthread_philo **p_philo, pthread_mutex_t *mutex)
{
	int	i;
	t_pthread_philo *philo;

	*p_philo = (t_pthread_philo *)malloc(sizeof(t_pthread_philo) * settings->number);
	philo = *p_philo;
	i = -1;
	while (++i < settings->number)
	{
		philo[i].data.i = i;
		philo[i].data.number = settings->number;
		philo[i].data.column_eat_for_die = settings->column_eat_for_die;
		philo[i].data.time_die = settings->time_die;
		philo[i].data.time_eat = settings->time_eat;
		philo[i].data.time_sleep = settings->time_sleep;
		setting_mutex(&(philo[i]), mutex, i);
		if (pthread_create(&(philo[i].pd), NULL, func, (void *)&(philo[i])))//func
			error("Error: pthread_creale error\n");
		printf("%d\n", i);
	}
}

void	init_mutex(pthread_mutex_t **mutex, int number)
{
	int	i;

	*mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * number);
	i = -1;
	while (++i < number)
	{
		printf("#\n");
		pthread_mutex_init(mutex[i], NULL);
	}
}
