#include "ft_printf.h"

void	s_flag(va_list vl, t_buf **buf, t_flags fl)
{
	char	*str;
	int		n;

	if ((str = va_arg(vl, char *)))
	{
		str = ft_strdup(str);
		if (fl.precision - 1 < ft_strlen(str))
			str[fl.precision] = '\0';
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
	else
		put_str_to_buf(buf, "(null)"); // тут тоже фришить нужно
}

char	*make_str_with_precision_for_i(t_flags fl, int k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_itoa(k);
	if (fl.precision && !((k >= 0 && ft_strlen(str) > fl.precision) \
	|| (k < 0 && ft_strlen(str) > fl.precision - 1)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 2));
		if (k < 0)
			s[i++] = '-';
		while ((k >= 0) ? (i < fl.precision - ft_strlen(str)) : (i < \
		fl.precision - ft_strlen(str) + 1))
		{
			s[i] = '0';
			i++;
		}
		if (k < 0)
		{
			s[i] = '0';
			i++;
			s = ft_strcpy(&(s[i]), &str[1]);
		}
		else
			s = ft_strcpy(&(s[i]), str);
		s = s - i;
		free(str);
		str = NULL;
		s[(k >= 0) ? (fl.precision) : (fl.precision + 1)] = '\0';
	}
	else
		s = str;
	return (s);
}

char	*make_str_with_precision_for_u(t_flags fl, unsigned int k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_utoa(k);
	if (fl.precision && !((ft_strlen(str) > fl.precision)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 1));
		while (i < fl.precision - ft_strlen(str))
		{
			s[i] = '0';
			i++;
		}
		s = ft_strcpy(&(s[i]), str);
		s = s - i;
		free(str);
		str = NULL;
		s[fl.precision] = '\0';
	}
	else
		s = str;
	return (s);
}

void	i_flag(va_list vl, t_buf **buf, t_flags fl)
{
	char	*str;
	int		n;
	int		k;
	char	z;

	k = va_arg(vl, int);
	z = (k >= 0) ? '+' : '-';
	str = make_str_with_precision_for_i(fl, k);
	n = fl.width - ft_strlen(str);
	if (fl.plus && k >= 0)
		n--;
	if (n > 0 && !fl.minus)
	{
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', n);
		else
			put_some_chars_to_buf(buf, ' ', n);
	}
	if (fl.plus && k >= 0)
		put_char_to_buf(buf, z);
	else if (fl.space)
		put_char_to_buf(buf, ' ');
	put_str_to_buf(buf, str);
	if (n > 0 && fl.minus)
		put_some_chars_to_buf(buf, ' ', n);
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
	c = va_arg(vl, int);
	put_char_to_buf(buf, c);
	if (fl.minus && fl.width > 1)
		put_some_chars_to_buf(buf, ' ', fl.width - 1);
}

void	u_flag(va_list vl, t_buf **buf, t_flags fl)
{
	char			*str;
	int				n;
	unsigned int	k;

	k = va_arg(vl, unsigned int);
	str = make_str_with_precision_for_u(fl, k);
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
		put_some_chars_to_buf(buf, ' ', n);
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
	fl->zero = 0;
	while ((**format) >= '0' && (**format) <= '9')
		(*format)++;
	(*format)--;
}

void	percentage(t_buf **buf, t_flags fl)
{
	if (!fl.minus && fl.width > 1)
	{
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', fl.width - 1);
		else
			put_some_chars_to_buf(buf, ' ', fl.width - 1);
	}
	put_char_to_buf(buf, '%');
	if (fl.minus && fl.width > 1)
		put_some_chars_to_buf(buf, ' ', fl.width - 1);
}

void	preparcing(t_buf **buf, t_flags *fl, const char *restrict *format)
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
		if ((**format) == '0' && !fl->precision)
			fl->zero = 1;
		if ((**format) > '0' && (**format) <= '9')
			make_t_width(fl, format);
		if ((**format) == '.')
			make_t_precision(fl, format);
		(*format)++;
	}
	if ((**format) == '%')
		percentage(buf, *fl);
}

void	turbo_parser(va_list vl, t_buf **buf, const char *restrict *format)
{
	t_flags	fl;

	make_t_flags0(&fl);
	preparcing(buf, &fl, format);
	if (**format == 's')
		s_flag(vl, buf, fl);
	else if (**format == 'i' || **format == 'd')
		i_flag(vl, buf, fl);
	else if (**format == 'u')
		u_flag(vl, buf, fl);
	else if (**format == 'c')
		c_flag(vl, buf, fl);
	(*format)++;
}