/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbharbo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:57:42 by vbharbo           #+#    #+#             */
/*   Updated: 2019/07/02 12:57:44 by vbharbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define MAX_PRINT 8

t_print	g_print[] =
{
	{"d", &ft_print_int},
	{"i", &ft_print_int},
	{"s", &ft_print_str},
	{"c", &ft_print_char},
	{"u", &ft_print_unsigned},
	{"f", &ft_print_double},
	{"o", &ft_print_octo},
	{"x", &ft_print_x}
};

void	ft_initialization(t_pf *pf)
{
	pf->zero = 0;
	pf->hesh = 0;
	pf->space = 0;
	pf->minus = 0;
	pf->plus = 0;
	pf->dot = 0;
	pf->len = 0;
	pf->accuracy = -1;
	pf->l = 0;
	pf->ll = 0;
	pf->h = 0;
	pf->hh = 0;
	pf->u = 0;
}

static void	ft_modify(char const *str, t_pf *pf)
{
	if (*str == 'l')
	{
		if (*(str + 1) == 'l')
			pf->ll = 1;
		else
			pf->l = 1;
	}
	if (*str == 'h')
	{
		if (*(str + 1) == 'h')
			pf->hh = 1;
		else
			pf->h = 1;
	}
}

static int	ft_flag(char const *str, t_pf *pf)
{
	ft_modify(str, pf);
	if (*str == '0' && !pf->len && pf->dot == 0)
		pf->zero = 1;
	if (*str == '-')
		pf->minus = 1;
	if (*str == '#')
		pf->hesh = 1;
	if (*str == ' ')
	{
		if (pf->space == 0)
			pf->space = 1;
		else
			return (0);
	}
	if (*str == '+')
		pf->plus = 1;
	if (*str > '0' && *str <= '9' && pf->len == 0 && !pf->dot)
		pf->len = ft_atoi(str);
	if (*str == '.')
	{
		pf->accuracy = ft_atoi(&str[1]);
		pf->dot = 1;
	}
	return (1);
}

int		ft_parcing(char *str, int i, t_pf *pf)
{
	int j;

	if (str[i + 1] == '%')
		return (i);
	ft_initialization(pf);
	while(str[i])
	{
		if (!ft_flag(&str[i], &(*pf)))
			return (i);
		j = -1;
		while(++j < MAX_PRINT)
		{

			if (str[i] == g_print[j].spc[0])
			{
//				printf("\nzero - %d --- hash - %d --- space - %d --- minus - %d --- plus - %d ---- len - %d ---- acur - %d",pf->zero,
//					   pf->hesh, pf->space, pf->minus, pf->plus, pf->len, pf->accuracy);
				return (i);
			}
		}
		i++;
	}
	return (i);
}

int		ft_printf(const char *str, ...)
{
	t_pf	pf;
	int		i;
	int		j;

	va_start(pf.ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i = ft_parcing((char*)str, i, &pf);
			j = -1;
			if (str[i] == '%')
				ft_put_buff(str[i++], 0);
			else
				while (++j < MAX_PRINT)
					if (str[i] == g_print[j].spc[0])
						g_print[j].f(&pf);
		}
		else
			ft_put_buff(str[i], 0);
		i++;
	}
	va_end(pf.ap);
	return (ft_put_buff('\0', 1));
}