/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:09:27 by hirebbec          #+#    #+#             */
/*   Updated: 2022/03/24 20:57:15 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo_bonus.h"

int	check_death(t_philo *philo, int d_time)
{
	if (philo->life_time < time_now() - philo->start_eat)
	{
		sem_wait(philo->death);
		message(DIE, *philo, d_time);
		return (1);
	}
	return (0);
}

int	philo_eat(t_philo *philo)
{
	sem_wait(philo->sem);
	message(FORK_1, *philo, time_now() - philo->born_time);
	sem_wait(philo->sem);
	message(FORK_2, *philo, time_now() - philo->born_time);
	message(EAT, *philo, time_now() - philo->born_time);
	philo->start_eat = time_now();
	while (philo->start_eat + philo->eat_time > time_now())
	{
		if (check_death(philo, time_now() - philo->born_time) == 1)
			return (1);
	}
	philo->last_eat = time_now();
	sem_post(philo->sem);
	sem_post(philo->sem);
	if (philo->eat_num == 1 && philo->philo_num == philo->philo_num)
		return (1);
	return (0);
}

int	philo_sleep_think(t_philo *philo)
{
	message(SLEEP, *philo, time_now() - philo->born_time);
	philo->start_sleep = time_now();
	while (philo->start_sleep + philo->sleep_time > time_now())
	{
		if (check_death(philo, time_now() - philo->born_time) == 1)
			return (1);
	}
	message(THINK, *philo, time_now() - philo->born_time);
	while (philo->eat_time * 2 + philo->start_eat > time_now())
	{
		if (check_death(philo, time_now() - philo->born_time) == 1)
			return (1);
	}
	return (0);
}

void	philo_life(t_philo *philo)
{
	if (philo->philo_num == 1)
		philo->born_time = time_now();
	philo->last_eat = time_now();
	while (philo->eat_num != 0)
	{
		if (philo_eat(philo) == 1)
			return ;
		if (philo_sleep_think(philo) == 1)
			return ;
		philo->eat_num--;
		if (philo->flag == -1)
			philo->eat_num++;
	}
}

void	creating_forks(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->num == 1)
		lol(philo);
	while (i < philo->num)
	{
		if (i != 0)
			philo->born_time = time_now();
		philo->philo_num = i + 1;
		philo->pid[i] = fork();
		if (philo->pid[i] < 0)
			error_msg("fork error\n");
		else if (philo->pid[i] == 0)
		{
			philo_life(philo);
			return ;
		}
		else if (philo->pid[i] > 0)
			i++;
	}
	wait(&i);
	i = -1;
	while (++i < philo->num)
		kill(philo->pid[i], SIGKILL);
}
