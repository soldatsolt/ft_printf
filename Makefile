NAME = ft_printf
MAKE = make
override G += 
FLAGS = -Wall -Wextra -Werror
SRCS = main.c l_ll_h_hh_for_i.c parsing_and_flags.c print_float.c buffer.c str_calc.c libft/libft.a
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
INCLUDE = ./ft_printf.h
all: $(NAME) #ft_printf.a

$(NAME): $(LIBFT)
	@gcc ./libft/libft.a $(SRCS) -g -o $(NAME)

g:
	@gcc -g $(SRCS) -o $(NAME)

ft_printf.a:
	@gcc -c $(SRCS) ./libft/ft_atoi.c ./libft/ft_itoa.c ./libft/ft_strlen.c ./libft/ft_strcpy.c \
	 ./libft/ft_utoa.c ./libft/ft_memalloc.c ./libft/ft_bzero.c ./libft/ft_memset.c \
	 ./libft/ft_strdup.c ./libft/ft_catstr.c ./libft/ft_itoa_base_small.c \
	 ./libft/ft_strnew.c ./libft/ft_itoa_h.c ./libft/ft_itoa_hh.c ./libft/ft_itoa_l.c \
	 ./libft/ft_itoa_ll.c -I $(INCLUDE)
	@ar rc libftprintf.a ./*.o
	@rm -f *.o

clean:
	@rm -f *.o
	@$(MAKE) -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	@rm -f libftprintf.a

re: fclean all

$(LIBFT):
	@$(MAKE) -C ./libft re

git:
	git add .
	git commit -am "$(G)"
	git push

rerun: re
	@./ft_printf