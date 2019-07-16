/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbharbo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:54:11 by vbharbo           #+#    #+#             */
/*   Updated: 2019/07/09 19:45:43 by vbharbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>
#include <stdio.h>


typedef struct	s_pf
{
	va_list			ap;
	int				len;
	int 			fr_len;
	int 			accuracy;
	unsigned int	zero:1;
	unsigned int	hesh:1;
	unsigned int	space:1;
	unsigned int	minus:1;
	unsigned int	plus:1;
	unsigned int	dot:1;
	unsigned int	l:1;
	unsigned int	ll:1;
	unsigned int	h:1;
	unsigned int	hh:1;
	unsigned int	u:1;
}				t_pf;

typedef struct  s_double
{
	double                  w;
	int                     len;
	int                     strlen;
	unsigned char   *s;
	char                    *str;
	int                     i;
	int                     pow;
	char                    c;
	int                     exp;
	char                    *mantissa;
}				t_double;

typedef struct	s_buff
{
	size_t 	i;
	int 	re;
	char	*tmp;
}				t_buff;

typedef	struct	s_print
{
	char	*spc;
	void	(*f)(t_pf *);
}				t_print;

void	ft_print_int(t_pf *pf);
void	ft_print_str(t_pf *pf);
void	ft_print_char(t_pf *pf);
int		ft_printf(const char *str, ...);
void	ft_unsigned_putnbr(long long n);
int		ft_put_buff(char c, int flag);
void	ft_zero_zero(t_pf *pf);
void	ft_print_unsigned(t_pf *pf);
void	ft_realy_unsigned_putnbr(unsigned long long n);
void	ft_print_octo(t_pf *pf);
void	ft_print_double(t_pf *pf);
void	ft_strsum(char **man, char **tmp);
void	ft_divstr(char **tmp);
void	double_minus(t_double *dd, t_pf *pf);
void	double_just(t_double *dd, t_pf *pf);
void	double_zero(t_double *dd, t_pf *pf);
int		ft_double_in_str(t_double *dd, t_pf *pf);
void	put_some_chars_to_buf(char c, int n);
void	ft_print_char(t_pf *pf);
void	put_str_to_buf(char *str);
char	*ft_itoa_base_costil(unsigned long long n, char flag);
void	ft_print_x(t_pf *pf);

#endif
