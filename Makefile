SRC = $(wildcard printf*.c) $(wildcard libft/*.c)

OBJ = $(SRC:%.c=%.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)

%.o: %.c
	gcc -c  -Wall -Werror -Wextra $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
