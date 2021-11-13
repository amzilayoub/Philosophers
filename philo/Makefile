# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamzil <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 15:29:46 by aamzil            #+#    #+#              #
#    Updated: 2021/11/13 15:29:47 by aamzil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo

FLAGS=-Wall -Wextra -Werror

SRC =	error_handling/error.c						\
		helper_functions/convert_to_milisec.c		\
		helper_functions/custom_isdigit.c			\
		helper_functions/custom_printf.c			\
		helper_functions/custom_usleep.c			\
		helper_functions/ft_atoi.c					\
		helper_functions/get_time_now.c				\
		helper_functions/watcher_helper_function.c	\
		init.c										\
		main.c										\
		parser/parser.c								\
		philosopher/philo.c							\
		philosopher/routines.c						\
		philosopher/start_threads.c					\

all: $(NAME)

$(NAME): $(SRC)
	gcc $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all