/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:26:21 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/08 00:00:51 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "pthread.h"

typedef struct s_settings
{
	int		number;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		column_eat_for_die;
} t_settings;
/*--------------------------------Utils---------------------------------------*/
int		ft_atoi(char *str, char **flag);
int		ft_strlen(char *str);
int		error(char *str);
/*--------------------------------Philo_Utils---------------------------------*/
int		get_arg(char *str);
void	init_settings(char **argv, t_settings *tmp);

#endif
