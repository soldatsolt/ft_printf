# include "ft_printf.h"

char	*make_str_with_precision_for_i(t_flags fl, int k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_itoa(k);
	if (fl.precision != -1 && !((k >= 0 && ft_strlen(str) > fl.precision) \
	|| (k < 0 && ft_strlen(str) - 1 > fl.precision)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 2));
		if (k < 0)
			s[i++] = '-';
		while ((k >= 0) ? (i < fl.precision - ft_strlen(str)) : (i < \
		fl.precision - ft_strlen(str) + 2))
		{
			s[i] = '0';
			i++;
		}
		if (k < 0)
		{
			s = ft_strcpy(&(s[i]), &str[1]);
		}
		else
			s = ft_strcpy(&(s[i]), str);
		s = s - i;
		free(str);
		str = NULL;
		s[(k >= 0) ? (fl.precision) : (fl.precision + 1)] = '\0';
	}
	else
		s = str;
	return (s);
}

char	*make_str_with_precision_for_u(t_flags fl, unsigned int k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_utoa(k);
	if (fl.precision != -1 && (((int)ft_strlen(str) <= fl.precision)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 1));
		while (i < fl.precision - ft_strlen(str))
		{
			s[i] = '0';
			i++;
		}
		s = ft_strcpy(&(s[i]), str);
		s = s - i;
		free(str);
		str = NULL;
		s[fl.precision] = '\0';
	}
	else
		s = str;
	return (s);
}

char	*make_str_with_precision_for_x(t_flags fl, unsigned int k, char *(*f)(unsigned int, int))
{
	char	*s;
	int		i;
	char	*str;

	str = f(k, 16);
	if (fl.precision != -1 && (((int)ft_strlen(str) <= fl.precision)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 1));
		while (i < fl.precision - ft_strlen(str))
		{
			s[i] = '0';
			i++;
		}
		s = ft_strcpy(&(s[i]), str);
		s = s - i;
		free(str);
		str = NULL;
		s[fl.precision] = '\0';
	}
	else
		s = str;
	return (s);
}

char	*make_str_with_precision_for_o(t_flags fl, unsigned int k)
{
	char	*s;
	int		i;
	char	*str;

	str = ft_itoa_base_small(k, 8);
	if (fl.precision != -1 && (((int)ft_strlen(str) <= fl.precision)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 1));
		while (i < fl.precision - ft_strlen(str))
		{
			s[i] = '0';
			i++;
		}
		s = ft_strcpy(&(s[i]), str);
		s = s - i;
		free(str);
		str = NULL;
		s[fl.precision] = '\0';
	}
	else
		s = str;
	return (s);
}
