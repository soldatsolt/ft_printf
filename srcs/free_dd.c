

#include "ft_printf.h"

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
