/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:01:30 by hirebbec          #+#    #+#             */
/*   Updated: 2022/03/24 20:57:07 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo_bonus.h"

void	init(t_philo *philo, char **argv)
{
	int	i;

	i = -1;
	philo->num = ft_atoi(argv[1]);
	philo->life_time = ft_atoi(argv[2]);
	philo->eat_time = ft_atoi(argv[3]);
	philo->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
	{
		philo->eat_num = ft_atoi(argv[5]);
		philo->flag = 1;
	}
	else
	{
		philo->eat_num = 100;
		philo->flag = -1;
	}
	philo->pid = malloc(sizeof(pid_t) * philo->num);
	if (!philo->pid)
		error_msg("malloc error\n");
	sem_unlink("forks");
	philo->sem = sem_open("forks", O_CREAT, 0640, philo->num);
	sem_unlink("death");
	philo->death = sem_open("death", O_CREAT, 0640, 1);
}

void	lol(t_philo *philo)
{
	printf("0 philo 1 took first fork\n");
	usleep(philo->life_time * 1000);
	printf("%d philo 1 is die :(\n", philo->life_time);
	exit(0);
}
