# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meudier <meudier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 11:53:31 by meudier           #+#    #+#              #
#    Updated: 2022/06/02 15:21:23 by meudier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror -g

NAME = pipex

BONUS = pipex_bonus

SRC = src/pipex.c ft_printf/ft_printf.c ft_printf/ft_utils.c ft_printf/ft_utils2.c \
	utils/split.c utils/ft_calloc.c utils/ft_strncmp.c utils/ft_strdup.c \
	utils/ft_strjoin.c utils/ft_strlen.c utils/free_tab.c src/close_all.c \
	src/create_process.c src/get_data.c src/dup_fd.c src/get_path_and_arg.c src/init_fds_and_pids.c

OBJ = $(SRC:.c=.o)

SRC_BONUS = bonus/pipex_bonus.c ft_printf/ft_printf.c ft_printf/ft_utils.c ft_printf/ft_utils2.c \
	utils/split.c utils/ft_calloc.c utils/ft_strncmp.c utils/ft_strdup.c \
	utils/ft_strjoin.c utils/ft_strlen.c utils/free_tab.c src/close_all.c \
	src/create_process.c src/get_data.c src/dup_fd.c src/get_path_and_arg.c src/init_fds_and_pids.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $^ -o $@

$(BONUS): $(OBJ_BONUS)
	$(CC) $^ -o $@

bonus: $(BONUS)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: clean fclean all

.PHONY: re clean fclean
