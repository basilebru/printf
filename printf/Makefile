SRC = $(wildcard printf*_n.c) 
LIBFT = $(wildcard libft/*.c)
BONUS = $(wildcard printf*_bonus.c)

SRC_OBJ = $(SRC:%.c=%.o)
LIBFT_OBJ = $(LIBFT:%.c=%.o)
BON_OBJ = $(BONUS:%.c=%.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(SRC_OBJ) $(LIBFT_OBJ)
	ar rc $@ $(SRC_OBJ) $(LIBFT_OBJ)

bonus: $(BON_OBJ) $(LIBFT_OBJ)
	rm -rf $(NAME)
	ar rc libftprintf.a $(BON_OBJ) $(LIBFT_OBJ)

%.o: %.c
	gcc -c  -Wall -Werror -Wextra $^ -o $@

clean:
	rm -f $(SRC_OBJ) $(BON_OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
