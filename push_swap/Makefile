# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meudier <meudier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 08:40:51 by meudier           #+#    #+#              #
#    Updated: 2022/05/12 12:38:15 by meudier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror

SRC_CK = checker.c get_rules_ck.c init_list.c rules_ck_and_ps.c \
	rules_ck.c utils.c

OBJ_CK = $(SRC_CK:.c=.o)

SRC_PS = push_swap.c sort_short.c ft_utils_radix.c radix.c init_list.c rules_ck_and_ps.c \
	rules_ps_a.c rules_ps_b.c utils_ps.c utils.c rules_a_b.c q_sort.c 

OBJ_PS = $(SRC_PS:.c=.o)

NAME = push_swap

all: $(NAME)

%o: %c
	$(CC) -c $< -o $^

$(NAME): $(OBJ_PS)
	$(CC) $(OBJ_PS) -o push_swap
	
bonus: $(OBJ_CK)
	$(CC) $(OBJ_CK) -o checker

clean: 
	rm -f $(OBJ_CK) $(OBJ_PS)

fclean: clean
	rm -f $(NAME) checker

re: fclean all

.PHONY: all clean fclean re
