/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:31:13 by kmills            #+#    #+#             */
/*   Updated: 2019/08/05 20:04:58 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_mantissa_str(char **man, char **tmp, t_double *dd)
{
	man[0][dd->dot - 1] = '1';
	tmp[0][dd->dot] = '5';
	while (dd->i < dd->size)
	{
		if (dd->s[dd->i++] == '1')
			ft_strsum(&man[0], &tmp[0]);
		ft_divstr(&tmp[0]);
	}
}

void		ft_exp_str(t_double *dd, char **man, char *tmp)
{
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	if (dd->exp > 0)
		while (dd->exp-- > 0)
		{
			tmp = ft_strdup(man[0]);
			ft_strsum(&man[0], &tmp);
			if (man[0][0] != '0')
				ft_step_mantissa(&man[0], dd);
			free(tmp);
			tmp = NULL;
		}
	else
		while (dd->exp++ < 0)
		{
			ft_divstr(&man[0]);
		}
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
}

static int	ft_only_zero_mantissa(const char *man)
{
	int i;

	i = 0;
	if (man[0] > '5')
		return (1);
	else if (man[0] == '5')
	{
		while (man[++i] == '0')
			;
		if (man[i] == '\0')
			return (0);
		else
			return (1);
	}
	return (0);
}

void		ft_mantissa_correct(char **man, t_flags *fl, t_double *dd)
{
	int i;

	if (man[0][0] != '0')
		ft_step_mantissa(&man[0], dd);
	i = (fl->precision > 0) ? dd->dot + fl->precision - 1 : dd->dot - 1;
	if (ft_only_zero_mantissa(&man[0][i + 1]))
		man[0][i]++;
	while (i > 0)
	{
		if (man[0][i] > '9')
		{
			man[0][i] = '0';
			man[0][i - 1]++;
		}
		i--;
	}
}

int			ft_double_in_str(t_double *dd, t_flags *fl)
{
	char	*man;
	char	*tmp;

	if (!(man = ft_strnew(20000)))
		return (0);
	if (!(tmp = ft_strnew(20000)))
		return (0);
	dd->i = -1;
	while (++dd->i < dd->dot)
	{
		man[dd->i] = '0';
		tmp[dd->i] = '0';
	}
	ft_mantissa_str(&man, &tmp, dd);
	ft_exp_str(dd, &man, tmp);
	ft_mantissa_correct(&man, fl, dd);
	dd->mantissa = man;
	return (1);
}
