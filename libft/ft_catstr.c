/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:47:49 by kmills            #+#    #+#             */
/*   Updated: 2019/07/20 14:23:05 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_catstr(const char *s1, char *s2)
{
	char	*s;

	if (!s1)
		return (s2);
	s = ft_strdup(s2);
	s2 = ft_strcpy(s2, s1);
	s2 = ft_strcpy(s2 + ft_strlen(s1), s);
	s2[ft_strlen(s1) + ft_strlen(s2) - 2] = '\0';
	s2 -= ft_strlen(s1);
	free(s);
	s = NULL;
	return (s2);
}
