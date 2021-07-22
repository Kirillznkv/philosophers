/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treads.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 23:51:07 by user              #+#    #+#             */
/*   Updated: 2021/07/19 00:34:49 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    eating(t_pthread_philo *philo)
{
	long int	time;

    if (philo->i % 2)
    {
        pthread_mutex_lock(philo->right);
		time = get_time() - philo->data->start_time;
        printf(YELLOW"%4ld: "RESET"%d "GREEN"philo has taken a right fork\n"RESET, time, philo->i);
        pthread_mutex_lock(philo->left);
        printf(YELLOW"%4ld: "RESET"%d "GREEN"philo has taken a left fork\n"RESET, time, philo->i);
    }
    else
    {
        pthread_mutex_lock(philo->left);
		time = get_time() - philo->data->start_time;
        printf(YELLOW"%4ld: "RESET"%d "GREEN"philo has taken a left fork\n", time, philo->i);
        pthread_mutex_lock(philo->right);
        printf(YELLOW"%4ld: "RESET"%d "GREEN"philo has taken a right fork\n", time, philo->i);
    }
    printf(YELLOW"%4ld: "RESET"%d "CYAN"philo eating\n", time, philo->i);
	// if (philo->data->column_eat_for_die > -1 && philo->data->column_eat_for_die != philo->col_eat)
		(philo->col_eat)++;
	philo->limit = get_time() + philo->data->time_die;
    my_sleep(philo->data->time_eat);
	pthread_mutex_unlock(philo->right);
	time = get_time() - philo->data->start_time;
	printf(YELLOW"%4ld: "RESET"%d "RED"philo right fork down\n", time, philo->i);
	pthread_mutex_unlock(philo->left);
	printf(YELLOW"%4ld: "RESET"%d "RED"philo left fork down\n", time, philo->i);
}

void    sleeping(t_pthread_philo *philo)
{
    long int    start_time;

    start_time = philo->data->start_time;
    printf(YELLOW"%4ld: "RESET"%d "BLUE"philo sleeping\n", get_time() - start_time, philo->i);
    my_sleep(philo->data->time_sleep);
}

void	thinking(t_pthread_philo *philo)
{
    long int    start_time;

    start_time = philo->data->start_time;
    printf(YELLOW"%4ld: "RESET"%d "MAGENTA"philo thinking\n", get_time() - start_time, philo->i);
}

void	*life(void	*arg)
{
	t_pthread_philo	*philo;

	philo = (t_pthread_philo *)arg;
	// pthread_detach(philo->pd);
	// philo->last_eat = get_time();
	// philo->limit = philo->last_eat + philo->data->time_die;
	while (1)
	{
		// if (philo->i == 1)
		// {
		eating(philo);
        sleeping(philo);
		thinking(philo);
		// }
        // thinking(philo);
	}
	return (NULL);
}

int go_treads(t_pthread_philo *philo)
{
    int         i;
    int         number;
    pthread_t   *pd;

    number = philo->data->number;
    pd = (pthread_t *)malloc(sizeof(pthread_t) * number);
	if (!pd)
		return (error("Error: malloc error\n"));
    i = -1;
    while (++i < number)
    {
		if (pthread_create(&(pd[i]), NULL, life, (void *)&(philo[i])))//func
			return (error("Error: pthread_create error\n"));
    }
    return (0);
}