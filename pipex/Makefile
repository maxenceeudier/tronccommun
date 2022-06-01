# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meudier <meudier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 11:53:31 by meudier           #+#    #+#              #
#    Updated: 2022/06/01 14:39:44 by meudier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror -g

NAME = pipex

SRC = pipex2.c ft_printf/ft_printf.c ft_printf/ft_utils.c ft_printf/ft_utils2.c \
	utils/split.c utils/ft_calloc.c utils/ft_strncmp.c utils/ft_strdup.c \
	utils/ft_strjoin.c utils/ft_strlen.c utils/free_tab.c close_all.c \
	create_process.c get_data.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean fclean all


.PHONY: re clean fclean
