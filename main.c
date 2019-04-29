/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 07:26:28 by kmills            #+#    #+#             */
/*   Updated: 2019/04/29 06:03:06 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_flag(va_list *vl, char **buf, int *ib,\
const char *restrict *format)
{
	char	*str;

	str = va_arg(*vl, char *);
	*format += 2;
	while (*str)
	{
		**buf = *str;
		str++;
		(*buf)++;
		(*ib)++;
	}
}

void	check_after_perc(va_list *vl, char **buf, int *ib,\
const char *restrict *format)
{
	if ((*format)[1] == '%')
	{
		*format += 2;
		**buf = '%';
		(*buf)++;
		(*ib)++;
		return ;
	}
	else if ((*format)[1] == 's')
		s_flag(vl, buf, ib, format);
}

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
			check_after_perc(&vl, &buf, &ib, &format);
		}
		if (*format)
		{
			*buf = *format;
			format++;
			buf++;
			ib++;
		}
	}
	*buf = '\0';
	buf -= ib;
	ft_putstr(buf);
	va_end(vl);
	return (ib);
}

int		main(int argc, char **argv)
{
	printf("\nThe number of c's in string is: %i\n", ft_printf("%s00001234%%56789%s", "12345", "abcdef"));
	return (0);
}
