
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

int		ft_len_exp(double w)
{
	int len;

	if (w < 0)
		w *= -1;
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
	make_exp(dd);
//	printf("%d ---- %d\n", fl->width, dd->len);
	fl->width = (dd->len + fl->precision >= fl->width) ? 0 : fl->width - dd->len - fl->precision;
//	printf("%d ---- %d\n", fl->width, dd->len);
	dd->strlen = dd->len + fl->width + fl->precision + 1;
	dd->str = (char*)malloc(sizeof(char) * (dd->strlen + 1));
//		return (NULL);
	dd->str[dd->strlen + 1] = '\0';
	ft_double_in_str(dd, fl);
}

void	ft_put_precision(t_double *dd, t_buf **buf, t_flags *fl)
{
	while (fl->precision-- && dd->mantissa[dd->i])
		put_char_to_buf(buf, dd->mantissa[dd->i++]);
	while (fl->precision-- >= 0)
		put_char_to_buf(buf, '0');
}

void	double_zero(t_double *dd, t_buf **buf, t_flags *fl)
{
	if (dd->w < 0)
		put_char_to_buf(buf, '-');
	else if (fl->plus)
		put_char_to_buf(buf, '+');
	else if (fl->space)
		put_char_to_buf(buf, ' ');
	dd->i = -1;
	while (dd->mantissa[++dd->i] == '0');
	while (fl->width-- > 0)
		put_char_to_buf(buf, '0');
	while (dd->i < 12)
		put_char_to_buf(buf, dd->mantissa[dd->i++]);
	if ((fl->dash && !fl->precision) || fl->precision)
		put_char_to_buf(buf, '.');
	ft_put_precision(dd, buf, fl);
}

void	double_just(t_double *dd, t_buf **buf, t_flags *fl)
{
//	printf("\n----%d\n",fl->width);
	while (fl->width-- > 0)
		put_char_to_buf(buf, ' ');
	if (dd->w < 0)
		put_char_to_buf(buf, '-');
	else if (fl->plus)
		put_char_to_buf(buf, '+');
	else if (fl->space)
		put_char_to_buf(buf, ' ');
	dd->i = -1;
	while (dd->mantissa[++dd->i] == '0');
	while (dd->i < 12)
		put_char_to_buf(buf, dd->mantissa[dd->i++]);
	if ((fl->dash && !fl->precision) || fl->precision)
		put_char_to_buf(buf, '.');
	ft_put_precision(dd, buf, fl);
}

void	double_minus(t_double *dd, t_buf **buf, t_flags *fl)
{
	if (dd->w < 0)
		put_char_to_buf(buf, '-');
	else if (fl->plus)
		put_char_to_buf(buf, '+');
	else if (fl->space)
		put_char_to_buf(buf, ' ');
	dd->i = -1;
	while (dd->mantissa[++dd->i] == '0');
	while (dd->i < 12)
		put_char_to_buf(buf, dd->mantissa[dd->i++]);
	if ((fl->dash && !fl->precision) || fl->precision)
		put_char_to_buf(buf, '.');
	ft_put_precision(dd, buf, fl);
	while (fl->width--)
		put_char_to_buf(buf, ' ');
}

void 	double_flag(va_list vl, t_buf **buf, t_flags *fl)
{
	t_double	dd;

	if (fl->precision == -1)
		fl->precision = 6;
	ft_itoa_double(va_arg(vl, double), &dd, fl);
	if ((fl->dash && fl->precision == 0) || fl->precision > 0)
		fl->width--;
//	printf("\n----%d\n",fl->width);
	if (fl->plus || fl->space || dd.w < 0)
		fl->width--;
//	printf("\n----%d\n",fl->width);
//	printf("\n----%d\n",fl->width);
	printf("%d\n",fl->zero);
	if (fl->minus)
		double_minus(&dd, buf, fl);
	else if (fl->zero)
		double_zero(&dd, buf, fl);
	else
		double_just(&dd, buf, fl);
}


void	f_flag(va_list vl, t_buf **buf, t_flags fl)
{
	double_flag(vl, buf, &fl);

}
