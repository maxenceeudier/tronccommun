CC = c++ -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

NAME = megaphone

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

.PHONY: all re clean fclean