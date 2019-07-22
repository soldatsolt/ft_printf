//
// Created by Verlie Bharbo on 2019-07-12.
//

#include "ft_printf.h"


void	ft_step_mantissa(char **man, t_double *dd)
{
	int	i;

	i = (int)ft_strlen(man[0]) + 1;
	while(--i >= 0)
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
	while	(tmp[0][++i])
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

void	ft_mantissa_str(char **man, char **tmp, t_double *dd)
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

void	ft_exp_str(t_double *dd, char **man, char *tmp)
{
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	if (dd->exp > 0)
		while (dd->exp-- > 0)
		{
			tmp = strdup(man[0]);
			ft_strsum(&man[0],&tmp);
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

static int ft_only_zero_mantissa(const char *man)
{
	int i;

	i = 0;
	if (man[0] > '5')
		return (1);
	else if (man[0] == '5')
	{
		while (man[++i] == '0');
		if (man[i] == '\0')
			return (0);
		else
			return (1);
	}
	return (0);
}

void	ft_mantissa_correct(char **man, t_flags *fl, t_double *dd)
{
	int i;

	if (man[0][0] != '0')
		ft_step_mantissa(&man[0], dd);
	i = (fl->precision > 0) ? dd->dot + fl->precision - 1: dd->dot;
	if (ft_only_zero_mantissa(&man[0][i + 1]))
		man[0][i]++;
	while (i)
	{
		if (man[0][i] > '9')
		{
			man[0][i] = '0';
			man[0][i - 1]++;
		}
		i--;
	}
}

int		ft_double_in_str(t_double *dd, t_flags *fl)
{
	char	*man;
	char	*tmp;

	if (!(man = ft_strnew(1000)))
		return (0);
	if (!(tmp = ft_strnew(1000)))
		return (0);
	dd->i = -1;
	while (++dd->i < dd->dot)
	{
		man[dd->i] = '0';
		tmp[dd->i] = '0';
	}
	ft_mantissa_str( &man, &tmp, dd);
	ft_exp_str(dd, &man, tmp);
	ft_mantissa_correct(&man, fl, dd);
	dd->mantissa = man;
	return (1);
}
