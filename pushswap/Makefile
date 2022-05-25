# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meudier <meudier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 08:40:51 by meudier           #+#    #+#              #
#    Updated: 2022/05/18 14:29:10 by meudier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror

SRC_CK = checker_bonus.c get_rules_ck_bonus.c init_list.c rules_ck_and_ps.c \
	utils.c no_leaks.c  utils2.c rules_ck_bonus.c

OBJ_CK = $(SRC_CK:.c=.o)

SRC_PS = push_swap.c sort_short.c init_list.c rules_ck_and_ps.c \
	rules_ps_a.c rules_ps_b.c utils_ps.c utils.c q_sort.c \
	get_mid_and_chunk.c no_leaks.c utils2.c

OBJ_PS = $(SRC_PS:.c=.o)

NAME = push_swap

all: $(NAME)

%o: %c
	$(CC) -c $< -o $^

$(NAME): $(OBJ_PS)
	$(CC) $(OBJ_PS) -o push_swap
	
checker: $(OBJ_CK)
	$(CC) $(OBJ_CK) -o checker
	
bonus: checker

clean: 
	rm -f $(OBJ_CK) $(OBJ_PS)

fclean: clean
	rm -f $(NAME) checker

re: fclean all

.PHONY: all clean fclean re
