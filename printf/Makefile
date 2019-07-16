# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbharbo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/27 18:21:59 by vbharbo           #+#    #+#              #
#    Updated: 2019/07/10 16:48:55 by vbharbo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
NAMEL = libftprintf.a
SRCS = ./srcs/

SRC = $(SRCS)ft_extra_int.c \
	  $(SRCS)ft_printf.c \
	  $(SRCS)ft_printf_int.c \
	  $(SRCS)ft_printf_char.c \
	  $(SRCS)ft_printf_str.c \
	  $(SRCS)ft_printf_unsigned.c \
	  $(SRCS)ft_extra_oxXunsigned.c \
	  $(SRCS)ft_printf_octo.c \
	  $(SRCS)ft_printf_double.c \
	  $(SRCS)ft_extra_double.c \
	  $(SRCS)str_calc.c \
	  $(SRCS)extra_calc.c \
	  $(SRCS)ft_printf_x.c \

SRCO = ft_extra_int.o \
	   ft_printf.o \
	   ft_printf_int.o \
	   ft_printf_char.o \
	   ft_printf_str.o \
	   ./libft/ft_atoi.o \
	   ./libft/ft_putchar.o \
	   ./libft/ft_putnbr.o \
	   ./libft/ft_putstr.o \
	   ./libft/ft_bzero.o \
	   ./libft/ft_memalloc.o \
	   ./libft/ft_memdel.o \
	   ./libft/ft_strlen.o \
	   ./libft/ft_strclr.o \
	   ./libft/ft_strnew.o \
	   ./libft/ft_strdup.o \
	   ./libft/ft_itoa_base_small.o \
	   ./libft/ft_itoa_base_big.o \
	   ft_extra_oxXunsigned.o \
	   ft_printf_unsigned.o \
	   ft_printf_octo.o \
	   extra_calc.o \
	   str_calc.o \
	   ft_extra_double.o \
	   ft_printf_double.o \
	   ft_printf_x.o

all: $(MAKELIB) $(NAME)

FLAGS = -Wextra -Werror -Wall

HEADER = ./includes
	

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc $(FLAGS) -c $(SRC) -I $(HEADER)
	ar rcs $(NAMEL) $(SRCO)

clean:
	rm -f *.o
	rm -rf ./libft/*.o
	rm -rf ./libft/libft.a

fclean: clean
	rm -f $(NAME) $(NAMEL)

re: fclean all
