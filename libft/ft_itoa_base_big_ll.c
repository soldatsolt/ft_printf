/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_big_ll.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 03:51:23 by kmills            #+#    #+#             */
/*   Updated: 2019/07/22 02:27:57 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*keks(int base, u_int64_t m, u_int64_t nl)
{
	char	*str;
	int		i;
	char	*abc;

	abc = ft_strdup("0123456789ABCDEF");
	i = 0;
	str = ft_strnew(70);
	while (m)
	{
		str[i++] = (abc[nl / m]);
		nl = nl % m;
		m = m / base;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_base_big_ll(unsigned long long n, int base)
{
	u_int64_t	m;
	u_int64_t	nl;
	int			l;

	m = 1;
	l = 0;
	nl = n;
	while (((m * base) > 0) ? (nl / (m * base) > 0) : 0)
	{
		m = m * base;
		l++;
	}
	return (keks(base, m, nl));
}
