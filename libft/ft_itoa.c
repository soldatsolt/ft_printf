/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:45:32 by kmills            #+#    #+#             */
/*   Updated: 2019/08/24 16:46:23 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*keks(int l, long m, long nl, int n)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)ft_memalloc(sizeof(char) * (l + 2))))
		return (NULL);
	if (n < 0)
		str[i++] = '-';
	while (m > 0)
	{
		str[i++] = (nl / m + '0');
		nl = nl % m;
		m = m / 10;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	long	m;
	long	nl;
	int		l;

	m = 1;
	nl = n;
	l = 0;
	if (nl < 0)
	{
		nl = -nl;
		l++;
	}
	while (((m * 10) > 0) ? ((nl / 10) / (m) > 0) : 0)
	{
		m = m * 10;
		l++;
	}
	return (keks(l, m, nl, n));
}
