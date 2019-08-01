//
// Created by Verlie Bharbo on 2019-07-22.
//

#include "ft_printf.h"

void	make_long_double_bits_str(t_double *dd)
{
	int				ic;
	unsigned char	*c;

	dd->s = (unsigned char *)malloc(sizeof(unsigned char) * 81);
	c = (unsigned char *)&dd->lw;
	bzero((void*)dd->s, 81);
	ic = 9;
	while (ic + 1)
	{
		dd->i = 0;
		while (dd->i < 8)
		{
			dd->s[8 * (9 - ic) + dd->i] = (char)((c[ic] & (128 >> dd->i)) ? '1' : '0');
			dd->i++;
		}
		ic--;
	}
	dd->s[80] = '\0';
}

int		ft_len_exp_long_double(t_double *dd)
{
	int len;

	if (dd->lw < 0)
	{
		dd->lw *= -1;
		dd->sign = 1;
	}
	else
		dd->sign = 0;
	len = 1;
	while (dd->lw >= 10.0)
	{
		dd->lw = dd->lw / 10;
		len++;
	}
	return (len);
}

void 	long_make_exp(t_double *dd)
{
	dd->exp = 0;
	dd->i = 16;
	dd->pow = 1;
	while (--dd->i > 0)
	{
		if (dd->s[dd->i] == '1')
			dd->exp += dd->pow;
		dd->pow = dd->pow << 1;
	}
	dd->exp = dd->exp - 16383;
}

void	ft_itoa_long_double(long double n, t_double *dd, t_flags *fl)
{

	dd->lw = n;
	make_long_double_bits_str(dd);
	dd->len = ft_len_exp_long_double(dd);
	long_make_exp(dd);
	fl->width = (dd->len + fl->precision >= fl->width) ? 0 : fl->width - dd->len - fl->precision;
	dd->strlen = dd->len + fl->width + fl->precision + 1;
	if (!(dd->str = (char*)malloc(sizeof(char) * (dd->strlen + 1))))
		exit(1);
	dd->str[dd->strlen + 1] = '\0';
	if (!ft_double_in_str(dd, fl))
		exit(1);
}

<<<<<<< HEAD
void 	long_double_flag(va_list vl, t_buf **buf, t_flags fl)
{
	t_double	dd;
	long double	lv2;

	lv2 = va_arg(vl, long double);
	if (ft_long_double_exception(lv2, buf, fl))
		return ;
=======
void	double_just_long_zero(t_buf **buf, t_flags *fl)
{
	put_str_to_buf(buf, "0.0"); // ВОТ ЗДЕСЬ ТЕБЕ ДЕЛАТЬ ФОРМАТИРОВАНИЕ
}

void 	long_double_flag(va_list vl, t_buf **buf, t_flags *fl)
{
	t_double	dd;
	long double	d;

	d = va_arg(vl, long double);
	if (d == 0.0 || (float)d == 0.0 || (long double)d == 0.0)
	{
		double_just_long_zero(buf, fl);
		return;
	}
>>>>>>> ba9f72d581e3d17d24c5a676874e7e68cb1e5947
	dd.size = 81;
	dd.dot = 17;
	if (fl.precision == -1)
		fl.precision = 6;
	ft_itoa_long_double(lv2, &dd, &fl);
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