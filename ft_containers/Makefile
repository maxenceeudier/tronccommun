# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meudier <meudier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 08:30:58 by maxenceeudi       #+#    #+#              #
#    Updated: 2022/11/18 13:01:37 by meudier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++ 
FLAGS = -Wall -Wextra -Werror -g
STD = -std=c++98

SRC =	test/test_map.cpp test/test_map_std.cpp \
		test/test_utils.cpp test/test_utils_std.cpp \
		test/test_vector.cpp test/test_vector_std.cpp \
		test/test_RBT.cpp \
		test/test_stack.cpp test/test_stack_std.cpp

OBJ =	$(SRC:.cpp=.o)

#test utils
UTL =	test/test_utils.cpp
OBJ_UTL = $(UTL:.cpp=.o)
UTL_STD =	test/test_utils_std.cpp
OBJ_UTL_STD = $(UTL_STD:.cpp=.o)

#test vector
VEC =	test/test_vector.cpp
OBJ_VEC =	$(VEC:.cpp=.o)
VEC_STD =	test/test_vector_std.cpp
OBJ_VEC_STD =	$(VEC_STD:.cpp=.o)

#test RBT
RBT =	test/test_RBT.cpp
OBJ_RBT =	$(RBT:.cpp=.o)

#test stack
STK =	test/test_stack.cpp
OBJ_STK =	$(STK:.cpp=.o)
STK_STD =	test/test_stack_std.cpp
OBJ_STK_STD =	$(STK_STD:.cpp=.o)

#test map
MAP = test/test_map.cpp
OBJ_MAP = $(MAP:.cpp=.o)
MAP_STD = test/test_map_std.cpp
OBJ_MAP_STD = $(MAP_STD:.cpp=.o)

NAME = ft_containers

all: $(NAME)

%.o:	%.cpp 
	$(CC) -c  $< -o $@


$(NAME): $(OBJ) vector map stack utils rbt


vector:
		@mkdir -p test_vector
		$(CC) $(FLAGS) $(STD) test/test_vector.o -o test_vector/vectorFt;
		$(CC) $(FLAGS) $(STD) test/test_vector_std.o -o test_vector/vectorStd;
		./test_vector/vectorFt > test_vector/vector_ft;
		./test_vector/vectorStd > test_vector/vector_std;


map: 	
		@mkdir -p test_map
		$(CC) $(FLAGS) $(STD) test/test_map.o -o test_map/mapFt;
		$(CC) $(FLAGS) $(STD) test/test_map_std.o -o test_map/mapStd;
		./test_map/mapFt > test_map/map_ft;
		./test_map/mapStd > test_map/map_std;
		
		
utils:
		@mkdir -p test_utils
		$(CC) $(FLAGS) $(STD) test/test_utils.o -o test_utils/utilsFt && \
		$(CC) $(FLAGS) -std=c++11 test/test_utils_std.o -o test_utils/utilsStd;
		./test_utils/utilsStd > test_utils/utils_std;
		./test_utils/utilsFt > test_utils/utils_ft;


rbt:
		@mkdir -p test_RBT;
		$(CC) $(FLAGS) $(STD) test/test_RBT.o -o test_RBT/RBTFt;

stack:
		@mkdir -p test_stack
		$(CC) $(FLAGS) $(STD) test/test_stack.o -o test_stack/stackFt && \
		$(CC) $(FLAGS) $(STD) test/test_stack_std.o -o test_stack/stackStd;
		./test_stack/stackFt > test_stack/stack_ft;
		./test_stack/stackStd > test_stack/stack_std;


clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf  test_vector test_utils test_RBT test_stack test_map;

re: fclean all

.PHONY: all re clean fclean