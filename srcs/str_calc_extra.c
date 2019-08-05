/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_calc_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:31:10 by kmills            #+#    #+#             */
/*   Updated: 2019/08/05 18:31:10 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_step_mantissa(char **man, t_double *dd)
{
	int	i;

	i = (int)ft_strlen(man[0]) + 1;
	while (--i >= 0)
		man[0][i] = man[0][i - 1];
	man[0][0] = '0';
	dd->dot++;
}

void	ft_divstr(char **tmp)
{
	static int	i;
	static int	ten;

	i = 0;
	while (tmp[0][i])
		i++;
	tmp[0][i] = '0';
	while (--i >= 0)
	{
		ten = (tmp[0][i] - '0') * 10;
		tmp[0][i] = (char)('0' + ten / 20);
		tmp[0][i + 1] += ten / 2 % 10;
	}
}

void	ft_strsum(char **man, char **tmp)
{
	static int	i;
	static int	ten;

	i = -1;
	while (tmp[0][++i])
		if (man[0][i] == '\0')
			man[0][i] = '0';
	while (--i >= 0)
	{
		if (man[0][i] == '9' + 1)
		{
			man[0][i] = '0';
			man[0][i - 1]++;
		}
		ten = tmp[0][i] + man[0][i] - '0' - '0';
		if (ten >= 10)
			man[0][i - 1] += 1;
		man[0][i] = (char)(ten % 10 + '0');
	}
}
