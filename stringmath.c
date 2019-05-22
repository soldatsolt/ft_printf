/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringmath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 06:34:21 by kmills            #+#    #+#             */
/*   Updated: 2019/05/22 09:36:10 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *strplus(char *str1, char *str2)
{
	char	*summ;
	int		i;
	int		ost;
	int		l;

	i = 0;
	ost = 0;
	summ = (char *)malloc(sizeof(char) * 500);
	str1 = ft_strrev(str1);
	str2 = ft_strrev(str2);
	if (ft_strlen(str1) < ft_strlen(str2))
	{
		l = ft_strlen(str1);
		while (i + l < ft_strlen(str2))
		{
			str1[i + l] = '0';
			i++;
		}
	}
	else
	{
		l = ft_strlen(str2);
		while (i + l < ft_strlen(str1))
		{
			str2[i + l] = '0';
			i++;
		}
	}
	i = 0;
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
	str1 = ft_strrev(str1);
	str2 = ft_strrev(str2);
	summ = ft_strrev(summ);
	return (summ);
}

char	*strminus(char *str1, char *str2)
{
	char	*razn;
	int		i;
	int		ost;
	int		l;

	i = 0;
	ost = 0;
	razn = (char *)malloc(sizeof(char) * 500);
	str1 = ft_strrev(str1);
	str2 = ft_strrev(str2);
	if (ft_strlen(str1) < ft_strlen(str2))
	{
		l = ft_strlen(str1);
		while (i + l < ft_strlen(str2))
		{
			str1[i + l] = '0';
			i++;
		}
	}
	else
	{
		l = ft_strlen(str2);
		while (i + l < ft_strlen(str1))
		{
			str2[i + l] = '0';
			i++;
		}
	}
	i = 0;
	while (i < ft_strlen(str1)) // ZDES' NUZHO USNAT' KAKYA DLINA BOL'SHE
	{
		if (str1[i] - str2[i] + '0' >= '0' && !ost)
			razn[i] = str1[i] - str2[i] + '0';
		else if (str1[i] - str2[i] + '0' >= '0' && ost)
		{
			razn[i] = str1[i] - str2[i] + '0' - ost;	// TYT TOZHE MB PEREPOLNENIE - ETO RABOTAET
			ost = 0;									// HZ KAK ))))
		}
		else
		{
			razn[i] = str1[i] - str2[i] + '0' - ost + 10;
			ost = 1;
		}
		if (!(str1[i + 1]) && ost)
			razn[i + 1] = '1';
		i++;
	}
	str1 = ft_strrev(str1);
	str2 = ft_strrev(str2);
	razn = ft_strrev(razn);
	return (razn);
}

char	*charumn(char c1, char c2)
{
	char	*rez;
	int		i;
	char	*cc1;

	if (c1 == '0' || c2 == '0')
		return ("0");
	i = 0;
	cc1 = (char *)malloc(sizeof(char) * 2);
	rez = (char *)malloc(sizeof(char) * 500);
	cc1[0] = c1;
	ft_bzero(rez, 500);
	while (i < ((int)c2 - '0'))
	{
		rez = strplus(rez, cc1);
		i++;
	}
	free(cc1);
	return (rez);
}
