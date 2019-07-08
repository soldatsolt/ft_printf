#include "ft_printf.h"

t_buf	*create_buf(void)
{
	t_buf	*buf;

	buf = (t_buf *)malloc(sizeof(t_buf));
	buf->next = NULL;
	return (buf);
}

t_buf	*put_char_to_buf(t_buf *buf, char c)
{
	t_buf	*buf1;

	buf1 = create_buf();
	buf->c = c;
	buf->next = buf1;
	return (buf1);
}

t_buf	*put_str_to_buf(t_buf *buf, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		buf = put_char_to_buf(buf, str[i]);
		i++;
	}
	return (buf);
}

void	printf_buf(t_buf *buf)
{
	while(buf->next)
	{
		write(1, &(buf->c), 1);
		buf = buf->next;
	}
}