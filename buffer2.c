/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:30:31 by kmills            #+#    #+#             */
/*   Updated: 2019/08/05 18:30:31 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_all_buff(t_buf *start)
{
	t_buf	*tmp;
	t_buf	*store;

	tmp = start;
	while (tmp)
	{
		store = tmp->next;
		free(tmp);
		tmp = store;
	}
}

void	put_some_chars_to_buf(t_buf **buf, char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		put_char_to_buf(buf, c);
		i++;
	}
}
