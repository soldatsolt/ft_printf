/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:31:31 by kmills            #+#    #+#             */
/*   Updated: 2019/08/05 18:31:31 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_double_bits_str(t_double *dd)
{
	int				ic;
	unsigned char	*c;

	dd->s = (unsigned char *)malloc(sizeof(unsigned char) * 65);
	c = (unsigned char *)&dd->w;
	bzero((void*)dd->s, 65);
	ic = 7;
	while (ic + 1)
	{
		dd->i = 0;
		while (dd->i < 8)
		{
			dd->s[8 * (7 - ic) + dd->i] = \
			(char)((c[ic] & (128 >> dd->i)) ? '1' : '0');
			dd->i++;
		}
		ic--;
	}
	dd->s[64] = '\0';
}

void	make_exp(t_double *dd)
{
	dd->exp = 0;
	dd->i = 12;
	dd->pow = 1;
	while (--dd->i > 0)
	{
		if (dd->s[dd->i] == '1')
			dd->exp += dd->pow;
		dd->pow = dd->pow << 1;
	}
	dd->exp = dd->exp - 1023;
}

int		ft_len_exp_double(t_double *dd)
{
	int len;

	if (dd->w < 0)
		dd->w *= -1;
	len = 1;
	while (dd->w >= 10.0)
	{
		dd->w = dd->w / 10;
		len++;
	}
	return (len);
}

int		ft_itoa_double(double n, t_double *dd, t_flags *fl)
{
	dd->w = n;
	make_double_bits_str(dd);
	dd->sign = (unsigned char)((dd->s[0] == '1') ? 1 : 0);
	dd->len = ft_len_exp_double(dd);
	make_exp(dd);
	fl->width = (dd->len + fl->precision >= fl->width) ? 0 : \
	fl->width - dd->len - fl->precision;
	dd->strlen = dd->len + fl->width + fl->precision + 1;
	if (!(dd->str = (char*)malloc(sizeof(char) * (dd->strlen + 1))))
		exit(1);
	dd->str[dd->strlen + 1] = '\0';
	if (!ft_double_in_str(dd, fl))
		exit(1);
	return (0);
}

void	double_flag(va_list vl, t_buf **buf, t_flags fl)
{
	t_double	dd;
	double		v2;

	v2 = va_arg(vl, double);
	if (ft_double_exception(v2, buf, fl))
		return ;
	dd.size = 65;
	dd.dot = 12;
	if (fl.precision == -1)
		fl.precision = 6;
	if (ft_itoa_double(v2, &dd, &fl))
		return ;
	if ((fl.dash && fl.precision == 0) || fl.precision > 0)
		fl.width--;
	if (fl.plus || fl.space || dd.sign)
		fl.width--;
	if (fl.minus)
		double_minus(&dd, buf, &fl);
	else if (fl.zero)
		double_zero(&dd, buf, &fl);
	else
		double_just(&dd, buf, &fl);
	ft_free_dd(&dd);
}
