/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 07:26:28 by kmills            #+#    #+#             */
/*   Updated: 2019/07/09 07:37:33 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buf *g_start;

void	put_some_chars_to_buf(t_buf **buf, char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		put_char_to_buf(buf, c);
		i++;
	}
}

void	stuff_for_s_flag(t_buf **buf, t_flags fl, int n)
{
	
}

void	s_flag(va_list vl, t_buf **buf, const char *restrict format, t_flags fl)
{
	char	*str;
	int		n;

	str = va_arg(vl, char *);
	n = fl.width - ft_strlen(str);
	if (n > 0 && !fl.minus)
	{
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', n);
		else
			put_some_chars_to_buf(buf, ' ', n);
	}
	put_str_to_buf(buf, str);
	if (n > 0 && fl.minus)
	{
		put_some_chars_to_buf(buf, ' ', n);
	}
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

void	ft_printf2(va_list vl, t_buf **buf, const char *restrict format)
{
	while (*format)
	{
		if (*format == '%' && format[1] == '%')
		{
			put_char_to_buf(buf, '%');
			format += 2;
		}
		else if (*format == '%' && format[1] != '%')
		{
			format++; // теперь в ф-ии парсера сразу идёт флаг (без %)
			turbo_parser(vl, buf, &format);
		}
		else
		{
			put_char_to_buf(buf, *format);
			format++;
		}
	}
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	vl;
	t_buf	*buf;
	t_buf	*buf_start;
	int		n;

	buf = create_buf();
	buf_start = buf;
	g_start = buf_start;
	va_start(vl, format);
	ft_printf2(vl, &buf, format);
	print_buf(buf_start);
	va_end(vl);
	n = returned_printf(buf_start);
	free_all_buff(buf_start);
	return (n);
}

int		main(int argc, char **argv)
{
	 ft_printf("qqq%-20sqqq\n", "123456789");
		printf("qqq%-20sqqq\n", "123456789");
	return (0);
}
