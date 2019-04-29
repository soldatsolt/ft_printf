/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 07:26:28 by kmills            #+#    #+#             */
/*   Updated: 2019/04/29 04:53:16 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *restrict format, ...)
{
	va_list	vl;
	char	*str;
	int		i;
	int		ib;
	char	*buf;

	i = 0;
	ib = 0;
	buf = (char *)malloc(sizeof(char) * 500);
	va_start(vl, format);
	while (format[i])
	{
		if (i > 0 && format[i] == '%' && format[i + 1] == 's')
		{
			str = va_arg(vl, char *);
			i += 2;
			while (*str)
			{
				buf[ib] = *str;
				str++;
				ib++;
			}
		}
		if (format[i])
		{
			buf[ib] = format[i];
			i++;
			ib++;
		}
	}
	buf[ib] = '\0';
	ft_putstr(buf);
	va_end(vl);
	return (i);
}

int	main(int argc, char **argv)
{
	printf("\nThe number of c's in string is: %i\n", ft_printf("12345%s6789", "12345"));
	return (0);
}
