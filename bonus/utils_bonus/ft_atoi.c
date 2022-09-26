/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:03:34 by hirebbec          #+#    #+#             */
/*   Updated: 2022/03/17 20:03:35 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo_bonus.h"

static int	pars_minus(const char *str, int *i, long int *n)
{
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*n *= -1;
		(*i)++;
		if (str[*i] == '-' || str[*i] == '+')
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	n;
	long int	k;

	i = 0;
	n = 1;
	k = 0;
	while (((str[i] >= 7) && (str[i] <= 13)) || (str[i] == ' '))
		i++;
	if (!pars_minus (str, &i, &n))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = (k * 10) + str[i] - '0';
		if ((k * n) > 2147483647)
			return (-1);
		if ((k * n) < -2147483648)
			return (0);
		i++;
	}
	return (k * n);
}
