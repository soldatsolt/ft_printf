/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 10:18:18 by kmills            #+#    #+#             */
/*   Updated: 2019/07/15 21:24:07 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H
# include "./libft/libft.h"


typedef struct	s_double
{
	double 			w;
	int 			len;
	int 			strlen;
	unsigned char	*s;
	char 			*str;
	int 			i;
	int 			pow;
	char 			c;
	int 			exp;
	char			*mantissa;
}				t_double;

typedef struct	s_flags
{
	int			dash;
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			width;
	int			precision;
	int			l;
	int			h;
}				t_flags;

typedef struct	s_buf
{
	char			c;
	struct s_buf	*next;
}				t_buf;

typedef struct	s_tofree
{
	void			*data;
	struct s_tofree	*next;
}				t_tofree;

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
void	put_some_chars_to_buf(t_buf **buf, char c, int n);
void	turbo_parser(va_list vl, t_buf **buf, const char *restrict *format);
void	f_flag(va_list vl, t_buf **buf, t_flags fl);
int		ft_double_in_str(t_double *dd, t_flags *fl);
void 	double_flag(va_list vl, t_buf **buf, t_flags *fl);
void	double_minus(t_double *dd, t_buf **buf, t_flags *fl);
void	double_just(t_double *dd, t_buf **buf, t_flags *fl);
void	double_zero(t_double *dd, t_buf **buf, t_flags *fl);
void	ft_itoa_double(double n, t_double *dd, t_flags *fl);
int		ft_len_exp(double w);
void 	make_exp(t_double *dd);
void	make_double_bits_str(t_double *dd);
void	ft_exp_str(t_double *dd, char **man, char *tmp);
void	ft_mantissa_str(char **man, char **tmp, t_double *dd);
void	ft_strsum(char **man, char **tmp);
void	ft_divstr(char **tmp);
void	ft_put_precision(t_double *dd, t_buf **buf, t_flags *fl);
int		ft_double_in_str(t_double *dd);

#endif
