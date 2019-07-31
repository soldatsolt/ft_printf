/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 07:26:28 by kmills            #+#    #+#             */
/*   Updated: 2019/07/31 20:09:14 by kmills           ###   ########.fr       */
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
	float f = 11.25111;
	double w;
	long double lw = 1111111111111111111111111111111111111111111111111.251111111100000000000000;
	printf   ("float -    %.100f\n", 0.0);
	ft_printf("ft_float - %.100f\n", 0.0);
	printf   ("float -    %.100Lf\n", 0.0);
	ft_printf("ft_float - %.100Lf\n", 0.0);
	w = -0.0;
	if (w == -0.0 && w == 0.0)
		printf("\n\n\n\n\n\nhello\n\n\n\n\n");
	f = (float) (0.0 / 0.0);
	w = 0.0 / 0.0;
	lw = 0.0 / 0.0;
	if (f != f && w != w && lw != lw)
	{
		printf("% #10.40f\n", f);
		ft_printf("% #10.40f\n", f);
	}
	return (0);
}
