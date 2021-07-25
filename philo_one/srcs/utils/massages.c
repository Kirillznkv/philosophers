/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   massages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:24:53 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/25 19:49:35 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	massage(int mas, long int time, int i, int status_die)
{
	if (status_die)
		return ;
	pthread_mutex_lock(&g_m_massage);
	if (mas == WR_LEFT_FORK_UP)
		printf(YELLOW"%4ld: "RESET"%3d "GREEN"philo has taken a right fork\n" \
																RESET, time, i);
	else if (mas == WR_RIGHT_FORK_UP)
		printf(YELLOW"%4ld: "RESET"%3d "GREEN"philo has taken a left fork\n" \
																RESET, time, i);
	else if (mas == WR_LEFT_FORK_DOWN)
		printf(YELLOW"%4ld: "RESET"%3d "RED"philo left fork down\n", time, i);
	else if (mas == WR_RIGHT_FORK_DOWN)
		printf(YELLOW"%4ld: "RESET"%3d "RED"philo right fork down\n", time, i);
	else if (mas == WR_EAT)
		printf(YELLOW"%4ld: "RESET"%3d "CYAN"philo eating\n", time, i);
	else if (mas == WR_SLEEP)
		printf(YELLOW"%4ld: "RESET"%3d "BLUE"philo sleeping\n", time, i);
	else if (mas == WR_THINK)
		 printf(YELLOW"%4ld: "RESET"%3d "MAGENTA"philo thinking\n", time, i);
	else if (mas == WR_DIE)
	{
		 printf(RED"%4ld: %3d PHILO IS DIE\n", time, i);
		 return ;
	}
	pthread_mutex_unlock(&g_m_massage);
}
