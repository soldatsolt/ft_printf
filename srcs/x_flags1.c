/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_flags1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:31:23 by kmills            #+#    #+#             */
/*   Updated: 2019/08/05 18:32:56 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_flag1(t_buf **buf, t_flags fl, char *(*f)(unsigned int, int), \
unsigned int k)
{
	char	*str;
	char	*s;
	char	*ox;

	ox = NULL;
	str = f(k, 16);
	if (f == &ft_itoa_base_small)
		ox = make_ox_for_x(ox, &fl, (int)ft_strlen(str));
	else
		ox = make_ox_for_xx(ox, &fl, (int)ft_strlen(str));
	s = ft_catstr(ox, str);
	s_flag(s, buf, fl);
	free(str);
	free(s);
	free(ox);
}

void	x_flag1_l(t_buf **buf, t_flags fl, char *(*f)(unsigned long, int), \
unsigned long k)
{
	char	*str;
	char	*s;
	char	*ox;

	ox = NULL;
	str = f(k, 16);
	if (f == &ft_itoa_base_small_l)
		ox = make_ox_for_x(ox, &fl, (int)ft_strlen(str));
	else
		ox = make_ox_for_xx(ox, &fl, (int)ft_strlen(str));
	s = ft_catstr(ox, str);
	s_flag(s, buf, fl);
	free(str);
	free(s);
	free(ox);
}

void	x_flag1_ll(t_buf **buf, t_flags fl, char *(*f)(unsigned long \
long, int), unsigned long long k)
{
	char	*str;
	char	*s;
	char	*ox;

	ox = NULL;
	str = f(k, 16);
	if (f == &ft_itoa_base_small_ll)
		ox = make_ox_for_x(ox, &fl, (int)ft_strlen(str));
	else
		ox = make_ox_for_xx(ox, &fl, (int)ft_strlen(str));
	s = ft_catstr(ox, str);
	s_flag(s, buf, fl);
	free(str);
	free(s);
	free(ox);
}

void	x_flag1_h(t_buf **buf, t_flags fl, char *(*f)(unsigned short, int), \
unsigned short k)
{
	char	*str;
	char	*s;
	char	*ox;

	ox = NULL;
	str = f(k, 16);
	if (f == &ft_itoa_base_small_h)
		ox = make_ox_for_x(ox, &fl, (int)ft_strlen(str));
	else
		ox = make_ox_for_xx(ox, &fl, (int)ft_strlen(str));
	s = ft_catstr(ox, str);
	s_flag(s, buf, fl);
	free(str);
	free(s);
	free(ox);
}

void	x_flag1_hh(t_buf **buf, t_flags fl, char *(*f)(u_int8_t, int), \
u_int8_t k)
{
	char	*str;
	char	*s;
	char	*ox;

	ox = NULL;
	str = f(k, 16);
	if (f == &ft_itoa_base_small_hh)
		ox = make_ox_for_x(ox, &fl, (int)ft_strlen(str));
	else
		ox = make_ox_for_xx(ox, &fl, (int)ft_strlen(str));
	s = ft_catstr(ox, str);
	s_flag(s, buf, fl);
	free(str);
	free(s);
	free(ox);
}
