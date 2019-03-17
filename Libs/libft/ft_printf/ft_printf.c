/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:14:51 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/10 12:57:06 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "libprintf.h"

static t_fl_fp	*ft_flag_funcs_arr_init(void)
{
	t_fl_fp	*res;

	res = (t_fl_fp*)malloc(sizeof(*res) * 5);
	res[0] = &ft_flag_hash;
	res[1] = &ft_flag_zero;
	res[2] = &ft_flag_minus;
	res[3] = &ft_flag_plus;
	res[4] = &ft_flag_space;
	return (res);
}

static size_t	ft_scan_field_width(const char *c, size_t j, int *f, va_list p)
{
	if (c[j] == '*')
	{
		f[FLAG_FIELD_WIDTH] = va_arg(p, int);
		return (j + 1);
	}
	else
	{
		f[FLAG_FIELD_WIDTH] = ft_atoi(c + j);
		while (c[j] >= '0' && c[j] <= '9')
			j++;
		return (j);
	}
}

static size_t	ft_scan_flags(const char *c, int *fgs, va_list par)
{
	char	*flags;
	t_fl_fp	*flags_funcs;
	int		i;
	size_t	j;

	ft_bzero(fgs, sizeof(int) * FLAGS_AM);
	flags = "#0-+ ";
	flags_funcs = ft_flag_funcs_arr_init();
	j = 1;
	i = 0;
	while (flags[i])
		if (c[j] == flags[i])
		{
			flags_funcs[i](fgs);
			j++;
			i = 0;
		}
		else
			i++;
	j = ft_scan_field_width(c, j, fgs, par);
	free(flags_funcs);
	return (j);
}

static int		ft_scan(const char *str, size_t *ct, int *flags, va_list par)
{
	char	*conv;
	int		i;
	size_t	j;

	conv = "cCsSpdDioOuUxXItmfFgG";
	j = ft_scan_flags(str, flags, par);
	j = ft_scan_prec(str, j, flags);
	if ((flags[9] = ft_scan_len(str, j)))
	{
		if (flags[9] == 1 || flags[9] == 3)
			j += 2;
		else
			j++;
	}
	i = 0;
	while (conv[i])
		if (str[j] == conv[i++])
		{
			*ct += j;
			ft_scan_conv(str + j, flags);
			return (i - 1);
		}
	return (-1);
}

int				ft_printf(const char *str, ...)
{
	va_list	par;
	size_t	i;
	int		ret[2];
	t_fp	*funcs;
	int		flags[FLAGS_AM + 1];

	flags[FLAGS_AM] = 1;
	va_start(par, str);
	ret[1] = 0;
	funcs = ft_fp_arr_init();
	i = -1;
	while (str[++i])
		if (str[i] != '%')
			ret[1] += write(flags[FLAGS_AM], str + i, 1);
		else if ((ret[0] = ft_scan(str + i, &i, flags, par)) != -1)
			ret[1] += funcs[ret[0]](par, flags);
		else if (str[++i] == '$')
			flags[FLAGS_AM] = va_arg(par, int);
		else
			ret[1] += write(flags[FLAGS_AM], str + i, 1);
	free(funcs);
	va_end(par);
	return (ret[1]);
}
