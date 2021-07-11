/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:26:21 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/11 22:46:40 by kshanti          ###   ########.fr       */
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
	int						col_eat;
	long int				last_eat;
	long int				limit;
	struct s_settings		*data;
	pthread_mutex_t			*left;
	pthread_mutex_t			*right;
}							t_pthread_philo;
/*--------------------------------Utils---------------------------------------*/
/*-------Base_Utils----------*/
int				error(char *str);
int				ft_strlen(char *str);
int				ft_atoi(char *str, char **flag);
/*-------Philo_Utils---------*/
int				get_arg(char *str, int *flag);
/*--------------------------------Init----------------------------------------*/
int				init(char **argv, t_pthread_philo **p_philo);
t_settings		*init_settings(char **argv);
pthread_mutex_t	*init_mutex(int number);
/*--------------------------------Philo_Utils---------------------------------*/

#endif
