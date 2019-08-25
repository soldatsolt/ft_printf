/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 07:26:28 by kmills            #+#    #+#             */
/*   Updated: 2019/08/25 17:20:09 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	fl->ll = 0;
}

void	ft_printf2(va_list vl, t_buf **buf, const char *restrict format)
{
	while (*format)
	{
		if (*format == '%' && format[1] == '%')
		{
			put_char_to_buf(buf, '%');
			format += 2;
		}
		else if (*format == '%' && !format[1])
		{
			break ;
		}
		else if (*format == '%' && format[1] != '%')
		{
			format++;
			turbo_parser(vl, buf, &format);
		}
		else
		{
			put_char_to_buf(buf, *format);
			format++;
		}
	}
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	vl;
	t_buf	*buf;
	t_buf	*buf_start;
	int		n;

	buf = create_buf();
	buf_start = buf;
	va_start(vl, format);
	ft_printf2(vl, &buf, format);
	print_buf(buf_start);
	va_end(vl);
	n = returned_printf(buf_start);
	free_all_buff(buf_start);
	return (n);
}

void	turbo_parser2(va_list vl, t_buf **buf, const char *restrict *format, \
t_flags fl)
{
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
		pre_parce_for_xx(vl, buf, fl);
}

void	turbo_parser(va_list vl, t_buf **buf, const char *restrict *format)
{
	t_flags	fl;

	make_t_flags0(&fl);
	preparcing(buf, &fl, format);
	turbo_parser2(vl, buf, format, fl);
	if (*format[0])
		(*format)++;
}

int main()
{
	printf("%5.0f|\n", -7.3);
	ft_printf("%5.0f|\n", -7.3);
	return 0;
}