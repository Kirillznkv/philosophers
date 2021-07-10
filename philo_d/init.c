/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 08:15:38 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/10 15:20:26 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int		get_arg(char *str, int *flag)
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
		*flag = 1;
	return (res);
}

int	init_settings(char **argv, t_settings *tmp)
{
	int	flag;

	flag = 0;
	tmp->number = get_arg(argv[0], &flag);
	tmp->time_die = get_arg(argv[1], &flag);
	tmp->time_eat = get_arg(argv[2], &flag);
	tmp->time_sleep = get_arg(argv[3], &flag);
	if (argv[4])
		tmp->column_eat_for_die = get_arg(argv[4], &flag);
	else
		tmp->column_eat_for_die = -1;
	if (flag)
		return (error("Error: its not a valid arguments\n"));
	return (0);
}

void	setting_mutex(t_pthread_philo *philo, pthread_mutex_t *mutex, int i)
{
	if (i != 0)
		philo->left = &(mutex[i - 1]);
	else
		philo->left = &(mutex[philo->data->number - 1]);
	philo->right = &(mutex[i]);
}

int	go_treads(t_settings *settings, t_pthread_philo **p_philo, pthread_mutex_t *mutex)
{
	int	i;
	t_pthread_philo *philo;

	*p_philo = (t_pthread_philo *)malloc(sizeof(t_pthread_philo) * settings->number);
	philo = *p_philo;
	if (!philo)
		return (error("Error: malloc error\n"));
	i = -1;
	while (++i < settings->number)
	{
		//philo[i].col_eat = 0;
		philo[i].i = i;
		philo[i].data = settings;
		//last_eat;
		setting_mutex(&(philo[i]), mutex, i);
		if (pthread_create(&(philo[i].pd), NULL, life, (void *)&(philo[i])))//func
			return (error("Error: pthread_creale error\n"));
	}
	return (0);
}

int	init_mutex(pthread_mutex_t **p_mutex, int number)
{
	int	i;
	pthread_mutex_t *mutex;

	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * number);
	if (!mutex)
		return (error("Error: malloc error\n"));
	*p_mutex = mutex;
	i = -1;
	while (++i < number)
	{
		pthread_mutex_init(&(mutex[i]), NULL);
		// pthread_mutex_unlock(&(mutex[i]));
	}
	return (0);
}
