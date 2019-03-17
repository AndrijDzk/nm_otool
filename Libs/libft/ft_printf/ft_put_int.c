/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 10:19:23 by adzikovs          #+#    #+#             */
/*   Updated: 2017/02/01 13:54:06 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "libprintf.h"

int		ft_put_int(va_list par, const int *flags)
{
	int			n;
	uintmax_t	n2;
	int			sign[1];
	int			digits;
	int			ret;

	if (flags[9])
		return (ft_int_recall(par, flags));
	ret = 0;
	n = va_arg(par, int);
	n2 = ft_cast(n, sign);
	digits = ft_count_digits(n2, 10);
	ret += ft_field_width(digits, sign[0], flags, 0);
	ret += ft_prefix(digits, sign[0], flags, 0);
	ret += ft_put_nbr_base(n2, 10, flags);
	ret += ft_field_width(digits, sign[0], flags, 5);
	return (ret);
}

int		ft_put_oint(va_list par, const int *flags)
{
	uintmax_t	n;
	int			digits;
	int			sign;
	int			ret;

	ret = 0;
	n = va_arg(par, uintmax_t);
	sign = 0;
	if (n)
		sign = 1;
	digits = ft_count_digits(n, 8);
	if (flags[1])
		ret += ft_prefix(digits, sign, flags, 1);
	ret += ft_field_width(digits, sign, flags, 1);
	if (!flags[1])
		ret += ft_prefix(digits, sign, flags, 1);
	ret += ft_put_nbr_base(n, 8, flags);
	ret += ft_field_width(digits, sign, flags, 3);
	return (ret);
}

int		ft_put_hint(va_list par, const int *flags)
{
	uintmax_t	n;
	int			digits;
	int			sign;
	int			ret;

	ret = 0;
	n = va_arg(par, uintmax_t);
	sign = 0;
	if (n)
		sign = 1;
	digits = ft_count_digits(n, 16);
	if (flags[1])
		ret += ft_prefix(digits, sign, flags, 2);
	ret += ft_field_width(digits, sign, flags, 2);
	if (!flags[1])
		ret += ft_prefix(digits, sign, flags, 2);
	ret += ft_put_nbr_base(n, 16, flags);
	ret += ft_field_width(digits, sign, flags, 4);
	return (ret);
}

int		ft_put_uint(va_list par, const int *flags)
{
	uintmax_t	n;
	int			digits;
	int			sign;
	int			ret;

	ret = 0;
	n = va_arg(par, uintmax_t);
	sign = 0;
	if (n)
		sign = 1;
	digits = ft_count_digits(n, 10);
	ret += ft_field_width(digits, sign, flags, 0);
	ret += ft_prefix(digits, sign, flags, 0);
	ret += ft_put_nbr_base(n, 10, flags);
	ret += ft_field_width(digits, sign, flags, 5);
	return (ret);
}

int		ft_put_int_arr(va_list par, const int *flags)
{
	int			*n;
	uintmax_t	n2;
	int			info[5];

	info[4] = 0;
	n = va_arg(par, int *);
	if (n == 0)
		return (info[4]);
	info[2] = ft_max_digits(n, flags[6]);
	info[4] += write(flags[FLAGS_AM], "\n", 1);
	info[3] = 0;
	while (info[3] < flags[6])
	{
		n2 = ft_cast(n[info[3]], info);
		info[4] += ft_int_arr_prefix(info, n2, flags);
		info[4] += ft_put_nbr_base(n2, 10, flags);
		if (n2 == 0)
			info[4] += write(flags[FLAGS_AM], "0", 1);
		info[3]++;
		if ((info[3] % flags[8]) == 0 || info[3] == flags[6])
			info[4] += write(flags[FLAGS_AM], "\n", 1);
		else if (info[3] < flags[6])
			info[4] += write(flags[FLAGS_AM], " ", 1);
	}
	return (info[4]);
}
