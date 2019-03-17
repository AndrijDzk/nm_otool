/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arr_prefix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:43:28 by adzikovs          #+#    #+#             */
/*   Updated: 2017/02/01 13:53:52 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "libprintf.h"

int		ft_int_arr_prefix(int *info, uintmax_t n2, const int *flags)
{
	int		ret;

	ret = 0;
	info[1] = ft_count_digits(n2, 10);
	if (info[0] < 0)
		info[1]++;
	while (info[1]++ < info[2])
		ret += write(flags[FLAGS_AM], " ", 1);
	if (info[0] < 0)
		ret += write(flags[FLAGS_AM], "-", 1);
	return (ret);
}
