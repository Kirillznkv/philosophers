/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   massages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:24:53 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/22 18:24:11 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	massage(int mas, long int time, int i, int status_die)
{
	if (status_die)
		return ;
	if (mas == WR_LEFT_FORK_UP)
		printf(YELLOW"%4ld: "RESET"%d "GREEN"philo has taken a right fork\n"RESET, time, i);
	else if (mas == WR_RIGHT_FORK_UP)
		printf(YELLOW"%4ld: "RESET"%d "GREEN"philo has taken a left fork\n"RESET, time, i);
	else if (mas == WR_LEFT_FORK_DOWN)
		printf(YELLOW"%4ld: "RESET"%d "RED"philo left fork down\n", time, i);
	else if (mas == WR_RIGHT_FORK_DOWN)
		printf(YELLOW"%4ld: "RESET"%d "RED"philo right fork down\n", time, i);
	else if (mas == WR_EAT)
		printf(YELLOW"%4ld: "RESET"%d "CYAN"philo eating\n", time, i);
	else if (mas == WR_SLEEP)
		printf(YELLOW"%4ld: "RESET"%d "BLUE"philo sleeping\n", time, i);
	else if (mas == WR_THINK)
		 printf(YELLOW"%4ld: "RESET"%d "MAGENTA"philo thinking\n", time, i);
	else if (mas == WR_DIE)
		 printf(RED"%4ld: %d PHILO IS DIE\n", time, i);
}
