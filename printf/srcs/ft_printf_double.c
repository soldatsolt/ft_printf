//
// Created by Verlie Bharbo on 2019-07-16.
//

#include "../includes/ft_printf.h"

static void	make_double_bits_str(t_double *dd)
{
	int				ic;
	unsigned char	*c;

	if (!(dd->s = (unsigned char *)malloc(sizeof(unsigned char) * 65)))
		exit(1);
	c = (unsigned char *)&dd->w;
	bzero((void*)dd->s, 65);
	ic = 7;
	while (ic + 1)
	{
		dd->i = 0;
		while (dd->i < 8)
		{
			dd->s[8 * (7 - ic) + dd->i] = (char)((c[ic] & (128 >> dd->i)) ? '1' : '0');
			dd->i++;
		}
		ic--;
	}
	dd->s[64] = '\0';
}

static void	make_exp(t_double *dd)
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

static int	ft_len_exp(double w)
{
	int len;

	if (w < 0)
		w *= -1;
	len = 1;
	while (w >= 10.0)
	{
		w = w / 10;
		len++;
	}
	return (len);
}


static void	ft_itoa_double(double n, t_double *dd, t_pf *pf)
{
	dd->w = n;
	make_double_bits_str(dd);
	dd->len = ft_len_exp(dd->w);
	make_exp(dd);
	pf->len = (dd->len + pf->accuracy >= pf->len) ? 0 : pf->len - dd->len - pf->accuracy;
	dd->strlen = dd->len + pf->len + pf->accuracy + 1;
	dd->str = (char*)malloc(sizeof(char) * (dd->strlen + 1));
	dd->str[dd->strlen + 1] = '\0';
	if (!ft_double_in_str(dd, pf))
		exit(1);
}

void 	ft_print_double(t_pf *pf)
{
	t_double	dd;

	if (pf->accuracy == -1)
		pf->accuracy = 6;
	ft_itoa_double(va_arg(pf->ap, double), &dd, pf);
	if ((pf->hesh && pf->accuracy == 0) || pf->accuracy > 0)
		pf->len--;
	if (pf->plus || pf->space || dd.w < 0)
		pf->len--;
	if (pf->minus)
		double_minus(&dd, pf);
	else if (pf->zero)
		double_zero(&dd, pf);
	else
		double_just(&dd, pf);
}