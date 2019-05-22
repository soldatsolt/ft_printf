/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringmath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 06:34:21 by kmills            #+#    #+#             */
/*   Updated: 2019/05/22 07:29:33 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *strplus(char *str1, char *str2)
{
	char	*summ;
	int		i;
	int		ost;
	int		k1;
	int		k2;

	k1 = ft_atoi(str1);
	k2 = ft_atoi(str2);
	printf("%i\n", k1 + k2);
	i = 0;
	ost = 0;
	summ = (char *)malloc(sizeof(char) * 500);
	str1 = ft_strrev(str1);
	str2 = ft_strrev(str2);
	while (i < ft_strlen(str1)) // ZDES' NUZHO USNAT' KAKYA DLINA BOL'SHE
	{
		if (str1[i] + str2[i] - '0' <= '9' && !ost)
			summ[i] = str1[i] + str2[i] - '0';
		else if (str1[i] + str2[i] - '0' <= '9' && ost)
		{
			summ[i] = str1[i] + str2[i] - '0' + ost;	// TYT TOZHE MB PEREPOLNENIE - ETO RABOTAET
			ost = 0;									// HZ KAK ))))
		}
		else
		{
			summ[i] = str1[i] + str2[i] - '0' + ost - 10;
			ost = 1;
		}
		if (!(str1[i + 1]) && ost)
			summ[i + 1] = '1';
		i++;
	}
	summ = ft_strrev(summ);
	ft_printf("%s\n", summ);
	return (summ);
}
