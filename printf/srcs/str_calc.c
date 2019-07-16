//
// Created by Verlie Bharbo on 2019-07-12.
//

#include "ft_printf.h"

static void	ft_mantissa_str(char **man, char **tmp, t_double *dd)
{
	man[0][12] = '1';
	tmp[0][13] = '5';
	--dd->i;
	while (dd->i < 65)
	{
		if (dd->s[dd->i++] == '1')
			ft_strsum(&man[0], &tmp[0]);
		ft_divstr(&tmp[0]);
	}
}

static void	ft_exp_str(t_double *dd, char **man, char *tmp)
{
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	if (dd->exp >= 0)
		while (dd->exp-- > 0)
		{
			tmp = strdup(man[0]);
			ft_strsum(&man[0],&tmp);
			free(tmp);
			tmp = NULL;
		}
	else
		while (dd->exp++ <= 0)
		{
			ft_divstr(&man[0]);
		}
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
}

static void	ft_mantissa_correct(char **man, t_pf *pf)
{
	int i;
	printf("%c", man[0][13]);
	i = (pf->accuracy > 0) ? 13 + pf->accuracy : 13;
	if (man[0][i] >= '5')
		man[0][i - 1]++;
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

int		ft_double_in_str(t_double *dd, t_pf *pf)
{
	char	*man;
	char	*tmp;

	if (!(man = ft_strnew(300)))
		return (0);
	if (!(tmp = ft_strnew(300)))
		return (0);
	dd->i = -1;
	while (++dd->i < 13)
	{
		man[dd->i] = '0';
		tmp[dd->i] = '0';
	}
	ft_mantissa_str( &man, &tmp, dd);
	ft_exp_str(dd, &man, tmp);
	ft_mantissa_correct(&man, pf);
	dd->mantissa = man;
	return (1);
}
