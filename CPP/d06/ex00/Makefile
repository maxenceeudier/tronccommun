# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meudier <meudier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 08:30:58 by maxenceeudi       #+#    #+#              #
#    Updated: 2022/08/22 22:34:56 by meudier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++ -Wall -Wextra -Werror -std=c++98

SRC = main.cpp ConvertType.cpp

OBJ = $(SRC:.cpp=.o)

NAME = convert

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

run: $(NAME)
	./$(NAME) nan;
	./$(NAME) nanf;
	./$(NAME) +inff;
	./$(NAME) +inf;
	./$(NAME) -inf;
	./$(NAME) -inff;
	./$(NAME) -2147483649;
	./$(NAME) -2147483648;
	./$(NAME) 2147483648;
	./$(NAME) 2147483647;
	./$(NAME) 0;
	./$(NAME) 42;
	./$(NAME) 214748364700000000000000000000;
	./$(NAME) ndnwe;
	./$(NAME) 21crr8;
	

.PHONY: all re clean fclean