/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treads.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 23:51:07 by user              #+#    #+#             */
/*   Updated: 2021/07/24 16:50:36 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    eating(t_pthread_philo *philo)
{
	long int	time;

    if (philo->i % 2)
    {
        if (philo->data->number % 2)
            usleep(100);
        pthread_mutex_lock(philo->right);
		time = get_time() - philo->data->start_time;
        massage(WR_RIGHT_FORK_UP, time, philo->i, philo->data->is_die);
        pthread_mutex_lock(philo->left);
		time = get_time() - philo->data->start_time;
        massage(WR_LEFT_FORK_UP, time, philo->i, philo->data->is_die);
    }
    else
    {
        pthread_mutex_lock(philo->left);
		time = get_time() - philo->data->start_time;
        massage(WR_LEFT_FORK_UP, time, philo->i, philo->data->is_die);
        pthread_mutex_lock(philo->right);
		time = get_time() - philo->data->start_time;
        massage(WR_RIGHT_FORK_UP, time, philo->i, philo->data->is_die);
    }
	massage(WR_EAT, time, philo->i, philo->data->is_die);
	philo->limit = get_time() + philo->data->time_die;
	if (philo->data->column_eat_for_die > -1 && philo->data->column_eat_for_die != philo->col_eat)
		(philo->col_eat)++;
    my_sleep(philo->data->time_eat);
	pthread_mutex_unlock(philo->right);
	time = get_time() - philo->data->start_time;
    massage(WR_RIGHT_FORK_DOWN, time, philo->i, philo->data->is_die);
	pthread_mutex_unlock(philo->left);
    massage(WR_LEFT_FORK_DOWN, time, philo->i, philo->data->is_die);
}

void    sleeping(t_pthread_philo *philo)
{
    long int    time;

    time =  get_time() - philo->data->start_time;
    massage(WR_SLEEP, time, philo->i, philo->data->is_die);
    my_sleep(philo->data->time_sleep);
}

void	thinking(t_pthread_philo *philo)
{
    long int    time;

    time = get_time() - philo->data->start_time;
    massage(WR_THINK, time, philo->i, philo->data->is_die);
}

void	*life(void	*arg)
{
	t_pthread_philo	*philo;

	philo = (t_pthread_philo *)arg;
	pthread_create(&(philo->p_check_die), NULL, check_die, (void *)philo);
	while (!(philo->data->is_die))
	{
		eating(philo);
        if (philo->data->column_eat_for_die != -1 && philo->data->column_eat_for_die == philo->col_eat)
            break ;
        sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

int go_treads(t_pthread_philo *philo)
{
    int         i;
    int         number;
    pthread_t   *pd;
	pthread_t	p_check_die;

    number = philo->data->number;
    pd = (pthread_t *)malloc(sizeof(pthread_t) * number);
	if (!pd)
		return (error("Error: malloc error\n"));
    i = -1;
    while (++i < number)
    {
		if (pthread_create(&(pd[i]), NULL, life, (void *)&(philo[i])))
			return (error("Error: pthread_create error\n"));
    }
    i = -1;
    while (++i < number)
	    pthread_join(pd[i], NULL);
    return (0);
}