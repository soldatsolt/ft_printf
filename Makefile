NAME = ft_printf
MAKE = make
SRC = ./srcs/
override G += 
FLAGS = -Wall -Wextra -Werror
SRCS = $(SRC)main.c \
       $(SRC)preparce_for_flags.c \
       $(SRC)all_flagsspec.c \
       $(SRC)make_str_with_precision_for_any.c \
       $(SRC)make_ox_for_any.c \
       $(SRC)l_ll_h_hh_for_x.c \
       $(SRC)l_ll_h_hh_for_u.c \
       $(SRC)l_ll_h_hh_for_o.c \
       $(SRC)l_ll_h_hh_for_i.c \
       $(SRC)parsing_and_flags.c \
       $(SRC)print_float.c \
       $(SRC)buffer.c \
       $(SRC)str_calc.c \
       $(SRC)long_double.c \
       $(SRC)double.c \
       $(SRC)none_infinity.c \
       $(SRC)str_calc_extra.c \

OBJS = main.o \
       preparce_for_flags.o \
       all_flagsspec.o \
       make_str_with_precision_for_any.o \
       make_ox_for_any.o \
       l_ll_h_hh_for_x.o \
       l_ll_h_hh_for_u.o \
       l_ll_h_hh_for_o.o \
       l_ll_h_hh_for_i.o \
       parsing_and_flags.o \
       print_float.o \
       buffer.o \
       str_calc.o \
       long_double.o \
       double.o \
       none_infinity.o \
       str_calc_extra.o \
       libft/libft.a

LIBFT = ./libft/libft.a
INCLUDE = ./ft_printf.h
all: $(NAME)  #ft_printf.a 

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc $(FLAGS) -c $(SRCS)
	ar rcs libftprintf.a $(OBJS)

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