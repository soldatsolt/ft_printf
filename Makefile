NAME = ft_printf
MAKE = make
override G += 
FLAGS = -Wall -Wextra -Werror
SRCS = main.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
all: $(NAME)

$(NAME): $(LIBFT)
	@gcc ./libft/libft.a $(SRCS) -o $(NAME)

g:
	@gcc -g $(SRCS) -o $(NAME)

clean:
	@$(MAKE) -C ./libft clean

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(LIBFT):
	@$(MAKE) -C ./libft re

git:
	git add .
	git commit -am "$(G)"
	git push
