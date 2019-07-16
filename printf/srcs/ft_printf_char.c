/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbharbo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:58:08 by vbharbo           #+#    #+#             */
/*   Updated: 2019/07/02 14:58:10 by vbharbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_some_chars_to_buf(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_put_buff(c, 0);
		i++;
	}
}

void	ft_print_char(t_pf *pf)
{
	char	c;

	c = (char)va_arg(pf->ap, int);
	if (!pf->minus && pf->len > 1)
	{
		if (pf->zero)
			put_some_chars_to_buf('0', pf->len - 1);
		else
			put_some_chars_to_buf(' ', pf->len - 1);
	}
	ft_put_buff(c, 0);
	if (pf->minus && pf->len > 1)
		put_some_chars_to_buf(' ', pf->len - 1);
}