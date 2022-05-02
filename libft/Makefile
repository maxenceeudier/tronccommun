# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meudier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 18:02:03 by meudier           #+#    #+#              #
#    Updated: 2022/05/02 18:13:36 by meudier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =gcc

FLAGS =-Wall -Wextra -Werror

SRC = $(wildcard ft*)

OBJ = $(SRC:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $^ 
        
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: clean re fclean all
