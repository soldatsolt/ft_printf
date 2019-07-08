#include "ft_printf.h"

void	make_double_bits_str(unsigned char **s, double d)
{
	int				i;
	int				ic;
	unsigned char	*c;

	*s = (unsigned char *)malloc(sizeof(unsigned char) * 65);
	c = (unsigned char *)&d;
	ft_bzero(*s, 65);
	ic = 7;
	i = 0;
	while (ic + 1)
	{
		while (i < 8)
		{
			(*s)[8 * (7 - ic) + i] = ((c[ic] & (128 >> i)) ? '1' : '0');
			i++;
		}
		ic--;
		i = 0;
	}
	(*s)[64] = '\0';
}

void	make_exp_mantissa_bits_str(unsigned char *s, unsigned char **exp, \
unsigned char **mantissa)
{
	int	i;
	int	ic;

	i = 1;
	ic = 0;
	*mantissa = (unsigned char *)malloc(sizeof(unsigned char) * 53);
	*exp = (unsigned char *)malloc(sizeof(unsigned char) * 12);
	ft_bzero(*mantissa, 53);
	ft_bzero(*exp, 12);
	while (i < 12)
		(*exp)[ic++] = s[i++];
	(*exp)[11] = '\0';
	i = 12;
	ic = 0;
	while (i < 64)
		(*mantissa)[ic++] = s[i++];
	(*mantissa)[52] = '\0';
}

void	make_d_exp(unsigned char *exp, double *d_step_exp)
{
	int	step_exp;
	int i;
	int ic;
	
	*(d_step_exp) = 1;
	i = 10;
	ic = 0;
	step_exp = 0;
	while (i + 1)
	{
		if (exp[i] == '1')
			step_exp += (1 << (10 - i));
		i--;
	}
	step_exp -= 1023;
	if (step_exp < 0)
	{
		*(d_step_exp) = (double)((double)1 / (double)((int64_t)1 << (-step_exp)));
	}
	else
	{
		i = 0;
		while (i++ < step_exp)
			*(d_step_exp) *= 2;
	}
}

void	make_rez_d(double d_step_exp, unsigned char *mantissa, double *step_man, double *n)
{
	int i;

	*step_man = 0;
	i = 51;
	while (i + 1)
	{
		if (mantissa[i] == '1')
			*step_man += (double)((double)1 / (double)((int64_t)1 << (i + 1)));
		i--;
	}

	*step_man += 1;

	*n = (d_step_exp) * (*step_man);
	printf("RES DBL = %.16lf\n", *n);
}