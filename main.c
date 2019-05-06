/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 07:26:28 by kmills            #+#    #+#             */
/*   Updated: 2019/05/06 20:06:58 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_flag(char *str, char **buf, int *ib,\
t_flags fl)
{
	int		i;
	int		l;

	i = 0;
	l = (int)(ft_strlen(str));
	if (fl.minus == 0)
		while (fl.width > l + i)
		{
			**buf = ' ';
			(*buf)++;
			(*ib)++;
			i++;
		}
	while (*str)
	{
		**buf = *str;
		str++;
		(*buf)++;
		(*ib)++;
	}
	if (fl.minus != 0)
	{
		while (fl.width > l + i)
		{
			**buf = ' ';
			(*buf)++;
			(*ib)++;
			i++;
		}
	}
}

int		razrydnost(int n)
{
	int r;
	int i;

	i = 10;
	r = 1;
	while (n / i > 0)
	{
		i *= 10;
		r++;
	}
	return (r);
}

void	i_flag(va_list vl, char **buf, int *ib,\
t_flags fl)
{
	int		num;
	char	*str;
	int		i;
	char	*s;

	i = 0;
	num = va_arg(vl, int);
	str = (char *)malloc(sizeof(char) * (razrydnost(num) + 1 + fl.precision + fl.width));
	s = str;
	if (fl.zero)
		while (fl.width - i)
		{
			*str = '0';
			str++;
			i++;
		}
	else
		while (fl.precision - i)
		{
			*str = '0';
			str++;
			i++;
		}
	*str = '\0';
	i = 0;
	str = ft_itoa(num);
	str[razrydnost(num)] = '\0';
	if (fl.zero)
		while (str[i])
		{
			s[fl.width - razrydnost(num) + i] = str[i];
			i++;
		}
	else if (fl.precision > razrydnost(num))
		while (str[i])
		{
			s[fl.precision - razrydnost(num) + i] = str[i];
			i++;
		}
	else
		while (str[i])
		{
			s[i] = str[i];
			i++;
		}
	s_flag(s, buf, ib, fl);
}

void	make_t_flags(t_flags *fl)
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
	(*fl).width = ft_atoi(*format);
	while ((**format) >= '0' && (**format) <= '9')
		(*format)++;
	(*format)--;
}

void	make_t_precision(t_flags *fl, const char *restrict *format)
{
	(*format)++;
	(*fl).precision = ft_atoi(*format);
	while ((**format) >= '0' && (**format) <= '9')
		(*format)++;
	(*format)--;
}

void	turbo_parser(va_list vl, char **buf, int *ib,\
const char *restrict *format)
{
	t_flags	fl;
	
	make_t_flags(&fl);
	(*format)++; // теперь указатель не на проценте, а на флаге
	while ((**format) == ' ' || (**format) == '-' || (**format) == '+' || \
	((**format) >= '0' && (**format) <= '9') || (**format) == '#' || \
	(**format) == '.')
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
		if	((**format) > '0' && (**format) <= '9')
			make_t_width(&fl, format);
		if ((**format) == '.')
			make_t_precision(&fl, format);
		(*format)++;
	}
	if ((**format) == 's')
	{
		s_flag(va_arg(vl, char *), buf, ib, fl);
		(*format)++;
	}
	if ((**format) == 'i' || (**format) == 'd')
	{
		i_flag(vl, buf, ib, fl);
		(*format)++;
	}
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
	|| c == 's' || c == 'i' || c == 'd')
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
	printf("%f\n", 340282366920938463463174607431768.0);
	printf("%llu\n", 340282366920938463463174607431768);
	// ft_printf("%.15i\n", 4587 + 45);
	return (0);
}
