/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_recall_funcs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:14:14 by adzikovs          #+#    #+#             */
/*   Updated: 2017/01/11 13:49:21 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_put_ascii(va_list par, const int *flags)
{
	int			n;
	uintmax_t	n2;
	int			sign[1];
	int			digits;
	int			ret;

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

int		ft_put_short(va_list par, const int *flags)
{
	int			n;
	uintmax_t	n2;
	int			sign[1];
	int			digits;
	int			ret;

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

int		ft_put_long(va_list par, const int *flags)
{
	long		n;
	uintmax_t	n2;
	int			sign[1];
	int			digits;
	int			ret;

	ret = 0;
	n = va_arg(par, long);
	n2 = ft_cast(n, sign);
	digits = ft_count_digits(n2, 10);
	ret += ft_field_width(digits, sign[0], flags, 0);
	ret += ft_prefix(digits, sign[0], flags, 0);
	ret += ft_put_nbr_base(n2, 10, flags);
	ret += ft_field_width(digits, sign[0], flags, 5);
	return (ret);
}

int		ft_put_long_long(va_list par, const int *flags)
{
	long long	n;
	uintmax_t	n2;
	int			sign[1];
	int			digits;
	int			ret;

	ret = 0;
	n = va_arg(par, long long);
	n2 = ft_cast(n, sign);
	digits = ft_count_digits(n2, 10);
	ret += ft_field_width(digits, sign[0], flags, 0);
	ret += ft_prefix(digits, sign[0], flags, 0);
	ret += ft_put_nbr_base(n2, 10, flags);
	ret += ft_field_width(digits, sign[0], flags, 5);
	return (ret);
}

int		ft_put_intmax_t(va_list par, const int *flags)
{
	intmax_t	n;
	uintmax_t	n2;
	int			sign[1];
	int			digits;
	int			ret;

	ret = 0;
	n = va_arg(par, intmax_t);
	n2 = ft_cast(n, sign);
	digits = ft_count_digits(n2, 10);
	ret += ft_field_width(digits, sign[0], flags, 0);
	ret += ft_prefix(digits, sign[0], flags, 0);
	ret += ft_put_nbr_base(n2, 10, flags);
	ret += ft_field_width(digits, sign[0], flags, 5);
	return (ret);
}
