/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:26:21 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/18 23:51:29 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "pthread.h"
# include "sys/time.h"

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"

pthread_mutex_t getTime_mutex;

typedef struct s_settings
{
	int						number;
	int						time_die;
	int						time_eat;
	int						time_sleep;
	int						column_eat_for_die;
	long int				start_time;
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
long int		get_time();
int				my_sleep(int sleep);
int				all_free(t_pthread_philo *philo);
int				get_arg(char *str, int *flag);
/*--------------------------------Init----------------------------------------*/
int				init(char **argv, t_pthread_philo **p_philo);
t_settings		*init_settings(char **argv);
pthread_mutex_t	*init_mutex(int number);
t_pthread_philo	*init_philo(t_settings *settings, pthread_mutex_t *mutex);
/*--------------------------------Treads--------------------------------------*/
void  		  	eating(t_pthread_philo *philo);
void   			sleeping(t_pthread_philo *philo);
void			thinking(t_pthread_philo *philo);
void			*life(void	*arg);
int 			go_treads(t_pthread_philo *philo);

#endif
