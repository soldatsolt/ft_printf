/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 07:26:28 by kmills            #+#    #+#             */
/*   Updated: 2019/04/29 03:33:42 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *restrict format, ...)
{
	va_list	vl;
	char	*str;
	int		i;

	i = 0;
	va_start(vl, format);
	str = va_arg(vl, char *);
	while (format[i])
	{
		ft_putchar(format[i]);
		ft_putchar('\n');
		i++;
	}
	va_end(vl);
	return (i);
}

int	main(int argc, char **argv)
{
	printf("The number of c's in string is: %i\n", ft_printf("123456789"));
	return (0);
}
