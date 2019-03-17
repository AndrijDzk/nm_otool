/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float_nbr_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:38:32 by adzikovs          #+#    #+#             */
/*   Updated: 2017/01/12 15:12:10 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "libprintf.h"

uintmax_t	ft_min_count(uintmax_t n, int base, const int *flags)
{
	uintmax_t	res;

	res = 1;
	if (flags[10] == 3 || flags[10] == 4)
		return (res);
	while ((n % (res * base)) == 0)
		res *= base;
	return (res);
}

int			ft_put_fnbr_base(uintmax_t n, int base, const int *flags, int digit)
{
	uintmax_t	count;
	uintmax_t	min_count;
	char		*bs;
	int			ret;

	if (flags[7] && n == 0)
		return (0);
	ret = 0;
	if (flags[5])
		bs = "0123456789ABCDEF";
	else
		bs = "0123456789abcdef";
	min_count = ft_min_count(n, base, flags);
	count = ft_initial_check(n, base);
	while (count >= min_count)
	{
		ret += write(flags[FLAGS_AM], bs + (n / count), 1);
		n -= (n / count) * count;
		count /= base;
		if (--digit == 0)
			ret += write(flags[FLAGS_AM], ".", 1);
	}
	return (ret);
}
