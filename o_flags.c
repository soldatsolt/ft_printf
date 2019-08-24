/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:29:55 by kmills            #+#    #+#             */
/*   Updated: 2019/08/05 22:05:35 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	o_flag(va_list vl, t_buf **buf, t_flags fl)
{
	char			*str;
	int				n;
	unsigned int	k;
	char			*s;

	s = NULL;
	fl.zero = (-1 != fl.precision) ? 0 : fl.zero;
	k = va_arg(vl, unsigned int);
	if (k == (unsigned int)0 && fl.precision == 0 && !fl.dash && !fl.width)
		return ;
	str = make_str_with_precision_for_o(fl, k);
	if (fl.dash && k != 0 && str[0] != '0')
		return (o_flag1(fl, buf, s, str));
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

void	o_flag_l(va_list vl, t_buf **buf, t_flags fl)
{
	char			*str;
	int				n;
	unsigned long	k;
	char			*s;

	s = NULL;
	fl.zero = (-1 != fl.precision) ? 0 : fl.zero;
	k = va_arg(vl, unsigned long);
	if (k == (unsigned long)0 && fl.precision == 0 && !fl.dash)
		return ;
	str = make_str_with_precision_for_lo(fl, k);
	if (fl.dash && k != 0 && str[0] != '0')
		return (o_flag1(fl, buf, s, str));
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

void	o_flag_ll(va_list vl, t_buf **buf, t_flags fl)
{
	char				*str;
	int					n;
	unsigned long long	k;
	char				*s;

	s = NULL;
	fl.zero = (-1 != fl.precision) ? 0 : fl.zero;
	k = va_arg(vl, unsigned long long);
	if (k == (unsigned long long)0 && fl.precision == 0 && !fl.dash)
		return ;
	str = make_str_with_precision_for_llo(fl, k);
	if (fl.dash && k != 0 && str[0] != '0')
		return (o_flag1(fl, buf, s, str));
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

void	o_flag_h(va_list vl, t_buf **buf, t_flags fl)
{
	char			*str;
	int				n;
	unsigned short	k;
	char			*s;

	s = NULL;
	fl.zero = (-1 != fl.precision) ? 0 : fl.zero;
	k = (unsigned short)va_arg(vl, unsigned int);
	if (k == (unsigned short)0 && fl.precision == 0 && !fl.dash)
		return ;
	str = make_str_with_precision_for_ho(fl, k);
	if (fl.dash && k != 0 && str[0] != '0')
		return (o_flag1(fl, buf, s, str));
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

void	o_flag_hh(va_list vl, t_buf **buf, t_flags fl)
{
	char		*str;
	int			n;
	u_int8_t	k;
	char		*s;

	s = NULL;
	fl.zero = (-1 != fl.precision) ? 0 : fl.zero;
	k = (u_int8_t)va_arg(vl, unsigned int);
	if (k == (u_int8_t)0 && fl.precision == 0 && !fl.dash)
		return ;
	str = make_str_with_precision_for_hho(fl, k);
	if (fl.dash && k != 0 && str[0] != '0')
		return (o_flag1(fl, buf, s, str));
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
