/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbharbo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:58:46 by vbharbo           #+#    #+#             */
/*   Updated: 2019/07/02 14:58:50 by vbharbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long long ft_recast(t_pf *pf, long long ll)
{
	if (pf->ll)
		ll = (long long) va_arg(pf->ap, long long);
	else if (pf->l)
		ll = (long)va_arg(pf->ap, long);
	else if (pf->hh)
		ll = (char)va_arg(pf->ap, int);
	else if (pf->h)
		ll = (short int)va_arg(pf->ap, int);
	else
		ll = (int)va_arg(pf->ap, int);
	return (ll);
}

static void	ft_just_putnbr(t_pf *pf, long long n)
{
	if (pf->accuracy)
		pf->accuracy -= pf->fr_len;
	pf->len = pf->len - pf->accuracy;
	if (pf->plus || pf->space || n < 0)
		pf->len--;
	while (pf->len-- > pf->fr_len)
		ft_put_buff(' ', 0);
	if (n < 0)
		ft_put_buff('-', 0);
	else if (pf->plus)
		ft_put_buff('+', 0);
	else if (pf->space)
		ft_put_buff(' ', 0);
	while (pf->accuracy--)
		ft_put_buff('0', 0);
	ft_unsigned_putnbr(n);
}

static void	ft_flag_int(t_pf *pf, long long n)
{
	if (pf->plus || pf->space || n < 0)
		pf->len--;
	if (n < 0)
		ft_put_buff('-', 0);
	else if (pf->plus)
		ft_put_buff('+', 0);
	else if (pf->space)
		ft_put_buff(' ', 0);
	if (pf->minus)
	{
		pf->len -= (pf->fr_len < pf->accuracy) ?  pf->accuracy : pf->fr_len;
		while (pf->accuracy-- > pf->fr_len)
			ft_put_buff('0', 0);
		ft_unsigned_putnbr(n);
		while (pf->len--)
			ft_put_buff(' ', 0);
	}
	else if (pf->zero)
	{
		while (pf->len-- > pf->fr_len)
			ft_put_buff('0', 0);
		ft_unsigned_putnbr(n);
	}
}

static int	ft_len_int(long long n)
{
	int k;

	if (n == LLONG_MIN)
		return (19);
	if (n < 0)
		n *= -1;
	k = 1;
	while(n >= 10)
	{
		n /= 10;
		k++;
	}
	return (k);
}

void		ft_print_int(t_pf *pf)
{
	long long	n;

	pf->hesh = 0;
	n = ft_recast(pf, 0);
	if (pf->accuracy == 0 && n == 0 && pf->dot)
	{
		ft_zero_zero(pf);
		return ;
	}
	pf->fr_len = ft_len_int(n);
	if (pf->len <= pf->fr_len || pf->len <= pf->accuracy)
		pf->len = 0;
	if (pf->dot || !pf->len)
		pf->zero = 0;
	if (pf->accuracy <= pf->fr_len && n)
		pf->accuracy = 0;
	if (!pf->len)
		pf->minus = 0;
	if (pf->minus || pf->zero)
		ft_flag_int(pf, n);
	else
		ft_just_putnbr(pf, n);
}