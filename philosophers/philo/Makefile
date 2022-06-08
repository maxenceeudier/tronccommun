CC = gcc -g -Wall -Wextra -Werror -pthread

NAME = philo

SRC = src/philo.c utils/ft_atoi.c utils/free_tab.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re clean fclean