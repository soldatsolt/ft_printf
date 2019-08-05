NAME = ft_printf
MAKE = make
SRC = ./srcs/
LIB = ./libft/
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
       $(SRC)free_dd.c \
       $(SRC)u_flags.c	\
	   $(SRC)x_flags.c \
	   $(SRC)x_flags1.c \
       $(LIB)ft_strlen.c \
       $(LIB)ft_strnew.c \
       $(LIB)ft_strcpy.c \
       $(LIB)ft_bzero.c \
       $(LIB)ft_itoa_base_small_hh.c \
       $(LIB)ft_itoa_base_small_h.c \
       $(LIB)ft_itoa_base_small_ll.c \
       $(LIB)ft_itoa_base_small_l.c \
       $(LIB)ft_catstr.c \
       $(LIB)ft_itoa_hh.c \
       $(LIB)ft_itoa_h.c \
       $(LIB)ft_itoa_ll.c \
       $(LIB)ft_itoa_l.c \
       $(LIB)ft_atoi.c \
       $(LIB)ft_memset.c \
       $(LIB)ft_itoa_base_small.c \
       $(LIB)ft_itoa_base_big.c \
       $(LIB)ft_itoa_base_big_l.c \
       $(LIB)ft_itoa_base_big_ll.c \
       $(LIB)ft_itoa_base_big_h.c \
       $(LIB)ft_itoa_base_big_hh.c \
       $(LIB)ft_strdup.c \
       $(LIB)ft_itoa.c \
       $(LIB)ft_utoa.c \
       $(LIB)ft_memalloc.c \
       $(LIB)ft_utoa_l.c \
       $(LIB)ft_utoa_ll.c \
       $(LIB)ft_utoa_h.c \
       $(LIB)ft_utoa_hh.c

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
       free_dd.o \
	   u_flags.o \
	   x_flags.o \
	   x_flags1.o \
       ft_strlen.o \
       ft_strnew.o \
       ft_strcpy.o \
       ft_bzero.o \
       ft_itoa_base_small_hh.o \
       ft_itoa_base_small_h.o \
       ft_itoa_base_small_ll.o \
       ft_itoa_base_small_l.o \
       ft_catstr.o \
       ft_itoa_hh.o \
       ft_itoa_h.o \
       ft_itoa_ll.o \
       ft_itoa_l.o \
       ft_atoi.o \
       ft_memset.o \
       ft_itoa_base_small.o \
       ft_itoa_base_big.o \
       ft_itoa_base_big_l.o \
       ft_itoa_base_big_ll.o \
       ft_itoa_base_big_h.o \
       ft_itoa_base_big_hh.o \
       ft_strdup.o \
       ft_itoa.o \
       ft_utoa.o \
       ft_memalloc.o \
       ft_utoa_l.o \
       ft_utoa_ll.o \
       ft_utoa_h.o \
       ft_utoa_hh.o

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	gcc $(FLAGS) -c $(SRCS)
	ar rcs libftprintf.a $(OBJS)

clean:
	@rm -f *.o
	@$(MAKE) -C ./libft clean

git:
	git add .
	git commit -am "$(G)"
	git push

lib:
	@$(MAKE) -C ./libft re
	@$(MAKE) -C ./libft clean

rerun:
	@gcc $(SRCS) -g -o ft_printf
	./ft_printf

fclean: clean
	@rm -f $(NAME)
	@rm -f libftprintf.a

re: fclean all
