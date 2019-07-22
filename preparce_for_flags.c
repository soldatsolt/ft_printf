#include "ft_printf.h"

void	pre_parce_for_i(va_list vl, t_buf **buf, t_flags fl)
{
	if (fl.l == 0 && fl.h == 0)
		i_flag(vl, buf, fl);
	else if (fl.l == 1)
		i_flag_l(vl, buf, fl);
	else if (fl.l == 2)
		i_flag_ll(vl, buf, fl);
	else if (fl.h == 1)
		i_flag_h(vl, buf, fl);
	else if (fl.h == 2)
		i_flag_hh(vl, buf, fl);
}

void	pre_parce_for_u(va_list vl, t_buf **buf, t_flags fl)
{
	if (fl.l == 0 && fl.h == 0)
		u_flag(vl, buf, fl);
	else if (fl.l == 1)
		u_flag_l(vl, buf, fl);
	else if (fl.l == 2)
		u_flag_ll(vl, buf, fl);
	else if (fl.h == 1)
		u_flag_h(vl, buf, fl);
	else if (fl.h == 2)
		u_flag_hh(vl, buf, fl);
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

void	pre_parce_for_x(va_list vl, t_buf **buf, t_flags fl)
{
	if (fl.l == 0 && fl.h == 0)
		x_flag(vl, buf, fl, &(ft_itoa_base_small));
	else if (fl.l == 1)
		x_flag_l(vl, buf, fl, &(ft_itoa_base_small_l));
	else if (fl.l == 2)
		x_flag_ll(vl, buf, fl, &(ft_itoa_base_small_ll));
	else if (fl.h == 1)
		x_flag_h(vl, buf, fl, &(ft_itoa_base_small_h));
	else if (fl.h == 2)
		x_flag_hh(vl, buf, fl, &(ft_itoa_base_small_hh));
}

void	pre_parce_for_xx(va_list vl, t_buf **buf, t_flags fl)
{
	if (fl.l == 0 && fl.h == 0)
		x_flag(vl, buf, fl, &(ft_itoa_base_big));
	else if (fl.l == 1)
		x_flag_l(vl, buf, fl, &(ft_itoa_base_big_l));
	else if (fl.l == 2)
		x_flag_ll(vl, buf, fl, &(ft_itoa_base_big_ll));
	else if (fl.h == 1)
		x_flag_h(vl, buf, fl, &(ft_itoa_base_big_h));
	else if (fl.h == 2)
		x_flag_hh(vl, buf, fl, &(ft_itoa_base_big_hh));
}

void	percentage(t_buf **buf, t_flags fl)
{
	if (!fl.minus && fl.width > 1)
	{
		if (fl.zero)
			put_some_chars_to_buf(buf, '0', fl.width - 1);
		else
			put_some_chars_to_buf(buf, ' ', fl.width - 1);
	}
	put_char_to_buf(buf, '%');
	if (fl.minus && fl.width > 1)
		put_some_chars_to_buf(buf, ' ', fl.width - 1);
}
