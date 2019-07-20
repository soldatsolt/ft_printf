/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 07:26:28 by kmills            #+#    #+#             */
/*   Updated: 2019/07/20 07:04:55 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf2(va_list vl, t_buf **buf, const char *restrict format)
{
	while (*format)
	{
		if (*format == '%' && format[1] == '%')
		{
			put_char_to_buf(buf, '%');
			format += 2;
		}
		else if (*format == '%' && format[1] != '%')
		{
			format++; // теперь в ф-ии парсера сразу идёт флаг (без %)
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

int main()
{
	int 		i = 123;

	printf("+++%0 ld+++\n", (long)-8);
	ft_printf("|||%0 ld|||\n", (long)-8);

	return (0);
}
