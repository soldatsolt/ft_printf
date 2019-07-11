
//typedef union	s_u_double
//{
//	double			n;
//	unsigned long	l;
//}				t_u_doble;

#include "ft_printf.h"

typedef struct	s_double
{
	int 			len;
	unsigned char	*s;
	double			d;
	int 			i;
	int 			pow;
}				t_double;

void	make_double_bits_str(t_double *dd)
{
	int				ic;
	unsigned char	*c;

	dd->s = (unsigned char *)malloc(sizeof(unsigned char) * 65);
	c = (unsigned char *)&dd->d;
	bzero((void*)dd->s, 65);
	ic = 7;
	while (ic + 1)
	{
		dd->i = 0;
		while (i < 8)
		{
			dd->s[8 * (7 - ic) + dd->i] = ((c[ic] & (128 >> dd->i)) ? '1' : '0');
			dd->i++;
		}
		ic--;
	}
	dd->s[64] = '\0';
}

int 	ft_pow(int i, int pow)
{
	int k;

	k = i;
	if (pow == 0)
		return (1);
	else if (pow == 1)
		return (i);
	else if (pow & 1 || pow == 2)
		return (i * ft_pow(i, pow - 1));
	else
		return (ft_pow(i * i, pow / 2));
}

int 	make_exp(t_double *dd)
{
	int	exp;

	exp = 0;
	dd->i = 12;
	dd->pow = 1;
	while (--i > 0)
	{
		if (dd->s[dd->i] == '1')
			exp += dd->pow;
		dd->pow = dd->pow << 1;
	}
	return(exp - 1023);
}
double	make_mantissa(t_double *dd)
{
	double	mantissa;
	double	pow;

	dd.i = 11;
	mantissa = 1.0;
	pow = 1.0;
	while (dd->s[++i])
	{
		pow = pow / 2;
		if (dd->s[i] == '1')
			mantissa += pow;
	}
	return (mantissa);
}

int		ft_len_exp(double w)
{
	int	len;

	len = 1
	while (w >= 10.0)
	{
		w = w / 10;
		len++;
	}
	return (len;)
}

void 	*ft_itoa_double(double w, t_double *dd, t_flags *fl)
{
	dd->d = n;
	make_double_bits_str(dd);
	dd->d = ft_pow(2, make_exp(dd)) * make_mantissa(dd);
	dd->len = ft_len_exp(dd->d);
}

void 	double_flag(va_list vl, t_buf **buf, t_flags fl)
{
	t_double	dd;

	s = ft_itoa_double(va_arg(vl, double), &dd, &fl);
}


void	f_flag(va_list vl, t_buf **buf, t_flags fl)
{

	if (fl.l == 1)
		double_flag(vl, buf, fl);
//	if (fl.L == 1)
//		long_double_flag(vl, buf, fl);
//	ft_itoa_float();
}