/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:06:37 by hirebbec          #+#    #+#             */
/*   Updated: 2022/03/24 20:54:34 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../mandatory/philo.h"

int	mutex_create(t_data *data, int num)
{
	int	i;

	i = 0;
	data->fid = malloc(sizeof(pthread_mutex_t) * (num + 2));
	while (i < num + 2)
	{
		if (pthread_mutex_init(&data->fid[i], NULL) < 0)
			return (0);
		i++;
	}
	return (1);
}

void	init(t_data *data, char **argv)
{
	data->num = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		data->eat_num = ft_atoi(argv[5]);
	else
		data->eat_num = -1;
}

int	p_sleep_think(t_data *data, t_tmp *tmp)
{
	message(*tmp, SLEEP, time_now() - tmp->b_t, data);
	tmp->start_sleep = time_now();
	while (data->sleep_time + tmp->start_sleep > time_now())
	{
		usleep(100);
		if (ch_death(data, tmp, time_now() - tmp->s_e, time_now() - tmp->b_t))
			return (1);
	}
	message(*tmp, THINK, time_now() - tmp->b_t, data);
	while (data->eat_time * 2 + tmp->s_e > time_now())
	{
		usleep(100);
		if (ch_death(data, tmp, time_now() - tmp->s_e, time_now() - tmp->b_t))
			return (1);
	}
	return (0);
}
