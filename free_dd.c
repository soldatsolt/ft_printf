/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:31:28 by kmills            #+#    #+#             */
/*   Updated: 2019/08/24 20:56:31 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p_if_fl_minus(char *str, t_buf **buf, t_flags fl, int len)
{
	put_str_to_buf(buf, "0x");
	put_some_chars_to_buf(buf, '0', fl.precision - len);
	put_str_to_buf(buf, str);
	put_some_chars_to_buf(buf, ' ', fl.width - 2 - \
	((fl.precision > len) ? fl.precision : len));
}

void	ft_free_dd(t_double *dd)
{
	free(dd->mantissa);
	free(dd->s);
	free(dd->str);
	dd->size = 0;
	dd->lw = 0;
	dd->sign = 0;
	dd->w = 0;
	dd->len = 0;
	dd->strlen = 0;
	dd->s = NULL;
	dd->str = NULL;
	dd->i = 0;
	dd->pow = 0;
	dd->c = 0;
	dd->exp = 0;
	dd->mantissa = NULL;
	dd->dot = 0;
}
