/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 07:26:28 by kmills            #+#    #+#             */
/*   Updated: 2019/05/17 06:33:16 by kmills           ###   ########.fr       */
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

long long int		pow2(int n)
{
	int				i;
	long long int	rez;

	rez = 1;
	if (n == 0)
		return (1);
	i = 0;
	while (i < n)
	{
		rez *= 2;
		i++;
	}
	return (rez);
}

int		main(int argc, char **argv)
{
	double			d;
	unsigned char	*s;
	unsigned char	*c;
	int				ic;
	int				i;
	double			n;
	unsigned char	*exp;
	unsigned char	*mantissa;
	int				step_exp;
	double			d_step_exp;
	double			step_man;
	unsigned char	*result_double;

	result_double = (unsigned char *)malloc(sizeof(unsigned char) * 60);
	mantissa = (unsigned char *)malloc(sizeof(unsigned char) * 53);
	s = (unsigned char *)malloc(sizeof(unsigned char) * 65);
	exp = (unsigned char *)malloc(sizeof(unsigned char) * 12);
	ft_bzero(result_double, 60);
	ft_bzero(mantissa, 53);
	ft_bzero(s, 65);
	ft_bzero(exp, 12);
	d = 0.5789651;
	c = (unsigned char *)&d;
	i = 0;
	ic = 7;
	while (ic + 1)
	{
		while (i < 8)
		{
			s[8 * (7 - ic) + i] = ((c[ic] & (128 >> i)) ? '1' : '0');
			i++;
		}
		ic--;
		i = 0;
	}
	s[64] = '\0';
	printf("DOUBLE  = %.16lf\n", d);
	printf("%s\n", s);
	i = 1;
	ic = 0;
	while (i < 12)
	{
		exp[ic] = s[i];
		i++;
		ic++;
	}
	exp[11] = '\0';
	printf("EXP = %s\n", exp);
	i = 12;
	ic = 0;
	while (i < 64)
	{
		mantissa[ic] = s[i];
		i++;
		ic++;
	}
	mantissa[52] = '\0';
	printf("MAN = %s\n", mantissa);
	i = 10;
	ic = 0;
	step_exp = 0;
	while (i + 1)
	{
		if (exp[i] == '1')
			step_exp += pow2(10 - i);
		i--;
	}
	step_exp -= 1023;
	if (step_exp < 0)
	{
		d_step_exp = (double)((double)1 / (double)pow2(-step_exp));
		printf("EXP STE = %.16lf\n", d_step_exp);
	}
	else
	{
		step_exp = pow2(step_exp);
		printf("EXP STE = %i\n", step_exp);
	}
	step_man = 0;
	i = 51;
	while (i + 1)
	{
		if (mantissa[i] == '1')
			step_man += (double)((double)1 / (double)pow2(i + 1));
		i--;
	}

	step_man += 1;

	printf("MAN STE = %.16lf\n", step_man);
	if (step_exp >= 0)
		d_step_exp = (double)step_exp;
	n = d_step_exp * step_man;
	if (s[0] == '1')
		n = -n;
	printf("RES DBL = %.16lf\n", n);
	return (0);
}
