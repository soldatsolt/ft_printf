/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbharbo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:58:20 by vbharbo           #+#    #+#             */
/*   Updated: 2019/07/02 14:58:23 by vbharbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		put_str_to_buf(char *str)
{
	if (str)
		while(*str)
			ft_put_buff(*str++, 0);
}


static void	printf_s_flag(char *str, t_pf *pf)
{
	int		n;

	if (pf->accuracy != -1)
		pf->zero = 0;
	str = ft_strdup(str);
	if (pf->accuracy != -1 && pf->accuracy - 1 < (int)ft_strlen(str))
		str[pf->accuracy] = '\0';
	n = pf->len - (int)ft_strlen(str);
	if (n > 0 && !pf->minus)
	{
		if (pf->zero)
			put_some_chars_to_buf('0', n);
		else
			put_some_chars_to_buf(' ', n);
	}
	put_str_to_buf(str);
	if (n > 0 && pf->minus)
	{
		put_some_chars_to_buf(' ', n);
	}
	free(str);
}

void	ft_print_str(t_pf *pf)
{
	char *str;

	str = va_arg(pf->ap, char*);
	if (str)
		printf_s_flag(str, pf);
	else
		printf_s_flag("(null)", pf);
}
