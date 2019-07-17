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
		{
			put_some_chars_to_buf(buf, ' ', n);
		}
	}
	else
		s_flag("(null)", buf, fl); // тут тоже фришить нужно
}

char	*make_ox_for_make_ox(char *ox, int n)
{
	int	i;

	i = 2;
	ox[0] = '0';
	ox[1] = 'x';
	while (i < n)
	{
		ox[i] = '0';
		i++;
	}
	ox[i] = '\0';
	return(ox);
}

char	*make_ox_for_p(char *ox, t_flags *fl)
{
	int	n;

	n = 0;
	if ((fl->zero && fl->width > 14) || fl->precision > 12)
	{
		if (fl->width - 2 > fl->precision && fl->precision == -1)
		{
			ox = ft_strnew(fl->width - 11 + 1);
			n = fl->width - 12;
		}
		else
		{
			ox = ft_strnew(fl->precision - 9 + 1);
			n = fl->precision - 10;
		}
		ox = make_ox_for_make_ox(ox, n);
		if (fl->precision != -1)
		{
			fl->zero = 0;
			fl->precision = -1;
		}
	}
	else
		ox = ft_strdup("0x");
	return(ox);
}

void	p_flag(va_list vl, t_buf **buf, t_flags fl)
{
	u_int64_t	ptr;
	char		*str;
	char		*s;
	char		*ox;

	ox = make_ox_for_p(ox, &fl);
	ptr = (uint64_t)(va_arg(vl, void*));
	s = ft_itoa_base_small(ptr, 16);
	str = ft_strnew(ft_strlen(s) + ft_strlen(ox) + 1);
	str = ft_catstr(ox, s);
	s_flag(str, buf, fl);
	// free(s); - фришить точно нужно, но он говорит, что s не замолочена или что-то вроде
	free(str);
}

char	*make_str_with_precision_for_i(t_flags fl, int k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_itoa(k);
	if (fl.precision != -1 && !((k >= 0 && ft_strlen(str) > fl.precision) \
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
	if (fl.precision != -1 && (((int)ft_strlen(str) <= fl.precision)))
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

    if (fl.precision != -1)
        fl.zero = 0;
	k = va_arg(vl, int);
	z = (k >= 0) ? '+' : '-';
	str = make_str_with_precision_for_i(fl, k);
	n = fl.width - (int)ft_strlen(str);
	if (fl.plus && k >= 0)
		n--;
    if ((k < 0 || fl.plus) && fl.zero)
    {
        if (n > 0 && !fl.minus)
        {
            put_char_to_buf(buf, z);
            if (fl.zero)
                put_some_chars_to_buf(buf, '0', n);
            else
                put_some_chars_to_buf(buf, ' ', n);
        }
        else if (fl.space)
            put_char_to_buf(buf, ' ');
		if (k < 0)
       		put_str_to_buf(buf, str + 1);
		else
			put_str_to_buf(buf, str);		
        if (n > 0 && fl.minus)
            put_some_chars_to_buf(buf, ' ', n);
    }
    else
    {
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

void	u_flag(va_list vl, t_buf **buf, t_flags fl)
{
	char			*str;
	int				n;
	unsigned int	k;

    if (fl.precision != -1)
        fl.zero = 0;
	k = va_arg(vl, unsigned int);
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
}

void	make_t_flags0(t_flags *fl)
{
	fl->dash = 0;
	fl->minus = 0;
	fl->plus = 0;
	fl->space = 0;
	fl->zero = 0;
	fl->width = 0;
	fl->precision = -1;
	fl->h = 0;
	fl->l = 0;
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
	(**format) == '.' || (**format) == 'h' || (**format) == 'l')
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
		if ((**format) > '0' && (**format) <= '9')
			make_t_width(fl, format);
		if ((**format) == '.')
			make_t_precision(fl, format);
		if ((**format) == 'l' && !fl->h && fl->l < 2)
			fl->l++;
		if ((**format) == 'h' && !fl->l && fl->h < 2)
			fl->h++;
		(*format)++;
	}
	if ((**format) == '%')
		percentage(buf, *fl);
}

void	pre_parce_for_i(va_list vl, t_buf **buf, t_flags fl)
{
	if (fl.l == 0 && fl.h == 0)
		i_flag(vl, buf, fl);
	else if(fl.l == 1)
		i_flag_l(vl, buf, fl);
	else if(fl.l == 2)
		i_flag_ll(vl, buf, fl);
	else if(fl.h == 1)
		i_flag_h(vl, buf, fl);
	else if(fl.h == 2)
		i_flag_hh(vl, buf, fl);
}

void	turbo_parser(va_list vl, t_buf **buf, const char *restrict *format)
{
	t_flags	fl;

	make_t_flags0(&fl);
	preparcing(buf, &fl, format);
	if (**format == 's')
		s_flag(va_arg(vl, char *), buf, fl);
	else if (**format == 'i' || **format == 'd')
		pre_parce_for_i(vl, buf, fl);
	else if (**format == 'D')
		i_flag_l(vl, buf, fl);
	else if (**format == 'u')
		u_flag(vl, buf, fl);
	else if (**format == 'c')
		c_flag(vl, buf, fl);
	else if (**format == 'f')
		f_flag(vl, buf, fl);
	else if (**format == 'p')
		p_flag(vl, buf, fl);
	(*format)++;
}
