#include "ft_printf.h"

char	*make_str_with_precision_for_hho(t_flags fl, u_int8_t k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_itoa_base_small_hh(k, 8);
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

char	*make_str_with_precision_for_ho(t_flags fl, unsigned short k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_itoa_base_small_h(k, 8);
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

char	*make_str_with_precision_for_llo(t_flags fl, unsigned long long k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_itoa_base_small_ll(k, 8);
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

char	*make_str_with_precision_for_lo(t_flags fl, unsigned long k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_itoa_base_small_l(k, 8);
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

void	o_flag_l(va_list vl, t_buf **buf, t_flags fl)
{
	char			*str;
	int				n;
	unsigned long	k;
	char			*o;
	char			*s;

    if (fl.precision != -1)
        fl.zero = 0;
	k = va_arg(vl, unsigned long);
	if (k == (unsigned long)0 && fl.precision == 0)
		return ;
	str = make_str_with_precision_for_lo(fl, k);
	if (fl.dash)
	{
		o = ft_strdup("00");
		s = ft_strnew(ft_strlen(str) + ft_strlen(o) + 2);
		s = ft_catstr(o, str);
	}
	n = fl.width - (int)ft_strlen(str + 1);
	if (n > 0 && !fl.minus)
	{
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', n);
		else
			put_some_chars_to_buf(buf, ' ', n);
	}
	put_str_to_buf(buf, s + 1);
	if (n > 0 && fl.minus)
		put_some_chars_to_buf(buf, ' ', n);
}

void	o_flag_ll(va_list vl, t_buf **buf, t_flags fl)
{
	char				*str;
	int					n;
	unsigned long long	k;
	char			*o;
	char			*s;

    if (fl.precision != -1)
        fl.zero = 0;
	k = va_arg(vl, unsigned long long);
	if (k == (unsigned long long)0 && fl.precision == 0)
		return ;
	str = make_str_with_precision_for_llo(fl, k);
	if (fl.dash)
	{
		o = ft_strdup("00");
		s = ft_strnew(ft_strlen(str) + ft_strlen(o) + 2);
		s = ft_catstr(o, str);
	}
	n = fl.width - (int)ft_strlen(str + 1);
	if (n > 0 && !fl.minus)
	{
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', n);
		else
			put_some_chars_to_buf(buf, ' ', n);
	}
	put_str_to_buf(buf, s + 1);
	if (n > 0 && fl.minus)
		put_some_chars_to_buf(buf, ' ', n);
}

void	o_flag_h(va_list vl, t_buf **buf, t_flags fl)
{
	char			*str;
	int				n;
	unsigned short	k;
	char			*o;
	char			*s;

    if (fl.precision != -1)
        fl.zero = 0;
	k = (unsigned short)va_arg(vl, unsigned int);
	if (k == (unsigned short)0 && fl.precision == 0)
		return ;
	str = make_str_with_precision_for_ho(fl, k);
	if (fl.dash)
	{
		o = ft_strdup("00");
		s = ft_strnew(ft_strlen(str) + ft_strlen(o) + 2);
		s = ft_catstr(o, str);
	}
	n = fl.width - (int)ft_strlen(str + 1);
	if (n > 0 && !fl.minus)
	{
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', n);
		else
			put_some_chars_to_buf(buf, ' ', n);
	}
	put_str_to_buf(buf, s + 1);
	if (n > 0 && fl.minus)
		put_some_chars_to_buf(buf, ' ', n);
}

void	o_flag_hh(va_list vl, t_buf **buf, t_flags fl)
{
	char		*str;
	int			n;
	u_int8_t	k;
	char			*o;
	char			*s;

    if (fl.precision != -1)
        fl.zero = 0;
	k = (u_int8_t)va_arg(vl, unsigned int);
	if (k == (u_int8_t)0 && fl.precision == 0)
		return ;
	str = make_str_with_precision_for_hho(fl, k);
	if (fl.dash)
	{
		o = ft_strdup("00");
		s = ft_strnew(ft_strlen(str) + ft_strlen(o) + 2);
		s = ft_catstr(o, str);
	}
	n = fl.width - (int)ft_strlen(str + 1);
	if (n > 0 && !fl.minus)
	{
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', n);
		else
			put_some_chars_to_buf(buf, ' ', n);
	}
	put_str_to_buf(buf, s + 1);
	if (n > 0 && fl.minus)
		put_some_chars_to_buf(buf, ' ', n);
}
