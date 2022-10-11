# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 08:30:58 by maxenceeudi       #+#    #+#              #
#    Updated: 2022/10/11 18:30:26 by maxenceeudi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++ -Wall -Wextra -Werror -std=c++98 -g

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

NAME = ft_containers

all: $(NAME)

%.o:%.cpp
	$(CC) -c $< -o $@

$(NAME): vector utils rbt
	

vector: $(OBJ_VEC_STD) $(OBJ_VEC)
		if [! -f test_vector] then mkdir test_vector fi;
		$(CC) test/test_vector.o -o test_vector/vectorFt && \
		$(CC) test/test_vector_std.o -o test_vector/vectorStd;
		./test_vector/vectorFt > test_vector/vector_ft;
		./test_vector/vectorStd > test_vector/vector_std;
		diff test_vector/vector_ft test_vector/vector_std > test_vector/diff;
		clear;
		./test_vector/vectorFt
		
utils:	$(OBJ_UTL_STD) $(OBJ_UTL)
		mkdir test_utils
		$(CC) test/test_utils.o -o test_utils/utilsFt && \
		$(CC) test/test_utils_std.o -o test_utils/utilsStd;
		./test_utils/utilsFt > test_utils/utils_ft;
		./test_utils/utilsStd > test_utils/utils_std;
		diff test_utils/utils_ft test_utils/utils_std > test_utils/diff;
		clear && \
		./test_utils/utilsFt

rbt:	$(OBJ_RBT)
		mkdir test_RBT;
		$(CC) test/test_RBT.o -o test_RBT/RBTFt;
		clear;
		./test_RBT/RBTFt;

clean:
		rm -rf $(OBJ_UTL) $(OBJ_UTL_STD) $(OBJ_VEC) $(OBJ_VEC_STD) \
		$(OBJ_RBT)

fclean: clean
	rm -rf  test_vector test_utils test_RBT;

re: fclean all

.PHONY: all re clean fclean