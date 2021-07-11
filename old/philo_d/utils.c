/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:37:24 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/11 20:43:34 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	my_sleep(int sleep)
{
	struct timeval	time;
	struct timeval	time_now;

	gettimeofday(&time, NULL);
	gettimeofday(&time_now, NULL);
	while (time.tv_sec * 1000 + time.tv_usec / 1000 + sleep > time.tv_sec * 1000 + time.tv_usec / 1000)
	{
		usleep(10);
		gettimeofday(&time_now, NULL);
	}
	return (1);
}

int	free_all(pthread_mutex_t *mutex, t_pthread_philo *philo)
{
	if (mutex)
		free(mutex);
	if (philo)
		free(philo);
	return (1);
}

int	ft_atoi(char *str, char **flag)
{
	unsigned int	res;
	unsigned int	i;
	char			m;

	m = 0;
	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || \
		str[i] == '\r' || str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-' && ++i)
		m++;
	if (str[i] < '0' || str[i] > '9')
		error("Error: its not a valid arguments\n");
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	*flag = &str[i];
	if (m)
		return (-res);
	else
		return (res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	error(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}