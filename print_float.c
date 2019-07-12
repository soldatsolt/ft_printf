
//typedef union	s_u_double
//{
//	double			n;
//	unsigned long	l;
//}				t_u_doble;

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

int 	make_exp(t_double *dd)
{
	dd->exp = 0;
	dd->i = 12;
	dd->pow = 1;
	while (--dd->i > 0)
	{
		if (dd->s[dd->i] == '1')
			dd->exp += dd->pow;
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


void	ft_itoa_double(double n, t_double *dd, t_flags *fl)
{
	dd->w = n;
	make_double_bits_str(dd);
	dd->len = ft_len_exp(dd->w);
	dd->exp = make_exp(dd);
	fl->width = (dd->len + fl->precision >= fl->width) ? 0 : fl->width - dd->len - fl->precision;
	if (!fl->precision && fl->dash)
		fl->width--;
	dd->strlen = dd->len + fl->width + fl->precision + 1;
	if (dd->str = (char*)malloc(sizeof(char) * (dd->strlen + 1)))
		return (NULL);
	dd->str[dd->strlen + 1] = '\0';
	ft_double_in_str(dd, fl);
}

void 	double_flag(va_list vl, t_buf **buf, t_flags *fl)
{
	t_double	dd;
	if (fl->precision == -1)
		fl->precision = 6;
	ft_itoa_double(va_arg(vl, double), &dd, fl);
}


void	f_flag(va_list vl, t_buf **buf, t_flags *fl)
{

	if (fl->l == 1)
		double_flag(vl, buf, &fl);
//	if (fl.L == 1)
//		long_double_flag(vl, buf, fl);
//	ft_itoa_float();
}