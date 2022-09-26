/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:38:04 by hirebbec          #+#    #+#             */
/*   Updated: 2022/03/24 20:57:29 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/types.h>
# include <signal.h>

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

typedef struct s_philo
{
	int		philo_num;
	int		life_time;
	int		sleep_time;
	int		eat_time;
	int		eat_num;
	int		num;
	sem_t	*sem;
	int		flag;
	pid_t	*pid;
	sem_t	*msg;
	sem_t	*death;
	long	born_time;
	long	start_eat;
	long	start_sleep;
	long	last_eat;
}	t_philo;

int		ft_check(char **argv);
int		error_msg(char *msg);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	creating_forks(t_philo *philo);
void	init(t_philo *philo, char **argv);
int		time_now(void);
void	lol(t_philo *philo);
void	message(int event, t_philo philo, long time);
#endif