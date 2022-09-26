/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:19:37 by hirebbec          #+#    #+#             */
/*   Updated: 2022/03/24 20:54:15 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../mandatory/philo.h"

t_data	*get_forks(void *link, t_tmp *tmp)
{
	t_data	*data;

	data = (t_data *)link;
	tmp->f1 = data->philo_num - 1;
	if (data->philo_num == 1)
		tmp->f2 = data->num - 1;
	else
		tmp->f2 = data->philo_num - 2;
	tmp->b_t = time_now();
	tmp->p = data->philo_num;
	tmp->s_e = tmp->b_t;
	tmp->flag = 0;
	if (data->eat_num == -1)
	{
		tmp->eat_num = 10;
		tmp->flag = 1;
	}
	else
		tmp->eat_num = data->eat_num;
	return (data);
}

void	*philo_life(void *link)
{
	t_data	*data;
	t_tmp	tmp;

	data = get_forks(link, &tmp);
	pthread_mutex_unlock(&data->fid[data->num]);
	tmp.b_t = time_now();
	while (tmp.eat_num > 0)
	{
		if (p_eating(data, &tmp) == 1)
			break ;
		if (p_sleep_think(data, &tmp) == 1)
			break ;
		tmp.eat_num--;
		if (tmp.flag == 1)
			tmp.eat_num++;
	}
	usleep(data->die_time * 1000);
	*data->death = 1;
	return (NULL);
}

int	p_eating(t_data *data, t_tmp *tmp)
{
	pthread_mutex_lock(&data->fid[tmp->f1]);
	message(*tmp, FORK_1, time_now() - tmp->b_t, data);
	pthread_mutex_lock(&data->fid[tmp->f2]);
	message(*tmp, FORK_2, time_now() - tmp->b_t, data);
	message(*tmp, EAT, time_now() - tmp->b_t, data);
	tmp->s_e = time_now();
	while (data->eat_time + tmp->s_e > time_now())
	{
		usleep(100);
		if (ch_death(data, tmp, time_now() - tmp->s_e, time_now() - tmp->b_t))
			return (1);
	}
	pthread_mutex_unlock(&data->fid[tmp->f1]);
	pthread_mutex_unlock(&data->fid[tmp->f2]);
	if (tmp->eat_num == 1 && data->philo_num == data->num - 1)
		return (1);
	return (0);
}

int	ch_death(t_data *data, t_tmp *tmp, int time, int d_time)
{
	if (data->die_time <= time)
	{
		if (*data->death == 1)
			return (1);
		*data->death = 1;
		usleep(10);
		printf(RED "%d philo %d dies:(\n" WHITE, d_time, tmp->p);
		return (1);
	}
	return (0);
}
