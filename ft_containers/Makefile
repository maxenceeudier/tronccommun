# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meudier <meudier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 08:30:58 by maxenceeudi       #+#    #+#              #
#    Updated: 2022/10/13 17:12:14 by meudier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++ -Wall -Wextra -Werror -g
STD = -std=c++98

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

NAME = ft_containers

all: $(NAME)


%.o:%.cpp
	$(CC) -c $< -o $@

$(NAME): vector utils rbt stack

vector: $(OBJ_VEC_STD) $(OBJ_VEC)
		mkdir test_vector
		$(CC) $(STD) test/test_vector.o -o test_vector/vectorFt && \
		$(CC) $(STD) test/test_vector_std.o -o test_vector/vectorStd;
		./test_vector/vectorFt > test_vector/vector_ft;
		./test_vector/vectorStd > test_vector/vector_std;
		diff test_vector/vector_ft test_vector/vector_std > test_vector/diff;
		
utils:	$(OBJ_UTL_STD) $(OBJ_UTL)
		mkdir test_utils
		$(CC) $(STD) test/test_utils.o -o test_utils/utilsFt && \
		c++ -Wall -Wextra -Werror -std=c++11 test/test_utils_std.o -o test_utils/utilsStd;
		./test_utils/utilsStd > test_utils/utils_std;
		./test_utils/utilsFt > test_utils/utils_ft;
		diff test_utils/utils_ft test_utils/utils_std > test_utils/diff;

rbt:	$(OBJ_RBT)
		mkdir test_RBT;
		$(CC) $(STD) test/test_RBT.o -o test_RBT/RBTFt;

stack:	$(OBJ_STK_STD) $(OBJ_STK)
		mkdir test_stack
		$(CC) $(STD) test/test_stack.o -o test_stack/stackFt && \
		$(CC) $(STD) test/test_stack_std.o -o test_stack/stackStd;
		./test_stack/stackFt > test_stack/stack_ft;
		./test_stack/stackStd > test_stack/stack_std;
		diff test_stack/stack_ft test_stack/stack_std > test_stack/diff;

clean:
		rm -rf $(OBJ_UTL) $(OBJ_UTL_STD) $(OBJ_VEC) $(OBJ_VEC_STD) \
		$(OBJ_RBT) $(OBJ_STK_STD) $(OBJ_STK)

fclean: clean
	rm -rf  test_vector test_utils test_RBT test_stack;

re: fclean all

.PHONY: all re clean fclean