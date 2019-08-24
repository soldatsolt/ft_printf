NAME = libftprintf.a
SRC = ./$(wildcard)*.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	make -C libft
	cp libft/libft.a libftprintf.a
	gcc -Wall -Wextra -Werror -c $(SRC) -Ift_printf.h -Ilibft/libft.h
	ar -rc $@ $(OBJ)
	ranlib $@
fclean: clean
	make -C libft fclean
	rm -f $(NAME)
clean:
	make -C libft clean
	rm -f $(OBJ)
re: fclean all