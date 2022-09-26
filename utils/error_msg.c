/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:56:39 by hirebbec          #+#    #+#             */
/*   Updated: 2022/03/24 20:41:38 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../mandatory/philo.h"

int	error_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (0);
}

int	ft_check(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_isnumber(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	message(t_tmp tmp, int event, long time, t_data *data)
{
	pthread_mutex_lock(&data->fid[data->num + 1]);
	printf("\033[0;36m" "%ld " WHITE, time);
	if (event == 1)
		printf(GREEN "philo %d took first fork\n" WHITE, tmp.p);
	else if (event == 2)
		printf(GREEN "philo %d took second fork\n" WHITE, tmp.p);
	else if (event == 3)
		printf(YELLOW "philo %d is eating\n" WHITE, tmp.p);
	else if (event == 4)
		printf(WHITE "philo %d is sleeping\n" WHITE, tmp.p);
	else if (event == 5)
		printf(BLUE "philo %d is thinking\n" WHITE, tmp.p);
	else
	{
		printf(RED "philo %d dies\n" WHITE, tmp.p);
		return ;
	}
	pthread_mutex_unlock(&data->fid[data->num + 1]);
}
