/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 07:26:28 by kmills            #+#    #+#             */
/*   Updated: 2019/08/01 06:06:13 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf2(va_list vl, t_buf **buf, const char *restrict format)
{
	while (*format)
	{
		if (*format == '%' && format[1] == '%')
		{
			put_char_to_buf(buf, '%');
			format += 2;
		}
		else if (*format == '%' && format[1] != '%')
		{
			format++;
			turbo_parser(vl, buf, &format);
		}
		else
		{
			put_char_to_buf(buf, *format);
			format++;
		}
	}
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	vl;
	t_buf	*buf;
	t_buf	*buf_start;
	int		n;

	buf = create_buf();
	buf_start = buf;
	va_start(vl, format);
	ft_printf2(vl, &buf, format);
	print_buf(buf_start);
	va_end(vl);
	n = returned_printf(buf_start);
	free_all_buff(buf_start);
	return (n);
}

<<<<<<< HEAD
//int		main(void)
//{
//	float f = 6.0 / 0.0;
//	double w;
//	long double lw = -10.0 / 0.0;
//	printf   ("float -    |%+100f\n", f);
//	ft_printf("ft_float - |%+100f\n", f);
//	printf   ("float -    |% 10Lf\n",lw);
//	ft_printf("ft_float - |% 10Lf\n", lw);
//	return (0);
//}
=======
int		main(void)
{
	ft_printf("%#020x\n", 24);
	printf("%#020x\n", 24);
	return (0);
}
>>>>>>> ba9f72d581e3d17d24c5a676874e7e68cb1e5947