/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringmath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 06:34:21 by kmills            #+#    #+#             */
/*   Updated: 2019/05/22 07:01:53 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *strplus(char *str1, char *str2)
{
	char	*summ;
	int		i;

	i = 0;
	summ = (char *)malloc(sizeof(char) * 500);
	str1 = ft_strrev(str1);
	str2 = ft_strrev(str2);
	while (i < ft_strlen(str1))
	{
		summ[i] = str1[i] + str2[i] - '0';
		i++;
	}
	ft_printf("%s\n", summ);
	return (summ);
}
