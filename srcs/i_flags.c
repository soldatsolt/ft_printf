/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:30:34 by kmills            #+#    #+#             */
/*   Updated: 2019/08/05 18:32:26 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	i_flag(va_list vl, t_buf **buf, t_flags fl)
{
	char	*str;
	int		n;
	int		k;

	if (fl.precision != -1)
		fl.zero = 0;
	k = va_arg(vl, int);
	if (k == (int)0 && fl.precision == 0)
		return ;
	str = make_str_with_precision_for_i(fl, k);
	n = fl.width - (int)ft_strlen(str);
	if (fl.plus && k >= 0)
		n--;
	if ((k < 0 || fl.plus) && fl.zero)
		i_flag1(buf, fl, str, k);
	else
		i_flag2(buf, fl, str, k);
	free(str);
}

void	i_flag_hh(va_list vl, t_buf **buf, t_flags fl)
{
	char	*str;
	int		n;
	int8_t	k;
	char	z;

	fl.zero = (-1 != fl.precision) ? 0 : fl.zero;
	k = (int8_t)va_arg(vl, int);
	if (k == (int8_t)0 && fl.precision == 0)
		return ;
	z = (char)((k >= 0) ? '+' : '-');
	str = make_str_with_precision_for_hhi(fl, k);
	n = fl.width - (int)ft_strlen(str);
	if (fl.plus && k >= 0)
		n--;
	if ((k < 0 || fl.plus) && fl.zero)
		i_flag1_hh(buf, fl, str, k);
	else
		i_flag2_hh(buf, fl, str, k);
	free(str);
}

void	i_flag_h(va_list vl, t_buf **buf, t_flags fl)
{
	char	*str;
	int		n;
	short	k;
	char	z;

	fl.zero = (-1 != fl.precision) ? 0 : fl.zero;
	k = (short)va_arg(vl, int);
	if (k == (short)0 && fl.precision == 0)
		return ;
	z = (char)((k >= 0) ? '+' : '-');
	str = make_str_with_precision_for_hi(fl, k);
	n = fl.width - (int)ft_strlen(str);
	if (fl.plus && k >= 0)
		n--;
	if ((k < 0 || fl.plus) && fl.zero)
		i_flag1_h(buf, fl, str, k);
	else
		i_flag2_h(buf, fl, str, k);
	free(str);
}

void	i_flag_ll(va_list vl, t_buf **buf, t_flags fl)
{
	char		*str;
	int			n;
	long long	k;
	char		z;

	fl.zero = (-1 != fl.precision) ? 0 : fl.zero;
	k = va_arg(vl, long long);
	if (k == (long long)0 && fl.precision == 0)
		return ;
	z = (char)((k >= 0) ? '+' : '-');
	str = make_str_with_precision_for_lli(fl, k);
	n = fl.width - (int)ft_strlen(str);
	if (fl.plus && k >= 0)
		n--;
	if ((k < 0 || fl.plus) && fl.zero)
		i_flag1_ll(buf, fl, str, k);
	else
		i_flag2_ll(buf, fl, str, k);
	free(str);
}

void	i_flag_l(va_list vl, t_buf **buf, t_flags fl)
{
	char	*str;
	int		n;
	long	k;
	char	z;

	fl.zero = (-1 != fl.precision) ? 0 : fl.zero;
	k = va_arg(vl, long);
	if (k == (long)0 && fl.precision == 0)
		return ;
	z = (char)((k >= 0) ? '+' : '-');
	str = make_str_with_precision_for_li(fl, k);
	n = fl.width - (int)ft_strlen(str);
	if (fl.plus && k >= 0)
		n--;
	if ((k < 0 || fl.plus) && fl.zero)
		i_flag1_l(buf, fl, str, k);
	else
		i_flag2_l(buf, fl, str, k);
	free(str);
}
