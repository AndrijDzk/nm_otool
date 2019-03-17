/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 14:54:18 by adzikovs          #+#    #+#             */
/*   Updated: 2018/07/12 11:35:14 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "libprintf.h"

static int		ft_str_find_in_begin(char const *s1, char const *s2)
{
	size_t		i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int				ft_scan_prec(const char *str, int j, int *flags)
{
	if (str[j] == '.')
	{
		j++;
		flags[FLAG_PREC] = 1;
		if (flags[1])
			flags[11] = 1;
		flags[1] = 0;
		flags[FLAG_PREC_VAL] = ft_atoi(str + j);
		while (str[j] >= '0' && str[j] <= '9')
			j++;
	}
	return (j);
}

int				ft_scan_len(const char *str, int j)
{
	char	*len[7];
	int		i;

	len[0] = "hh";
	len[1] = "h";
	len[2] = "ll";
	len[3] = "l";
	len[4] = "j";
	len[5] = "z";
	len[6] = 0;
	i = 0;
	while (len[i])
		if (ft_str_find_in_begin(str + j, len[i++]))
			return (i);
	return (0);
}
