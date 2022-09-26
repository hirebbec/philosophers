/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:15:29 by hirebbec          #+#    #+#             */
/*   Updated: 2022/03/24 20:54:58 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define FORK_1	1
# define FORK_2	2
# define EAT	3
# define SLEEP	4
# define THINK	5
# define DIE	6

# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define WHITE	"\033[0;37m"
# define BLUE	"\033[0;34m"
# define RED	"\033[0;31m"

typedef struct s_data
{
	pthread_t		*pid;
	pthread_mutex_t	*fid;
	int				num;
	int				die_time;
	int				sleep_time;
	int				eat_time;
	int				eat_num;
	int				*death;
	int				philo_num;
}	t_data;

typedef struct s_tmp
{
	int				f1;
	int				f2;
	int				p;
	int				b_t;
	int				s_e;
	int				start_sleep;
	int				eat_num;
	int				flag;
}	t_tmp;
//
//UTILS
//
int		error_msg(char *msg);
int		ft_check(char **argv);
int		ft_isnumber(char *str);
int		time_now(void);
void	message(t_tmp tmp, int event, long time, t_data *data);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
//
//MANDATORY
//
int		mutex_create(t_data *data, int num);
void	init(t_data *data, char **argv);
void	*philo_life(void *link);
int		start(t_data *data);
int		p_eating(t_data *data, t_tmp *tmp);
int		ch_death(t_data *data, t_tmp *tmp, int time, int d_time);
int		p_sleep_think(t_data *data, t_tmp *tmp);
#endif