/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:26:35 by adzikovs          #+#    #+#             */
/*   Updated: 2017/01/12 15:49:57 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "libprintf.h"

uintmax_t	ft_cast(intmax_t value, int *sign)
{
	if (value < 0)
	{
		sign[0] = -1;
		return (-value);
	}
	else if (value == 0)
	{
		sign[0] = 0;
		return (value);
	}
	else
	{
		sign[0] = 1;
		return (value);
	}
}

char		*ft_define_lang(int sign, const int *flags, int mode)
{
	char	*lang;

	lang = (char*)malloc(sizeof(*lang) * 2);
	lang[0] = ' ';
	if (sign < 0)
		lang[0] = '-';
	else if (flags[3])
		lang[0] = '+';
	lang[1] = ' ';
	if (flags[1] && mode != -1 && mode != 6)
		lang[1] = '0';
	if (mode == -1 || mode == 6 || mode == -2 || mode == 7)
		lang[0] = 0;
	return (lang);
}

int			ft_count_padd(int digits, int sign, const int *flags, int mode)
{
	int		padd;

	if (mode == -1 || mode == 6)
	{
		if (flags[7] && flags[8] < digits)
			padd = flags[6] - flags[8];
		else
			padd = flags[6] - digits;
	}
	else if (mode == -2 || mode == 7)
		padd = flags[6] - digits;
	else
		padd = flags[6] - (flags[8] > digits ? flags[8] : digits);
	if (sign == 0 && flags[7] && !flags[8] &&
		(!flags[0] || (mode != 1 && mode != 3)))
		padd++;
	if (sign && flags[0])
	{
		if ((mode == 1 || mode == 3) && flags[8] < digits)
			padd--;
		if (mode == 2 || mode == 4)
			padd -= 2;
	}
	padd = flags[10] > 0 ? (flags[6] - digits) : padd;
	return (padd);
}

int			ft_field_width(int digits, int sign, const int *flags, int mode)
{
	int		padd;
	char	*lang;
	int		ret;

	ret = 0;
	lang = ft_define_lang(sign, flags, mode);
	padd = ft_count_padd(digits, sign, flags, mode);
	if ((flags[1] || flags[2]) && (sign < 0 || flags[3] || flags[4]) && mode < 3
		&& lang[0] != 0)
		ret += write(flags[FLAGS_AM], lang, 1);
	if ((sign < 0 || flags[3] || flags[4]) && mode != -1 & mode != 6)
		padd--;
	if ((flags[2] == 0 && mode < 3) || (flags[2] && mode > 2))
		while (padd-- > 0)
			ret += write(flags[FLAGS_AM], lang + 1, 1);
	if (flags[1] == 0 && flags[2] == 0 && (sign < 0 || flags[3] || flags[4]) &&
		mode < 3 && lang[0] != 0)
		ret += write(flags[FLAGS_AM], lang, 1);
	free(lang);
	return (ret);
}

int			ft_prefix(int digits, int sign, const int *flags, int mode)
{
	int		prec;
	int		ret;

	ret = 0;
	prec = flags[8] - digits;
	if (flags[7] && !sign)
		prec++;
	if (flags[0])
	{
		if (mode == 1)
		{
			prec--;
			ret += write(flags[FLAGS_AM], "0", 1);
		}
		else if (mode == 2 && sign)
		{
			if (flags[5])
				ret += write(flags[FLAGS_AM], "0X", 2);
			else
				ret += write(flags[FLAGS_AM], "0x", 2);
		}
	}
	while (prec-- > 0)
		ret += write(flags[FLAGS_AM], "0", 1);
	return (ret);
}
