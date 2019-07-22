/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 07:26:28 by kmills            #+#    #+#             */
/*   Updated: 2019/07/22 05:42:56 by kmills           ###   ########.fr       */
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

int		main(void)
{
	// printf("%s\n" ,ft_catstr("12345", "6789 10 11 12"));
	printf("+++!%3.3lo%#3.3lo%#3.3x%#3.3X %.2s%p!+++\n", 12345, 12345, 12345, 12345, "QWE", "2");
	ft_printf("|||!%3.3lo%#3.3lo%#3.3x%#3.3X %.2s%p!|||\n", 12345, 12345, 12345, 12345, "QWE", "2");
	// printf("%p\n", "@");
	// ft_printf("%p\n", "@");
	// printf("%#3.3o\n", 12345);
	// ft_printf("%#3.3o\n", 12345);
	return (0);
}
