//
// Created by Verlie Bharbo on 2019-07-16.
//

#include "../includes/ft_printf.h"

static unsigned long long	ft_recast(t_pf *pf, unsigned long long ul)
{
	if (pf->ll)
		ul = (unsigned long long) va_arg(pf->ap, unsigned long long);
	else if (pf->l)
		ul = (unsigned long)va_arg(pf->ap, unsigned long);
	else if (pf->hh)
		ul = (unsigned char)va_arg(pf->ap, unsigned int);
	else if (pf->h)
		ul = (unsigned short int)va_arg(pf->ap, unsigned int);
	else
	ul = (unsigned int)va_arg(pf->ap, unsigned int);
	return (ul);
}

static void					ft_flag_x(t_pf *pf, char *str)
{
	if (pf->hesh)
		pf->len--;
	if (pf->minus)
	{
		pf->len -= (pf->fr_len < pf->accuracy) ?  pf->accuracy : pf->fr_len;
		while (pf->accuracy-- > pf->fr_len)
			ft_put_buff('0', 0);
		if (pf->hesh)
			ft_put_buff('0', 0);
		put_str_to_buf(str);
		while (pf->len--)
			ft_put_buff(' ', 0);
	}
	else if (pf->zero)
	{
		if (pf->hesh)
			ft_put_buff('0', 0);
		while (pf->len-- > pf->fr_len)
			ft_put_buff('0', 0);
		put_str_to_buf(str);
	}
	free(str);
}

static void					ft_just_x(t_pf *pf, char *str)
{
	if (pf->accuracy)
		pf->accuracy -= pf->fr_len;
	if (pf->accuracy > 0)
		pf->len = pf->len - pf->accuracy;
	if (pf->hesh)
		pf->len--;
	while (pf->len-- > pf->fr_len)
		ft_put_buff(' ', 0);
	if (pf->hesh)
		ft_put_buff('0', 0);
	while (pf->accuracy-- > 0)
		ft_put_buff('0', 0);
	put_str_to_buf(str);
	free(str);
}

void		ft_print_x(t_pf *pf)
{
	unsigned long long	n;
	char 				*str;

	pf->plus = 0;
	pf->space = 0;
	n = ft_recast(pf, 0);
	if (pf->accuracy == 0 && n == 0 && pf->dot)
	{
		ft_zero_zero(pf);
		return ;
	}
	str = ft_itoa_base_costil(n, 'x');
	pf->fr_len = (int)ft_strlen(str);
	if (pf->len <= pf->fr_len || pf->len <= pf->accuracy)
		pf->len = 0;
	if (pf->dot || !pf->len)
		pf->zero = 0;
	if (!pf->len)
		pf->minus = 0;
	if (pf->minus || pf->zero)
		ft_flag_x(pf, str);
	else
		ft_just_x(pf, str);
}