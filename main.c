/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 07:26:28 by kmills            #+#    #+#             */
/*   Updated: 2019/07/09 04:06:12 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	turbo_parser(va_list vl, t_buf *buf, const char *restrict format)
{
	printf("\n\n==PARSER==\n\nformat = %s\n\n==PARSER==\n\n", format);
}

void	ft_printf2(va_list vl, t_buf *buf, const char *restrict format)
{
	while (*format)
	{
		if (*format == '%' && format[1] == '%')
		{
			buf = put_char_to_buf(buf, '%');
			format += 2;
		}
		else if (*format == '%' && format[1] != '%')
		{
			format++; // теперь в ф-ии парсера сразу идёт флаг (без %)
			turbo_parser(vl, buf, format);
		}
		else
		{
			buf = put_char_to_buf(buf, *format);
			format++;
		}
	}
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	vl;
	t_buf	*buf;
	t_buf	*start;
	int		n;

	buf = create_buf();
	start = buf;
	va_start(vl, format);
	ft_printf2(vl, buf, format);
	printf_buf(start);
	va_end(vl);
	n = returned_printf(start);
	free_all_buff(start);
	return (n);
}

int		main(int argc, char **argv)
{
	ft_printf("123542%s%i6rere%%");
	return (0);
}
