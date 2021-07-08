/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 23:36:20 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/08 06:21:08 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	*func(void	*arg)
{
	arg = NULL;
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

void	init_philo(t_settings *settings, t_pthread_philo *philo)
{
	int	i;

	philo->number = settings->number;
	philo->pd = (pthread_t *)malloc(sizeof(pthread_t) * philo->number);
	i = -1;
	while (++i < philo->number)
	{
		if (pthread_create(&((philo->pd)[i]), NULL, func, (void *)NULL))//func
			error("Error: pthread_creale error\n");
	}

}
