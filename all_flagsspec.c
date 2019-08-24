/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_flagsspec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:31:44 by kmills            #+#    #+#             */
/*   Updated: 2019/08/24 20:57:04 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_flag(char *str, t_buf **buf, t_flags fl)
{
	int		n;

	if (fl.precision != -1)
		fl.zero = 0;
	if (str)
	{
		str = ft_strdup(str);
		if (fl.precision != -1 && fl.precision - 1 < (int)ft_strlen(str))
			str[fl.precision] = '\0';
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
	else
		s_flag("(null)", buf, fl);
}

void	print_p(char *str, t_buf **buf, t_flags fl)
{
	int len;

	len = (int)ft_strlen(str);
	if (fl.minus)
		print_p_if_fl_minus(str, buf, fl, len);
	else if (fl.precision >= 0)
	{
		put_some_chars_to_buf(buf, ' ', fl.width - 2 - \
		((fl.precision > len) ? fl.precision : len));
		put_str_to_buf(buf, "0x");
		put_some_chars_to_buf(buf, '0', fl.precision - len);
		put_str_to_buf(buf, str);
	}
	else if (fl.zero)
	{
		put_str_to_buf(buf, "0x");
		put_some_chars_to_buf(buf, '0', fl.width - len - 2);
		put_str_to_buf(buf, str);
	}
	else
	{
		put_some_chars_to_buf(buf, ' ', fl.width - len - 2);
		put_str_to_buf(buf, "0x");
		put_str_to_buf(buf, str);
	}
}

void	p_flag(va_list vl, t_buf **buf, t_flags fl)
{
	u_int64_t	ptr;
	char		*str;
	char		*s;

	str = NULL;
	ptr = (u_int64_t)(va_arg(vl, void*));
	s = ft_itoa_base_small_ll(ptr, 16);
	if (!fl.precision && !ptr)
	{
		fl.precision = -1;
		s_flag("0x", buf, fl);
	}
	else
		print_p(s, buf, fl);
	free(str);
	free(s);
}

void	c_flag(va_list vl, t_buf **buf, t_flags fl)
{
	char	c;

	if (!fl.minus && fl.width > 1)
	{
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', fl.width - 1);
		else
			put_some_chars_to_buf(buf, ' ', fl.width - 1);
	}
	c = (char)va_arg(vl, int);
	put_char_to_buf(buf, c);
	if (fl.minus && fl.width > 1)
		put_some_chars_to_buf(buf, ' ', fl.width - 1);
}
