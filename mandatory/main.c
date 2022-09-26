/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:48:26 by hirebbec          #+#    #+#             */
/*   Updated: 2022/03/24 20:53:26 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_pth(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num)
	{
		pthread_mutex_lock(&data->fid[data->num]);
		data->philo_num = i + 1;
		pthread_create(&data->pid[i], NULL, philo_life, (void *) data);
		i = i + 2;
	}
	i = 1;
	while (i < data->num)
	{
		pthread_mutex_lock(&data->fid[data->num]);
		data->philo_num = i + 1;
		pthread_create(&data->pid[i], NULL, philo_life, (void *) data);
		i = i + 2;
	}
}

int	lol(long die_time)
{
	printf("0 phlo 1 takes first fork\n");
	usleep(die_time * 1000);
	printf("%ld philo 1 die:(\n", die_time);
	return (1);
}

int	start(t_data *data)
{
	int	death;

	death = 0;
	data->death = &death;
	data->pid = malloc(sizeof(pthread_t) * data->num);
	if (data->num == 0)
		return (1);
	else if (data->num == 1)
		return (lol(data->die_time));
	create_pth(data);
	while (!*data->death)
		usleep(1000);
	usleep(1000);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if ((argc != 5 && argc != 6) || !ft_check(argv))
		return (error_msg("Wrong arguments\n"));
	if (!mutex_create(&data, ft_atoi(argv[1])))
		return (error_msg("mutex initialization error\n"));
	init(&data, argv);
	start(&data);
	free(data.pid);
	free(data.fid);
}
