/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 10:19:04 by adzikovs          #+#    #+#             */
/*   Updated: 2017/02/09 12:09:51 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "libprintf.h"

int			ft_count_digits(uintmax_t value, int base)
{
	int			digits;
	uintmax_t	count;

	if (base < 2)
		return (1);
	digits = 1;
	count = 1;
	while (((value / base) % (count)) != (value / base))
	{
		count *= base;
		digits++;
	}
	return (digits);
}

int			ft_max_digits(int *arr, int size)
{
	int			res;
	int			i;
	int			sign[1];
	int			digits;
	uintmax_t	n;

	res = 0;
	i = 0;
	while (i < size)
	{
		n = ft_cast(arr[i], sign);
		digits = ft_count_digits(n, 10);
		if (sign[0] < 0)
			digits++;
		if (digits > res)
			res = digits;
		i++;
	}
	return (res);
}

uintmax_t	ft_initial_check(uintmax_t value, int base)
{
	uintmax_t	count;
	int			digits;

	digits = ft_count_digits(value, base);
	count = 1;
	while (digits-- > 1)
		count *= base;
	return (count);
}

int			ft_put_nbr_base(uintmax_t n, int base, const int *flags)
{
	uintmax_t	count;
	char		*bs;
	int			ret;

	if ((flags[7] || (flags[0] && base == 8)) && n == 0)
		return (0);
	ret = 0;
	if (flags[5])
		bs = "0123456789ABCDEF";
	else
		bs = "0123456789abcdef";
	count = ft_initial_check(n, base);
	while (count != 0)
	{
		ret += write(flags[FLAGS_AM], bs + (n / count), 1);
		n -= (n / count) * count;
		count /= base;
	}
	return (ret);
}
