/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 10:18:18 by kmills            #+#    #+#             */
/*   Updated: 2019/08/24 21:00:03 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"

typedef struct		s_double
{
	int				size;
	long double		lw;
	unsigned char	sign;
	double			w;
	int				len;
	int				strlen;
	unsigned char	*s;
	char			*str;
	int				i;
	long			pow;
	char			c;
	int				exp;
	char			*mantissa;
	int				dot;
}					t_double;

typedef struct		s_flags
{
	int				dash;
	int				minus;
	int				plus;
	int				space;
	int				zero;
	int				width;
	int				precision;
	int				l;
	int				h;
	int				ll;
}					t_flags;

typedef struct		s_buf
{
	char			c;
	struct s_buf	*next;
}					t_buf;

typedef struct		s_tofree
{
	void			*data;
	struct s_tofree	*next;
}					t_tofree;

int					ft_printf(const char *restrict format, ...);
t_buf				*create_buf();
void				put_char_to_buf(t_buf **buf, char c);
void				print_buf(t_buf *buf);
void				put_str_to_buf(t_buf **buf, char *str);
void				check_after_perc(va_list vl, char **buf, int *ib,\
const char *restrict *format);
int					returned_printf(t_buf *buf);
void				free_all_buff(t_buf *start);
void				put_some_chars_to_buf(t_buf **buf, char c, int n);
void				turbo_parser(va_list vl, t_buf **buf,
const char *restrict *format);
void				f_flag(va_list vl, t_buf **buf, t_flags fl);
int					ft_double_in_str(t_double *dd, t_flags *fl);
void				double_flag(va_list vl, t_buf **buf, t_flags fl);
void				long_double_flag(va_list vl, t_buf **buf, t_flags fl);
void				ft_itoa_long_double
(long double n, t_double *dd, t_flags *fl);
void				double_minus(t_double *dd, t_buf **buf, t_flags *fl);
void				double_just(t_double *dd, t_buf **buf, t_flags *fl);
void				double_zero(t_double *dd, t_buf **buf, t_flags *fl);
int					ft_itoa_double(double n, t_double *dd, t_flags *fl);
int					ft_len_exp_double(t_double *dd);
void				make_exp(t_double *dd);
void				make_double_bits_str(t_double *dd);
void				ft_exp_str(t_double *dd, char **man, char *tmp);
void				ft_mantissa_str(char **man, char **tmp, t_double *dd);
void				ft_strsum(char **man, char **tmp);
void				ft_divstr(char **tmp);
void				ft_mantissa_correct(char **man, t_flags *fl, t_double *dd);
void				ft_put_precision(t_double *dd, t_buf **buf, t_flags *fl);
void				i_flag_l(va_list vl, t_buf **buf, t_flags fl);
void				i_flag_ll(va_list vl, t_buf **buf, t_flags fl);
void				i_flag_h(va_list vl, t_buf **buf, t_flags fl);
void				i_flag_hh(va_list vl, t_buf **buf, t_flags fl);
void				u_flag_l(va_list vl, t_buf **buf, t_flags fl);
void				u_flag_ll(va_list vl, t_buf **buf, t_flags fl);
void				u_flag_h(va_list vl, t_buf **buf, t_flags fl);
void				u_flag_hh(va_list vl, t_buf **buf, t_flags fl);
void				o_flag_l(va_list vl, t_buf **buf, t_flags fl);
void				o_flag_ll(va_list vl, t_buf **buf, t_flags fl);
void				o_flag_h(va_list vl, t_buf **buf, t_flags fl);
void				o_flag_hh(va_list vl, t_buf **buf, t_flags fl);
void				x_flag_hh(va_list vl, t_buf **buf, t_flags fl, char *(*f)\
(unsigned char, int));
void				x_flag_h(va_list vl, t_buf **buf, t_flags fl, char *(*f)\
(unsigned short, int));
void				x_flag_ll(va_list vl, t_buf **buf, t_flags fl, char *(*f)\
(unsigned long long, int));
void				x_flag_l(va_list vl, t_buf **buf, t_flags fl, char *(*f)\
(unsigned long, int));
char				*make_ox_for_p(char *ox, t_flags *fl);
char				*make_ox_for_make_ox(char *ox, int n);
char				*make_ox_for_x(char *ox, t_flags *fl, int l);
char				*make_str_with_precision_for_i(t_flags fl, int k);
char				*make_str_with_precision_for_u(t_flags fl, unsigned int k);
char				*make_str_with_precision_for_x(t_flags fl, unsigned int k, \
char *(*f)(unsigned int, int));
char				*make_str_with_precision_for_o(t_flags fl, unsigned int k);
void				s_flag(char *str, t_buf **buf, t_flags fl);
void				p_flag(va_list vl, t_buf **buf, t_flags fl);
void				i_flag(va_list vl, t_buf **buf, t_flags fl);
void				c_flag(va_list vl, t_buf **buf, t_flags fl);
void				o_flag(va_list vl, t_buf **buf, t_flags fl);
void				x_flag(va_list vl, t_buf **buf, t_flags fl, \
char *(*f)(unsigned int, int));
void				u_flag(va_list vl, t_buf **buf, t_flags fl);
void				make_t_flags0(t_flags *fl);
void				make_t_width(t_flags *fl, const char *restrict *format);
void				make_t_precision(t_flags *fl, const char *restrict *format);
void				percentage(t_buf **buf, t_flags fl);
void				preparcing
(t_buf **buf, t_flags *fl, const char *restrict *format);
void				pre_parce_for_i(va_list vl, t_buf **buf, t_flags fl);
void				pre_parce_for_u(va_list vl, t_buf **buf, t_flags fl);
void				pre_parce_for_o(va_list vl, t_buf **buf, t_flags fl);
void				pre_parce_for_x(va_list vl, t_buf **buf, t_flags fl);
void				pre_parce_for_xx(va_list vl, t_buf **buf, t_flags fl);
char				*make_ox_for_xx(char *ox, t_flags *fl, int l);
void				ft_step_mantissa(char **man, t_double *dd);
int					ft_double_exception
(double n, t_buf **buf, t_flags fl);
int					ft_long_double_exception
(long double n, t_buf **buf, t_flags fl);
void				ft_free_dd(t_double *dd);
void				o_flag1(t_flags fl, t_buf **buf, char *s, char *str);
char				*make_str_with_precision_for_lu
(t_flags fl, unsigned long k);
char				*make_str_with_precision_for_llu
(t_flags fl, unsigned long long k);
char				*make_str_with_precision_for_hu
(t_flags fl, unsigned short k);
char				*make_str_with_precision_for_hhu
(t_flags fl, unsigned char k);
void				x_flag1(t_buf **buf, t_flags fl, char *(*f)
(unsigned int, int), unsigned int k);
char				*make_str_with_precision_for_hhx(t_flags fl, \
unsigned char k, char *(*f)(unsigned char, int));
char				*make_str_with_precision_for_hx(t_flags fl, \
unsigned short k, char *(*f)(unsigned short, int));
char				*make_str_with_precision_for_llx
(t_flags fl, unsigned long long k, char *(*f)(unsigned long long, int));
char				*make_str_with_precision_for_lx
(t_flags fl, unsigned long k, char *(*f)(unsigned long, int));
void				x_flag1_hh(t_buf **buf, t_flags fl, char *(*f)
(unsigned char, int), unsigned char k);
void				x_flag1_h(t_buf **buf, t_flags fl, char *(*f)
(unsigned short, int), unsigned short k);
void				x_flag1_ll(t_buf **buf, t_flags fl, char *(*f)
(unsigned long long, int), unsigned long long k);
void				x_flag1_l
(t_buf **buf, t_flags fl, char *(*f)(unsigned long, int), unsigned long k);
void				i_flag_hh(va_list vl, t_buf **buf, t_flags fl);
void				i_flag2_hh(t_buf **buf, t_flags fl, char *str, int8_t k);
void				i_flag1_hh(t_buf **buf, t_flags fl, char *str, int8_t k);
void				i_flag_h(va_list vl, t_buf **buf, t_flags fl);
void				i_flag2_h(t_buf **buf, t_flags fl, char *str, short k);
void				i_flag1_h(t_buf **buf, t_flags fl, char *str, short k);
void				i_flag_ll(va_list vl, t_buf **buf, t_flags fl);
void				i_flag2_ll(t_buf **buf, t_flags fl, char *str, long long k);
void				i_flag1_ll(t_buf **buf, t_flags fl, char *str, long long k);
void				i_flag_l(va_list vl, t_buf **buf, t_flags fl);
void				i_flag2_l(t_buf **buf, t_flags fl, char *str, long k);
void				i_flag1_l(t_buf **buf, t_flags fl, char *str, long k);
char				*make_str_with_precision_for_li(t_flags fl, long k);
char				*make_str_with_precision_for_lli(t_flags fl, long long k);
char				*make_str_with_precision_for_hi(t_flags fl, short k);
char				*make_str_with_precision_for_hhi(t_flags fl, int8_t k);
void				i_flag2(t_buf **buf, t_flags fl, char *str, int k);
void				i_flag1(t_buf **buf, t_flags fl, char *str, int k);
char				*make_str_with_precision_for_hho
(t_flags fl, unsigned char k);
char				*make_str_with_precision_for_ho
(t_flags fl, unsigned short k);
char				*make_str_with_precision_for_llo
(t_flags fl, unsigned long long k);
char				*make_str_with_precision_for_lo
(t_flags fl, unsigned long k);
void				print_p_if_fl_minus(char *str, t_buf **buf, t_flags fl, \
int len);

#endif
