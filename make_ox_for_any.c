/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ox_for_any.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:30:57 by kmills            #+#    #+#             */
/*   Updated: 2019/08/05 18:31:00 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_ox_for_make_ox(char *ox, int n)
{
	int	i;

	i = 2;
	ox[0] = '0';
	ox[1] = 'x';
	while (i < n)
	{
		ox[i] = '0';
		i++;
	}
	ox[i] = '\0';
	return (ox);
}

char	*make_ox_for_make_oxx(char *ox, int n)
{
	int	i;

	i = 2;
	ox[0] = '0';
	ox[1] = 'X';
	while (i < n)
	{
		ox[i] = '0';
		i++;
	}
	ox[i] = '\0';
	return (ox);
}

char	*make_ox_for_p(char *ox, t_flags *fl)
{
	int	n;

	n = 0;
	if ((fl->zero && fl->width > 14) || fl->precision > 12)
	{
		if (fl->width - 2 > fl->precision && fl->precision == -1)
		{
			ox = ft_strnew(fl->width - 11 + 1);
			n = fl->width - 12;
		}
		else
		{
			ox = ft_strnew(fl->precision - 9 + 1);
			n = fl->precision - 10;
		}
		ox = make_ox_for_make_ox(ox, n);
		if (fl->precision != -1)
		{
			fl->zero = 0;
			fl->precision = -1;
		}
	}
	else
		ox = ft_strdup("0x");
	return (ox);
}

char	*make_ox_for_xx(char *ox, t_flags *fl, int l)
{
	int	n;

	n = 0;
	if ((fl->zero && fl->width > l + 2) || fl->precision > l)
	{
		if (fl->width - 2 > fl->precision && fl->precision == -1)
		{
			ox = ft_strnew(fl->width - (l - 1) + 1);
			n = fl->width - l;
		}
		else
		{
			ox = ft_strnew(fl->precision - (l - 3) + 1);
			n = fl->precision - (l - 2);
		}
		ox = make_ox_for_make_oxx(ox, n);
	}
	else
		ox = ft_strdup("0X");
	if (fl->precision != -1)
		fl->zero = 0;
	fl->precision = -1;
	return (ox);
}

char	*make_ox_for_x(char *ox, t_flags *fl, int l)
{
	int	n;

	n = 0;
	if ((fl->zero && fl->width > l + 2) || fl->precision > l)
	{
		if (fl->width - 2 > fl->precision && fl->precision == -1)
		{
			ox = ft_strnew(fl->width - (l - 1) + 1);
			n = fl->width - l;
		}
		else
		{
			ox = ft_strnew(fl->precision - (l - 3) + 1);
			n = fl->precision - (l - 2);
		}
		ox = make_ox_for_make_ox(ox, n);
	}
	else
		ox = ft_strdup("0x");
	if (fl->precision != -1)
		fl->zero = 0;
	fl->precision = -1;
	return (ox);
}
