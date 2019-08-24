# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmills <kmills@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/24 21:02:57 by kmills            #+#    #+#              #
#    Updated: 2019/08/24 21:03:14 by kmills           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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