/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:28:04 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/11 22:28:37 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	all_free(t_pthread_philo *philo)
{
	if (!philo)
		return (1);
	free(philo->left);
	free(philo->data);
	free(philo);
}

int		get_arg(char *str, int *flag)
{
	char	*test;
	int		i;
	int		res;

	test = NULL;
	res = ft_atoi(str, &test);
	i = 0;
	while (test && test[i] == ' ')
		i++;
	if (res <= 0 || (test && test[i] != '\0'))
		*flag = 1;
	return (res);
}
