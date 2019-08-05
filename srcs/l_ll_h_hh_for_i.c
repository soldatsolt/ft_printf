/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_ll_h_hh_for_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:30:19 by kmills            #+#    #+#             */
/*   Updated: 2019/08/05 18:30:19 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_str_with_precision_for_hhi(t_flags fl, int8_t k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_itoa_hh(k);
	if (fl.precision != -1 && !((k >= 0 && (int)ft_strlen(str) > fl.precision) \
	|| (k < 0 && (int)ft_strlen(str) - 1 > fl.precision)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 2));
		if (k < 0)
			s[i++] = '-';
		while ((k >= 0) ? (i < fl.precision - (int)ft_strlen(str)) : (i < \
		fl.precision - (int)ft_strlen(str) + 2))
			s[i++] = '0';
		s = ((k < 0) ? ft_strcpy(&(s[i]), &str[1]) : ft_strcpy(&(s[i]), str));
		s = s - i;
		free(str);
		str = NULL;
		s[(k >= 0) ? (fl.precision) : (fl.precision + 1)] = '\0';
	}
	else
		s = str;
	return (s);
}

char	*make_str_with_precision_for_hi(t_flags fl, short k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_itoa_h(k);
	if (fl.precision != -1 && !((k >= 0 && (int)ft_strlen(str) > fl.precision) \
	|| (k < 0 && (int)ft_strlen(str) - 1 > fl.precision)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 2));
		if (k < 0)
			s[i++] = '-';
		while ((k >= 0) ? (i < fl.precision - (int)ft_strlen(str)) : (i < \
		fl.precision - (int)ft_strlen(str) + 2))
			s[i++] = '0';
		s = ((k < 0) ? ft_strcpy(&(s[i]), &str[1]) : ft_strcpy(&(s[i]), str));
		s = s - i;
		free(str);
		str = NULL;
		s[(k >= 0) ? (fl.precision) : (fl.precision + 1)] = '\0';
	}
	else
		s = str;
	return (s);
}

char	*make_str_with_precision_for_lli(t_flags fl, long long k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_itoa_ll(k);
	if (fl.precision != -1 && !((k >= 0 && (int)ft_strlen(str) > fl.precision) \
	|| (k < 0 && (int)ft_strlen(str) - 1 > fl.precision)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 2));
		if (k < 0)
			s[i++] = '-';
		while ((k >= 0) ? (i < fl.precision - (int)ft_strlen(str)) : (i < \
		fl.precision - (int)ft_strlen(str) + 2))
			s[i++] = '0';
		s = ((k < 0) ? ft_strcpy(&(s[i]), &str[1]) : ft_strcpy(&(s[i]), str));
		s = s - i;
		free(str);
		str = NULL;
		s[(k >= 0) ? (fl.precision) : (fl.precision + 1)] = '\0';
	}
	else
		s = str;
	return (s);
}

char	*make_str_with_precision_for_li(t_flags fl, long k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_itoa_l(k);
	if (fl.precision != -1 && !((k >= 0 && (int)ft_strlen(str) > fl.precision) \
	|| (k < 0 && (int)ft_strlen(str) - 1 > fl.precision)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 2));
		if (k < 0)
			s[i++] = '-';
		while ((k >= 0) ? (i < fl.precision - (int)ft_strlen(str)) : (i < \
		fl.precision - (int)ft_strlen(str) + 2))
			s[i++] = '0';
		s = ((k < 0) ? ft_strcpy(&(s[i]), &str[1]) : ft_strcpy(&(s[i]), str));
		s = s - i;
		free(str);
		str = NULL;
		s[(k >= 0) ? (fl.precision) : (fl.precision + 1)] = '\0';
	}
	else
		s = str;
	return (s);
}
