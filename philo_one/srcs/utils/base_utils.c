/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:09:33 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/24 15:57:06 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	ft_atoi(char *str, char **flag)
{
	unsigned int	res;
	unsigned int	i;

	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || \
		str[i] == '\r' || str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	if (flag)
		*flag = &str[i];
	if (res <= 2147483647)
		return (res);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}
