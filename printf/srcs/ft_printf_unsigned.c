/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbharbo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:23:06 by vbharbo           #+#    #+#             */
/*   Updated: 2019/07/10 15:23:38 by vbharbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int					ft_len_un_int(unsigned long long n)
{
	int k;

	k = 1;
	while(n >= 10)
	{
		n /= 10;
		k++;
	}
	return (k);
}

static void					ft_flag_un_int(t_pf *pf, unsigned long long n)
{
	if (pf->minus)
	{
		pf->len -= (pf->fr_len < pf->accuracy) ?  pf->accuracy : pf->fr_len;
		while (pf->accuracy-- > pf->fr_len)
			ft_put_buff('0', 0);
		ft_realy_unsigned_putnbr(n);
		while (pf->len--)
			ft_put_buff(' ', 0);
	}
	else if (pf->zero)
	{
		while (pf->len-- > pf->fr_len)
			ft_put_buff('0', 0);
		ft_realy_unsigned_putnbr(n);
	}
}

static void					ft_just_un_putnbr(t_pf *pf, unsigned long long n)
{
	if (pf->accuracy)
		pf->accuracy -= pf->fr_len;
	pf->len = pf->len - pf->accuracy;
	while (pf->len-- > pf->fr_len)
		ft_put_buff(' ', 0);
	while (pf->accuracy--)
		ft_put_buff('0', 0);
	ft_realy_unsigned_putnbr(n);
}

void						ft_print_unsigned(t_pf *pf)
{
	unsigned long long	n;

	n = ft_recast(pf, 0);
	pf->plus = 0;
	pf->space = 0;
	if (pf->accuracy == 0 && n == 0 && pf->dot)
	{
		ft_zero_zero(pf);
		return ;
	}
	pf->fr_len = ft_len_un_int(n);
	if (pf->len <= pf->fr_len || pf->len <= pf->accuracy)
		pf->len = 0;
	if (pf->dot || !pf->len)
		pf->zero = 0;
	if (pf->accuracy <= pf->fr_len)
		pf->accuracy = 0;
	if (!pf->len)
		pf->minus = 0;
	if (pf->minus || pf->zero)
		ft_flag_un_int(pf, n);
	else
		ft_just_un_putnbr(pf, n);
}