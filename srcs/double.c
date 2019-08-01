//
// Created by Verlie Bharbo on 2019-07-24.
//

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
			dd->s[8 * (7 - ic) + dd->i] = (char)((c[ic] & (128 >> dd->i)) ? '1' : '0');
			dd->i++;
		}
		ic--;
	}
	dd->s[64] = '\0';
}

void 	make_exp(t_double *dd)
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

int		ft_len_exp_double(t_double *dd)
{
	int len;

	if (dd->w < 0)
		dd->w *= -1;
	len = 1;
	while (dd->w >= 10.0)
	{
		dd->w = dd->w / 10;
		len++;
	}
	return (len);
}

int		ft_itoa_double(double n, t_double *dd, t_flags *fl)
{
	dd->w = n;
	make_double_bits_str(dd);
	dd->sign = (unsigned char) ((dd->s[0] == '1') ? 1 : 0);
	dd->len = ft_len_exp_double(dd);
	make_exp(dd);
	fl->width = (dd->len + fl->precision >= fl->width) ? 0 : fl->width - dd->len - fl->precision;
	dd->strlen = dd->len + fl->width + fl->precision + 1;
	if (!(dd->str = (char*)malloc(sizeof(char) * (dd->strlen + 1))))
		exit(1);
	dd->str[dd->strlen + 1] = '\0';
	if (!ft_double_in_str(dd, fl))
		exit(1);
	return (0);
}

void	double_just_zero(t_buf **buf, t_flags fl)
{
	put_str_to_buf(buf, "0.0"); // ВОТ ЗДЕСЬ ТЕБЕ ДЕЛАТЬ ФОРМАТИРОВАНИЕ
}

void 	double_flag(va_list vl, t_buf **buf, t_flags fl)
{
	t_double	dd;
<<<<<<< HEAD
	double		v2;

	v2 = va_arg(vl, double);
	if (ft_double_exception(v2, buf, fl))
		return ;
=======
	double		d;

	d = va_arg(vl, double);
	if (d == 0.0 || (float)d == 0.0 || (long double)d == 0.0)
	{
		double_just_zero(buf, fl);
		return;
	}
>>>>>>> ba9f72d581e3d17d24c5a676874e7e68cb1e5947
	dd.size = 65;
	dd.dot = 12;
	if (fl.precision == -1)
		fl.precision = 6;
<<<<<<< HEAD
	ft_itoa_double(v2, &dd, &fl);
=======
	
	if (ft_itoa_double(d, &dd, &fl))
	{
		ft_none(buf, fl);
		return ;
	}
>>>>>>> ba9f72d581e3d17d24c5a676874e7e68cb1e5947
	if ((fl.dash && fl.precision == 0) || fl.precision > 0)
		fl.width--;
	if (fl.plus || fl.space || dd.w < 0)
		fl.width--;
	if (fl.minus)
		double_minus(&dd, buf, &fl);
	else if (fl.zero)
		double_zero(&dd, buf, &fl);
	else
		double_just(&dd, buf, &fl);
}