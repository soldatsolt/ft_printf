/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbharbo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:48:41 by vbharbo           #+#    #+#             */
/*   Updated: 2019/07/10 15:49:24 by vbharbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_realy_unsigned_putnbr(unsigned long long n)
{
	if (n == ULLONG_MAX)
	{
		ft_realy_unsigned_putnbr(1844674407370955161);
		ft_put_buff('5', 0);
	}
	else if (n > 9)
	{
		ft_realy_unsigned_putnbr(n / 10);
		ft_put_buff((char)(n % 10 + '0'), 0);
	}
	else
		ft_put_buff((char)(n + '0'), 0);
}

char	*ft_itoa_base_costil(unsigned long long n, char flag)
{
	if (flag == 'o')
	{
		if (n == ULLONG_MAX)
			return ("1777777777777777777777");
		else
			return ft_itoa_base_small(n, 8);
	}
	else if (flag == 'x')
	{
		if (n == ULLONG_MAX)
			return ("ffffffffffffffff");
		else
			return ft_itoa_base_small(n, 16);
	}
	else
	{

		if (n == ULLONG_MAX)
			return ("FFFFFFFFFFFFFFFF");
		else
			return ft_itoa_base_big(n, 16);
	}
}