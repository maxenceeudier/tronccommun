CC = gcc -Wall -Wextra -Werror -pthread -g

NAME = philo

SRC = src/philo.c utils/ft_atoi.c utils/free_tab.c src/time.c \
	src/get_all_data.c src/routine.c src/print.c src/thread.c \
	src/check.c utils/ft_isdigit.c

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