/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:31:15 by kmills            #+#    #+#             */
/*   Updated: 2019/08/05 18:31:15 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_flag(va_list vl, t_buf **buf, t_flags fl)
{
	char			*str;
	int				n;
	unsigned int	k;

	if (fl.precision != -1)
		fl.zero = 0;
	k = va_arg(vl, unsigned int);
	if (k == (unsigned int)0 && fl.precision == 0)
		return ;
	str = make_str_with_precision_for_u(fl, k);
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

void	u_flag_l(va_list vl, t_buf **buf, t_flags fl)
{
	char			*str;
	int				n;
	unsigned long	k;

	fl.zero = (-1 != fl.precision) ? 0 : fl.zero;
	k = va_arg(vl, unsigned long);
	if (k == (unsigned long)0 && fl.precision == 0)
		return ;
	str = make_str_with_precision_for_lu(fl, k);
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

void	u_flag_ll(va_list vl, t_buf **buf, t_flags fl)
{
	char				*str;
	int					n;
	unsigned long long	k;

	fl.zero = (-1 != fl.precision) ? 0 : fl.zero;
	k = va_arg(vl, unsigned long long);
	if (k == (unsigned long long)0 && fl.precision == 0)
		return ;
	str = make_str_with_precision_for_llu(fl, k);
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

void	u_flag_h(va_list vl, t_buf **buf, t_flags fl)
{
	char			*str;
	int				n;
	unsigned short	k;

	fl.zero = (-1 != fl.precision) ? 0 : fl.zero;
	k = (unsigned short)va_arg(vl, unsigned int);
	if (k == (unsigned short)0 && fl.precision == 0)
		return ;
	str = make_str_with_precision_for_hu(fl, k);
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

void	u_flag_hh(va_list vl, t_buf **buf, t_flags fl)
{
	char		*str;
	int			n;
	u_int8_t	k;

	fl.zero = (-1 != fl.precision) ? 0 : fl.zero;
	k = (u_int8_t)va_arg(vl, unsigned int);
	if (k == (u_int8_t)0 && fl.precision == 0)
		return ;
	str = make_str_with_precision_for_hhu(fl, k);
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
