//
// Created by Verlie Bharbo on 2019-08-01.
//
#include <float.h>
#include "./srcs/ft_printf.h"

int		main(void)
{
//	float f = 6.0 / 0.0;
//	double w;
//	long double lw = -10.0 / 0.0;
	printf("%f\n", FLT_MANT_DIG);
	ft_printf("%f\n", FLT_MANT_DIG);
    printf("%f\n", FLT_DIG );
    ft_printf("%f\n", FLT_DIG );
    printf("%f\n", FLT_MAX_10_EXP );
    ft_printf("%f\n", FLT_MIN_10_EXP );
    printf("%f\n", FLT_MAX );
    ft_printf("%f\n", FLT_MAX );
    printf("%f\n", FLT_MIN);
    ft_printf("%f\n", FLT_MIN);
    printf("%f\n",FLT_EPSILON );
    ft_printf("%f\n", FLT_EPSILON);
//	printf   ("float -    |%+100f| %i % i %+i\n", f, -2, 1, 1);
//	ft_printf("ft_float - |%+100f| %i % i %+i\n", f, -2, 1, 1);
//	printf   ("float -    |% 10Lf\n",lw);
//	ft_printf("ft_float - |% 10Lf\n", lw);
//	printf("%s\n");
//	ft_printf("%s\n");
    return (0);
}