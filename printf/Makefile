# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meudier <meudier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 17:31:42 by meudier           #+#    #+#              #
#    Updated: 2022/05/03 18:13:56 by meudier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =gcc

FLAGS = -Wall -Wextra -Werror

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $^ 
        
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(OBJ) $(OBJ_BONUS)
	ar -crs $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean re fclean all