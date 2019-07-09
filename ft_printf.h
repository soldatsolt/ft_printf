/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 10:18:18 by kmills            #+#    #+#             */
/*   Updated: 2019/07/09 06:26:46 by kmills           ###   ########.fr       */
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

typedef struct	s_buf
{
	char			c;
	struct s_buf	*next;
}				t_buf;

char	*strplus(char *s1, char *s2);
int		ft_printf(const char *restrict format, ...);
char	*charumn(char c1, char c2);
char	*strminus(char *s1, char *s2);
int		srav_nums(char *str1, char *str2);
void	replace_strings(char **str1, char **str2);
char	*des(int step);
char	*partumn(char *str1, char c2);
char	*umno(char *s1, char *s2);
char	*umwn2(char *s1);
t_buf	*create_buf();
void	put_char_to_buf(t_buf **buf, char c);
void	print_buf(t_buf *buf);
void	put_str_to_buf(t_buf **buf, char *str);
void	check_after_perc(va_list vl, char **buf, int *ib,\
const char *restrict *format);
int		returned_printf(t_buf *buf);
void	free_all_buff(t_buf *start);

#endif
