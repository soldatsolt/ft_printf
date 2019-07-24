#include "ft_printf.h"

char	*make_str_with_precision_for_hhi(t_flags fl, int8_t k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_itoa_hh(k);
	if (fl.precision != -1 && !((k >= 0 && ft_strlen(str) > fl.precision) \
	|| (k < 0 && ft_strlen(str) - 1 > fl.precision)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 2));
		if (k < 0)
			s[i++] = '-';
		while ((k >= 0) ? (i < fl.precision - ft_strlen(str)) : (i < \
		fl.precision - ft_strlen(str) + 2))
		{
			s[i] = '0';
			i++;
		}
		if (k < 0)
		{
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

char	*make_str_with_precision_for_hi(t_flags fl, short k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_itoa_h(k);
	if (fl.precision != -1 && !((k >= 0 && ft_strlen(str) > fl.precision) \
	|| (k < 0 && ft_strlen(str) - 1 > fl.precision)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 2));
		if (k < 0)
			s[i++] = '-';
		while ((k >= 0) ? (i < fl.precision - ft_strlen(str)) : (i < \
		fl.precision - ft_strlen(str) + 2))
		{
			s[i] = '0';
			i++;
		}
		if (k < 0)
		{
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

char	*make_str_with_precision_for_lli(t_flags fl, long long k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_itoa_ll(k);
	if (fl.precision != -1 && !((k >= 0 && ft_strlen(str) > fl.precision) \
	|| (k < 0 && ft_strlen(str) - 1 > fl.precision)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 2));
		if (k < 0)
			s[i++] = '-';
		while ((k >= 0) ? (i < fl.precision - ft_strlen(str)) : (i < \
		fl.precision - ft_strlen(str) + 2))
		{
			s[i] = '0';
			i++;
		}
		if (k < 0)
		{
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

char	*make_str_with_precision_for_li(t_flags fl, long k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_itoa_l(k);
	if (fl.precision != -1 && !((k >= 0 && ft_strlen(str) > fl.precision) \
	|| (k < 0 && ft_strlen(str) - 1> fl.precision)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 2));
		if (k < 0)
			s[i++] = '-';
		while ((k >= 0) ? (i < fl.precision - ft_strlen(str)) : (i < \
		fl.precision - ft_strlen(str) + 2))
		{
			s[i] = '0';
			i++;
		}
		if (k < 0)
		{
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

void	i_flag_l(va_list vl, t_buf **buf, t_flags fl)
{
	char	*str;
	int		n;
	long	k;
	char	z;

    if (fl.precision != -1)
        fl.zero = 0;
	k = va_arg(vl, long);
	if (k == (long)0 && fl.precision == 0)
		return ;
	z = (k >= 0) ? '+' : '-';
	str = make_str_with_precision_for_li(fl, k);
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
       		put_str_to_buf(buf, str + 1);
		else
			put_str_to_buf(buf, str);		
        if (n > 0 && fl.minus)
            put_some_chars_to_buf(buf, ' ', n);
    }
    else
    {
		if (fl.space && k >= 0)
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
	free(str);
}

void	i_flag_ll(va_list vl, t_buf **buf, t_flags fl)
{
	char		*str;
	int			n;
	long long	k;
	char		z;

    if (fl.precision != -1)
        fl.zero = 0;
	k = va_arg(vl, long long);
	if (k == (long long)0 && fl.precision == 0)
		return ;
	z = (k >= 0) ? '+' : '-';
	str = make_str_with_precision_for_lli(fl, k);
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
       		put_str_to_buf(buf, str + 1);
		else
			put_str_to_buf(buf, str);		
        if (n > 0 && fl.minus)
            put_some_chars_to_buf(buf, ' ', n);
    }
    else
    {
		if (fl.space && k >= 0)
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
	free(str);
}

void	i_flag_h(va_list vl, t_buf **buf, t_flags fl)
{
	char	*str;
	int		n;
	short	k;
	char	z;

    if (fl.precision != -1)
        fl.zero = 0;
	k = (short)va_arg(vl, int);
	if (k == (short)0 && fl.precision == 0)
		return ;
	z = (k >= 0) ? '+' : '-';
	str = make_str_with_precision_for_hi(fl, k);
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
       		put_str_to_buf(buf, str + 1);
		else
			put_str_to_buf(buf, str);
        if (n > 0 && fl.minus)
            put_some_chars_to_buf(buf, ' ', n);
    }
    else
    {
		if (fl.space && k >= 0)
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
	free(str);
}

void	i_flag_hh(va_list vl, t_buf **buf, t_flags fl)
{
	char	*str;
	int		n;
	int8_t	k;
	char	z;

    if (fl.precision != -1)
        fl.zero = 0;
	k = (int8_t)va_arg(vl, int);
	if (k == (int8_t)0 && fl.precision == 0)
		return ;
	z = (k >= 0) ? '+' : '-';
	str = make_str_with_precision_for_hhi(fl, k);
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
       		put_str_to_buf(buf, str + 1);
		else
			put_str_to_buf(buf, str);
        if (n > 0 && fl.minus)
            put_some_chars_to_buf(buf, ' ', n);
    }
    else
    {
		if (fl.space && k >= 0)
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
	free(str);
}
