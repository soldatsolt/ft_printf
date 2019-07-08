/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 07:26:28 by kmills            #+#    #+#             */
/*   Updated: 2019/07/09 02:06:42 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list	vl;
	char	*str;
	int		i;
	int		ib;
	char	*buf;

	i = 0;
	ib = 0;
	buf = (char *)malloc(sizeof(char) * 500);
	ft_bzero(buf, 500);
	va_start(vl, format);
	while (*format)
	{
		if (*format == '%')
		{
			check_after_perc(vl, &buf, &ib, &format);
		}
		if (*format && *format != '%')
		{
			*buf = *format;
			format++;
			buf++;
			ib++;
		}
	}
	*buf = '\0';
	buf -= ib;
	write(1, buf, ft_strlen(buf) + 1);
	va_end(vl);
	free(buf);
	return (ib);
}

int		main(int argc, char **argv)
{
	t_buf	*buf;
	t_buf	*start;
	char	c;

	c = 'a';
	buf = create_buf();
	start = buf;
	while (c <= 'z')
	{
		buf = put_char_to_buf(buf, c);
		c++;
	}
	put_str_to_buf(buf, "1234567890\n\nasdfghjkl\n");
	printf_buf(start);
	return (0);
}
