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
