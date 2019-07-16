//
// Created by Verlie Bharbo on 2019-07-09.
//

#include "./includes/ft_printf.h"

int		main(void)
{
//	int i = 257;
	int a;
	int b;
//	char c;
//
//	c = (char)i;
//	i = c;
//	ft_putnbr(i);
//	ft_putendl("\n--------------");
//	a = printf("%f\n", 1.1234);
//	b = ft_printf("%f\n", 1.1234);
//	printf("\n------\na  = %d b = %d\n-----\n", a, b);
//	a = printf("%+5.50d\n",-1);
//	b = ft_printf("%+5.50d\n",-1);
//	printf("\n------\na  = %d b = %d\n-----\n", a, b);
//	printf("%0#7o ---- %0#7X", 9, 20);
//	ft_printf("\n-\n-%0#7d---------- %f ------------ %u\n-\n", 9, 123.123999999, 15);
	a = printf("% 0+-#10.5llo|\n",42);
	b = ft_printf("% 0+-#10.5llo)\n",42);
	printf("%d - %d", a , b);
	return (0);
}
