# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 09:36:17 by meudier           #+#    #+#              #
#    Updated: 2022/06/29 18:22:11 by maxenceeudi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror -g

NAME = minishell

SRC = utils/ft_strjoin.c utils/ft_split.c src/main.c \
	utils/ft_strdup.c utils/ft_strlen.c utils/ft_strcmp.c \
	src/ft_split_lexer.c src/pipe.c src/parser.c src/lexer.c \
	src/close.c utils/ft_calloc.c src/cpy.c
	
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $^ -lreadline -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean