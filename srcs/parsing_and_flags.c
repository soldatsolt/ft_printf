/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_and_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:30:21 by kmills            #+#    #+#             */
/*   Updated: 2019/08/05 22:40:49 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_t_width(t_flags *fl, const char *restrict *format)
{
	fl->width = ft_atoi(*format);
	while ((**format) >= '0' && (**format) <= '9')
		(*format)++;
	(*format)--;
}

void	make_t_precision(t_flags *fl, const char *restrict *format)
{
	(*format)++;
	fl->precision = ft_atoi(*format);
	if (fl->precision == -1)
		fl->precision = 0;
	while ((**format) >= '0' && (**format) <= '9')
		(*format)++;
	(*format)--;
}

void	preparcing3(t_flags *fl, const char *restrict *format)
{
	if ((**format) == ' ' && !fl->plus)
		fl->space = 1;
	if ((**format) == '#')
		fl->dash = 1;
	if ((**format) == '-')
	{
		fl->minus = 1;
		fl->zero = 0;
	}
	if ((**format) == '+')
	{
		fl->plus = 1;
		fl->space = 0;
	}
	if ((**format) == '0' && !fl->minus)
		fl->zero = 1;
	if ((**format) > '0' && (**format) <= '9')
		make_t_width(fl, format);
	if ((**format) == '.')
		make_t_precision(fl, format);
	if ((**format) == 'l' && fl->l < 2)
		fl->l++;
	if ((**format) == 'j' && fl->l < 1)
		fl->l++;
}

void	preparcing2(t_flags *fl, const char *restrict *format)
{
	preparcing3(fl, format);
	if ((**format) == 'h' && !fl->l && fl->h < 2)
		fl->h++;
	if ((**format) == 'L' && !fl->l && fl->h < 2)
		fl->ll++;
	(*format)++;
}

void	preparcing(t_buf **buf, t_flags *fl, const char *restrict *format)
{
	while ((**format) == ' ' || (**format) == '-' || (**format) == '+' || \
	((**format) >= '0' && (**format) <= '9') || (**format) == '#' || \
	(**format) == '.' || (**format) == 'h' || (**format) == 'l' || \
	(**format) == 'L')
	{
		preparcing2(fl, format);
	}
	if ((**format) == '%')
		percentage(buf, *fl);
}
