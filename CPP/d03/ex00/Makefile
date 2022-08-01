# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 08:30:58 by maxenceeudi       #+#    #+#              #
#    Updated: 2022/08/01 16:36:32 by maxenceeudi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++ -Wall -Wextra -Werror -std=c++98 -g

SRC = ClapTrap.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = claptrap

all: $(NAME)

%.o:%.cpp
	$(CC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean