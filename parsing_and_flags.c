#include "ft_printf.h"

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
		if ((**format) == 'l' && fl->l < 2)
			fl->l++;
		if ((**format) == 'j' && fl->l < 1)
			fl->l++;
		if ((**format) == 'h' && !fl->l && fl->h < 2)
			fl->h++;
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
		s_flag(va_arg(vl, char *), buf, fl);
	else if (**format == 'i' || **format == 'd')
		pre_parce_for_i(vl, buf, fl);
	else if (**format == 'D')
		i_flag_l(vl, buf, fl);
	else if (**format == 'u')
		pre_parce_for_u(vl, buf, fl);
	else if (**format == 'U')
		u_flag_l(vl, buf, fl);
	else if (**format == 'c')
		c_flag(vl, buf, fl);
	else if (**format == 'f')
		f_flag(vl, buf, fl);
	else if (**format == 'p')
		p_flag(vl, buf, fl);
	else if (**format == 'o')
		pre_parce_for_o(vl, buf, fl);
	else if (**format == 'O')
		o_flag_l(vl, buf, fl);
	else if (**format == 'x')
		pre_parce_for_x(vl, buf, fl);
	else if (**format == 'X')
		pre_parce_for_X(vl, buf, fl);
	(*format)++;
}
