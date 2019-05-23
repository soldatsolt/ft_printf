/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringmath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 06:34:21 by kmills            #+#    #+#             */
/*   Updated: 2019/05/23 15:48:01 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *strplus(char *s1, char *s2)
{
	char	*summ;
	int		i;
	int		ost;
	int		l;
	char	*str1;
	char	*str2;

	str1 = (char *)malloc(sizeof(char) * 500);
	str2 = (char *)malloc(sizeof(char) * 500);
	ft_bzero(str1, 500);
	ft_bzero(str2, 500);
	ft_strcpy(str1, s1);
	ft_strcpy(str2, s2);
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
		else if (str1[i] + str2[i] - '0' < '9' && ost)
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
	while (summ[i] == '0')
	{
		summ[i] = '\0';
		i--;
	}
	str1 = ft_strrev(str1);
	str2 = ft_strrev(str2);
	summ = ft_strrev(summ);
	return (summ);
}

void	replace_strings(char **str1, char **str2)
{
	char *tmp;

	tmp = (char *)malloc(sizeof(char) * 500);
	ft_strcpy(tmp, (*str1));
	ft_strcpy((*str1), (*str2));
	ft_strcpy((*str2), tmp);
	free(tmp);
}

char	*strminus(char *s1, char *s2)
{
	char	*razn;
	int		i;
	int		ost;
	int		l;
	int		f;
	char	*str1;
	char	*str2;

	str1 = (char *)malloc(sizeof(char) * 500);
	str2 = (char *)malloc(sizeof(char) * 500);
	ft_bzero(str1, 500);
	ft_bzero(str2, 500);
	ft_strcpy(str1, s1);
	ft_strcpy(str2, s2);
	f = 0;
	i = 0;
	ost = 0;
	razn = (char *)malloc(sizeof(char) * 500);
	ft_bzero(razn, 500);
	if (!srav_nums(str1, str2))
	{
		replace_strings(&str1, &str2);
		f = 1;
	}
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
		else if (str1[i] - str2[i] + '0' > '0' && ost)
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
	while (razn[i - 1] == '0')
	{
		razn[i - 1] = '\0';
		i--;
	}
	if (f)
		razn[i] = '-';
	str1 = ft_strrev(str1);
	str2 = ft_strrev(str2);
	if (f)
		replace_strings(&str1, &str2);
	razn = ft_strrev(razn);
	return (razn);
}

int		srav_nums(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (ft_strlen(str1) > ft_strlen(str2))
		return (1);
	else if (ft_strlen(str1) < ft_strlen(str2))
		return (0);
	else
	{
		while (str1[i])
		{
			if (str1[i] > str2[i])
				return (1);
			else if (str2[i] > str1[i])
				return (0);
			i++;
		}
	}
	return (-1);
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
	rez = (char *)malloc(sizeof(char) * 4);
	cc1[0] = c1;
	ft_bzero(rez, 4);
	while (i < ((int)c2 - '0'))
	{
		rez = strplus(rez, cc1);
		i++;
	}
	rez[i] = '\0';
	free(cc1);
	return (rez);
}

char	*des(int step)
{
	char	*rez;
	int		i;

	i = 1;
	rez = (char *)malloc(sizeof(char) * step + 2);
	rez[0] = '1';
	while (i < step + 1)
	{
		rez[i] = '0';
		i++;
	}
	rez[step + 1] = '\0';
	return (rez);
}

char	*partumn(char *str1, char c2)
{
	int		i;
	char	*rez;
	char	*zero;

	zero = (char *)malloc(sizeof(char) * 2);
	zero[0] = '0';
	zero[1] = '\0';
	rez = strplus(zero, str1);
	i = 1;
	while (i < (int)c2 - '0')
	{
		rez = strplus(rez, str1);
		i++;
	}
	
	return (rez);
}

char	*umnoz(char *s1, char *s2)
{
	char	*rez;
	char	*i;
	char	*str1;
	char	*str2;
	char	*zero;
	char	*one;
	
	zero = (char *)malloc(sizeof(char) * 2);
	zero[0] = '0';
	zero[1] = '\0';
	one = (char *)malloc(sizeof(char) * 2);
	one[0] = '1';
	one[1] = '\0';
	str1 = (char *)malloc(sizeof(char) * 500);
	str2 = (char *)malloc(sizeof(char) * 500);
	i = (char *)malloc(sizeof(char) * 500);
	ft_bzero(str1, 500);
	ft_bzero(str2, 500);
	ft_strcpy(str1, s1);
	ft_strcpy(str2, s2);
	ft_strcpy(i, s2);
	rez = strplus(zero, str1);
	i = strminus(i, one);
	while (srav_nums(i, "0") == 1)
	{
		rez = strplus(rez, str1);
		i = strminus(i, one);
	}
	return (rez);
}