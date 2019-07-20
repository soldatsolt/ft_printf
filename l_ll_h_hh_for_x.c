#include "ft_printf.h"

char	*make_str_with_precision_for_hhx(t_flags fl, u_int8_t k, char *(*f)(u_int8_t, int))
{
	char	*s;
	int		i;
	char	*str;

	str = f(k, 16);
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

char	*make_str_with_precision_for_hx(t_flags fl, unsigned short k, char *(*f)(unsigned short, int))
{
	char	*s;
	int		i;
	char	*str;

	str = f(k, 16);
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

char	*make_str_with_precision_for_llx(t_flags fl, unsigned long long k, char *(*f)(unsigned long long, int))
{
	char	*s;
	int		i;
	char	*str;

	str = f(k, 16);
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

char	*make_str_with_precision_for_lx(t_flags fl, unsigned long k, char *(*f)(unsigned long, int))
{
	char	*s;
	int		i;
	char	*str;

	str = f(k, 16);
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

void	x_flag_l(va_list vl, t_buf **buf, t_flags fl, char *(*f)(unsigned long, int))
{
	char			*str;
	int				n;
	unsigned long	k;
	char			*ox;
	char			*s;

    if (fl.precision != -1)
        fl.zero = 0;
	k = va_arg(vl, unsigned long);
	if (k == (unsigned long)0 && fl.precision == 0)
		return ;
	if (fl.dash)
	{
		str = f(k ,16);
		if (f == &ft_itoa_base_small_l)
			ox = make_ox_for_x(ox, &fl, (int)ft_strlen(str));
		else
			ox = make_ox_for_X(ox, &fl, (int)ft_strlen(str));
		s = ft_strnew(ft_strlen(str) + ft_strlen(ox) + 1);
		s = ft_catstr(ox, str);
		s_flag(str, buf, fl);
		return ;
	}
	str = make_str_with_precision_for_lx(fl, k, f);
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

void	x_flag_ll(va_list vl, t_buf **buf, t_flags fl, char *(*f)(unsigned long long, int))
{
	char				*str;
	int					n;
	unsigned long long	k;
	char			*ox;
	char			*s;

    if (fl.precision != -1)
        fl.zero = 0;
	k = va_arg(vl, unsigned long long);
	if (k == (unsigned long long)0 && fl.precision == 0)
		return ;
	if (fl.dash)
	{
		str = f(k ,16);
		if (f == &ft_itoa_base_small_ll)
			ox = make_ox_for_x(ox, &fl, (int)ft_strlen(str));
		else
			ox = make_ox_for_X(ox, &fl, (int)ft_strlen(str));
		s = ft_strnew(ft_strlen(str) + ft_strlen(ox) + 1);
		s = ft_catstr(ox, str);
		s_flag(str, buf, fl);
		return ;
	}
	str = make_str_with_precision_for_llx(fl, k, f);
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

void	x_flag_h(va_list vl, t_buf **buf, t_flags fl, char *(*f)(unsigned short, int))
{
	char			*str;
	int				n;
	unsigned short	k;
	char			*ox;
	char			*s;

    if (fl.precision != -1)
        fl.zero = 0;
	k = (unsigned short)va_arg(vl, unsigned int);
	if (k == (unsigned short)0 && fl.precision == 0)
		return ;
	if (fl.dash)
	{
		str = f(k ,16);
		if (f == &ft_itoa_base_small_h)
			ox = make_ox_for_x(ox, &fl, (int)ft_strlen(str));
		else
			ox = make_ox_for_X(ox, &fl, (int)ft_strlen(str));
		s = ft_strnew(ft_strlen(str) + ft_strlen(ox) + 1);
		s = ft_catstr(ox, str);
		s_flag(str, buf, fl);
		return ;
	}
	str = make_str_with_precision_for_hx(fl, k, f);
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

void	x_flag_hh(va_list vl, t_buf **buf, t_flags fl, char *(*f)(u_int8_t, int))
{
	char		*str;
	int			n;
	u_int8_t	k;
	char			*ox;
	char			*s;

    if (fl.precision != -1)
        fl.zero = 0;
	k = (u_int8_t)va_arg(vl, unsigned int);
	if (k == (u_int8_t)0 && fl.precision == 0)
		return ;
	if (fl.dash)
	{
		str = f(k ,16);
		if (f == &ft_itoa_base_small_hh)
			ox = make_ox_for_x(ox, &fl, (int)ft_strlen(str));
		else
			ox = make_ox_for_X(ox, &fl, (int)ft_strlen(str));
		s = ft_strnew(ft_strlen(str) + ft_strlen(ox) + 1);
		s = ft_catstr(ox, str);
		s_flag(str, buf, fl);
		return ;
	}
	str = make_str_with_precision_for_hhx(fl, k, f);
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