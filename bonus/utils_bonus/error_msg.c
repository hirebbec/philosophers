/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:49:15 by hirebbec          #+#    #+#             */
/*   Updated: 2022/03/24 20:55:49 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo_bonus.h"

int	error_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (0);
}

void	message(int event, t_philo philo, long time)
{
	sem_wait(philo.msg);
	printf("%ld ", time);
	if (event == 1)
		printf(GREEN "philo %d took first fork\n" WHITE, philo.philo_num);
	else if (event == 2)
		printf(GREEN "philo %d took second fork\n" WHITE, philo.philo_num);
	else if (event == 3)
		printf(YELLOW "philo %d is eating\n" WHITE, philo.philo_num);
	else if (event == 4)
		printf(WHITE "philo %d is sleeping\n" WHITE, philo.philo_num);
	else if (event == 5)
		printf(BLUE "philo %d is thinking\n" WHITE, philo.philo_num);
	else
		printf(RED "philo %d dies\n" WHITE, philo.philo_num);
	sem_post(philo.msg);
}

int	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
