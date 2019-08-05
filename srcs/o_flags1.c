/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_flags1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:29:57 by kmills            #+#    #+#             */
/*   Updated: 2019/08/05 18:29:58 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	o_flag1(t_flags fl, t_buf **buf, char *s, char *str)
{
	s = ft_catstr("0", str);
	if (fl.precision != -1)
	{
		fl.zero = 0;
		fl.precision = -1;
	}
	free(str);
	str = NULL;
	str = s;
	s_flag(s, buf, fl);
	free(str);
}

void	pre_parce_for_o(va_list vl, t_buf **buf, t_flags fl)
{
	if (fl.l == 0 && fl.h == 0)
		o_flag(vl, buf, fl);
	else if (fl.l == 1)
		o_flag_l(vl, buf, fl);
	else if (fl.l == 2)
		o_flag_ll(vl, buf, fl);
	else if (fl.h == 1)
		o_flag_h(vl, buf, fl);
	else if (fl.h == 2)
		o_flag_hh(vl, buf, fl);
}
