/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:38:18 by hirebbec          #+#    #+#             */
/*   Updated: 2022/03/24 18:56:24 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	if ((argc != 5 && argc != 6) || !ft_check(argv))
		return (error_msg("Wrong arguments\n"));
	init(&philo, argv);
	sem_unlink("forks");
	philo.msg = sem_open("msg", O_CREAT, 00644, 1);
	if (philo.sem < 0)
		error_msg("sem error\n");
	creating_forks(&philo);
	free(philo.pid);
	sem_unlink("forks");
	sem_unlink("msg");
	return (0);
}
