/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:31:18 by kmills            #+#    #+#             */
/*   Updated: 2019/08/05 23:21:28 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_flag(va_list vl, t_buf **buf, t_flags fl,
char *(*f)(unsigned int, int))
{
	char			*str;
	int				n;
	unsigned int	k;

	if (fl.precision != -1)
		fl.zero = 0;
	k = va_arg(vl, unsigned int);
	if (k == (unsigned int)0 && fl.precision == 0 && !fl.dash && !fl.width)
		return ;
	if (fl.dash && k != 0)
		return (x_flag1(buf, fl, f, k));
	str = make_str_with_precision_for_x(fl, k, f);
	n = fl.width - (int)ft_strlen(str);
	if (n > 0 && !fl.minus)
	{
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', n);
		else
			put_some_chars_to_buf(buf, ' ', n);
	}
	put_str_to_buf(buf, str);
	if (n > 0 && fl.minus)
		put_some_chars_to_buf(buf, ' ', n);
	free(str);
}

void	x_flag_hh(va_list vl, t_buf **buf, t_flags fl,
char *(*f)(unsigned char, int))
{
	char		*str;
	int			n;
	u_int8_t	k;

	fl.zero = (-1 != fl.precision) ? 0 : fl.zero;
	k = (u_int8_t)va_arg(vl, unsigned int);
	if (k == (u_int8_t)0 && fl.precision == 0 && !fl.dash && !fl.width)
		return ;
	if (fl.dash && k != 0)
		return (x_flag1_hh(buf, fl, f, k));
	str = make_str_with_precision_for_hhx(fl, k, f);
	n = fl.width - (int)ft_strlen(str);
	if (n > 0 && !fl.minus)
	{
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', n);
		else
			put_some_chars_to_buf(buf, ' ', n);
	}
	put_str_to_buf(buf, str);
	if (n > 0 && fl.minus)
		put_some_chars_to_buf(buf, ' ', n);
	free(str);
}

void	x_flag_h(va_list vl, t_buf **buf, t_flags fl,
char *(*f)(unsigned short, int))
{
	char			*str;
	int				n;
	unsigned short	k;

	fl.zero = (-1 != fl.precision) ? 0 : fl.zero;
	k = (unsigned short)va_arg(vl, unsigned int);
	if (k == (unsigned short)0 && fl.precision == 0 && !fl.dash && !fl.width)
		return ;
	if (fl.dash && k != 0)
		return (x_flag1_h(buf, fl, f, k));
	str = make_str_with_precision_for_hx(fl, k, f);
	n = fl.width - (int)ft_strlen(str);
	if (n > 0 && !fl.minus)
	{
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', n);
		else
			put_some_chars_to_buf(buf, ' ', n);
	}
	put_str_to_buf(buf, str);
	if (n > 0 && fl.minus)
		put_some_chars_to_buf(buf, ' ', n);
	free(str);
}

void	x_flag_ll(va_list vl, t_buf **buf, t_flags fl,
char *(*f)(unsigned long long, int))
{
	char				*str;
	int					n;
	unsigned long long	k;

	fl.zero = (-1 != fl.precision) ? 0 : fl.zero;
	k = va_arg(vl, unsigned long long);
	if (k == 0 && fl.precision == 0 && !fl.dash && !fl.width)
		return ;
	if (fl.dash && k != 0)
		return (x_flag1_ll(buf, fl, f, k));
	str = make_str_with_precision_for_llx(fl, k, f);
	n = fl.width - (int)ft_strlen(str);
	if (n > 0 && !fl.minus)
	{
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', n);
		else
			put_some_chars_to_buf(buf, ' ', n);
	}
	put_str_to_buf(buf, str);
	if (n > 0 && fl.minus)
		put_some_chars_to_buf(buf, ' ', n);
	free(str);
}

void	x_flag_l(va_list vl, t_buf **buf, t_flags fl,
char *(*f)(unsigned long, int))
{
	char			*str;
	int				n;
	unsigned long	k;

	fl.zero = (-1 != fl.precision) ? 0 : fl.zero;
	k = va_arg(vl, unsigned long);
	if (k == (unsigned long)0 && fl.precision == 0 && !fl.dash && !fl.width)
		return ;
	if (fl.dash && k != 0)
		return (x_flag1_l(buf, fl, f, k));
	str = make_str_with_precision_for_lx(fl, k, f);
	n = fl.width - (int)ft_strlen(str);
	if (n > 0 && !fl.minus)
	{
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', n);
		else
			put_some_chars_to_buf(buf, ' ', n);
	}
	put_str_to_buf(buf, str);
	if (n > 0 && fl.minus)
		put_some_chars_to_buf(buf, ' ', n);
	free(str);
}
