/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 07:26:28 by kmills            #+#    #+#             */
/*   Updated: 2019/07/09 02:22:15 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list	vl;
	char	*str;
	t_buf	*buf;
	t_buf	*start;
	int		n;

	buf = create_buf();
	start = buf;
	va_start(vl, format);
	while (*format)
	{
		// if (*format == '%')
		// {
		// 	// check_after_perc(vl, &buf, &ib, &format);
		// }
		// if (*format && *format != '%')
		{
			buf = put_char_to_buf(buf, *format);
			format++;
		}
	}
	printf_buf(start);
	va_end(vl);
	n = returned_printf(start);
	free_all_buff(start);
	return (n);
}

int		main(int argc, char **argv)
{
	ft_printf("235426rere");
	return (0);
}
