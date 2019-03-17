/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:27:30 by adzikovs          #+#    #+#             */
/*   Updated: 2017/01/22 14:54:59 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_scan_conv(const char *str, int *flags)
{
	char	*fl_p_types;
	int		i;

	fl_p_types = "eEfFgGaA";
	if (*str == 'X')
		flags[5] = 1;
	if (*str == 'p')
		flags[0] = 1;
	i = 0;
	while (fl_p_types[i])
		if (*str == fl_p_types[i++])
		{
			flags[10] = i;
			if (flags[11])
				flags[1] = 1;
			if (!flags[8])
				flags[8] = 6;
		}
}
