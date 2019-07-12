//typedef struct	s_double
//{
//	int 			len;
//	int 			strlen;
//	unsigned char	*s;
//	char 			*str;
//	int 			i;
//	int 			pow;
//	char 			c;
//	int 			exp;
//	char			*mantissa;
//	double 			w;
//}				t_double;

#include <stdlib.h>
#include "ft_printf.h"

void	make_double_bits_str(t_double *dd)
{
	int				ic;
	unsigned char	*c;

	dd->s = (unsigned char *)malloc(sizeof(unsigned char) * 65);
	c = (unsigned char *)&dd->w;
	bzero((void*)dd->s, 65);
	ic = 7;
	while (ic + 1)
	{
		dd->i = 0;
		while (dd->i < 8)
		{
			dd->s[8 * (7 - ic) + dd->i] = ((c[ic] & (128 >> dd->i)) ? '1' : '0');
			dd->i++;
		}
		ic--;
	}
	dd->s[64] = '\0';
}

//int 	ft_pow(int i, int pow)
//{
//	int k;
//
//	k = i;
//	if (pow == 0)
//		return (1);
//	else if (pow == 1)
//		return (i);
//	else if (pow & 1 || pow == 2)
//		return (i * ft_pow(i, pow - 1));
//	else
//		return (ft_pow(i * i, pow / 2));
//}

void	make_exp(t_double *dd)
{
	dd->exp = 0;
	dd->i = 12;
	dd->pow = 1;
	while (--dd->i > 0)
	{
		if (dd->s[dd->i] == '1')
		{
			dd->exp += dd->pow;
		}
		dd->pow = dd->pow << 1;
	}
	dd->exp = dd->exp - 1023;
}

int		ft_len_exp(double w)
{
	int len;

	len = 1;
	while (w >= 10.0)
	{
		w = w / 10;
		len++;
	}
	return (len);
}

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
		man[0][i] = ten % 10 + '0';
	}
	//printf("%s\n", man[0]);
}

void	ft_mantissa_str(t_double *dd, char **man, char **tmp)
{
	man[0][11] = '1';
	tmp[0][12] = '5';
	while (dd->i < 65)
	{
		if (dd->s[dd->i++] == '1')
			ft_strsum(&man[0], &tmp[0]);
		printf("man -- %s     exp -- %s\n", man[0] , tmp[0]);
		ft_divstr(&tmp[0]);

	}
}

void	ft_exp_str(t_double *dd, char **man, char *tmp)
{
	free(tmp);
	if (dd->exp >= 0)
		while (dd->exp-- > 0)
		{
			tmp = NULL;
			tmp = strdup(man[0]);
			ft_strsum(&man[0],&tmp);
			printf("%s\n", man[0]);
			free(tmp);
		}
	else
		while (dd->exp++ <= 0)
		{
			ft_divstr(&man[0]);
		}
	tmp = NULL;
}

int		ft_double_in_str(t_double *dd)
{
	char	*man;
	char	*tmp;

	if (!(man = ft_strnew(300)))
		return (0);
	if (!(tmp = ft_strnew(300)))
		return (0);
	dd->i = -1;
	while (++dd->i < 12)
	{
		man[dd->i] = '0';
		tmp[dd->i] = '0';
	}
	ft_mantissa_str(dd, &man, &tmp);
	printf(" exp - %d, man - %s\n", dd->exp, man);
	ft_exp_str(dd, &man, tmp);
	dd->mantissa = man;
	printf("%s\n",man);
	return (1);
}

void 	ft_itoa_double(double n)
{
	t_double	dd;

	dd.w = n;
	make_double_bits_str(&dd);
	dd.len = ft_len_exp(dd.w);
	make_exp(&dd);
	ft_double_in_str(&dd);
}

int main()
{
	int i;
	double w;

	w = -1234.345621448;
	i = (int) w;
	ft_itoa_double(w);
	printf("%52.40f", w);
	return (0);
}