/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libconvfuncs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:24:14 by adzikovs          #+#    #+#             */
/*   Updated: 2017/01/12 16:10:29 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCONVFUNCS_H
# define LIBCONVFUNCS_H
# include "libprintf.h"

typedef int		(*t_fp)(va_list par, const int *flags);

int				ft_put_char(va_list par, const int *flags);

int				ft_put_wchar(va_list par, const int *flags);

int				ft_put_str(va_list par, const int *flags);

int				ft_put_wstr(va_list par, const int *flags);

int				ft_put_nbr_base(uintmax_t n, int base, const int *flags);

int				ft_put_fnbr_base(uintmax_t n, int bs, const int *flags, int d);

int				ft_put_int(va_list par, const int *flags);

int				ft_put_oint(va_list par, const int *flags);

int				ft_put_hint(va_list par, const int *flags);

int				ft_put_uhint(va_list par, const int *flags);

int				ft_put_uint(va_list par, const int *flags);

int				ft_put_pointer(va_list par, const int *flags);

int				ft_put_int_arr(va_list par, const int *flags);

int				ft_put_tab(va_list par, const int *flags);

int				ft_put_memory(va_list par, const int *flags);

int				ft_put_float(va_list par, const int *flags);

#endif
