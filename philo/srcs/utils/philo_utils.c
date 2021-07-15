/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:28:04 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/15 05:00:08 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

long int	get_time()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long int)time.tv_sec * 1000 + (long int)time.tv_usec / 1000);
}

int	my_sleep(int sleep)
{
	long int	time;

	time = get_time();
	while (get_time() - time < sleep)
	{
		usleep(20);
	}
	return (1);
}

int	all_free(t_pthread_philo *philo)
{
	if (!philo)
		return (1);
	free(philo->left);
	free(philo->data);
	free(philo);
	return (1);
}

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
