/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbharbo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:49:49 by vbharbo           #+#    #+#             */
/*   Updated: 2019/07/07 16:49:51 by vbharbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_put_buff(char c, int flag)
{
	static t_buff	buff;

	if (!buff.tmp)
	{
		buff.i = 0;
		buff.re = 0;
		if (!(buff.tmp = ft_memalloc(1000)))
			return (-1);
	}
	if (flag)
	{
		write(1, buff.tmp, buff.i);
		ft_memdel((void*)&buff.tmp);
		return ((int)(buff.re * 1000 + buff.i));
	}
	if (buff.i == 1000)
	{
		buff.re++;
		buff.i = 0;
		write(1, buff.tmp, 1000);
		ft_strclr(buff.tmp);
	}
	buff.tmp[buff.i] = c;
	buff.i++;
	return (int)(buff.re * 1000 + buff.i);
}

void	ft_zero_zero(t_pf *pf)
{
	if (pf->plus || pf->space || pf->hesh)
		pf->len--;
	while (pf->len-- > 0)
		ft_put_buff(' ', 0);
	if (pf->plus)
		ft_put_buff('+', 0);
	else if (pf->space)
		ft_put_buff(' ', 0);
	else if (pf->hesh)
		ft_put_buff('0', 0);
}

void	ft_unsigned_putnbr(long long n)
{
	if (n > 9)
	{
		ft_unsigned_putnbr(n / 10);
		ft_put_buff(n % 10 + '0', 0);
	}
	else if (n >= 0)
		ft_put_buff(n + '0', 0);
	else if (n == LLONG_MIN)
	{
		ft_unsigned_putnbr(922337203685477580);
		ft_put_buff('8', 0);
	}
	else
	{
		n *= -1;
		ft_unsigned_putnbr(n);
	}
}
