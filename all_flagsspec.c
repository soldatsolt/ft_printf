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

void	p_flag(va_list vl, t_buf **buf, t_flags fl)
{
	u_int64_t	ptr;
	char		*str;
	char		*s;
	char		*ox;

	ox = make_ox_for_p(ox, &fl);
	ptr = (uint64_t)(va_arg(vl, void*));
	s = ft_itoa_base_small_ll(ptr, 16);
	str = ft_strnew(ft_strlen(s) + ft_strlen(ox) + 1);
	str = ft_catstr(ox, s);
	s_flag(str, buf, fl);
	// free(s); - фришить точно нужно, но он говорит, что s не замолочена или что-то вроде
	free(str); // ПОТОМУ ЧТО s и str - одно и то же после ф-ии catstr! (фришить)
}										//				нужно там значит, наверное


void	i_flag(va_list vl, t_buf **buf, t_flags fl)
{
	char	*str;
	int		n;
	int		k;
	char	z;

    if (fl.precision != -1)
        fl.zero = 0;
	k = va_arg(vl, int);
	if (k == (int)0 && fl.precision == 0)
		return ;
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
		if (k < 0 && (int)ft_strlen(str) < fl.width)
       		put_str_to_buf(buf, str + 1); // из-за +1 при отриц числе и флаге 0
		else						// не выводится '-' TODO: mb mistake in if
			put_str_to_buf(buf, str);		
        if (n > 0 && fl.minus)
            put_some_chars_to_buf(buf, ' ', n);
    }
    else
    {
		if (fl.space)
		{
        	put_char_to_buf(buf, ' ');
			n--;
		}
        if (n > 0 && !fl.minus)
        {
            if (fl.zero)
                put_some_chars_to_buf(buf, '0', n);
            else
                put_some_chars_to_buf(buf, ' ', n);
        }
        if (fl.plus && k >= 0)
            put_char_to_buf(buf, z);
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

void	o_flag(va_list vl, t_buf **buf, t_flags fl)
{
	char			*str;
	int				n;
	unsigned int	k;

    if (fl.precision != -1)
        fl.zero = 0;
	k = va_arg(vl, unsigned int);
	if (k == (unsigned int)0 && fl.precision == 0)
		return ;
	str = make_str_with_precision_for_o(fl, k);
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

void	x_flag(va_list vl, t_buf **buf, t_flags fl, char *(*f)(unsigned int, int))
{
	char			*str;
	int				n;
	unsigned int	k;
	char			*ox;
	char			*s;

    if (fl.precision != -1)
        fl.zero = 0;
	k = va_arg(vl, unsigned int);
	if (k == (unsigned int)0 && fl.precision == 0)
		return ;
	if (fl.dash)
	{
		str = f(k ,16);
		ox = make_ox_for_x(ox, &fl, (int)ft_strlen(str));
		s = ft_strnew(ft_strlen(str) + ft_strlen(ox) + 1);
		s = ft_catstr(ox, str);
		s_flag(str, buf, fl);
		return ;
	}
	str = make_str_with_precision_for_x(fl, k, f);
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

void	u_flag(va_list vl, t_buf **buf, t_flags fl)
{
	char			*str;
	int				n;
	unsigned int	k;

    if (fl.precision != -1)
        fl.zero = 0;
	k = va_arg(vl, unsigned int);
	if (k == (unsigned int)0 && fl.precision == 0)
		return ;
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
