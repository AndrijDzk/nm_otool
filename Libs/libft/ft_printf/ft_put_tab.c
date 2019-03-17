/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 08:00:57 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/05 12:42:17 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "libprintf.h"

int		ft_put_char(va_list par, const int *flags)
{
	char	c;
	int		ret;

	if (flags[9] == 4)
		return (ft_put_wchar(par, flags));
	ret = 1;
	c = (char)va_arg(par, int);
	ret += ft_field_width(1, 1, flags, -1);
	write(flags[FLAGS_AM], &c, 1);
	ret += ft_field_width(1, 1, flags, 6);
	return (ret);
}

int		ft_put_wchar(va_list par, const int *flags)
{
	wchar_t	c;
	int		ret;

	ret = 1;
	c = (wchar_t)va_arg(par, int);
	ret += ft_field_width(1, 1, flags, -1);
	write(flags[FLAGS_AM], &c, ft_wcharlen(&c));
	ret += ft_field_width(1, 1, flags, 6);
	return (ret);
}

int		ft_put_str(va_list par, const int *flags)
{
	int		i;
	int		ret;
	int		j;
	char	*str;
	int		len;

	if (flags[9] == 4)
		return (ft_put_wstr(par, flags));
	ret = 0;
	j = flags[8];
	str = va_arg(par, char *);
	len = ((str == 0) ? 6 : ft_strlen(str));
	ret += ft_field_width(len, 1, flags, -1);
	i = 0;
	if (str)
		while (str[i] && (!flags[7] || j-- > 0))
			ret += write(flags[FLAGS_AM], str + i++, 1);
	else
		ret += write(flags[FLAGS_AM], "(null)", 6);
	ret += ft_field_width(len, 1, flags, 6);
	return (ret);
}

int		ft_put_wstr(va_list par, const int *flags)
{
	int		i;
	int		ret;
	int		j;
	wchar_t	*str;
	int		len;

	ret = 0;
	j = flags[8];
	str = va_arg(par, wchar_t *);
	len = ((str == 0) ? 6 : ft_wstrlen(str));
	ret += ft_field_width(len, 1, flags, -1);
	if (str)
	{
		i = -1;
		while (str[++i] && (!flags[7] || j-- > 0))
			ret += write(flags[FLAGS_AM], str + i, ft_wcharlen(str + i));
	}
	else
		ret += write(flags[FLAGS_AM], "(null)", 6);
	ret += ft_field_width(len, 1, flags, 6);
	return (ret);
}

int		ft_put_tab(va_list par, const int *flags)
{
	char	**tab;
	int		ct[3];
	int		ret;

	ret = 0;
	tab = va_arg(par, char **);
	if (tab == 0)
		return (ret);
	if (flags[2])
		ret += write(flags[FLAGS_AM], "\n", 1);
	ct[0] = -1;
	while (tab[++ct[0]] && (!flags[6] || ct[0] < flags[6]))
	{
		ct[1] = -1;
		while (tab[ct[0]][++ct[1]])
		{
			ct[2] = 0;
			if (ct[1])
				while (ct[2]++ < flags[8])
					ret += write(flags[FLAGS_AM], " ", 1);
			ret += write(flags[FLAGS_AM], tab[ct[0]] + ct[1], 1);
		}
		ret += ft_putchar((char)(flags[3] == 1 ? 10 : 92), flags);
	}
	return (ret);
}
