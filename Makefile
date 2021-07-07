# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 23:54:19 by kshanti           #+#    #+#              #
#    Updated: 2021/07/08 00:02:45 by kshanti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEAD = ./philosophers.h
SRCS=./philo_d/
CFLAGS = -Wall -Wextra -Werror
C_FILE = $(SRCS)main.c $(SRCS)philo_utils.c $(SRCS)utils.c
O_FILE = $(C_FILE:.c=.o)

all:
	$(MAKE) $(NAME) -j 4

$(NAME): $(O_FILE)
	gcc $(O_FILE) -o $(NAME)

%.o: %.c $(HEAD)
	gcc -c $(СFLAGS) $< -o $@

clean:
	@rm -f $(O_FILE)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
