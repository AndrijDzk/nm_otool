/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:23:24 by adzikovs          #+#    #+#             */
/*   Updated: 2017/01/12 15:56:54 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int			ft_count_offset(double val, const int *flags, int sign)
{
	if (flags[10] == 3 || flags[10] == 4)
		return (flags[8] + 1);
	else
		return (flags[8] - ft_count_digits(val * sign, 10) + 1);
}

uintmax_t	ft_cast_float(double val, const int *flags, int *sign)
{
	uintmax_t	res;
	int			offset;

	*sign = 1;
	if (val < 0)
		*sign = -1;
	else if (val == 0)
		*sign = 0;
	offset = ft_count_offset(val, flags, *sign);
	res = *sign * val * ft_power(10, offset);
	if ((res % 10) >= 5)
		return ((res / 10) + 1);
	else
		return (res / 10);
}

int			ft_float_count_digits(uintmax_t n, const int *flags)
{
	if (flags[10] == 3 || flags[10] == 4)
		return (ft_count_digits(n, 10));
	else
		return (ft_count_digits(n / ft_min_count(n, 10, flags), 10));
}

int			ft_put_float(va_list par, const int *flags)
{
	double		n;
	uintmax_t	n2;
	int			sign[1];
	int			ret;
	int			digits;

	ret = 0;
	n = va_arg(par, double);
	n2 = ft_cast_float(n, flags, sign);
	digits = ft_float_count_digits(n2, flags);
	ret += ft_field_width(digits + 1, sign[0], flags, 0);
	ret += ft_put_fnbr_base(n2, 10, flags, ft_count_digits(n * sign[0], 10));
	ret += ft_field_width(digits + 1, sign[0], flags, 5);
	return (ret);
}
