typedef struct	s_double
{
	unsigned char	*s;
	double			d;
}				t_double;

void	make_double_bits_str(t_double *dd)
{
	int				i;
	int				ic;
	unsigned char	*c;

	dd->s = (unsigned char *)malloc(sizeof(unsigned char) * 65);
	c = (unsigned char *)&dd->d;
	bzero((void*)dd->s, 65);
	ic = 7;
	while (ic + 1)
	{
		i = 0;
		while (i < 8)
		{
			dd->s[8 * (7 - ic) + i] = ((c[ic] & (128 >> i)) ? '1' : '0');
			i++;
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
	int i;
	int pow;
	int	exp;

	exp = 0;
	i = 12;
	pow = 1;
	while (--i > 0)
	{
		if (dd->s[i] == '1')
			exp += pow;
		pow = pow << 1;
	}
	return(exp - 1023);
}
double	make_mantissa(t_double *dd)
{
	double	mantissa;
	double	pow;
	int 	i;

	i = 11;
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

void 	*ft_itoa_double(double n)
{
	t_double	dd;

	dd.d = n;
	make_double_bits_str(&dd);
	dd.d = ft_pow(2, make_exp(&dd)) * make_mantissa(&dd);
	printf("%0.100lf", dd.d);
}

int main()
{
	ft_itoa_double(1.0000000000000000000000000000000000000000000000000000000000000000000000000000002);
	printf("\n%0.100lf", 1.0000000000000000000000000000000000000000000000000000000000000000000000000000002);
	return(0);
}