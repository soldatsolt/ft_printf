/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 07:26:28 by kmills            #+#    #+#             */
/*   Updated: 2019/05/04 12:35:11 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_flag(va_list vl, char **buf, int *ib,\
const char *restrict *format)
{
	char	*str;

	str = va_arg(vl, char *);
	*format += 1;
	while (*str)
	{
		**buf = *str;
		str++;
		(*buf)++;
		(*ib)++;
	}
}

void	make_t_flags(t_flags *fl)
{
	fl->dash = 0;
	fl->minus = 0;
	fl->plus = 0;
	fl->space = 0;
	fl->zero = 0;
}

void	turbo_parser(va_list vl, char **buf, int *ib,\
const char *restrict *format)
{
	t_flags	fl;
	
	make_t_flags(&fl);
	(*format)++; // теперь указатель не на проценте, а на флаге
	while ((**format) == ' ' || (**format) == '-' || (**format) == '+' || \
	((**format) >= '0' && (**format) <= '9') || (**format) == '#')
	{
		if ((**format) == ' ')
			fl.space = 1;
		if ((**format) == '#')
			fl.dash = 1;
		if ((**format) == '-')
			fl.minus = 1;
		if ((**format) == '+')
			fl.plus = 1;
		if ((**format) == '0')
			fl.zero = 1;
		(*format)++;
	}
	if ((**format) == 's')
		s_flag(vl, buf, ib, format);
}

void	check_after_perc(va_list vl, char **buf, int *ib,\
const char *restrict *format)
{
	char	c; 

	c = (*format)[1];
	if (c == '%')
	{
		*format += 2;
		**buf = '%';
		(*buf)++;
		(*ib)++;
		return ;
	}
	if (c == ' ' || c == '-' || c == '+' || (c >= '0' && c <= '9') || c == '#'\
	|| c == 's')
		turbo_parser(vl, buf, ib, format);
	// if ((*format)[1] == 's')
	// 	s_flag(vl, buf, ib, format);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	vl;
	char	*str;
	int		i;
	int		ib;
	char	*buf;

	i = 0;
	ib = 0;
	buf = (char *)malloc(sizeof(char) * 500);
	ft_bzero(buf, 500);
	va_start(vl, format);
	while (*format)
	{
		if (*format == '%')
		{
			check_after_perc(vl, &buf, &ib, &format);
		}
		if (*format && *format != '%')
		{
			*buf = *format;
			format++;
			buf++;
			ib++;
		}
	}
	*buf = '\0';
	buf -= ib;
	write(1, buf, ft_strlen(buf) + 1);
	va_end(vl);
	free(buf);
	return (ib);
}

int		main(int argc, char **argv)
{
	printf("%%%%%s00001234%%56789%%%-s%%%s\n", "12345", "abcdef", "iop");
	ft_printf("%%%%%s00001234%%56789%%%-s%%%s\n", "12345", "abcdef", "iop");
	return (0);
}
