# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 19:05:21 by hirebbec          #+#    #+#              #
#    Updated: 2022/03/17 20:24:37 by hirebbec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

NAME_BONUS = philo_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = mandatory/main.c utils/error_msg.c utils/mutex.c utils/philo_life.c utils/ft_strlen.c \
		utils/ft_isdigit.c utils/ft_atoi.c

FILES_BONUS =	bonus/main_bonus.c bonus/utils_bonus/ft_check.c bonus/utils_bonus/error_msg.c \
				bonus/utils_bonus/ft_strlen.c bonus/utils_bonus/init.c bonus/utils_bonus/philo_life.c \
				bonus/utils_bonus/ft_atoi.c
					
OBJS = $(FILES:%.c=%.o)

OBJS_BONUS = $(FILES_BONUS:%.c=%.o)


%.o: %.c mandatory/philo.h
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

.PHONY:all clean fclean re bonus
