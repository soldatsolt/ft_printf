/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 07:26:28 by kmills            #+#    #+#             */
/*   Updated: 2019/07/09 04:47:10 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buf *g_start;

void	s_flag(va_list vl, t_buf **buf, const char *restrict format, t_flags fl)
{
	char	*str; // TODO: мб ****** эти лишние

	str = va_arg(vl, char *);
	*buf = put_str_to_buf(*buf, str);
}

void	make_t_flags0(t_flags *fl)
{
	fl->dash = 0;
	fl->minus = 0;
	fl->plus = 0;
	fl->space = 0;
	fl->zero = 0;
	fl->width = 0;
	fl->precision = 0;
}

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
	while ((**format) >= '0' && (**format) <= '9')
		(*format)++;
	(*format)--;
}

void	preparcing(t_flags *fl, const char *restrict *format)
{
	while ((**format) == ' ' || (**format) == '-' || (**format) == '+' || \
	((**format) >= '0' && (**format) <= '9') || (**format) == '#' || \
	(**format) == '.')
	{
		if ((**format) == ' ')
			fl->space = 1;
		if ((**format) == '#')
			fl->dash = 1;
		if ((**format) == '-')
			fl->minus = 1;
		if ((**format) == '+')
			fl->plus = 1;
		if ((**format) == '0')
			fl->zero = 1;
		if	((**format) > '0' && (**format) <= '9')
			make_t_width(fl, format);
		if ((**format) == '.')
			make_t_precision(fl, format);
		(*format)++;
	}
}

void	turbo_parser(va_list vl, t_buf **buf, const char *restrict *format)
{
	t_flags	fl;
	
	make_t_flags0(&fl);
	preparcing(&fl, format);
	if (**format == 's')
		s_flag(vl, buf, *format, fl);
	(*format)++;
}

void	ft_printf2(va_list vl, t_buf *buf, const char *restrict format)
{
	while (*format)
	{
		if (*format == '%' && format[1] == '%')
		{
			buf = put_char_to_buf(buf, '%');
			format += 2;
		}
		else if (*format == '%' && format[1] != '%')
		{
			format++; // теперь в ф-ии парсера сразу идёт флаг (без %)
			turbo_parser(vl, &buf, &format);
		}
		else
		{
			buf = put_char_to_buf(buf, *format);
			format++;
		}
	}
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	vl;
	t_buf	*buf;
	t_buf	*start;
	int		n;

	buf = create_buf();
	start = buf;
	g_start = start;
	va_start(vl, format);
	ft_printf2(vl, buf, format);
	printf_buf(start);
	va_end(vl);
	n = returned_printf(start);
	free_all_buff(start);
	return (n);
}

int		main(int argc, char **argv)
{
	ft_printf("123542% s%%i6rere%%", "==ETA STROKA==");
	return (0);
}
