/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_tread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 19:26:49 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/24 20:04:44 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void    wait_die(pthread_t *pd, t_pthread_philo *philo)
{
    while (philo->data->is_die == 0)
        ;
}

void    wait_eat(pthread_t *pd, int number)
{
    int i;

    i = -1;
    while (++i < number)
        pthread_join(pd[i], NULL);
}
