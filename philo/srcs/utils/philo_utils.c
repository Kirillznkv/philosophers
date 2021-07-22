/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:28:04 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/19 00:22:27 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

// void	massage(char *str, int i, long int start_time)
// {
// 	long int	time;

// 	time = get_time();
// 	write(1, YELLOW"", 6);//"%4ld: "RESET");
// }

long int	get_time()
{
	struct timeval	time;

	// pthread_mutex_lock(&getTime_mutex);
	gettimeofday(&time, NULL);
	// pthread_mutex_unlock(&getTime_mutex);
	return ((long int)time.tv_sec * 1000 + (long int)time.tv_usec / 1000);
}

int	my_sleep(int sleep)
{
	long int	time;

	time = get_time();
	while (get_time() - time < sleep)
	{
		usleep(10);
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
