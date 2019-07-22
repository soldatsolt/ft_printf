NAME = ft_printf
MAKE = make
override G += 
FLAGS = -Wall -Wextra -Werror
SRCS = main.c \
       preparce_for_flags.c \
       all_flagsspec.c \
       make_str_with_precision_for_any.c \
       make_ox_for_any.c \
       l_ll_h_hh_for_x.c \
       l_ll_h_hh_for_u.c \
       l_ll_h_hh_for_o.c \
       l_ll_h_hh_for_i.c \
       parsing_and_flags.c \
       print_float.c \
       buffer.c \
       str_calc.c \
       long_double.c \
       libft/libft.a

OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
INCLUDE = ./ft_printf.h
all: $(NAME)  #ft_printf.a 

$(NAME): $(LIBFT)
	@gcc ./libft/libft.a $(SRCS) -g -o $(NAME)

g:
	@gcc -g $(SRCS) -o $(NAME)

ft_printf.a:
	@gcc -c $(SRCS) -I $(INCLUDE)
	@ar -x ./libft/libft.a
	@ar rc libftprintf.a *.o
	@rm -f *.o

clean:
	@rm -f *.o
	@$(MAKE) -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	@rm -f libftprintf.a

re: fclean all

lib:
	@$(MAKE) -C ./libft re
	@$(MAKE) -C ./libft clean

git:
	git add .
	git commit -am "$(G)"
	git push

rerun: re
	@./ft_printf