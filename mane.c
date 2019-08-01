//
// Created by Verlie Bharbo on 2019-08-01.
//

#include "./srcs/ft_printf.h"

int		main(void)
{
	float f = 6.0 / 0.0;
	double w;
	long double lw = -10.0 / 0.0;
	printf   ("float -    |%+100f\n", f);
	ft_printf("ft_float - |%+100f\n", f);
	printf   ("float -    |% 10Lf\n",lw);
	ft_printf("ft_float - |% 10Lf\n", lw);
	return (0);
}