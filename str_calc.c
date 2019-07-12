//
// Created by Verlie Bharbo on 2019-07-12.
//

#include "ft_printf.h"


void	ft_divstr(char **tmp)
{
	static int	i;
	static int	ten;

	i = 0;
	while	(tmp[0][i])
		i++;
	tmp[0][i] = '0';
	while (--i >= 0)
	{
		ten = (tmp[0][i] - '0') * 10;
		tmp[0][i] = '0' + ten / 20;
		tmp[0][i + 1] += ten / 2 % 10;
	}
}

void	ft_strsum(char **man, char **tmp)
{
	static int	i;
	static int	ten;

	i = 0;
	while	(tmp[0][i])
		i++;
	while (--i >= 0)
	{
		ten = tmp[0][i] + man[0][i] - '0' - '0';
		if (ten >= 10)
			man[0][i - 1] += 1;
		man[0][i] = ten % 10 + '0';
	}
}

void	ft_mantissa_str(char **man, char **tmp)
{
	man[0][11] = '1';
	tmp[0][12] = '5';
	while (dd->i < 65)
	{
		if (dd->s[dd->i++] == '1')
			ft_strsum(&man[0], &tmp[0]);
		ft_strdiv(&tmp[0]);
	}
}

void	ft_exp_str(t_double *dd, char **man, char *tmp)
{
	while (dd->exp--)
	{
		strcpy(tmp, man[0]);
		ft_strsum(&man[0],&tmp);
	}
}

int		ft_double_in_str(t_double *dd)
{
		char	*man;
		char	*tmp;

		if (!(man = ft_srnew(300)))
			return (0);
		if (!(tmp = ft_strnew(300)))
			return (0);
		dd->i = -1;
		while (++dd->i < 12)
		{
			man[dd->i] = '0';
			tmp[dd->i] = '0';
		}
		ft_mantissa_str(( &man, &tmp));
		ft_exp_str(dd, &man, tmp);
		free(tmp);
		tmp = NULL;
		dd->mantissa = man;
		return (1);
}
