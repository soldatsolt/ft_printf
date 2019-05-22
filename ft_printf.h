/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 10:18:18 by kmills            #+#    #+#             */
/*   Updated: 2019/05/22 09:49:13 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H
# include "./libft/libft.h"

typedef struct	s_flags
{
	int			dash;
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			width;
	int			precision;
}				t_flags;

char	*strplus(char *str1, char *str2);
int		ft_printf(const char *restrict format, ...);
char	*charumn(char c1, char c2);
char	*strminus(char *str1, char *str2);
int		srav_nums(char *str1, char *str2);
void	replace_strings(char **str1, char **str2);

#endif
