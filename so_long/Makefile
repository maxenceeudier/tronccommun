# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meudier <meudier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 15:52:00 by meudier           #+#    #+#              #
#    Updated: 2022/05/30 15:49:01 by meudier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror

NAME = so_long

SRC = so_long.c split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c get_map.c \
	cmp.c destroy.c free_tab.c get_pos_link.c init_vars.c loop_event.c \
	move.c print_image.c check_extension.c check_line.c get_lines.c \
	init_map.c key_move.c ft_printf/ft_utils.c ft_printf/ft_utils2.c ft_printf/ft_printf.c 

OBJ = $(SRC:.c=.o)

SRC_BONUS = so_long.c split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c get_map.c \
	cmp.c destroy.c free_tab.c get_pos_link.c Bonus/init_vars_bonus.c Bonus/loop_event_bonus.c \
	Bonus/move_bonus.c Bonus/print_image_bonus.c check_extension.c Bonus/check_line_bonus.c get_lines.c \
	init_map.c key_move.c Bonus/print_fire_bonus.c ft_printf/ft_utils.c ft_printf/ft_utils2.c ft_printf/ft_printf.c 

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	cd mlx_linux && make && cd ..
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

bonus : $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME) bonus

re: clean fclean all


.PHONY: re clean fclean 
