/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:00:17 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/22 20:15:01 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*check_die(void *arg)
{
	t_pthread_philo	*philo;

	philo = (t_pthread_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&(philo->data->m_die));
		if (philo->data->is_die == 0 && philo->limit <= get_time())
		{
			philo->data->is_die = philo->i;
			massage(WR_DIE, get_time() - philo->data->start_time, philo->i, 0);
			return (NULL);
		}
		pthread_mutex_unlock(&(philo->data->m_die));
	}
	return (NULL);
}