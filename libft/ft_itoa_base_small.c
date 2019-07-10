/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_small.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:56:42 by kmills            #+#    #+#             */
/*   Updated: 2019/07/10 15:20:50 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*keks(int base, u_int64_t m, u_int64_t nl, int n)
{
	char	*str;
	int		i;
	int		l;
	char	*abc;

	abc = ft_strdup("0123456789abcdef");
	l = 0;
	i = 0;
	str = ft_strnew(70);
	if (n < 0)
		str[i++] = '-';
	while (m)
	{
		str[i++] = (abc[nl / m]);
		nl = nl % m;
		m = m / base;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_base_small(int64_t n, int base)
{
	u_int64_t	m;
	u_int64_t	nl;
	int			l;

	m = 1;
	l = 0;
	if (n < 0)
	{
		nl = -n;
		l++;
	}
	else
		nl = n;
	while (nl / (m * base) > 0)
	{
		m = m * base;
		l++;
	}
	return (keks(base, m, nl, n));
}