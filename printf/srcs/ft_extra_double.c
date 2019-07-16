//
// Created by Verlie Bharbo on 2019-07-16.
//

#include "../includes/ft_printf.h"

static void	ft_put_precision(t_double *dd, t_pf *pl)
{
	while (pl->accuracy-- && dd->mantissa[dd->i])
		ft_put_buff(dd->mantissa[dd->i++], 0);
	while (pl->accuracy-- >= 0)
		ft_put_buff('0', 0);
}

void	double_zero(t_double *dd, t_pf *pf)
{
	if (dd->w < 0)
		ft_put_buff('-', 0);
	else if (pf->plus)
		ft_put_buff('+', 0);
	else if (pf->space)
		ft_put_buff(' ', 0);
	dd->i = -1;
	while (dd->mantissa[++dd->i] == '0');
	while (pf->len-- > 0)
		ft_put_buff('0', 0);
	while (dd->i < 13)
		ft_put_buff(dd->mantissa[dd->i++], '0');
	if ((pf->hesh && !pf->accuracy) || pf->accuracy)
		ft_put_buff('.', 0);
	ft_put_precision(dd, pf);
}

void	double_just(t_double *dd, t_pf *pf)
{
	while (pf->len-- > 0)
		ft_put_buff(' ', 0);
	if (dd->w < 0)
		ft_put_buff('-', 0);
	else if (pf->plus)
		ft_put_buff('+', 0);
	else if (pf->space)
		ft_put_buff(' ', 0);
	dd->i = -1;
	while (dd->mantissa[++dd->i] == '0');
	while (dd->i < 13)
		ft_put_buff(dd->mantissa[dd->i++], 0);
	if ((pf->hesh && !pf->accuracy) || pf->accuracy)
		ft_put_buff('.', 0);
	ft_put_precision(dd, pf);
}

void	double_minus(t_double *dd, t_pf *pf)
{
	if (dd->w < 0)
		ft_put_buff('-', 0);
	else if (pf->plus)
		ft_put_buff('+', 0);
	else if (pf->space)
		ft_put_buff(' ', 0);
	dd->i = -1;
	while (dd->mantissa[++dd->i] == '0');
	while (dd->i < 13)
		ft_put_buff(dd->mantissa[dd->i++], 0);
	if ((pf->hesh && !pf->accuracy) || pf->accuracy)
		ft_put_buff('.', 0);
	ft_put_precision(dd, pf);
	while (pf->len--)
		ft_put_buff(' ', 0);
}