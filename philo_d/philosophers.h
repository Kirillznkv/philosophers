/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:26:21 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/08 10:03:03 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "pthread.h"
# include "sys/time.h"

typedef struct s_settings
{
	int						number;
	int						time_die;
	int						time_eat;
	int						time_sleep;
	int						column_eat_for_die;
} 							t_settings;
typedef struct s_pthread_philo
{
	int						i;
	__darwin_suseconds_t	last_eat;
	pthread_t				pd;
	struct s_settings		*data;
	pthread_mutex_t			*left;
	pthread_mutex_t			*right;
}							t_pthread_philo;
/*--------------------------------Utils---------------------------------------*/
int		ft_atoi(char *str, char **flag);
int		ft_strlen(char *str);
int		error(char *str);
/*--------------------------------Philo_Utils---------------------------------*/
void	*func(void	*arg);
/*--------------------------------Init----------------------------------------*/
int		get_arg(char *str);
void	init_settings(char **argv, t_settings *tmp);
void	setting_mutex(t_pthread_philo *philo, pthread_mutex_t *mutex, int i);
void	init_philo(t_settings *settings, t_pthread_philo **philo, pthread_mutex_t *mutex);
void	init_mutex(pthread_mutex_t **mutex, int number);

#endif
