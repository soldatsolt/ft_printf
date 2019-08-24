/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_flags1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:30:00 by kmills            #+#    #+#             */
/*   Updated: 2019/08/24 18:02:38 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	i_flag1_hh(t_buf **buf, t_flags fl, char *str, int8_t k)
{
	int		n;
	char	z;

	z = (char)((k >= 0) ? '+' : '-');
	n = fl.width - (int)ft_strlen(str);
	if (fl.plus && k >= 0)
		n--;
	if (n > 0 && !fl.minus)
	{
		put_char_to_buf(buf, z);
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', n);
		else
			put_some_chars_to_buf(buf, ' ', n);
	}
	if (k < 0 && (int)ft_strlen(str) < fl.width)
		put_str_to_buf(buf, str + 1);
	else
		put_str_to_buf(buf, str);
	if (n > 0 && fl.minus)
		put_some_chars_to_buf(buf, ' ', n);
}

void	i_flag1_h(t_buf **buf, t_flags fl, char *str, short k)
{
	int		n;
	char	z;

	z = (char)((k >= 0) ? '+' : '-');
	n = fl.width - (int)ft_strlen(str);
	if (fl.plus && k >= 0)
		n--;
	if (n > 0 && !fl.minus)
	{
		put_char_to_buf(buf, z);
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', n);
		else
			put_some_chars_to_buf(buf, ' ', n);
	}
	if (k < 0 && (int)ft_strlen(str) < fl.width)
		put_str_to_buf(buf, str + 1);
	else
		put_str_to_buf(buf, str);
	if (n > 0 && fl.minus)
		put_some_chars_to_buf(buf, ' ', n);
}

void	i_flag1_ll(t_buf **buf, t_flags fl, char *str, long long k)
{
	int		n;
	char	z;

	z = (char)((k >= 0) ? '+' : '-');
	n = fl.width - (int)ft_strlen(str);
	if (fl.plus && k >= 0)
		n--;
	if (n > 0 && !fl.minus)
	{
		put_char_to_buf(buf, z);
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', n);
		else
			put_some_chars_to_buf(buf, ' ', n);
	}
	if (k < 0 && (int)ft_strlen(str) < fl.width)
		put_str_to_buf(buf, str + 1);
	else
		put_str_to_buf(buf, str);
	if (n > 0 && fl.minus)
		put_some_chars_to_buf(buf, ' ', n);
}

void	i_flag1_l(t_buf **buf, t_flags fl, char *str, long k)
{
	int		n;
	char	z;

	z = (char)((k >= 0) ? '+' : '-');
	n = fl.width - (int)ft_strlen(str);
	if (fl.plus && k >= 0)
		n--;
	if (n > 0 && !fl.minus)
	{
		put_char_to_buf(buf, z);
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', n);
		else
			put_some_chars_to_buf(buf, ' ', n);
	}
	if (k < 0 && (int)ft_strlen(str) < fl.width)
		put_str_to_buf(buf, str + 1);
	else
		put_str_to_buf(buf, str);
	if (n > 0 && fl.minus)
		put_some_chars_to_buf(buf, ' ', n);
}

void	i_flag1(t_buf **buf, t_flags fl, char *str, int k)
{
	int		n;
	char	z;

	z = (char)((k >= 0) ? '+' : '-');
	n = fl.width - (int)ft_strlen(str);
	if (fl.plus && k >= 0)
		n--;
	if (k >= 0 && !fl.minus)
	{
		put_char_to_buf(buf, z);
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', n);
		else
			put_some_chars_to_buf(buf, ' ', n);
	}
	if (k < 0 && (int)ft_strlen(str) < fl.width)
	{
		put_char_to_buf(buf, z);
		put_some_chars_to_buf(buf, '0', ((n >= 0) ? n : 0));
		put_str_to_buf(buf, str + 1);
	}
	else
		put_str_to_buf(buf, str);
	if (n > 0 && fl.minus)
		put_some_chars_to_buf(buf, ' ', n);
}
