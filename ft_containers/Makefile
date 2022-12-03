# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 08:30:58 by maxenceeudi       #+#    #+#              #
#    Updated: 2022/12/02 21:06:02 by maxenceeudi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++ 
FLAGS = -Wall -Wextra -Werror -g
STD = -std=c++98

SRC =	test/test_map.cpp test/test_map_std.cpp \
		test/test_vector.cpp test/test_vector_std.cpp \
		test/test_RBT.cpp \
		test/test_stack.cpp test/test_stack_std.cpp \
		main.cpp \
		test/test_utils.cpp test/test_utils_std.cpp

OBJ =	$(SRC:.cpp=.o)

NAME = ft_containers

all: $(NAME)

%.o:	%.cpp 
	$(CC) $(FLAGS)  -c  $< -o $@


$(NAME): $(OBJ) 
	

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf  test_vector test_utils test_RBT test_stack test_map;

re: fclean all

.PHONY: all re clean fclean