#include "ft_printf.h"

t_buf	*create_buf(void)
{
	t_buf	*buf;

	buf = (t_buf *)malloc(sizeof(t_buf));
	buf->next = NULL;
	return (buf);
}

void	put_char_to_buf(t_buf **buf, char c)
{
	t_buf	*tmp;

	tmp = *buf;
	(*buf) = create_buf();
	tmp->c = c;
	tmp->next = (*buf);
}

void	put_str_to_buf(t_buf **buf, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		put_char_to_buf(buf, str[i]);
		i++;
	}
}

void	print_buf(t_buf *buf)
{
	while (buf)
	{
		write(1, &(buf->c), 1);
		buf = buf->next;
	}
}

int		returned_printf(t_buf *buf)
{
	int	i;

	i = 0;
	while (buf->next)
	{
		i++;
		buf = buf->next;
	}
	return (i);
}

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