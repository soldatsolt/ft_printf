//
// Created by Verlie Bharbo on 2019-07-24.
//

#include "ft_printf.h"

void	ft_none(t_buf **buf, t_flags fl)
{
	fl.zero = 0;
	fl.precision = -1;
	s_flag("nan", buf, fl);
}