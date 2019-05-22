/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 20:19:28 by kmills            #+#    #+#             */
/*   Updated: 2019/05/22 06:53:07 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		i;
	int		s;
	char	t;

	i = 0;
	s = 0;
	while (str[i] != '\0')
		i++;
	while (s < i / 2)
	{
		t = str[s];
		str[s] = str[i - s - 1];
		str[i - s - 1] = t;
		s++;
	}
	return (str);
}