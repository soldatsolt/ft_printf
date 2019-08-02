//
// Created by Verlie Bharbo on 2019-08-01.
//

#include "./srcs/ft_printf.h"

int		main(void)
{
	float f = 6.0 / 0.0;
	double w;
	long double lw = -10.0 / 0.0;
	printf("%s\n");
	ft_printf("%s\n");
	printf   ("float -    |%+100f| %i % i %+i\n", f, -2, 1, 1);
	ft_printf("ft_float - |%+100f| %i % i %+i\n", f, -2, 1, 1);
	printf   ("float -    |% 10Lf\n",lw);
	ft_printf("ft_float - |% 10Lf\n", lw);
	printf("%s\n");
	ft_printf("%s\n");
	return (0);
}